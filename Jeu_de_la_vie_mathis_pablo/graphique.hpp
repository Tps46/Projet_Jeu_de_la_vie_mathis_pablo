#ifndef GRAPHIQUE_HPP
#define GRAPHIQUE_HPP

// Inclusion des bibliothèques nécessaires pour la gestion graphique
#include <SFML/Graphics.hpp> // Pour l'affichage graphique
#include <vector>              // Pour utiliser les vecteurs (tables dynamiques)
#include <iostream>            // Pour les flux de sortie standard
#include <ctime>               // Pour la gestion du temps (initialisation des générateurs aléatoires)
#include <cstdlib>             // Pour l'usage de fonctions comme rand()
#include "cellule.hpp"         // Inclut la classe 'cellule', représentant l'état de chaque cellule dans la grille

class graphique {
private:
    const int cellSize;            // Taille d'une cellule en pixels
    const int gridWidth;           // Largeur de la grille en termes de cellules
    const int gridHeight;          // Hauteur de la grille en termes de cellules
    std::vector<std::vector<cellule>> grid; // Grille de cellules représentant l'état du jeu
    sf::RenderWindow window;       // Fenêtre d'affichage pour SFML
    int duree_iteration;           // Durée d'attente entre les itérations (en millisecondes)

public:
    // Méthode pour afficher la grille
    void renderGrid(std::vector<std::vector<cellule>> grid);

    // Constructeur de la classe, initialise la taille de la cellule et les dimensions de la grille
    graphique();

    // Méthode d'initialisation de l'objet graphique avec la grille et la durée d'itération
    void initialiser(std::vector<std::vector<cellule>> grid, int entree_duree_iteration);

    // Méthode pour obtenir une référence vers la grille de cellules
    std::vector<std::vector<cellule>>& obtenirGrid();
};

#endif
