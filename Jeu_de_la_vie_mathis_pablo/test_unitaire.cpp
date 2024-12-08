#include "test_unitaire.hpp"

void testCellule() {
    cellule c1;
    cellule c2(true);

    std::cout << "Test cellule par défaut : ";
    if (!c1.obtenirEtat()) {
        std::cout << "OK\n";
    }
    else {
        std::cout << "Échec\n";
    }

    std::cout << "Test cellule initialisée vivante : ";
    if (c2.obtenirEtat()) {
        std::cout << "OK\n";
    }
    else {
        std::cout << "Échec\n";
    }

    std::cout << "Test changement d'état : ";
    c1.definirEtat(true);
    if (c1.obtenirEtat()) {
        std::cout << "OK\n";
    }
    else {
        std::cout << "Échec\n";
    }
}


void testGrille() {
    grille g;

    std::vector<std::vector<cellule>> testGrid = {
        {cellule(false), cellule(true), cellule(false)},
        {cellule(true), cellule(false), cellule(true)},
        {cellule(false), cellule(true), cellule(false)}
    };

    g.initialiser(testGrid);


    std::cout << "Test initialisation de la grille : ";
    bool check_initialisation(true);
    for (int y = 0; y < testGrid[0].size(); ++y) {
        for (int x = 0; x < testGrid.size(); ++x) {
            if (g.obtenirCellules()[x][y].obtenirEtat() != testGrid[x][y].obtenirEtat()) {
                check_initialisation = false;
            }

        }
    }

    if (check_initialisation) {
        std::cout << "OK\n";
    }
    else {
        std::cout << "Échec\n";
    }


    std::cout << "Test calcul voisins vivants : ";
    int voisins = g.compterVoisinsVivants(1, 1); // Centre
    if (voisins == 4) {
        std::cout << "OK\n";
    }
    else {
        std::cout << "Échec\n";
    }

}

void testFichier() {
    fichier f;
    f.charger("test");

    std::cout << "Test chargement fichier : ";
    auto grid = f.obtenirGrille();
    if (!grid.empty() && grid[0].size() > 0) {
        std::cout << "OK\n";
    }
    else {
        std::cout << "Échec\n";
    }

    std::cout << "Test écriture fichier : ";
    grille gril;
    gril.initialiser(grid);
    f.ecrire(1, gril);
    
}


void testGraphique() {
    graphique graph;

    std::cout << "Test initialisation graphique : ";
    std::vector<std::vector<cellule>> testGrid2 = {
        {cellule(false), cellule(true), cellule(false)},
        {cellule(true), cellule(false), cellule(true)},
        {cellule(false), cellule(true), cellule(false)}
    };
    graph.initialiser(testGrid2, 500);

    bool check_graphique(true);
    for (int y = 0; y < testGrid2[0].size(); ++y) {
        for (int x = 0; x < testGrid2.size(); ++x) {
            if (graph.obtenirGrid()[x][y].obtenirEtat() != testGrid2[x][y].obtenirEtat()) {
                check_graphique = false;
            }

        }
    }

    if (check_graphique) {
        std::cout << "OK\n";
    }
    else {
        std::cout << "Échec\n";
    }
}


void lancerTests() {
    std::cout << "Test Unitaires :\n------------------------------------------\n";
    testCellule();
    testGrille();
    testFichier();
    testGraphique();
    std::cout << "\n------------------------------------------\nFin des test Unitaires\n";
}

