#ifndef GRILLE_HPP
#define GRILLE_HPP

#include <vector>
#include "cellule.hpp"

class grille {
private:
    int hauteur;
    int largeur;
    std::vector<std::vector<cellule>> cellules;

public:
    grille();

    int compterVoisinsVivants(int x, int y) const;
    std::vector<std::vector<cellule>>& obtenirCellules();
    void initialiser(std::vector<std::vector<cellule>> entreeGrille);
    void afficher() const; // On met en const lorsque l'on n'a pas besoin de modifier
    void prochaineGeneration();
};

#endif 