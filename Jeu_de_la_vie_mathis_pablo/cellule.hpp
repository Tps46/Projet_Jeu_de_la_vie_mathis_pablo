#ifndef CELLULE_HPP
#define CELLULE_HPP

// Définition de la classe 'cellule', représentant une cellule du jeu de la vie
class cellule {
private:
    bool estVivante; // Attribut privé représentant l'état de la cellule (vivante ou morte)
    bool estObstacle; // Indique si la cellule est un obstacle

public:
    // Constructeur de la classe 'cellule'. Le paramètre 'vivante' est par défaut false (cellule morte) et 'obstacle' est par défaut, non obstacle.
    // Ce constructeur initialise l'état de la cellule.
    cellule(bool vivante = false, bool obstacle = false);

    // Méthode pour définir l'état de la cellule. Elle prend un booléen 'vivante' qui détermine si la cellule
    // doit être vivante (true) ou morte (false).
    void definirEtat(bool vivante);

    // Méthode pour obtenir l'état actuel de la cellule.
    // Elle renvoie true si la cellule est vivante, sinon false.
    bool obtenirEtat() const;

    // Vérifier si une cellule est un obstacle
    bool obtenirObstacle() const;

    // Définir si une cellule est un obstacle
    void definirObstacle(bool obstacle);
};

#endif
