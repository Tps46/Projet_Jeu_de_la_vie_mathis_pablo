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
    // Efface le contenu pr�c�dent de la fen�tre afin de pr�parer l'affichage de la nouvelle g�n�ration
    window.clear();

    // Cr�e un objet 'RectangleShape' repr�sentant une cellule. La taille de la cellule est ajust�e par 'cellSize' (taille de la cellule)
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));

    // Parcourt chaque ligne de la grille (y correspond aux lignes)
    for (int y = 0; y < grid[0].size(); ++y) {
        // Parcourt chaque colonne de la grille (x correspond aux colonnes)
        for (int x = 0; x < grid.size(); ++x) {

            // Calcule la position de chaque cellule sur la fen�tre en fonction de sa position dans la grille
            // La cellule (x, y) sera plac�e dans la fen�tre en fonction de la taille de la cellule et de sa position dans la grille
            cell.setPosition(y * cellSize, x * cellSize);

            // V�rifie si la cellule (x, y) contient un "obstacle"
            if (grid[x][y].obtenirObstacle()) {
                // Si la cellule est un obstacle, v�rifie si elle est vivante ou morte
                if (grid[x][y].obtenirEtat()) {
                    // Si la cellule est vivante, la couleur est d�finie sur vert
                    cell.setFillColor(sf::Color::Green);
                }
                else {
                    // Si la cellule est morte, la couleur est d�finie sur rouge
                    cell.setFillColor(sf::Color::Red);
                }
            }
            else {
                // Si la cellule n'est pas un obstacle, elle est affich�e en fonction de son �tat (vivant ou mort)
                if (grid[x][y].obtenirEtat()) {
                    // Si la cellule est vivante, elle est color�e en blanc
                    cell.setFillColor(sf::Color::White);
                }
                else {
                    // Si la cellule est morte, elle est color�e en noir
                    cell.setFillColor(sf::Color::Black);
                }
            }

            // Dessine la cellule sur la fen�tre
            window.draw(cell);
        }
    }

    // Affiche tous les objets dessin�s sur la fen�tre (y compris toutes les cellules)
    window.display();

    // Met en pause l'ex�cution pour permettre � l'utilisateur de voir l'�tat actuel de la grille avant la prochaine mise � jour
    sf::sleep(sf::milliseconds(duree_iteration));
}



// M�thode pour obtenir une r�f�rence vers la grille actuelle
std::vector<std::vector<cellule>>& graphique::obtenirGrid() {
    return grid; // Retourner la grille
}
