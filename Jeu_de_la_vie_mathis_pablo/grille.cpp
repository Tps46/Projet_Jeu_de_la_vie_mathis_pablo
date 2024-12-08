#include "grille.hpp"
#include "fichier.hpp"
#include <iostream>

grille::grille() {
    //pas besoin de constructeur autre que celui par defaut A MODIFIERRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
}

std::vector<std::vector<cellule>>& grille::obtenirCellules() {
    return cellules;
}


void grille::initialiser(std::vector<std::vector<cellule>> entreeGrille) {

    cellules = entreeGrille;

}

void grille::afficher() const {
    for (int i = 0; i < cellules.size(); ++i) {
        for (int j = 0; j < cellules[0].size(); ++j) {
            std::cout << (cellules[j][i].obtenirEtat() ? '1' : '0') << " ";
        }
        std::cout << std::endl;
    }
}

int grille::compterVoisinsVivants(int x, int y) const {
    int compteur = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {

            int xi = x + i;

            if (xi < 0) { // torique
                xi = cellules.size() + xi;
            }
            else if (xi >= cellules.size()) { // torique
                xi = xi - cellules.size();
            }
            else {

            }

            int yj = y + j;

            if (yj < 0) { // torique
                yj = cellules[0].size() + yj;
            }
            else if (yj >= cellules[0].size()) { // torique
                yj = yj - cellules[0].size();
            }
            else {

            }

            if ((cellules[xi][yj].obtenirEtat() == true) and !(i == 0 and j == 0)) {

                compteur += 1;
            }
        }
    }

    return compteur;
}


void grille::prochaineGeneration() {
    std::vector<std::vector<cellule>> nouvelleGrille = cellules; //Si je ne fais pas �a les cellules changent en m�me temps que je la parcours

    for (int i = 0; i < cellules.size(); ++i) {
        for (int j = 0; j < cellules[0].size(); ++j) {
            int voisinsVivants = compterVoisinsVivants(i, j);

            if (cellules[i][j].obtenirEtat() == true) { //cellule vivante reste vivant si 2 ou 3 voisines
                if (voisinsVivants != 2 and voisinsVivants != 3) {
                    nouvelleGrille[i][j].definirEtat(false);
                }
            }
            else if (cellules[i][j].obtenirEtat() == false) { //cellule morte devient vivante si exactement 3 voisines
                if (voisinsVivants == 3) {
                    nouvelleGrille[i][j].definirEtat(true);
                }
            }
        }
    }

    // applique les nouveaux �tats � la grille principale, en faisant cela les calculs de compterVoisinsVivants ne changent pas en cours de route
    cellules = nouvelleGrille;
}