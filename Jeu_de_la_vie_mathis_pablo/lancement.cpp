#include "lancement.hpp"
#include "fichier.hpp"
#include "grille.hpp"
#include "graphique.hpp"
#include <SFML/Graphics.hpp>

lancement::lancement(){}


void lancement::leLancement()
{
    int mode_lancement;
    std::cout << "saisir mode de lancement 1 pour Console\n2 pour Graphique" << std::endl;
    std::cin >> mode_lancement;
    switch (mode_lancement) {
    case (1):
        lancementConsole();
        break;
    case (2):
        lancementGraphique();
        break;
    default:
        lancementGraphique();
    }
}

void lancement::lancementGraphique() {

    fichier fichierGraphique;
    fichierGraphique.charger("test3");
    // f.affiche();

    grille maGrille;

    // Initialiser avec quelques cellules vivantes
    maGrille.initialiser(fichierGraphique.obtenirGrille());

    // Créer l'objet graphique
    graphique g;
    g.initialiser(maGrille.obtenirCellules());
    g.renderGrid(maGrille.obtenirCellules());

    // Boucle pour itérer sur les générations
    for (int i = 1; i < 3; ++i) {
        maGrille.prochaineGeneration();
                
        fichierGraphique.ecrire(i, maGrille);

        // Appeler la fonction graphique pour afficher la nouvelle génération
        
        g.renderGrid(maGrille.obtenirCellules());
    }
}

void lancement::lancementConsole()
{
    fichier fichierConsole;
    fichierConsole.charger("test3");
    
    grille maGrille;

    // Initialiser avec quelques cellules vivantes
    maGrille.initialiser(fichierConsole.obtenirGrille());

    std::cout << "Generation initiale:" << std::endl;
    maGrille.afficher();

    // Boucle pour itérer sur les générations
    for (int i = 1; i < 3; ++i) {
        maGrille.prochaineGeneration();
        std::cout << "Generation suivante:" << std::endl;
        maGrille.afficher();

        fichierConsole.ecrire(i, maGrille);

    }

}

