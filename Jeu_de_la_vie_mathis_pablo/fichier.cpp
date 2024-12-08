#include "fichier.hpp"

#include <windows.h>

fichier::fichier() : hauteur(0), longeur(0) {}

void fichier::charger(const std::string& filename) {
    nomFichier = filename; // Enregistrer le nom du fichier d'entr�e (sans le txt) nous le r�utilisons pour l'�criture
    std::ifstream file(filename + ".txt");
    if (!file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier : " << nomFichier << std::endl;
        return;
    }

    // Lire les dimensions du fichier
    if (!(file >> hauteur >> longeur)) {
        std::cerr << "Erreur de lecture des dimensions." << std::endl;
        return;
    }

    // Redimensionner la grille
    maGrille.resize(hauteur, std::vector<cellule>(longeur));

    // Lire les valeurs de la grille
    char ch;
    int row = 0, col = 0;

    while (file.get(ch)) {
        if (ch == '0' || ch == '1') {
            maGrille[row][col] = cellule(ch == '1');
            ++col;
            if (col == longeur) {
                col = 0;
                ++row;
            }
        }
    }

    if (row != hauteur || col != 0) {
        std::cerr << "Donn�es incompl�tes ou format incorrect." << std::endl;
    }

    // Cr�er le dossier
    if (!CreateDirectoryA((nomFichier + "_out").c_str(), NULL)) {
        DWORD dwError = GetLastError(); 
        if (dwError != ERROR_ALREADY_EXISTS) { //j'affiche une erreur si elle est diff�rente de ERROR_ALREADY_EXISTS, qui n'est pas vraiment problematique
            std::cerr << "Erreur lors de la cr�ation du dossier !" << std::endl;
        } 
        
        return; 
    }
}

std::vector<std::vector<cellule>>& fichier::obtenirGrille() {
    return maGrille;
}

void fichier::ecrire(int generation, grille& maGrille) {

    // Obtenir la grille apr�s g�n�ration
    const auto& nouvelleGrille = maGrille.obtenirCellules();

    
    
    std::string outputFilename = nomFichier + "_out\\" + nomFichier + "_out_" + std::to_string(generation) + ".txt";
    // Ouvrir le fichier pour l'�criture
    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier en �criture : " << outputFilename << std::endl;
        return;
    }

    // �crire les dimensions
    outputFile << nouvelleGrille.size() << " " << nouvelleGrille[0].size() << "\n";

    // �crire la grille
    for (const auto& ligne : nouvelleGrille) {
        for (const auto& cell : ligne) {
            outputFile << (cell.obtenirEtat() ? '1' : '0') << " ";
        }
        outputFile << "\n";
    }

    outputFile.close();
}


