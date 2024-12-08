#include "graphique.hpp"
#include "grille.hpp"



graphique::graphique() : cellSize(20), gridWidth(20), gridHeight(20){
    

}

void graphique::initialiser(std::vector<std::vector<cellule>> entreeGrid) {
    grid = entreeGrid;
    sf::RenderWindow window(sf::VideoMode(grid.size() * cellSize, grid[0].size() * cellSize), "Game of Life");

    // La boucle d'�v�nements pour la fen�tre
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
                
                window.close();
        }

        // Afficher la grille (appel�e apr�s chaque g�n�ration)
        renderGrid(window, grid);

        // Optionnel : Ajouter un petit d�lai entre chaque g�n�ration
        sf::sleep(sf::milliseconds(500));  // Attendre 500 ms
                
        window.close();
    }
}




void graphique::renderGrid(sf::RenderWindow& window, std::vector<std::vector<cellule>> grid) {
    
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
}


std::vector<std::vector<cellule>>& graphique::obtenirGrid()
{
    return grid;
}