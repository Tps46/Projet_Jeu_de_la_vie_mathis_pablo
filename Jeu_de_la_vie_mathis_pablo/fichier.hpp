#ifndef FICHIER_HPP
#define FICHIER_HPP

#include <vector>
#include <string>
#include "cellule.hpp"
#include "grille.hpp"

class fichier {
private:
    int hauteur;
    int longeur;
    std::vector<std::vector<cellule>> maGrille;
    std::string nomFichier;
    

public:
    fichier();

    void charger(const std::string& filename);

    std::vector<std::vector<cellule>>& obtenirGrille();
    
    void ecrire(int generation, grille& maGrille);


};

#endif // FICHIER_HPP
