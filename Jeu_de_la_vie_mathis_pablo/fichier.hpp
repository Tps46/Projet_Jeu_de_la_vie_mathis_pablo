#ifndef FICHIER_HPP
#define FICHIER_HPP

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "cellule.hpp"
#include "grille.hpp"

// Classe qui gère les opérations de lecture et d'écriture de fichiers pour la grille
class fichier {
private:
    int hauteur;  // Hauteur de la grille (nombre de lignes)
    int longeur;  // Longueur de la grille (nombre de colonnes)
    std::vector<std::vector<cellule>> maGrille; // Grille de cellules (représentation de l'état du jeu)
    std::string nomFichier; // Nom du fichier à charger ou dans lequel écrire

public:
    // Constructeur de la classe fichier
    fichier();

    // Fonction pour charger une grille depuis un fichier
    void charger(const std::string& filename);

    // Fonction pour obtenir une référence à la grille de cellules
    std::vector<std::vector<cellule>>& obtenirGrille();

    // Fonction pour écrire une génération spécifique dans un fichier
    void ecrire(int generation, grille& maGrille);
};

#endif // FICHIER_HPP
