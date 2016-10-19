#ifndef PLACEMENT_H_INCLUDED
#define PLACEMENT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define TAILLE_TABLEAU 20
#define NOMBRE_TABLEAU 3
#define JOUEUR_1 1
#define JOUEUR_2 2
#define CORVETTE 1
#define DESTROYER 3
#define CROISEUR 4
#define PORTE_AVION 6
#define INFOS 3

void PlacementBateauxJoueur(int tableau[TAILLE_TABLEAU][TAILLE_TABLEAU][NOMBRE_TABLEAU],int joueur);
void PlacementCorvette(int tableau[TAILLE_TABLEAU][TAILLE_TABLEAU][NOMBRE_TABLEAU],int joueur);
void PlacementDestroyer(int tableau[TAILLE_TABLEAU][TAILLE_TABLEAU][NOMBRE_TABLEAU],int joueur);
void PlacementCroiseur(int tableau[TAILLE_TABLEAU][TAILLE_TABLEAU][NOMBRE_TABLEAU],int joueur);
void PlacementPorteAvion(int tableau[TAILLE_TABLEAU][TAILLE_TABLEAU][NOMBRE_TABLEAU],int joueur);

#endif // PLACEMENT_H_INCLUDED
