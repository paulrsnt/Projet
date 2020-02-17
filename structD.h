#include <stdio.h>
#include <stdlib.h>

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

/**
* \struct joueurs_s
* \brief stucture afin de definir les joueur
*
*/

typedef struct joueurs_s {

  char * couleur;

}joueur ;

/**
* \enum piece_s
* \brief stucture enumeration piece afin de definir le type de la piece
*
*/
typedef enum piece_s {bloquante,creuse,pleine} piece;
