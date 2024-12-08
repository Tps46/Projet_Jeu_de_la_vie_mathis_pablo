#include "cellule.hpp"

// Constructeur de la classe 'cellule' qui initialise l'�tat de la cellule.
// Le param�tre 'vivante' d�termine si la cellule doit �tre initialis�e comme vivante (true) ou morte (false).
// Si aucun argument n'est pass�, la cellule sera par d�faut morte (false).
cellule::cellule(bool vivante) : estVivante(vivante) {}

// M�thode pour d�finir l'�tat de la cellule.
// Elle prend un param�tre 'vivante' (bool�en) qui d�finit si la cellule doit �tre vivante ou morte.
// Cette m�thode modifie l'attribut 'estVivante' de l'objet.
void cellule::definirEtat(bool vivante) {
    estVivante = vivante;  // Attribue la valeur de 'vivante' � l'attribut 'estVivante'.
}

// M�thode pour obtenir l'�tat actuel de la cellule.
// Elle renvoie 'true' si la cellule est vivante, et 'false' si elle est morte.
// Cette m�thode est constante (ne modifie pas l'�tat de l'objet).
bool cellule::obtenirEtat() const {
    return estVivante;  // Retourne l'�tat actuel de la cellule (vivante ou morte).
}
