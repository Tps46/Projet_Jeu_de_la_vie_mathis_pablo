#include "fichier.hpp"
#include <windows.h>

// Constructeur de la classe 'fichier', initialise hauteur et longeur à 0
fichier::fichier() : hauteur(0), longeur(0) {}

// Méthode pour charger une grille à partir d'un fichier
void fichier::charger(const std::string& filename) {
    nomFichier = filename; // Enregistre le nom du fichier d'entrée (sans l'extension .txt), il est réutilisé pour l'écriture
    std::ifstream file(filename + ".txt"); // Ouvre le fichier d'entrée avec l'extension .txt
    if (!file.is_open()) { // Vérifie si le fichier a été ouvert correctement
        std::cerr << "Erreur lors de l'ouverture du fichier : " << nomFichier << std::endl;
        return;
    }

    // Lecture des dimensions de la grille depuis le fichier
    if (!(file >> hauteur >> longeur)) { // Si la lecture des dimensions échoue
        std::cerr << "Erreur de lecture des dimensions." << std::endl;
        return;
    }

    // Redimensionnement de la grille pour correspondre aux dimensions lues
    maGrille.resize(hauteur, std::vector<cellule>(longeur));

    // Lecture des valeurs de la grille depuis le fichier
    char ch;
    int row = 0, col = 0;

    // Lecture caractère par caractère
    while (file.get(ch)) {
        if (ch == '0' || ch == '1' || ch == '2' || ch == '3') { // Si le caractère est valide
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

            ++col; // Passer à la colonne suivante

            if (col == longeur) { // Si la ligne est complète
                col = 0;          // Réinitialiser la colonne
                ++row;            // Passer à la ligne suivante
            }
        }
    }



    // Vérifie si le nombre de lignes et de colonnes correspond à la grille attendue
    if (row != hauteur || col != 0) {
        std::cerr << "Données incomplètes ou format incorrect." << std::endl;
    }

    // Créer un dossier pour stocker les sorties de chaque génération
    if (!CreateDirectoryA((nomFichier + "_out").c_str(), NULL)) {
        DWORD dwError = GetLastError();
        if (dwError != ERROR_ALREADY_EXISTS) { // Si l'erreur n'est pas ERROR_ALREADY_EXISTS, afficher une erreur
            std::cerr << "Erreur lors de la création du dossier !" << std::endl;
        }
        return; // Si le dossier n'a pas pu être créé, retourner
    }
}

// Méthode pour obtenir une référence à la grille interne 'maGrille'
std::vector<std::vector<cellule>>& fichier::obtenirGrille() {
    return maGrille;
}

// Méthode pour écrire une génération spécifique dans un fichier
void fichier::ecrire(int generation, grille& maGrille) {

    // Obtenir la grille après la génération
    const auto& nouvelleGrille = maGrille.obtenirCellules();

    // Créer un nom de fichier pour la génération actuelle
    std::string outputFilename = nomFichier + "_out\\" + nomFichier + "_out_" + std::to_string(generation) + ".txt";

    // Ouvrir le fichier de sortie
    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) { // Vérifier si l'ouverture du fichier en écriture échoue
        std::cerr << "Erreur lors de l'ouverture du fichier en écriture : " << outputFilename << std::endl;
        return;
    }

    // Écrire les dimensions de la grille dans le fichier
    outputFile << nouvelleGrille.size() << " " << nouvelleGrille[0].size() << "\n";

    // Écrire la grille dans le fichier
    for (const auto& ligne : nouvelleGrille) {
        for (const auto& cell : ligne) {
            outputFile << (cell.obtenirEtat() ? '1' : '0') << " "; // Écrire l'état de chaque cellule (1 ou 0)
        }
        outputFile << "\n"; // Nouvelle ligne après chaque ligne de la grille
    }

    outputFile.close(); // Fermer le fichier après l'écriture
}