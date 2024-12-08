#include "lancement.hpp"

// Constructeur de la classe "lancement". Il initialise le nombre d'itérations à 10 par défaut.
lancement::lancement() : nombre_iteration(10) {}

// Méthode principale qui démarre le processus de lancement en fonction du mode choisi.
void lancement::leLancement()
{
    // Affiche le menu pour que l'utilisateur choisisse le mode de lancement.
    menu();
}

// Lancement avec une interface graphique (mode graphique).
void lancement::lancementGraphique(int duree_iteration) {

    // Création d'un objet fichier pour charger les données du fichier graphique.
    fichier fichierGraphique;

    // Demande à l'utilisateur d'entrer le nom du fichier contenant la configuration de la grille.
    std::string nomFichier;
    std::cout << "Entrez le nom du fichier : ";
    std::cin >> nomFichier;
    fichierGraphique.charger(nomFichier);  // Charge le fichier.

    // Création d'un objet grille pour stocker l'état de la grille.
    grille maGrille;

    // Initialisation de la grille avec les données du fichier.
    maGrille.initialiser(fichierGraphique.obtenirGrille());

    // Création de l'objet graphique pour gérer l'affichage visuel.
    graphique g;
    g.initialiser(maGrille.obtenirCellules(), duree_iteration);  // Initialisation avec la grille et la durée des itérations.
    g.renderGrid(maGrille.obtenirCellules());  // Rendu de la grille initiale.

    // Boucle pour itérer sur les générations.
    for (int i = 1; i <= nombre_iteration; ++i) {
        // Vérifie si le programme entre dans une répétition infinie (par exemple, si la grille ne change plus).
        if (!maGrille.prochaineGeneration()) {
            std::cout << "Le programme se répète" << std::endl;
            break;  // Arrête la boucle si la grille ne change plus.
        }

        // Écriture de la génération courante dans un fichier.
        fichierGraphique.ecrire(i, maGrille);

        // Affichage de la grille après l'itération.
        g.renderGrid(maGrille.obtenirCellules());
    }
}

// Lancement en mode console (affichage texte dans la console).
void lancement::lancementConsole()
{
    // Création d'un objet fichier pour charger les données du fichier texte.
    fichier fichierConsole;

    std::string nomFichier;
    std::cout << "Entrez le nom du fichier : ";
    std::cin >> nomFichier;
    fichierConsole.charger(nomFichier);  // Charge le fichier.

    // Création d'un objet grille pour stocker l'état de la grille.
    grille maGrille;

    // Initialisation de la grille avec les données du fichier.
    maGrille.initialiser(fichierConsole.obtenirGrille());

    // Affichage de la génération initiale.
    std::cout << "Generation initiale:" << std::endl;
    maGrille.afficher();

    // Boucle pour itérer sur les générations.
    for (int i = 1; i <= nombre_iteration; ++i) {
        // Vérifie si le programme entre dans une répétition infinie (par exemple, si la grille ne change plus).
        if (!maGrille.prochaineGeneration()) {
            std::cout << "Le programme se répète" << std::endl;
            break;  // Arrête la boucle si la grille ne change plus.
        }

        // Affichage de la nouvelle génération.
        std::cout << "Generation suivante:" << std::endl;
        maGrille.afficher();

        // Écriture de la génération courante dans un fichier.
        fichierConsole.ecrire(i, maGrille);
    }
}

// Lancement des tests unitaires pour vérifier certaines fonctionnalités du jeu.
void lancement::lancementTest_unitaire()
{
    // Appel à une méthode qui lance les tests unitaires. À définir dans un autre fichier.
    lancerTests();
}

// Affichage du menu pour permettre à l'utilisateur de choisir le mode de lancement.
void lancement::menu()
{
    int mode_lancement;
    std::cout << "Saisir mode de lancement \n1 pour Console\n2 pour Graphique\n3 pour les tests unitaires" << std::endl;

    // Validation de l'entrée pour le mode de lancement
    while (true) {
        std::cin >> mode_lancement;
        if (std::cin.fail() || (mode_lancement < 1 || mode_lancement > 3)) {
            std::cin.clear();  // Efface l'erreur de saisie
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore le reste de l'entrée
            std::cout << "Entrée invalide. Veuillez choisir entre 1, 2 ou 3." << std::endl;
        }
        else {
            break;  // Sort de la boucle si l'entrée est valide
        }
    }

    // Si le mode choisi n'est pas "tests unitaires", on demande le nombre d'itérations.
    if (mode_lancement != 3) {
        int saisie_nombre_iteration;
        std::cout << "Saisir le nombre max d'itération" << std::endl;

        // Validation de l'entrée pour le nombre d'itérations
        while (true) {
            std::cin >> saisie_nombre_iteration;
            if (std::cin.fail() || saisie_nombre_iteration <= 0) {
                std::cin.clear();  // Efface l'erreur de saisie
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore le reste de l'entrée
                std::cout << "Entrée invalide. Veuillez entrer un nombre d'itérations positif." << std::endl;
            }
            else {
                nombre_iteration = saisie_nombre_iteration;
                break;  // Sort de la boucle si l'entrée est valide
            }
        }
    }

    // Exécution du mode choisi.
    switch (mode_lancement) {
    case (1):
        // Lancement en mode console.
        lancementConsole();
        break;

    case (2):
        // Lancement en mode graphique.
        int duree_iteration;
        std::cout << "Saisir la durée entre deux itérations (en millisecondes) :" << std::endl;

        // Validation de l'entrée pour la durée des itérations
        while (true) {
            std::cin >> duree_iteration;
            if (std::cin.fail() || duree_iteration <= 0) {
                std::cin.clear();  // Efface l'erreur de saisie
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore le reste de l'entrée
                std::cout << "Entrée invalide. Veuillez entrer une durée positive en millisecondes." << std::endl;
            }
            else {
                lancementGraphique(duree_iteration);
                break;  // Sort de la boucle si l'entrée est valide
            }
        }
        break;

    case (3):
        // Lancement des tests unitaires.
        lancementTest_unitaire();
        break;

    default:
        // Si l'utilisateur entre un mode incorrect, on réaffiche le menu.
        std::cout << "Erreur mode choisi non renseigné";
        menu();
    }
}
