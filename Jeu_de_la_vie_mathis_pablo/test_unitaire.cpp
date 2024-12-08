#include "test_unitaire.hpp"

// Teste la classe cellule
void testCellule() {
    cellule c1;  // Cr�e une cellule morte par d�faut (�tat initial = false)
    cellule c2(true);  // Cr�e une cellule vivante (�tat initial = true)

    std::cout << "Test cellule par d�faut : ";
    // V�rifie si la cellule c1 est morte par d�faut
    if (!c1.obtenirEtat()) {
        std::cout << "OK\n";
    }
    else {
        std::cout << "�chec\n";
    }

    std::cout << "Test cellule initialis�e vivante : ";
    // V�rifie si la cellule c2 est vivante
    if (c2.obtenirEtat()) {
        std::cout << "OK\n";
    }
    else {
        std::cout << "�chec\n";
    }

    std::cout << "Test changement d'�tat : ";
    c1.definirEtat(true);  // Change l'�tat de la cellule c1 pour la rendre vivante
    // V�rifie si l'�tat de c1 a bien �t� mis � true
    if (c1.obtenirEtat()) {
        std::cout << "OK\n";
    }
    else {
        std::cout << "�chec\n";
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

    g.initialiser(testGrid);  // Initialise la grille avec les donn�es testGrid

    std::cout << "Test initialisation de la grille : ";
    bool check_initialisation(true);
    // V�rifie si chaque cellule dans la grille g est correctement initialis�e
    for (int y = 0; y < testGrid[0].size(); ++y) {
        for (int x = 0; x < testGrid.size(); ++x) {
            if (g.obtenirCellules()[x][y].obtenirEtat() != testGrid[x][y].obtenirEtat()) {
                check_initialisation = false;  // Si l'�tat de la cellule ne correspond pas, �chec du test
            }
        }
    }

    if (check_initialisation) {
        std::cout << "OK\n";
    }
    else {
        std::cout << "�chec\n";
    }

    std::cout << "Test calcul voisins vivants : ";
    // Compte les voisins vivants de la cellule situ�e au centre de la grille (1, 1)
    int voisins = g.compterVoisinsVivants(1, 1);  // Attendu : 4 voisins vivants
    if (voisins == 4) {
        std::cout << "OK\n";
    }
    else {
        std::cout << "�chec\n";
    }
}

// Teste la classe fichier
void testFichier() {
    fichier f;
    f.charger("test");  // Charge le fichier "test.txt"

    std::cout << "Test chargement fichier : ";
    auto grid = f.obtenirGrille();  // Obtenez la grille du fichier
    // V�rifie si la grille charg�e n'est pas vide
    if (!grid.empty() && grid[0].size() > 0) {
        std::cout << "OK\n";
    }
    else {
        std::cout << "�chec\n";
    }

    std::cout << "Test �criture fichier : ";
    grille gril;
    gril.initialiser(grid);  // Initialise la grille avec les donn�es charg�es
    f.ecrire(1, gril);  // �crit la grille apr�s la premi�re g�n�ration dans un fichier
}

// Teste la classe graphique
void testGraphique() {
    graphique graph;

    std::cout << "Test initialisation graphique : ";
    // Cr�e une grille de test 3x3 pour l'affichage graphique
    std::vector<std::vector<cellule>> testGrid2 = {
        {cellule(false), cellule(true), cellule(false)},
        {cellule(true), cellule(false), cellule(true)},
        {cellule(false), cellule(true), cellule(false)}
    };
    graph.initialiser(testGrid2, 500);  // Initialise le graphique avec la grille et une dur�e d'it�ration de 500 ms

    bool check_graphique(true);
    // V�rifie si les cellules dans la grille graphique correspondent � celles de testGrid2
    for (int y = 0; y < testGrid2[0].size(); ++y) {
        for (int x = 0; x < testGrid2.size(); ++x) {
            if (graph.obtenirGrid()[x][y].obtenirEtat() != testGrid2[x][y].obtenirEtat()) {
                check_graphique = false;  // Si l'�tat de la cellule ne correspond pas, �chec du test
            }
        }
    }

    if (check_graphique) {
        std::cout << "OK\n";
    }
    else {
        std::cout << "�chec\n";
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
