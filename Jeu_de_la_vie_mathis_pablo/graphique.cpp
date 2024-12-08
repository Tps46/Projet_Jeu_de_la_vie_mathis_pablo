#include "graphique.hpp"
#include "grille.hpp"

// Constructeur de la classe graphique
graphique::graphique()
    : cellSize(20),  // Taille de chaque cellule en pixels
    gridWidth(20),  // Largeur de la grille en cellules
    gridHeight(20), // Hauteur de la grille en cellules
    duree_iteration(200), // Dur�e d'attente entre chaque it�ration (en millisecondes)
    window(sf::VideoMode(800, 600), "Game of Life") { // Initialisation de la fen�tre SFML avec une taille de 800x600
    // La fen�tre est initialis�e ici avec une taille par d�faut
}

// M�thode pour initialiser la grille et ajuster la fen�tre selon les dimensions de la grille
void graphique::initialiser(std::vector<std::vector<cellule>> entreeGrid, int entree_duree_iteration) {
    grid = entreeGrid; // Assigner la grille d'entr�e � la variable membre 'grid'
    duree_iteration = entree_duree_iteration; // Assigner la dur�e d'it�ration

    // Redimensionner la fen�tre pour s'adapter � la taille de la grille
    window.create(sf::VideoMode(grid[0].size() * cellSize, grid.size() * cellSize), "Game of Life");

    // La boucle d'�v�nements qui g�re les interactions avec la fen�tre
    while (window.isOpen()) {
        sf::Event event; // Objet pour stocker les �v�nements
        while (window.pollEvent(event)) { // R�cup�rer tous les �v�nements
            if (event.type == sf::Event::Closed) { // Si la fen�tre est ferm�e
                window.close(); // Fermer la fen�tre
            }
        }

        // Afficher la grille apr�s chaque g�n�ration
        renderGrid(grid);

        break; // Terminer la boucle apr�s un seul rendu
    }
}

// M�thode pour afficher la grille sur la fen�tre
void graphique::renderGrid(std::vector<std::vector<cellule>> grid) {
    int x, y; // Variables pour parcourir la grille
    int cellSize = 20; // Taille de chaque cellule

    window.clear(); // Effacer le contenu pr�c�dent de la fen�tre
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f)); // Cr�ation d'un rectangle pour chaque cellule

    // Parcourir chaque cellule de la grille
    for (y = 0; y < grid[0].size(); ++y) {  // Parcours des colonnes (hauteur de la grille)
        for (x = 0; x < grid.size(); ++x) { // Parcours des lignes (largeur de la grille)
            if (grid[x][y].obtenirEtat() == 1) { // Si la cellule est vivante
                cell.setPosition(y * cellSize, x * cellSize); // D�finir la position du rectangle (cellule)
                window.draw(cell); // Dessiner la cellule sur la fen�tre
            }
        }
    }

    window.display(); // Afficher tous les objets dessin�s sur la fen�tre
    sf::sleep(sf::milliseconds(duree_iteration)); // Attendre pendant la dur�e sp�cifi�e (en millisecondes)
}

// M�thode pour obtenir une r�f�rence vers la grille actuelle
std::vector<std::vector<cellule>>& graphique::obtenirGrid() {
    return grid; // Retourner la grille
}
