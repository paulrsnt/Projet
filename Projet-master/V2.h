#include <stdio.h>
#include <stdlib.h>
#include "structD.h"



 int statut2v2(int y, char mat[N][M], int p);


  void initmatrice2v2(char mat[N][M],char mat2[N][M]);


  void afficher_mat2v2(char mat[N][M]);


  void inserer2v2(int x, int y, joueur t, char mat[N][M],char mat2[N][M], int p);


  int gagnant_ligne2v2(char mat[N][M]);


  int gagnant_colonne2v2(char mat[N][M]);


  int gagnant_diagonale2v2(char mat[N][M]);


  int quigagne2v2(char mat[N][M]);


  int JouerNormal2v2(char mat[N][M],char mat2[N][M], joueur j1, joueur j2, joueur j3, joueur j4, int p);
