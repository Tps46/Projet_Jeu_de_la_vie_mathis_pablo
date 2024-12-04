#ifndef CELLULE_HPP
#define CELLULE_HPP

class cellule {
private:
    bool estVivante;

public:
    cellule(bool vivante = false);
    void definirEtat(bool vivante);
    bool obtenirEtat() const;
};

#endif // CELLULE_HPP
