#ifndef FICHIER_HPP
#define FICHIER_HPP

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "cellule.hpp"
#include "grille.hpp"

// Classe qui g�re les op�rations de lecture et d'�criture de fichiers pour la grille
class fichier {
private:
    int hauteur;  // Hauteur de la grille (nombre de lignes)
    int longeur;  // Longueur de la grille (nombre de colonnes)
    std::vector<std::vector<cellule>> maGrille; // Grille de cellules (repr�sentation de l'�tat du jeu)
    std::string nomFichier; // Nom du fichier � charger ou dans lequel �crire

public:
    // Constructeur de la classe fichier
    fichier();

    // Fonction pour charger une grille depuis un fichier
    void charger(const std::string& filename);

    // Fonction pour obtenir une r�f�rence � la grille de cellules
    std::vector<std::vector<cellule>>& obtenirGrille();

    // Fonction pour �crire une g�n�ration sp�cifique dans un fichier
    void ecrire(int generation, grille& maGrille);
};

#endif // FICHIER_HPP
