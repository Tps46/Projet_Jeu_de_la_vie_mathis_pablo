#include "graphique.hpp"
#include "grille.hpp"

// Constructeur de la classe graphique
graphique::graphique()
    : cellSize(20),  // Taille de chaque cellule en pixels
    gridWidth(20),  // Largeur de la grille en cellules
    gridHeight(20), // Hauteur de la grille en cellules
    duree_iteration(200), // Durée d'attente entre chaque itération (en millisecondes)
    window(sf::VideoMode(800, 600), "Game of Life") { // Initialisation de la fenêtre SFML avec une taille de 800x600
    // La fenêtre est initialisée ici avec une taille par défaut
}

// Méthode pour initialiser la grille et ajuster la fenêtre selon les dimensions de la grille
void graphique::initialiser(std::vector<std::vector<cellule>> entreeGrid, int entree_duree_iteration) {
    grid = entreeGrid; // Assigner la grille d'entrée à la variable membre 'grid'
    duree_iteration = entree_duree_iteration; // Assigner la durée d'itération

    // Redimensionner la fenêtre pour s'adapter à la taille de la grille
    window.create(sf::VideoMode(grid[0].size() * cellSize, grid.size() * cellSize), "Game of Life");

    // La boucle d'événements qui gère les interactions avec la fenêtre
    while (window.isOpen()) {
        sf::Event event; // Objet pour stocker les événements
        while (window.pollEvent(event)) { // Récupérer tous les événements
            if (event.type == sf::Event::Closed) { // Si la fenêtre est fermée
                window.close(); // Fermer la fenêtre
            }
        }

        // Afficher la grille après chaque génération
        renderGrid(grid);

        break; // Terminer la boucle après un seul rendu
    }
}

// Méthode pour afficher la grille sur la fenêtre
void graphique::renderGrid(std::vector<std::vector<cellule>> grid) {
    int x, y; // Variables pour parcourir la grille
    int cellSize = 20; // Taille de chaque cellule

    window.clear(); // Effacer le contenu précédent de la fenêtre
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f)); // Création d'un rectangle pour chaque cellule

    // Parcourir chaque cellule de la grille
    for (y = 0; y < grid[0].size(); ++y) {  // Parcours des colonnes (hauteur de la grille)
        for (x = 0; x < grid.size(); ++x) { // Parcours des lignes (largeur de la grille)
            if (grid[x][y].obtenirEtat() == 1) { // Si la cellule est vivante
                cell.setPosition(y * cellSize, x * cellSize); // Définir la position du rectangle (cellule)
                window.draw(cell); // Dessiner la cellule sur la fenêtre
            }
        }
    }

    window.display(); // Afficher tous les objets dessinés sur la fenêtre
    sf::sleep(sf::milliseconds(duree_iteration)); // Attendre pendant la durée spécifiée (en millisecondes)
}

// Méthode pour obtenir une référence vers la grille actuelle
std::vector<std::vector<cellule>>& graphique::obtenirGrid() {
    return grid; // Retourner la grille
}
