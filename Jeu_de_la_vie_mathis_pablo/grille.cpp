#include "grille.hpp"
#include "fichier.hpp"

std::vector<std::vector<cellule>>& grille::obtenirCellules() {
    return cellules;
}


void grille::initialiser(std::vector<std::vector<cellule>> entreeGrille) {

    cellules = entreeGrille;

}

void grille::afficher() const {
    for (int i = 0; i < cellules.size(); ++i) {
        for (int j = 0; j < cellules[0].size(); ++j) {
            std::cout << (cellules[i][j].obtenirEtat() ? '1' : '0') << " ";
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


bool grille::prochaineGeneration() {
    std::vector<std::vector<cellule>> nouvelleGrille = cellules; // Copie de la grille pour appliquer les changements après avoir compté les voisins

    for (int i = 0; i < cellules.size(); ++i) {
        for (int j = 0; j < cellules[0].size(); ++j) {
            int voisinsVivants = compterVoisinsVivants(i, j);

            if (cellules[i][j].obtenirEtat() == true) { // Cellule vivante
                if (voisinsVivants != 2 && voisinsVivants != 3) {
                    nouvelleGrille[i][j].definirEtat(false);
                }
            }
            else if (cellules[i][j].obtenirEtat() == false) { // Cellule morte
                if (voisinsVivants == 3) {
                    nouvelleGrille[i][j].definirEtat(true);
                }
            }
        }
    }


    
    

    bool check_evolution(false);
    //bool total_evolution(false);
    for (int y = 0; y < cellules[0].size(); ++y) {
        for (int x = 0; x < cellules.size(); ++x) {
            if (cellules[x][y].obtenirEtat() != nouvelleGrille[x][y].obtenirEtat()) {
                check_evolution = true;
                
            }
        }
    }

    
    // Appliquer les nouveaux états
    cellules = nouvelleGrille;

    return(check_evolution);
}
