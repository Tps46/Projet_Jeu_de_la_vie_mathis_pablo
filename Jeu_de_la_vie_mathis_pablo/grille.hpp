#ifndef GRILLE_HPP
#define GRILLE_HPP

// Inclusion des bibliothèques nécessaires
#include <vector>    // Pour utiliser std::vector, une structure de données dynamique
#include <iostream>  // Pour les entrées/sorties en console
#include "cellule.hpp"  // Inclusion de la classe cellule, probablement pour manipuler les cellules de la grille

// Définition de la classe "grille" qui représente une grille de cellules.
class grille {
private:
    // Un vecteur 2D de cellules (matrice de cellules). Chaque élément est un objet de type "cellule".
    std::vector<std::vector<cellule>> cellules;

public:
    // Compte le nombre de voisins vivants pour une cellule donnée aux coordonnées (x, y).
    // Cette méthode est marquée const car elle ne modifie pas l'état de l'objet grille.
    int compterVoisinsVivants(int x, int y) const;

    // Retourne une référence vers la matrice des cellules de la grille. Permet de manipuler directement les cellules.
    // Cette méthode renvoie une référence non-const pour permettre la modification des cellules.
    std::vector<std::vector<cellule>>& obtenirCellules();

    // Initialise la grille avec une matrice de cellules (probablement fournie par un fichier ou d'autres données externes).
    void initialiser(std::vector<std::vector<cellule>> entreeGrille);

    // Affiche l'état actuel de la grille sur la sortie standard (console).
    // La méthode est const car elle ne modifie pas l'état de l'objet grille.
    void afficher() const;

    // Calcule et applique la prochaine génération à la grille selon les règles du jeu de la vie (ou autre logique).
    // Renvoie vrai si la grille a changé, faux si la grille est stable (par exemple, si aucune cellule n'a changé).
    bool prochaineGeneration();
};

#endif
