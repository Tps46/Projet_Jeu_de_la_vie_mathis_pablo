#include "lancement.hpp"

// Constructeur de la classe "lancement". Il initialise le nombre d'it�rations � 10 par d�faut.
lancement::lancement() : nombre_iteration(10) {}

// M�thode principale qui d�marre le processus de lancement en fonction du mode choisi.
void lancement::leLancement()
{
    // Affiche le menu pour que l'utilisateur choisisse le mode de lancement.
    menu();
}

// Lancement avec une interface graphique (mode graphique).
void lancement::lancementGraphique(int duree_iteration) {

    // Cr�ation d'un objet fichier pour charger les donn�es du fichier graphique.
    fichier fichierGraphique;

    // Demande � l'utilisateur d'entrer le nom du fichier contenant la configuration de la grille.
    std::string nomFichier;
    std::cout << "Entrez le nom du fichier : ";
    std::cin >> nomFichier;
    fichierGraphique.charger(nomFichier);  // Charge le fichier.

    // Cr�ation d'un objet grille pour stocker l'�tat de la grille.
    grille maGrille;

    // Initialisation de la grille avec les donn�es du fichier.
    maGrille.initialiser(fichierGraphique.obtenirGrille());

    // Cr�ation de l'objet graphique pour g�rer l'affichage visuel.
    graphique g;
    g.initialiser(maGrille.obtenirCellules(), duree_iteration);  // Initialisation avec la grille et la dur�e des it�rations.
    g.renderGrid(maGrille.obtenirCellules());  // Rendu de la grille initiale.

    // Boucle pour it�rer sur les g�n�rations.
    for (int i = 1; i <= nombre_iteration; ++i) {
        // V�rifie si le programme entre dans une r�p�tition infinie (par exemple, si la grille ne change plus).
        if (!maGrille.prochaineGeneration()) {
            std::cout << "Le programme se r�p�te" << std::endl;
            break;  // Arr�te la boucle si la grille ne change plus.
        }

        // �criture de la g�n�ration courante dans un fichier.
        fichierGraphique.ecrire(i, maGrille);

        // Affichage de la grille apr�s l'it�ration.
        g.renderGrid(maGrille.obtenirCellules());
    }
}

// Lancement en mode console (affichage texte dans la console).
void lancement::lancementConsole()
{
    // Cr�ation d'un objet fichier pour charger les donn�es du fichier texte.
    fichier fichierConsole;

    std::string nomFichier;
    std::cout << "Entrez le nom du fichier : ";
    std::cin >> nomFichier;
    fichierConsole.charger(nomFichier);  // Charge le fichier.

    // Cr�ation d'un objet grille pour stocker l'�tat de la grille.
    grille maGrille;

    // Initialisation de la grille avec les donn�es du fichier.
    maGrille.initialiser(fichierConsole.obtenirGrille());

    // Affichage de la g�n�ration initiale.
    std::cout << "Generation initiale:" << std::endl;
    maGrille.afficher();

    // Boucle pour it�rer sur les g�n�rations.
    for (int i = 1; i <= nombre_iteration; ++i) {
        // V�rifie si le programme entre dans une r�p�tition infinie (par exemple, si la grille ne change plus).
        if (!maGrille.prochaineGeneration()) {
            std::cout << "Le programme se r�p�te" << std::endl;
            break;  // Arr�te la boucle si la grille ne change plus.
        }

        // Affichage de la nouvelle g�n�ration.
        std::cout << "Generation suivante:" << std::endl;
        maGrille.afficher();

        // �criture de la g�n�ration courante dans un fichier.
        fichierConsole.ecrire(i, maGrille);
    }
}

// Lancement des tests unitaires pour v�rifier certaines fonctionnalit�s du jeu.
void lancement::lancementTest_unitaire()
{
    // Appel � une m�thode qui lance les tests unitaires. � d�finir dans un autre fichier.
    lancerTests();
}

// Affichage du menu pour permettre � l'utilisateur de choisir le mode de lancement.
void lancement::menu()
{
    int mode_lancement;
    std::cout << "Saisir mode de lancement \n1 pour Console\n2 pour Graphique\n3 pour les tests unitaires" << std::endl;

    // Validation de l'entr�e pour le mode de lancement
    while (true) {
        std::cin >> mode_lancement;
        if (std::cin.fail() || (mode_lancement < 1 || mode_lancement > 3)) {
            std::cin.clear();  // Efface l'erreur de saisie
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore le reste de l'entr�e
            std::cout << "Entr�e invalide. Veuillez choisir entre 1, 2 ou 3." << std::endl;
        }
        else {
            break;  // Sort de la boucle si l'entr�e est valide
        }
    }

    // Si le mode choisi n'est pas "tests unitaires", on demande le nombre d'it�rations.
    if (mode_lancement != 3) {
        int saisie_nombre_iteration;
        std::cout << "Saisir le nombre max d'it�ration" << std::endl;

        // Validation de l'entr�e pour le nombre d'it�rations
        while (true) {
            std::cin >> saisie_nombre_iteration;
            if (std::cin.fail() || saisie_nombre_iteration <= 0) {
                std::cin.clear();  // Efface l'erreur de saisie
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore le reste de l'entr�e
                std::cout << "Entr�e invalide. Veuillez entrer un nombre d'it�rations positif." << std::endl;
            }
            else {
                nombre_iteration = saisie_nombre_iteration;
                break;  // Sort de la boucle si l'entr�e est valide
            }
        }
    }

    // Ex�cution du mode choisi.
    switch (mode_lancement) {
    case (1):
        // Lancement en mode console.
        lancementConsole();
        break;

    case (2):
        // Lancement en mode graphique.
        int duree_iteration;
        std::cout << "Saisir la dur�e entre deux it�rations (en millisecondes) :" << std::endl;

        // Validation de l'entr�e pour la dur�e des it�rations
        while (true) {
            std::cin >> duree_iteration;
            if (std::cin.fail() || duree_iteration <= 0) {
                std::cin.clear();  // Efface l'erreur de saisie
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore le reste de l'entr�e
                std::cout << "Entr�e invalide. Veuillez entrer une dur�e positive en millisecondes." << std::endl;
            }
            else {
                lancementGraphique(duree_iteration);
                break;  // Sort de la boucle si l'entr�e est valide
            }
        }
        break;

    case (3):
        // Lancement des tests unitaires.
        lancementTest_unitaire();
        break;

    default:
        // Si l'utilisateur entre un mode incorrect, on r�affiche le menu.
        std::cout << "Erreur mode choisi non renseign�";
        menu();
    }
}
