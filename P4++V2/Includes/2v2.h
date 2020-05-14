#include <stdio.h>
#include <stdlib.h>
#include "strD.h"


#ifndef DEUX_VS_DEUX_H
#define DEUX_VS_DEUX_H

/**

* \file 2v2.h
* \brief Fichier.h du programme contenant les fonctions du mode 2v2 du jeu du puissance 4++
* \author Aaron Amani Oussama Belkadi Fatih et Paul riga
* \version 1.0
* \date 5 mai 2020

*/



/**
 * \fn int grille_plein2v2(char mat[N][M])
 * \brief fonction qui retourne 1 si la grille est pleine, 0 si elle ne l'est pas
 *
 * \param mat la grille du jeu.
 *
 * \return int.
 *
 *\author Aaron Amani
*/

extern int grille_plein2v2(char mat[N][M]);

/**
 * \fn int statut2v2(int y, char mat[N][M],int pc)
 * \brief verifie le numero de colonne et retourne la ligne de disponible ou pas
 *
 * \param y numero de colonne.
 * \param mat la grille du jeu.
 * \param int p indice de la piece.
 *
 * \return int.
 *
 *\author Aaron Amani, Paul riga
*/

extern int statut2v2(int y, char mat[N][M],int pc);

/**
 * \fn void initMatrice2v2(char mat[N][M])
 * \brief fonction qui initialise la matrice
 *
 * \param mat la grille du jeu.
 *
 * \author Fatih Ufacik
*/
extern void initMatrice2v2(char mat[N][M]);


/**
 * \fn void afficher_mat2v2(char mat[N][M])
 * \brief fonction qui affiche la matrice du jeu
 *
 * \param mat la grille du jeu.
 *
 * \author Oussama Belkadi
*/

extern void afficher_mat2v2(char mat[N][M]);


/**
 * \fn void inserer2v2(int y, int x, joueur *t, char mat[N][M], char mat2[N][M] ,int pc)
 * \brief fonction qui permet a l'utilisateur d'inserer une piece
 *
 * \param y numero de la colonne
 * \param x numero de la ligne
 * \param t structure representant le joueur
 * \param mat la grille du jeu representant la couleur des pieces .
 * \param mat2 la grille du jeu representant le type de la pieces .
 * \param int p indice de la piece.
 *
 * \author Oussama Belkadi, Aaron Amani
*/

extern void inserer2v2(int y, int x, joueur *t, char mat[N][M], char mat2[N][M],int pc);

/**
 * \fn int JouerNormal2v2(char mat[N][M], char mat2[N][M], joueur *j1, joueur *j2, joueur *j3, joueur *j4)
 * \brief fonction qui permet de jouer a 1vs1 en mode normal et retourne une lettre qui designe qui a gagné (r ou j)
 *
 * \param mat la grille du representant les couleurs des pices.
 * \param mat2 la grille du jeu representant les types des pieces.
 * \param j1 joueur 1.
 * \param j2 joueur 2.
 * \param j3 joueur 3.
 * \param j4 joueur 4.
 *
 * \return int
 * \author Oussama Belkadi, Aaron Amani
*/

extern int JouerNormal2v2(char mat[N][M],char mat2[N][M], joueur *j1, joueur *j2, joueur *j3, joueur *j4);

#endif
