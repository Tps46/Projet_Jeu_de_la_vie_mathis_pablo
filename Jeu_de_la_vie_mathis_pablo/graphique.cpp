#include "graphique.hpp"
#include "grille.hpp"

graphique::graphique() : cellSize(20), gridWidth(20), gridHeight(20), window(sf::VideoMode(800, 600), "Game of Life") {
    // Initialisation de la fenêtre avec une taille par défaut
}

void graphique::initialiser(std::vector<std::vector<cellule>> entreeGrid) {
    grid = entreeGrid;

    // Redimensionner la fenêtre en fonction de la taille de la grille
    window.create(sf::VideoMode(grid[0].size() * cellSize, grid.size() * cellSize), "Game of Life");

    // La boucle d'événements pour la fenêtre
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Afficher la grille (appelée après chaque génération)
        renderGrid(grid);

        // Optionnel : Ajouter un petit délai entre chaque génération
        sf::sleep(sf::milliseconds(500));  // Attendre 500 ms
        break;
    }
}

void graphique::renderGrid(std::vector<std::vector<cellule>> grid) {
    int x, y;
    int cellSize = 20;

    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (y = 0; y < grid[0].size(); ++y) {
        for (x = 0; x < grid.size(); ++x) {
            if (grid[x][y].obtenirEtat() == 1) {
                cell.setPosition(y * cellSize, x * cellSize);
                window.draw(cell);
            }
        }
    }
    window.display();
    sf::sleep(sf::milliseconds(500));
}

std::vector<std::vector<cellule>>& graphique::obtenirGrid() {
    return grid;
}
