#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef STRD_H
#define STRD_H

/**

* \file strD.h
* \brief Programme contenant les stucture et variable constante du jeu du puissance 4++
* \author Aaron Amani Oussama Belkadi Fathi et Paul riga
* \version 1.0
* \date 17 fevrier 2020

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

  int x;
  int y;
  char couleur ;

}joueur ;

#endif
