#ifndef CELLULE_HPP
#define CELLULE_HPP

// Définition de la classe 'cellule', représentant une cellule du jeu de la vie
class cellule {
private:
    bool estVivante; // Attribut privé représentant l'état de la cellule (vivante ou morte)

public:
    // Constructeur de la classe 'cellule'. Le paramètre 'vivante' est par défaut false (cellule morte).
    // Ce constructeur initialise l'état de la cellule.
    cellule(bool vivante = false);

    // Méthode pour définir l'état de la cellule. Elle prend un booléen 'vivante' qui détermine si la cellule
    // doit être vivante (true) ou morte (false).
    void definirEtat(bool vivante);

    // Méthode pour obtenir l'état actuel de la cellule.
    // Elle renvoie true si la cellule est vivante, sinon false.
    bool obtenirEtat() const;
};

#endif
