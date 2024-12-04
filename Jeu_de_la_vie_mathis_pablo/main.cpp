#include "fichier.hpp"
#include "grille.hpp"

int main() {


    grille maGrille(5, 10);

    // Initialiser avec quelques cellules vivantes
    maGrille.initialiser({ {1, 2}, {2, 2}, {3, 2} });

    std::cout << "Generation initiale:" << std::endl;
    maGrille.afficher();

    maGrille.prochaineGeneration();
    std::cout << "Generation suivante:" << std::endl;
    maGrille.afficher();

    maGrille.prochaineGeneration();
    std::cout << "Generation suivante:" << std::endl;
    maGrille.afficher();

    fichier f;
    f.charger("test.txt");
    

    return 0;
}
