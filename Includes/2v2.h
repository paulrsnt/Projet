#include <stdio.h>
#include <stdlib.h>
#include "strD.h"


#ifndef DEUX_VS_DEUX_H
#define DEUX_VS_DEUX_H

/**

* \file 2v2.h
* \brief Programme contenant les fonctions du mode 2v2 du jeu du puissance 4++
* \author Aaron Amani Oussama Belkadi Fathi et Paul riga
* \version 1.0
* \date 17 fevrier 2020

*/
extern int statut2v2(int y, char mat[N][M], int p);

extern int grille_plein2v2(char mat[N][M]);

extern void initMatrice2v2(char mat[N][M]);

extern void afficher_mat2v2(char mat[N][M]);

extern void inserer2v2(int x, int y, joueur t, char mat[N][M],char mat2[N][M], int p);

extern int gagnant_ligne2v2(char mat[N][M]);

extern int gagnant_colonne2v2(char mat[N][M]);

extern int gagnant_diagonale2v2(char mat[N][M]);

extern int quigagne2v2(char mat[N][M]);

extern int JouerNormal2v2(char mat[N][M],char mat2[N][M], joueur j1, joueur j2, joueur j3, joueur j4);

#endif
