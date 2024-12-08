#ifndef TEST_UNITAIRE_HPP
#define TEST_UNITAIRE_HPP

#include <iostream> // Inclusion de la bibliothèque pour les entrées/sorties standard
#include "cellule.hpp"  // Inclusion de la classe cellule pour tester les objets cellule
#include "grille.hpp"    // Inclusion de la classe grille pour tester les opérations liées à la grille
#include "fichier.hpp"   // Inclusion de la classe fichier pour tester les opérations sur les fichiers
#include "graphique.hpp" // Inclusion de la classe graphique pour tester les affichages graphiques


// Déclaration des fonctions de test pour chaque composant du projet

// Teste la classe cellule, en vérifiant son comportement
// pour définir et obtenir l'état d'une cellule (vivante ou morte)
void testCellule();

// Teste la classe grille, vérifie son fonctionnement
// concernant l'initialisation de la grille, l'obtention des cellules,
// et la gestion des générations de cellules
void testGrille();

// Teste la classe fichier, vérifie la lecture et l'écriture
// des données dans un fichier texte (chargement de la grille et sauvegarde des générations)
void testFichier();

// Teste la classe graphique, vérifie la capacité à afficher
// la grille et les mises à jour graphiques (affichage des générations)
void testGraphique();

// Fonction qui lance tous les tests définis ci-dessus dans l'ordre
void lancerTests();

#endif // TEST_UNITAIRE_HPP
