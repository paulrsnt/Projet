#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "strD.h"

#ifndef UN_VS_UN_H
#define UN_VS_UN_H

/**

* \file 1v1.h
* \brief Fichier.h du programme regroupant les fonctions du mode 1v1 du jeu du puissance 4++
* \author Aaron Amani Oussama Belkadi Fatih Ufacik et Paul riga
* \version 2.0
* \date 5 mai 2020

*/

/**
 * \fn int grille_plein(char mat[N][M])
 * \brief fonction qui retourne 1 si la grille est pleine, 0 si elle ne l'est pas
 *
 * \param mat la grille du jeu.
 *
 * \return int.
 *
 *\author Aaron Amani
 *
*/
extern int grille_plein(char mat[N][M]);

/**
 * \fn int statut(int y, char mat[N][M])
 * \brief verifie le numero de colonne et retourne la ligne de disponible ou pas
 *
 * \param y numero de colonne.
 * \param mat la grille du jeu.
 *
 * \return int.
 *
 *\author Aaron Amani, Paul Riga
*/
extern int statut(int y, char mat[N][M]);

/**
 * \fn void initMatrice(char mat[N][M])
 * \brief fonction qui initialise la matrice
 *
 * \param mat la grille du jeu.
 *
 *
 *\author Fatih Ufacik
 *
*/

extern void initMatrice(char mat[N][M]);


/**
 * \fn void afficher_mat(char mat[N][M])
 * \brief fonction qui affiche la matrice du jeu
 *
 * \param mat la grille du jeu.
 * \author Oussama Belkadi
 *
*/

extern void afficher_mat(char mat[N][M]);


/**
 * \fn void inserer(int y, int x, joueur *t, char mat[N][M])
 * \brief fonction qui permet a l'utilisateur d'inserer une piece
 *
 * \param y numero de la colonne
 * \param x numero de la ligne
 * \param t structure representant le joueur
 * \param mat la grille du jeu.
 *
 *\author Oussama Belkadi
*/

extern void inserer(int y, int x, joueur *t, char mat[N][M]);


/**
 * \fn void JouerNormal1vs1(char mat[N][M], joueur *j1, joueur *j2)
 * \brief fonction qui permet de jouer a 1vs1 en mode normal et retourne une lettre qui designe qui a gagné (r ou j)
 *
 * \param mat la grille du jeu.
 * \param j2 joueur *2.
 * \param j1 joueur *1.
 *
 * \return char
 *
 *\author Aaron Amani Fatih Ufacik
*/

extern int JouerNormal1vs1(char mat[N][M], joueur *j1, joueur *j2);


#endif
