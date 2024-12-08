#ifndef GRAPHIQUE_HPP
#define GRAPHIQUE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib> 
#include "cellule.hpp"


class graphique {
private:
    const int cellSize;
    const int gridWidth;
    const int gridHeight;
    std::vector<std::vector<cellule>> grid;
    

public:
    
    void renderGrid(sf::RenderWindow& window, std::vector<std::vector<cellule>> grid);
    graphique();
    void initialiser(std::vector<std::vector<cellule>> grid);

    std::vector<std::vector<cellule>>& obtenirGrid();
};



#endif