#ifndef TEST_UNITAIRE_HPP
#define TEST_UNITAIRE_HPP

#include <iostream> // Inclusion de la biblioth�que pour les entr�es/sorties standard
#include "cellule.hpp"  // Inclusion de la classe cellule pour tester les objets cellule
#include "grille.hpp"    // Inclusion de la classe grille pour tester les op�rations li�es � la grille
#include "fichier.hpp"   // Inclusion de la classe fichier pour tester les op�rations sur les fichiers
#include "graphique.hpp" // Inclusion de la classe graphique pour tester les affichages graphiques


// D�claration des fonctions de test pour chaque composant du projet

// Teste la classe cellule, en v�rifiant son comportement
// pour d�finir et obtenir l'�tat d'une cellule (vivante ou morte)
void testCellule();

// Teste la classe grille, v�rifie son fonctionnement
// concernant l'initialisation de la grille, l'obtention des cellules,
// et la gestion des g�n�rations de cellules
void testGrille();

// Teste la classe fichier, v�rifie la lecture et l'�criture
// des donn�es dans un fichier texte (chargement de la grille et sauvegarde des g�n�rations)
void testFichier();

// Teste la classe graphique, v�rifie la capacit� � afficher
// la grille et les mises � jour graphiques (affichage des g�n�rations)
void testGraphique();

// Fonction qui lance tous les tests d�finis ci-dessus dans l'ordre
void lancerTests();

#endif // TEST_UNITAIRE_HPP
