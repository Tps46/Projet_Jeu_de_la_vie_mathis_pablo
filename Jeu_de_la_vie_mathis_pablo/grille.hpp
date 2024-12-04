#ifndef GRILLE_HPP
#define GRILLE_HPP

#include <vector>
#include "cellule.hpp"

class grille {
private:
    int hauteur;
    int largeur;
    std::vector<std::vector<cellule>> cellules;

    int compterVoisinsVivants(int x, int y) const;

public:
    grille(int h, int l);

    void initialiser(const std::vector<std::pair<int, int>>& positionsVivantes);
    void afficher() const;
    void prochaineGeneration();
};

#endif // GRILLE_HPP
