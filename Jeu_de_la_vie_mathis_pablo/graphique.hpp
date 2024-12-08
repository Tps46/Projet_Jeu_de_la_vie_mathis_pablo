#ifndef GRAPHIQUE_HPP
#define GRAPHIQUE_HPP

// Inclusion des biblioth�ques n�cessaires pour la gestion graphique
#include <SFML/Graphics.hpp> // Pour l'affichage graphique
#include <vector>              // Pour utiliser les vecteurs (tables dynamiques)
#include <iostream>            // Pour les flux de sortie standard
#include <ctime>               // Pour la gestion du temps (initialisation des g�n�rateurs al�atoires)
#include <cstdlib>             // Pour l'usage de fonctions comme rand()
#include "cellule.hpp"         // Inclut la classe 'cellule', repr�sentant l'�tat de chaque cellule dans la grille

class graphique {
private:
    const int cellSize;            // Taille d'une cellule en pixels
    const int gridWidth;           // Largeur de la grille en termes de cellules
    const int gridHeight;          // Hauteur de la grille en termes de cellules
    std::vector<std::vector<cellule>> grid; // Grille de cellules repr�sentant l'�tat du jeu
    sf::RenderWindow window;       // Fen�tre d'affichage pour SFML
    int duree_iteration;           // Dur�e d'attente entre les it�rations (en millisecondes)

public:
    // M�thode pour afficher la grille
    void renderGrid(std::vector<std::vector<cellule>> grid);

    // Constructeur de la classe, initialise la taille de la cellule et les dimensions de la grille
    graphique();

    // M�thode d'initialisation de l'objet graphique avec la grille et la dur�e d'it�ration
    void initialiser(std::vector<std::vector<cellule>> grid, int entree_duree_iteration);

    // M�thode pour obtenir une r�f�rence vers la grille de cellules
    std::vector<std::vector<cellule>>& obtenirGrid();
};

#endif
