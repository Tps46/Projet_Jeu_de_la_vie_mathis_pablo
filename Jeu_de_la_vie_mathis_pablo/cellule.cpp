#include "cellule.hpp"

cellule::cellule(bool vivante) : estVivante(vivante) {}

void cellule::definirEtat(bool vivante) {
    estVivante = vivante;
}

bool cellule::obtenirEtat() const {
    return estVivante;
}
