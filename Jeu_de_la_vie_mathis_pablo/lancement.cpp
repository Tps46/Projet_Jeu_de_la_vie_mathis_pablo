#include "lancement.hpp"
#include "fichier.hpp"
#include "grille.hpp"

lancement::lancement(){}


void lancement::lelancement() {

    fichier f;
    f.charger("test");
    //f.affiche();

    grille maGrille;


    // Initialiser avec quelques cellules vivantes
    maGrille.initialiser(f.obtenirGrille());

    std::cout << "Generation initiale:" << std::endl;
    maGrille.afficher();


    for (int i = 1; i < 5; ++i) {
        maGrille.prochaineGeneration();
        std::cout << "Generation suivante:" << std::endl;
        maGrille.afficher();


        f.ecrire(i, maGrille);
    }
    

}


