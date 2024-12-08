#ifndef LANCEMENT_HPP
#define LANCEMENT_HPP

// Inclusion des biblioth�ques n�cessaires
#include <iostream>  // Pour les entr�es et sorties standard
#include <cstdlib>   // Pour les fonctions de gestion de l'environnement
#include <SFML/Graphics.hpp> // Pour l'affichae graphique
#include "fichier.hpp"
#include "grille.hpp"
#include "graphique.hpp"
#include "test_unitaire.hpp"

// D�claration de la classe "lancement"
class lancement {
public:
    // Constructeur de la classe, initialise les param�tres de lancement
    lancement();

    // M�thode principale qui lance le jeu en fonction de l'option choisie (console, graphique, etc.)
    void leLancement();

private:
    // Attribut pour sp�cifier le nombre d'it�rations � effectuer 
    int nombre_iteration;

    // M�thodes priv�es pour diff�rents types de lancement
    // Lancement avec une interface graphique (avec dur�e d'it�ration)
    void lancementGraphique(int duree_iteration);

    // Lancement avec affichage dans la console 
    void lancementConsole();

    // Lancement pour effectuer un test unitaire de certaines fonctionnalit�s
    void lancementTest_unitaire();

    // Affichage d'un menu pour choisir l'option de lancement (graphique, console, test, etc.)
    void menu();

};

#endif
