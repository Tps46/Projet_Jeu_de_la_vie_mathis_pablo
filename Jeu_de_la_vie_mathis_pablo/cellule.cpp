#include "cellule.hpp"

// Constructeur de la classe 'cellule' qui initialise l'état de la cellule.
// Le paramètre 'vivante' détermine si la cellule doit être initialisée comme vivante (true) ou morte (false).
// Si aucun argument n'est passé, la cellule sera par défaut morte (false).
cellule::cellule(bool vivante, bool obstacle) : estVivante(vivante), estObstacle(obstacle) {}

// Méthode pour définir l'état de la cellule.
// Elle prend un paramètre 'vivante' (booléen) qui définit si la cellule doit être vivante ou morte.
// Cette méthode modifie l'attribut 'estVivante' de l'objet.
void cellule::definirEtat(bool vivante) {
    if (!estObstacle) {
        estVivante = vivante;// Attribue la valeur de 'vivante' à l'attribut 'estVivante', seulemet si elle n'est pas obstacle
    }

}

// Méthode pour obtenir l'état actuel de la cellule.
// Elle renvoie 'true' si la cellule est vivante, et 'false' si elle est morte.
// Cette méthode est constante (ne modifie pas l'état de l'objet).
bool cellule::obtenirEtat() const {
    return estVivante;  // Retourne l'état actuel de la cellule (vivante ou morte).
}

// Vérifier si la cellule est un obstacle
bool cellule::obtenirObstacle() const {
    return estObstacle;
}

// Définir la cellule comme obstacle
void cellule::definirObstacle(bool obstacle) {
    estObstacle = obstacle;
}