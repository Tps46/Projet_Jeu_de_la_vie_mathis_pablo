#include "lancement.hpp"
#include "fichier.hpp"
#include "grille.hpp"
#include "graphique.hpp"
#include <SFML/Graphics.hpp>

lancement::lancement(){}


void lancement::lelancement() {
    fichier f;
    f.charger("test");
    // f.affiche();

    grille maGrille;

    // Initialiser avec quelques cellules vivantes
    maGrille.initialiser(f.obtenirGrille());

    std::cout << "Generation initiale:" << std::endl;
    maGrille.afficher();

    // Créer l'objet graphique
    graphique g;

    // Boucle pour itérer sur les générations
    for (int i = 1; i < 7; ++i) {
        maGrille.prochaineGeneration();
        std::cout << "Generation suivante:" << std::endl;
        maGrille.afficher();

        f.ecrire(i, maGrille);

        // Appeler la fonction graphique pour afficher la nouvelle génération
        g.initialiser(maGrille.obtenirCellules());
        
    }
}

