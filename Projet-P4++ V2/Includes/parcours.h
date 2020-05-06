#include <stdio.h>
#include <stdlib.h>
#include "../Includes/strD.h"


#ifndef _PARCOURS_H
#define _PARCOURS_H


/**

* \file  parcours.h
* \brief Fichier.h du programme regroupant les fonctions de parcours de la matrice jeu du puissance 4++
* \author Aaron Amani
* \version 1.0
* \date 17 fevrier 2020

*/


/**
 * \fn int parcours(int x, int y, char mat[N][M],joueur *j)
 * \brief fonction qui utilise des sous fonctions afin de parcourir toute la matrice et vaut vrai si le pion du joueur afin de determiner la victoire de celui-ci
 *
 * \param x coordonnée du pion du joueur en abscisse .
 * \param y coordonnée du pion du joueur en ordonnée.
 * \param mat du jeu.
 * \param structure du joueur contenant le couleur du joueur
 *
 * \return int
*/

extern int parcours(int x, int y, char mat[N][M],joueur *j);


/**
 * \fn int parcoursLigneB(int x, int y, char mat[N][M],joueur *j)
 * \brief fonction qui parcours la matrice a partir du pion en ligne a partir du bas
 *
 * \param x coordonnée du pion du joueur en abscisse .
 * \param y coordonnée du pion du joueur en ordonnée.
 * \param mat du jeu.
 * \param structure du joueur contenant le couleur du joueur
 *
 *
*/


int parcoursLigneB(int x, int y, char mat[N][M],joueur *j);

/**
 * \fn int parcoursLigneH(int x, int y, char mat[N][M],joueur *j)
 * \brief fonction qui parcours la matrice a partir du pion en ligne a partir du haut
 *
 * \param x coordonnée du pion du joueur en abscisse .
 * \param y coordonnée du pion du joueur en ordonnée.
 * \param mat du jeu.
 * \param structure du joueur contenant le couleur du joueur
 *
 *
*/

int parcoursLigneH(int x, int y, char mat[N][M],joueur *j);

/**
 * \fn int parcoursColonneD(int x, int y, char mat[N][M],joueur *j)
 * \brief fonction qui parcours la matrice a partir du pion en colonne a partir de la droite
 *
 * \param x coordonnée du pion du joueur en abscisse .
 * \param y coordonnée du pion du joueur en ordonnée.
 * \param mat du jeu.
 * \param structure du joueur contenant le couleur du joueur
 *
 *
*/

int parcoursColonneD(int x, int y, char mat[N][M],joueur *j);

/**
 * \fn int parcoursColonneG(int x, int y, char mat[N][M],joueur *j)
 * \brief fonction qui parcours la matrice a partir du pion en colonne a partir de la gauche
 *
 * \param x coordonnée du pion du joueur en abscisse .
 * \param y coordonnée du pion du joueur en ordonnée.
 * \param mat du jeu.
 * \param structure du joueur contenant le couleur du joueur
 *
 *
*/
int parcoursColonneG(int x, int y, char mat[N][M],joueur *j);

/**
 * \fn int parcoursDiagDH(int x, int y, char mat[N][M],joueur *j)
 * \brief fonction qui parcours la matrice a partir du pion en diagonale a partir de la droite en bas
 *
 * \param x coordonnée du pion du joueur en abscisse .
 * \param y coordonnée du pion du joueur en ordonnée.
 * \param mat du jeu.
 * \param structure du joueur contenant le couleur du joueur
 *
 *
*/

int parcoursDiagDB(int x, int y, char mat[N][M],joueur *j);

/**
 * \fn int parcoursDiagGH(int x, int y, char mat[N][M],joueur *j)
 * \brief fonction qui parcours la matrice a partir du pion en diagonale a partir de la gauche en haut
 *
 * \param x coordonnée du pion du joueur en abscisse .
 * \param y coordonnée du pion du joueur en ordonnée.
 * \param mat du jeu.
 * \param structure du joueur contenant le couleur du joueur
 *
 *
*/

int parcoursDiagGH(int x, int y, char mat[N][M],joueur *j);

/**
 * \fn int parcoursDiagGB(int x, int y, char mat[N][M],joueur *j)
 * \brief fonction qui parcours la matrice a partir du pion en diagonale en partant a gauche en bas
 *
 * \param x coordonnée du pion du joueur en abscisse .
 * \param y coordonnée du pion du joueur en ordonnée.
 * \param mat du jeu.
 * \param structure du joueur contenant le couleur du joueur
 *
 *
*/

int parcoursDiagGB(int x, int y, char mat[N][M],joueur *j);

/**
 * \fn int parcoursDiagDH(int x, int y, char mat[N][M],joueur *j)
 * \brief fonction qui parcours la matrice a partir du pion en diagonale a partir de la droite en haut
 *
 * \param x coordonnée du pion du joueur en abscisse .
 * \param y coordonnée du pion du joueur en ordonnée.
 * \param mat du jeu.
 * \param structure du joueur contenant le couleur du joueur
 *
 *
*/

int parcoursDiagDH(int x, int y, char mat[N][M],joueur *j);


#endif
