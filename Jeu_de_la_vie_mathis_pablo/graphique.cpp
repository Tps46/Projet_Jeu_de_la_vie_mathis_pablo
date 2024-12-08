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
    // Efface le contenu précédent de la fenêtre afin de préparer l'affichage de la nouvelle génération
    window.clear();

    // Crée un objet 'RectangleShape' représentant une cellule. La taille de la cellule est ajustée par 'cellSize' (taille de la cellule)
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));

    // Parcourt chaque ligne de la grille (y correspond aux lignes)
    for (int y = 0; y < grid[0].size(); ++y) {
        // Parcourt chaque colonne de la grille (x correspond aux colonnes)
        for (int x = 0; x < grid.size(); ++x) {

            // Calcule la position de chaque cellule sur la fenêtre en fonction de sa position dans la grille
            // La cellule (x, y) sera placée dans la fenêtre en fonction de la taille de la cellule et de sa position dans la grille
            cell.setPosition(y * cellSize, x * cellSize);

            // Vérifie si la cellule (x, y) contient un "obstacle"
            if (grid[x][y].obtenirObstacle()) {
                // Si la cellule est un obstacle, vérifie si elle est vivante ou morte
                if (grid[x][y].obtenirEtat()) {
                    // Si la cellule est vivante, la couleur est définie sur vert
                    cell.setFillColor(sf::Color::Green);
                }
                else {
                    // Si la cellule est morte, la couleur est définie sur rouge
                    cell.setFillColor(sf::Color::Red);
                }
            }
            else {
                // Si la cellule n'est pas un obstacle, elle est affichée en fonction de son état (vivant ou mort)
                if (grid[x][y].obtenirEtat()) {
                    // Si la cellule est vivante, elle est colorée en blanc
                    cell.setFillColor(sf::Color::White);
                }
                else {
                    // Si la cellule est morte, elle est colorée en noir
                    cell.setFillColor(sf::Color::Black);
                }
            }

            // Dessine la cellule sur la fenêtre
            window.draw(cell);
        }
    }

    // Affiche tous les objets dessinés sur la fenêtre (y compris toutes les cellules)
    window.display();

    // Met en pause l'exécution pour permettre à l'utilisateur de voir l'état actuel de la grille avant la prochaine mise à jour
    sf::sleep(sf::milliseconds(duree_iteration));
}



// Méthode pour obtenir une référence vers la grille actuelle
std::vector<std::vector<cellule>>& graphique::obtenirGrid() {
    return grid; // Retourner la grille
}
