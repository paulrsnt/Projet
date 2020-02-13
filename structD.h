#include <stdio.h>
#include <stdlib.h>

#define N  7
#define M  7


char mat[N][M];


typedef struct joueurs_s {

  char * couleur;

}joueur ;


typedef enum piece_s {bloquante,creuse,pleine} piece;
