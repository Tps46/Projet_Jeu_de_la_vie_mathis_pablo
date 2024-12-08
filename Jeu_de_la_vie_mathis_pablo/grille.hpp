#ifndef GRILLE_HPP
#define GRILLE_HPP

// Inclusion des biblioth�ques n�cessaires
#include <vector>    // Pour utiliser std::vector, une structure de donn�es dynamique
#include <iostream>  // Pour les entr�es/sorties en console
#include "cellule.hpp"  // Inclusion de la classe cellule, probablement pour manipuler les cellules de la grille

// D�finition de la classe "grille" qui repr�sente une grille de cellules.
class grille {
private:
    // Un vecteur 2D de cellules (matrice de cellules). Chaque �l�ment est un objet de type "cellule".
    std::vector<std::vector<cellule>> cellules;

public:
    // Compte le nombre de voisins vivants pour une cellule donn�e aux coordonn�es (x, y).
    // Cette m�thode est marqu�e const car elle ne modifie pas l'�tat de l'objet grille.
    int compterVoisinsVivants(int x, int y) const;

    // Retourne une r�f�rence vers la matrice des cellules de la grille. Permet de manipuler directement les cellules.
    // Cette m�thode renvoie une r�f�rence non-const pour permettre la modification des cellules.
    std::vector<std::vector<cellule>>& obtenirCellules();

    // Initialise la grille avec une matrice de cellules (probablement fournie par un fichier ou d'autres donn�es externes).
    void initialiser(std::vector<std::vector<cellule>> entreeGrille);

    // Affiche l'�tat actuel de la grille sur la sortie standard (console).
    // La m�thode est const car elle ne modifie pas l'�tat de l'objet grille.
    void afficher() const;

    // Calcule et applique la prochaine g�n�ration � la grille selon les r�gles du jeu de la vie (ou autre logique).
    // Renvoie vrai si la grille a chang�, faux si la grille est stable (par exemple, si aucune cellule n'a chang�).
    bool prochaineGeneration();
};

#endif
