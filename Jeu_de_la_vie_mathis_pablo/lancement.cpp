#include "lancement.hpp"
#include "fichier.hpp"
#include "grille.hpp"
#include "graphique.hpp"
#include <SFML/Graphics.hpp>

lancement::lancement(){}


void lancement::leLancement()
{
    //lancementConsole();
    lancementGraphique();
}

void lancement::lancementGraphique() {
    fichier f;
    f.charger("test");
    // f.affiche();

    grille maGrille;

    // Initialiser avec quelques cellules vivantes
    maGrille.initialiser(f.obtenirGrille());

    // Créer l'objet graphique
    graphique g;
    g.initialiser(maGrille.obtenirCellules());
    g.renderGrid(maGrille.obtenirCellules());

    // Boucle pour itérer sur les générations
    for (int i = 1; i < 7; ++i) {
        maGrille.prochaineGeneration();
        std::cout << "Generation suivante:" << std::endl;
        
        f.ecrire(i, maGrille);

        // Appeler la fonction graphique pour afficher la nouvelle génération
        
        g.renderGrid(maGrille.obtenirCellules());
    }
}

void lancement::lancementConsole()
{
    fichier f;
    f.charger("test");
    // f.affiche();

    grille maGrille;

    // Initialiser avec quelques cellules vivantes
    maGrille.initialiser(f.obtenirGrille());

    std::cout << "Generation initiale:" << std::endl;
    maGrille.afficher();

    // Boucle pour itérer sur les générations
    for (int i = 1; i < 7; ++i) {
        maGrille.prochaineGeneration();
        std::cout << "Generation suivante:" << std::endl;
        maGrille.afficher();

        f.ecrire(i, maGrille);

    }

}

