#include "lancement.hpp"
#include "fichier.hpp"
#include "grille.hpp"

lancement::lancement(){}


void lancement::lelancement() {

    fichier f;
    f.charger("test.txt");
    //f.affiche();

    grille maGrille;

    // Initialiser avec quelques cellules vivantes
    maGrille.initialiser(f.obtenirGrille());

    std::cout << "Generation initiale:" << std::endl;
    maGrille.afficher();

    maGrille.prochaineGeneration();
    std::cout << "Generation suivante:" << std::endl;
    maGrille.afficher();

}