#ifndef LANCEMENT_HPP
#define LANCEMENT_HPP

// Inclusion des bibliothèques nécessaires
#include <iostream>  // Pour les entrées et sorties standard
#include <cstdlib>   // Pour les fonctions de gestion de l'environnement
#include <SFML/Graphics.hpp> // Pour l'affichae graphique
#include "fichier.hpp"
#include "grille.hpp"
#include "graphique.hpp"
#include "test_unitaire.hpp"

// Déclaration de la classe "lancement"
class lancement {
public:
    // Constructeur de la classe, initialise les paramètres de lancement
    lancement();

    // Méthode principale qui lance le jeu en fonction de l'option choisie (console, graphique, etc.)
    void leLancement();

private:
    // Attribut pour spécifier le nombre d'itérations à effectuer 
    int nombre_iteration;

    // Méthodes privées pour différents types de lancement
    // Lancement avec une interface graphique (avec durée d'itération)
    void lancementGraphique(int duree_iteration);

    // Lancement avec affichage dans la console 
    void lancementConsole();

    // Lancement pour effectuer un test unitaire de certaines fonctionnalités
    void lancementTest_unitaire();

    // Affichage d'un menu pour choisir l'option de lancement (graphique, console, test, etc.)
    void menu();

};

#endif
