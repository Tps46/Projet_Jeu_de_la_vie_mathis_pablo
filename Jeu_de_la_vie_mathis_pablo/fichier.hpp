#ifndef FICHIER_HPP_INCLUDED
#define FICHIER_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "cellule.hpp"

class fichier {
public:
    fichier();
    ~fichier();
    void charger(std::string);
    void affiche() const;
    std::vector<std::vector<cellule>>& obtenirGrille();
    std::vector<std::vector<cellule>> maGrille;
    int* hauteur, * longeur;
       
    
};

#endif
