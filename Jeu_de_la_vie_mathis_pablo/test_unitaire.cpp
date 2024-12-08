#include "test_unitaire.hpp"

// Teste la classe cellule
void testCellule() {
    cellule c1;  // Crée une cellule morte par défaut (état initial = false)
    cellule c2(true);  // Crée une cellule vivante (état initial = true)

    std::cout << "Test cellule par défaut : ";
    // Vérifie si la cellule c1 est morte par défaut
    if (!c1.obtenirEtat()) {
        std::cout << "OK\n";
    }
    else {
        std::cout << "Échec\n";
    }

    std::cout << "Test cellule initialisée vivante : ";
    // Vérifie si la cellule c2 est vivante
    if (c2.obtenirEtat()) {
        std::cout << "OK\n";
    }
    else {
        std::cout << "Échec\n";
    }

    std::cout << "Test changement d'état : ";
    c1.definirEtat(true);  // Change l'état de la cellule c1 pour la rendre vivante
    // Vérifie si l'état de c1 a bien été mis à true
    if (c1.obtenirEtat()) {
        std::cout << "OK\n";
    }
    else {
        std::cout << "Échec\n";
    }
}


// Teste la classe grille
void testGrille() {
    grille g;

    // Initialisation d'une grille de test 3x3 avec des cellules vivantes et mortes
    std::vector<std::vector<cellule>> testGrid = {
        {cellule(false), cellule(true), cellule(false)},
        {cellule(true), cellule(false), cellule(true)},
        {cellule(false), cellule(true), cellule(false)}
    };

    g.initialiser(testGrid);  // Initialise la grille avec les données testGrid

    std::cout << "Test initialisation de la grille : ";
    bool check_initialisation(true);
    // Vérifie si chaque cellule dans la grille g est correctement initialisée
    for (int y = 0; y < testGrid[0].size(); ++y) {
        for (int x = 0; x < testGrid.size(); ++x) {
            if (g.obtenirCellules()[x][y].obtenirEtat() != testGrid[x][y].obtenirEtat()) {
                check_initialisation = false;  // Si l'état de la cellule ne correspond pas, échec du test
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
    // Compte les voisins vivants de la cellule située au centre de la grille (1, 1)
    int voisins = g.compterVoisinsVivants(1, 1);  // Attendu : 4 voisins vivants
    if (voisins == 4) {
        std::cout << "OK\n";
    }
    else {
        std::cout << "Échec\n";
    }
}

// Teste la classe fichier
void testFichier() {
    fichier f;
    f.charger("test");  // Charge le fichier "test.txt"

    std::cout << "Test chargement fichier : ";
    auto grid = f.obtenirGrille();  // Obtenez la grille du fichier
    // Vérifie si la grille chargée n'est pas vide
    if (!grid.empty() && grid[0].size() > 0) {
        std::cout << "OK\n";
    }
    else {
        std::cout << "Échec\n";
    }

    std::cout << "Test écriture fichier : ";
    grille gril;
    gril.initialiser(grid);  // Initialise la grille avec les données chargées
    f.ecrire(1, gril);  // Écrit la grille après la première génération dans un fichier
}

// Teste la classe graphique
void testGraphique() {
    graphique graph;

    std::cout << "Test initialisation graphique : ";
    // Crée une grille de test 3x3 pour l'affichage graphique
    std::vector<std::vector<cellule>> testGrid2 = {
        {cellule(false), cellule(true), cellule(false)},
        {cellule(true), cellule(false), cellule(true)},
        {cellule(false), cellule(true), cellule(false)}
    };
    graph.initialiser(testGrid2, 500);  // Initialise le graphique avec la grille et une durée d'itération de 500 ms

    bool check_graphique(true);
    // Vérifie si les cellules dans la grille graphique correspondent à celles de testGrid2
    for (int y = 0; y < testGrid2[0].size(); ++y) {
        for (int x = 0; x < testGrid2.size(); ++x) {
            if (graph.obtenirGrid()[x][y].obtenirEtat() != testGrid2[x][y].obtenirEtat()) {
                check_graphique = false;  // Si l'état de la cellule ne correspond pas, échec du test
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

// Lance tous les tests unitaires
void lancerTests() {
    std::cout << "Test Unitaires :\n------------------------------------------\n";
    testCellule();  // Lance les tests de la classe cellule
    testGrille();   // Lance les tests de la classe grille
    testFichier();  // Lance les tests de la classe fichier
    testGraphique(); // Lance les tests de la classe graphique
    std::cout << "\n------------------------------------------\nFin des test Unitaires\n";
}
