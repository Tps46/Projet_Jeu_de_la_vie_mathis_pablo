#ifndef CELLULE_HPP
#define CELLULE_HPP

// D�finition de la classe 'cellule', repr�sentant une cellule du jeu de la vie
class cellule {
private:
    bool estVivante; // Attribut priv� repr�sentant l'�tat de la cellule (vivante ou morte)
    bool estObstacle; // Indique si la cellule est un obstacle

public:
    // Constructeur de la classe 'cellule'. Le param�tre 'vivante' est par d�faut false (cellule morte) et 'obstacle' est par d�faut, non obstacle.
    // Ce constructeur initialise l'�tat de la cellule.
    cellule(bool vivante = false, bool obstacle = false);

    // M�thode pour d�finir l'�tat de la cellule. Elle prend un bool�en 'vivante' qui d�termine si la cellule
    // doit �tre vivante (true) ou morte (false).
    void definirEtat(bool vivante);

    // M�thode pour obtenir l'�tat actuel de la cellule.
    // Elle renvoie true si la cellule est vivante, sinon false.
    bool obtenirEtat() const;

    // V�rifier si une cellule est un obstacle
    bool obtenirObstacle() const;

    // D�finir si une cellule est un obstacle
    void definirObstacle(bool obstacle);
};

#endif
