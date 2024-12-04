#include "grille.hpp"
#include "fichier.hpp"
#include <iostream>

grille::grille(int h, int l) : hauteur(h), largeur(l) {
    
    std::cout << "iccccccccccccccccccci : " << "e" << std::endl;
    
    std::cout << "f.obtenirGrille()[1][1]" << std::endl;
    cellules = std::vector<std::vector<cellule>>(hauteur, std::vector<cellule>(largeur));
}

void grille::initialiser(const std::vector<std::pair<int, int>>& positionsVivantes) {
    for (const auto& pos : positionsVivantes) {
        int x = pos.first;
        int y = pos.second;
        if (x >= 0 && x < hauteur && y >= 0 && y < largeur) {
            cellules[x][y].definirEtat(true); // Rendre vivante
        }
    }
}

void grille::afficher() const {
    fichier f;
    f.obtenirGrille();
    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            std::cout << (f.obtenirGrille[i][j].obtenirEtat() ? 'O' : 'L') << " ";
        }
        std::cout << std::endl;
    }
}

int grille::compterVoisinsVivants(int x, int y) const {
    int compte = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue; // Ne pas compter la cellule elle-même
            int voisinX = x + i;
            int voisinY = y + j;
            if (voisinX >= 0 && voisinX < hauteur && voisinY >= 0 && voisinY < largeur) {
                if (cellules[voisinX][voisinY].obtenirEtat()) {
                    ++compte;
                }
            }
        }
    }
    return compte;
}

void grille::prochaineGeneration() {
    std::vector<std::vector<cellule>> nouvelleGrille = cellules;

    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            int voisinsVivants = compterVoisinsVivants(i, j);
            if (cellules[i][j].obtenirEtat()) {
                nouvelleGrille[i][j].definirEtat(voisinsVivants == 2 || voisinsVivants == 3);
            }
            else {
                nouvelleGrille[i][j].definirEtat(voisinsVivants == 3);
            }
        }
    }

    cellules = nouvelleGrille; // Mise à jour de l'état de la grille
}

