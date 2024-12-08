#ifndef CELLULE_HPP
#define CELLULE_HPP

// D�finition de la classe 'cellule', repr�sentant une cellule du jeu de la vie
class cellule {
private:
    bool estVivante; // Attribut priv� repr�sentant l'�tat de la cellule (vivante ou morte)

public:
    // Constructeur de la classe 'cellule'. Le param�tre 'vivante' est par d�faut false (cellule morte).
    // Ce constructeur initialise l'�tat de la cellule.
    cellule(bool vivante = false);

    // M�thode pour d�finir l'�tat de la cellule. Elle prend un bool�en 'vivante' qui d�termine si la cellule
    // doit �tre vivante (true) ou morte (false).
    void definirEtat(bool vivante);

    // M�thode pour obtenir l'�tat actuel de la cellule.
    // Elle renvoie true si la cellule est vivante, sinon false.
    bool obtenirEtat() const;
};

#endif
