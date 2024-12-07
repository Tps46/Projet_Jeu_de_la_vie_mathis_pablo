#include "lancement.hpp"
#include "fichier.hpp"
#include "grille.hpp"

lancement::lancement(){}


void lancement::leLancement() {
    
    fichier f;
    f.charger("test");
    //f.affiche();

    grille maGrille;


    // Initialiser avec quelques cellules vivantes
    maGrille.initialiser(f.obtenirGrille());

    std::cout << "Generation initiale:" << std::endl;
    maGrille.afficher();


    for (int i = 1; i < 7; ++i) {
        maGrille.prochaineGeneration();
        std::cout << "\nGeneration n+" + std::to_string(i) + " :" << std::endl;
        maGrille.afficher();


        f.ecrire(i, maGrille);
    }
    

}


