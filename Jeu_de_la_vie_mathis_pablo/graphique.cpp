#include "graphique.hpp"
#include "grille.hpp"

graphique::graphique() : cellSize(20), gridWidth(20), gridHeight(20), window(sf::VideoMode(800, 600), "Game of Life") {
    // Initialisation de la fen�tre avec une taille par d�faut
}

void graphique::initialiser(std::vector<std::vector<cellule>> entreeGrid) {
    grid = entreeGrid;

    // Redimensionner la fen�tre en fonction de la taille de la grille
    window.create(sf::VideoMode(grid.size() * cellSize, grid[0].size() * cellSize), "Game of Life");

    // La boucle d'�v�nements pour la fen�tre
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Afficher la grille (appel�e apr�s chaque g�n�ration)
        renderGrid(grid);

        // Optionnel : Ajouter un petit d�lai entre chaque g�n�ration
        sf::sleep(sf::milliseconds(500));  // Attendre 500 ms
        break;
    }
}

void graphique::renderGrid(std::vector<std::vector<cellule>> grid) {
    int x, y;
    int cellSize = 20;

    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (x = 0; x < grid.size(); ++x) {
        for (y = 0; y < grid[0].size(); ++y) {
            if (grid[x][y].obtenirEtat() == 1) {
                cell.setPosition(x * cellSize, y * cellSize);
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
