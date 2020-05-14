#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef STRD_H
#define STRD_H

/**

* \file strD.h
* \brief Fichier.h contenant les stucture et variable globale du jeu du puissance 4++
* \author Aaron Amani Oussama Belkadi Fatih et Paul riga
* \version 2.0
* \date 5 mai 2020

*/

#define N  8
#define M  9


char mat[N][M];
char mat2[N][M];

/**
* \struct joueurs_s
* \brief stucture afin de definir les joueur
*
*/

typedef struct joueurs_s {

  int x;    //sert uniquement a l'ia
  int y;
  char couleur ;

}joueur ;

#endif
