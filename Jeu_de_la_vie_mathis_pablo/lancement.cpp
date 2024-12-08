#include "lancement.hpp"
#include "fichier.hpp"
#include "grille.hpp"
#include "graphique.hpp"
#include "test_unitaire.hpp"
#include <SFML/Graphics.hpp>

lancement::lancement(){}


void lancement::leLancement()
{
    
    menu();    
}

void lancement::lancementGraphique(int duree_iteration) {

    fichier fichierGraphique;
    fichierGraphique.charger("test");
    // f.affiche();

    grille maGrille;

    // Initialiser avec quelques cellules vivantes
    maGrille.initialiser(fichierGraphique.obtenirGrille());

    // Créer l'objet graphique
    graphique g;
    g.initialiser(maGrille.obtenirCellules(), duree_iteration);
    g.renderGrid(maGrille.obtenirCellules());

    // Boucle pour itérer sur les générations
    for (int i = 1; i <= nombre_iteration; ++i) {
        maGrille.prochaineGeneration();
                
        fichierGraphique.ecrire(i, maGrille);

        // afficher la nouvelle génération
        g.renderGrid(maGrille.obtenirCellules());
    }
}

void lancement::lancementConsole()
{
    fichier fichierConsole;
    fichierConsole.charger("test");
    
    grille maGrille;

    // Initialiser avec quelques cellules vivantes
    maGrille.initialiser(fichierConsole.obtenirGrille());

    std::cout << "Generation initiale:" << std::endl;
    maGrille.afficher();

    // Boucle pour itérer sur les générations
    for (int i = 1; i <= nombre_iteration; ++i) {
        maGrille.prochaineGeneration();
        std::cout << "Generation suivante:" << std::endl;
        maGrille.afficher();

        fichierConsole.ecrire(i, maGrille);

    }

}

void lancement::lancementTest_unitaire()
{
    lancerTests();
}

void lancement::menu()
{
    int mode_lancement;
    std::cout << "Saisir mode de lancement \n1 pour Console\n2 pour Graphique\n3 pour les tests unitaires" << std::endl;
    std::cin >> mode_lancement;

    int saisie_nombre_iteration;
    std::cout << "Saisir le nombre max d'itération" << std::endl;
    std::cin >> saisie_nombre_iteration;
    nombre_iteration = saisie_nombre_iteration;
    switch (mode_lancement) {
    case (1):
        lancementConsole();
        break;

    case (2):
        int duree_iteration;
        std::cout << "Saisir la durée entre deux itérations (en milisecondes) :" << std::endl;
        std::cin >> duree_iteration;
        lancementGraphique(duree_iteration);
        break;

    case (3):
        lancementTest_unitaire();
        break;

    default:
        std::cout << "Erreur mode choisi non renseigné";
        menu();
    }
}

