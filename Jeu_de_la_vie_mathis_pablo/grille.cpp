#include "grille.hpp"
#include "fichier.hpp"

// Fonction qui retourne une référence à la grille de cellules.
std::vector<std::vector<cellule>>& grille::obtenirCellules() {
    return cellules; // Renvoie la grille de cellules sous forme de référence.
}

// Fonction pour initialiser la grille avec une grille entrée en paramètre.
void grille::initialiser(std::vector<std::vector<cellule>> entreeGrille) {
    cellules = entreeGrille; // Affecte l'argument entreeGrille à la grille interne "cellules".
}

// Fonction pour afficher la grille.
void grille::afficher() const {
    // Parcours de la grille pour afficher chaque cellule
    for (int i = 0; i < cellules.size(); ++i) { // Parcours des lignes
        for (int j = 0; j < cellules[0].size(); ++j) { // Parcours des colonnes
            // Affiche '1' si la cellule est vivante, '0' si elle est morte
            std::cout << (cellules[i][j].obtenirEtat() ? '1' : '0') << " ";
        }
        std::cout << std::endl; // Nouvelle ligne après chaque ligne de la grille
    }
}

// Fonction pour compter le nombre de voisins vivants autour d'une cellule.
int grille::compterVoisinsVivants(int x, int y) const {
    int compteur = 0; // Initialisation du compteur de voisins vivants

    // Parcours des cellules autour de la cellule (x, y) dans un rayon de 1
    for (int i = -1; i <= 1; ++i) { // Parcours de -1 à +1 sur l'axe des x
        for (int j = -1; j <= 1; ++j) { // Parcours de -1 à +1 sur l'axe des y

            int xi = x + i; // Coordonnée x de la cellule voisine
            // Gestion du cas "torique" : si xi est hors des bords, on boucle sur l'autre côté.
            if (xi < 0) { // Si xi est en dehors du bord gauche
                xi = cellules.size() + xi; // On revient à l'autre côté de la grille
            }
            else if (xi >= cellules.size()) { // Si xi est en dehors du bord droit
                xi = xi - cellules.size(); // On revient à l'autre côté de la grille
            }

            int yj = y + j; // Coordonnée y de la cellule voisine
            // Gestion du cas "torique" pour l'axe y.
            if (yj < 0) { // Si yj est en dehors du bord supérieur
                yj = cellules[0].size() + yj; // On revient à l'autre côté de la grille
            }
            else if (yj >= cellules[0].size()) { // Si yj est en dehors du bord inférieur
                yj = yj - cellules[0].size(); // On revient à l'autre côté de la grille
            }

            // Si la cellule voisine est vivante et que ce n'est pas la cellule elle-même
            if ((cellules[xi][yj].obtenirEtat() == true) and !(i == 0 and j == 0)) {
                compteur += 1; // Incrémente le compteur de voisins vivants
            }
        }
    }

    return compteur; // Retourne le nombre total de voisins vivants
}

// Fonction qui calcule la prochaine génération de cellules.
bool grille::prochaineGeneration() {
    std::vector<std::vector<cellule>> nouvelleGrille = cellules; // Crée une copie de la grille actuelle pour modifier les états

    // Parcours de toutes les cellules de la grille
    for (int i = 0; i < cellules.size(); ++i) {
        for (int j = 0; j < cellules[0].size(); ++j) {
            int voisinsVivants = compterVoisinsVivants(i, j); // Récupère le nombre de voisins vivants

            // Si la cellule est vivante et que le nombre de voisins n'est pas 2 ou 3, elle meurt
            if (cellules[i][j].obtenirEtat() == true) {
                if (voisinsVivants != 2 && voisinsVivants != 3) {
                    nouvelleGrille[i][j].definirEtat(false); // Cellule meurt
                }
            }
            // Si la cellule est morte et qu'il y a exactement 3 voisins vivants, elle naît
            else if (cellules[i][j].obtenirEtat() == false) {
                if (voisinsVivants == 3) {
                    nouvelleGrille[i][j].definirEtat(true); // Cellule devient vivante
                }
            }
        }
    }

    bool check_evolution = false; // Variable pour vérifier si la grille a évolué
    // Parcours des cellules pour vérifier si un changement a eu lieu
    for (int y = 0; y < cellules[0].size(); ++y) {
        for (int x = 0; x < cellules.size(); ++x) {
            if (cellules[x][y].obtenirEtat() != nouvelleGrille[x][y].obtenirEtat()) {
                check_evolution = true; // Si un changement est détecté, la grille a évolué
            }
        }
    }

    // Applique les changements de la nouvelle grille à la grille principale
    cellules = nouvelleGrille;

    return check_evolution; // Retourne vrai si la grille a évolué, sinon faux
}
