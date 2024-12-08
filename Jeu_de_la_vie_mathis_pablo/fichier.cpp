#include "fichier.hpp"
#include <windows.h>

// Constructeur de la classe 'fichier', initialise hauteur et longeur � 0
fichier::fichier() : hauteur(0), longeur(0) {}

// M�thode pour charger une grille � partir d'un fichier
void fichier::charger(const std::string& filename) {
    nomFichier = filename; // Enregistre le nom du fichier d'entr�e (sans l'extension .txt), il est r�utilis� pour l'�criture
    std::ifstream file(filename + ".txt"); // Ouvre le fichier d'entr�e avec l'extension .txt
    if (!file.is_open()) { // V�rifie si le fichier a �t� ouvert correctement
        std::cerr << "Erreur lors de l'ouverture du fichier : " << nomFichier << std::endl;
        return;
    }

    // Lecture des dimensions de la grille depuis le fichier
    if (!(file >> hauteur >> longeur)) { // Si la lecture des dimensions �choue
        std::cerr << "Erreur de lecture des dimensions." << std::endl;
        return;
    }

    // Redimensionnement de la grille pour correspondre aux dimensions lues
    maGrille.resize(hauteur, std::vector<cellule>(longeur));

    // Lecture des valeurs de la grille depuis le fichier
    char ch;
    int row = 0, col = 0;

    // Lecture caract�re par caract�re
    while (file.get(ch)) {
        if (ch == '0' || ch == '1' || ch == '2' || ch == '3') { // Si le caract�re est valide
            switch (ch) {
            case '0': // Cellule normale morte
                maGrille[row][col] = cellule(false, false);
                break;
            case '1': // Cellule normale vivante
                maGrille[row][col] = cellule(true, false);
                break;
            case '2': // Obstacle mort
                maGrille[row][col] = cellule(false, true);
                break;
            case '3': // Obstacle vivant
                maGrille[row][col] = cellule(true, true);
                break;
            }

            ++col; // Passer � la colonne suivante

            if (col == longeur) { // Si la ligne est compl�te
                col = 0;          // R�initialiser la colonne
                ++row;            // Passer � la ligne suivante
            }
        }
    }



    // V�rifie si le nombre de lignes et de colonnes correspond � la grille attendue
    if (row != hauteur || col != 0) {
        std::cerr << "Donn�es incompl�tes ou format incorrect." << std::endl;
    }

    // Cr�er un dossier pour stocker les sorties de chaque g�n�ration
    if (!CreateDirectoryA((nomFichier + "_out").c_str(), NULL)) {
        DWORD dwError = GetLastError();
        if (dwError != ERROR_ALREADY_EXISTS) { // Si l'erreur n'est pas ERROR_ALREADY_EXISTS, afficher une erreur
            std::cerr << "Erreur lors de la cr�ation du dossier !" << std::endl;
        }
        return; // Si le dossier n'a pas pu �tre cr��, retourner
    }
}

// M�thode pour obtenir une r�f�rence � la grille interne 'maGrille'
std::vector<std::vector<cellule>>& fichier::obtenirGrille() {
    return maGrille;
}

// M�thode pour �crire une g�n�ration sp�cifique dans un fichier
void fichier::ecrire(int generation, grille& maGrille) {

    // Obtenir la grille apr�s la g�n�ration
    const auto& nouvelleGrille = maGrille.obtenirCellules();

    // Cr�er un nom de fichier pour la g�n�ration actuelle
    std::string outputFilename = nomFichier + "_out\\" + nomFichier + "_out_" + std::to_string(generation) + ".txt";

    // Ouvrir le fichier de sortie
    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) { // V�rifier si l'ouverture du fichier en �criture �choue
        std::cerr << "Erreur lors de l'ouverture du fichier en �criture : " << outputFilename << std::endl;
        return;
    }

    // �crire les dimensions de la grille dans le fichier
    outputFile << nouvelleGrille.size() << " " << nouvelleGrille[0].size() << "\n";

    // �crire la grille dans le fichier
    for (const auto& ligne : nouvelleGrille) {
        for (const auto& cell : ligne) {
            outputFile << (cell.obtenirEtat() ? '1' : '0') << " "; // �crire l'�tat de chaque cellule (1 ou 0)
        }
        outputFile << "\n"; // Nouvelle ligne apr�s chaque ligne de la grille
    }

    outputFile.close(); // Fermer le fichier apr�s l'�criture
}