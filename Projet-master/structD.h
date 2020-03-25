#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef STRUCTD_H
#define STRUCTD_H

/**

* \file structD.h
* \brief Programme contenant les stucture et variable constante du jeu du puissance 4++
* \author Aaron Amani Oussama Belkadi Fathi et Paul riga
* \version 1.0
* \date 17 fevrier 2020

*/

#define N  7
#define M  7


char mat[N][M];
char mat2[N][M]; 

/**
* \struct joueurs_s
* \brief stucture afin de definir les joueur
*
*/

typedef struct joueurs_s {

  char * couleur;

}joueur ;


/**
 * \fn int grille_plein(char mat[N][M])
 * \brief fonction qui retourne 1 si la grille est pleine, 0 si elle ne l'est pas
 *
 * \param mat la grille du jeu.
 *
 * \return int.
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
*/

extern int statut(int y, char mat[N][M]);

/**
 * \fn void initMatrice(char mat[N][M])
 * \brief fonction qui initialise la matrice
 *
 * \param mat la grille du jeu.
 *
 *
*/

extern void initMatrice(char mat[N][M]);


/**
 * \fn void afficher_mat(char mat[N][M])
 * \brief fonction qui affiche la matrice du jeu
 *
 * \param mat la grille du jeu.
 *
 *
*/

extern void afficher_mat(char mat[N][M]);


/**
 * \fn void inserer(int y, int x, joueur t, char mat[N][M])
 * \brief fonction qui permet a l'utilisateur d'inserer une piece
 *
 * \param y numero de la colonne
 * \param x numero de la ligne
 * \param t structure representant le joueur
 * \param mat la grille du jeu.
 *
 *
*/

extern void inserer(int y, int x, joueur t, char mat[N][M]);


/**
 * \fn void inserer(int y, int x, joueur t, char mat[N][M])
 * \brief fonction qui permet a l'utilisateur d'inserer une piece
 *
 * \param ia structure representant le joueur
 * \param mat la grille du jeu.
 *
 *
*/

extern void insererIA(joueur ia, char mat[N][M]);


/**
 * \fn int gagnant_lignev2(char mat[N][M])
 * \brief fonction retourne 1 si les jaunes gagnent avec les pion en lignes ou 2 si les rouges gagnent avec les pion en lignes
 *
 * \param mat la grille du jeu.
 *
 * \return int.
*/

extern int parcours_ligne(char mat[N][M]);


/**
 * \fn int gagnant_colonnev2(char mat[N][M])
 * \brief fonction retourne 1 si les jaunes gagnent avec les pion en colonnes ou 2 si les rouges gagnent avec les pion en colonnes
 *
 * \param mat la grille du jeu.
 *
 * \return int.
*/

extern int parcours_colonne(char mat[N][M]);

/**
 * \fn int gagnant_diagonalev2(char mat[N][M])
 * \brief fonction retourne 1 si les jaunes gagnent avec les pion en diagonale ou 2 si les rouges gagnent avec les pion en diagonale
 *
 * \param mat la grille du jeu.
 *
 * \return int.
*/


extern int parcours_diagonale(char mat[N][M]);

/**
 * \fn void modifGagnant(char mat[N][M])
 * \brief fonction permettant de savoir qui a gagné en modifiant les caractère R ou J par '*'
 *
 * \param mat la grille du jeu.
 *
*/


extern void modif(char mat[N][M]);


/**
 * \fn int gagnant_ligne(char mat[N][M])
 * \brief fonction retourne 1 si les jaunes gagnent avec les pion en lignes ou 2 si les rouges gagnent avec les pion en lignes
 *
 * \param mat la grille du jeu.
 *
 * \return int.
*/

extern int gagnant_ligne(char mat[N][M]);


/**
 * \fn int gagnant_colonne(char mat[N][M])
 * \brief fonction retourne 1 si les jaunes gagnent avec les pion en colonnes ou 2 si les rouges gagnent avec les pion en colonnes
 *
 * \param mat la grille du jeu.
 *
 * \return int.
*/

extern int gagnant_colonne(char mat[N][M]);

/**
 * \fn int gagnant_diagonale(char mat[N][M])
 * \brief fonction retourne 1 si les jaunes gagnent avec les pion en diagonale ou 2 si les rouges gagnent avec les pion en diagonale
 *
 * \param mat la grille du jeu.
 *
 * \return int.
*/


extern int gagnant_diagonale(char mat[N][M]);


/**
 * \fn int qui_gagne(char mat[N][M])
 * \brief fonction retourne 1 si les jaunes  ou 2 si les rouges
 *
 * \param mat la grille du jeu.
 *
 * \return int.
*/


extern int qui_gagne(char mat[N][M]);



/**
 * \fn void JouerNormal1vs1(char mat[N][M], joueur j1, joueur j2)
 * \brief fonction qui permet de jouer a 1vs1 en mode normal et retourne une lettre qui designe qui a gagné (r ou j)
 *
 * \param mat la grille du jeu.
 * \param j2 joueur 2.
 * \param j1 joueur 1.
 *
 * \return char
*/


extern int JouerNormal1vs1(char mat[N][M], joueur j1, joueur j2);

/**
 * \fn void JouerNormal1vs1(char mat[N][M], joueur j1, joueur j2)
 * \brief fonction qui permet de jouer a 1vs1 en mode normal et retourne une lettre qui designe qui a gagné (r ou j)
 *
 * \param mat la grille du jeu.
 *
 * \param j1 joueur 1.
 *
 * \return int
*/


extern int JouerNormal1vsIA(char mat[N][M], joueur j1, joueur ia);

#endif
