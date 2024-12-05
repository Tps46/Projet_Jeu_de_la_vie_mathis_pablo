#include "fichier.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

fichier::fichier() {
    hauteur = new int;      // vrm besoin de ça ???????????????????????????????????????????????
    longeur = new int;
}

fichier::~fichier() {
    delete hauteur;
    delete longeur;
}

void fichier::charger(std::string filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        char ch;

        // Lire les dimensions du fichier
        if (std::getline(file, line)) {
            std::istringstream iss(line);
            if (iss >> *hauteur >> *longeur) {
                std::cout << "hauteur: " << *hauteur << std::endl;
                std::cout << "longeur: " << *longeur << std::endl;
            }
        }

        // Redimensionner la grille selon les dimensions lues
        maGrille.resize(*hauteur, std::vector<cellule>(*longeur));

        int isaut = 0;  // Indice de la ligne, colonne
        int iespace = 0;  // Indice de la colonne

        // Lire le reste du fichier et remplir la grille
        while (file.get(ch)) {
            if (ch == '\n') {  // Nouvelle ligne
                isaut += 1;
                iespace = 0;  // Revenir à la première colonne
            }
            else if (ch == ' ') {  // Espace entre les valeurs
                iespace += 1;
            }
            else if (ch == '0' || ch == '1') {  // Lire '0' ou '1'
                std::cout << "chek: " << ch << std::endl;
                // Créer une cellule avec l'état approprié
                maGrille[isaut][iespace] = cellule(ch == '1');  // '1' -> true, '0' -> false
                                
            }
        }

        file.close();
    }
    else {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
    }
}
 

void fichier::affiche() const {
    std::cout << "haut eurrrrr: " << *hauteur << std::endl;
    std::cout << "long eurrrrr: " << *longeur << std::endl;
    for (int i = 0; i < *hauteur; ++i) {
        for (int j = 0; j < *longeur; ++j) {
            // Vérifiez l'état de la cellule directement
            std::cout << (maGrille[i][j].obtenirEtat() ? '1' : '0') << " ";
        }
        std::cout << "\n";
    }
}

std::vector<std::vector<cellule>>& fichier::obtenirGrille() { 
    return maGrille; 
}