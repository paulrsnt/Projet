#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "strD.h"
#include "1v1.h"


/**
* \file 1vIA.h
* \brief Fichier.h du programme regroupant les fonctions du mode 1vIA du jeu du puissance 4++
* \author Aaron Amani, Fatih Ufacik et Paul Riga
* \version 2.0
* \date 5 mai 2020
*/

/**
 * \fn void insererMode1vsIA(int y, int x, joueur t, char mat[N][M])
 * \brief fonction qui permet a l'utilisateur d'inserer une piece
 *
 * \param y numero de la colonne
 * \param x numero de la ligne
 * \param t structure representant le joueur
 * \param mat la grille du jeu.
 *
 * \author Aaron Amani
*/

void insererMode1vsIA(int y, int x, joueur *t, char mat[N][M]);

/**
 * \fn void insererIA(joueur t, char mat[N][M])
 * \brief fonction qui permet a l'IA d'inserer une piece
 *
 * \param ia structure representant le joueur
 * \param mat la grille du jeu.
 *
 *\author Paul Riga, Fatih Ufacik
*/

 void insererIA(joueur *ia, char mat[N][M]);


/**
 * \fn void JouerNormal1vsIA(char mat[N][M], joueur j1, joueur j2)
 * \brief fonction qui permet de jouer a 1vsIA en mode normal
 *
 * \param mat la grille du jeu.
 *
 * \param j1 joueur 1.
 *
 * \return int
 *
 * \author Aaron Amani
*/


 int JouerNormal1vsIA(char mat[N][M], joueur *j1, joueur *ia);
