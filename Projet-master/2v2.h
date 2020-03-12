#include <stdio.h>
#include <stdlib.h>
#include "structD.h"



extern int statut2v2(int y, int mat[N][M], int p);


extern void initmatrice2v2(int mat[N][M]);


extern void afficher_mat2v2(int mat[N][M]);


extern void inserer2v2(int x, int y, joueur t, int mat[N][M], int p);


extern int gagnant_ligne2v2(int mat[N][M]);


extern int gagnant_colonne2v2(int mat[N][M]);


extern int gagnant_diagonale2v2(int mat[N][M]);


extern int quigagne2v2(int mat[N][M]);


extern int JouerNormal2v2(int mat[N][M], joueur j1, joueur j2, joueur j3, joueur j4, int p);
