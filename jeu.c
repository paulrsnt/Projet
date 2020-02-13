#include <stdio.h>
#include <stdlib.h>
#include "structD.h"

int main() {

int x=0;

printf("###############################\n");
printf("###                          ##\n");
printf("###                          ##\n");
printf("###        PUISSANCE         ##\n");
printf("###                          ##\n");
printf("###           4++            ##\n");
printf("###                          ##\n");
printf("###                          ##\n");
printf("###############################\n");

printf("Voici le jeu du puissance 4++ \n\n");
printf("Ce Jeu comporte plusieurs mode \n");
printf("Quel mode choisissez vous ?? \n\n\n");


while(x!=3){

  do {
    printf("Appuyer sur la touche 1 pour lancer une partie 1 vs 1 en local\n\n");
    printf("Appuyer sur la touche 2 pour lancer une partie 2 vs 2 en local (ce mode comporte les fonctions specifiques des pieces)\n\n");
    printf("Appuyer sur la touche 3 pour quitter le jeu \n\n");


    scanf("%d",&x);

    if((x!=1)&&(x!=2)&&(x!=3)){
      printf("Veuillez taper 1,2 ou 3 merci  %d   !!\n\n\n",x);
    }

  } while((x!=1)&&(x!=2)&&(x!=3));

  joueur j1,j2;

  if(x==1){
    int y=0;

    JouerNormal1vs1(mat,j1,j2);
    printf("\n\n");
    printf("Voulez vous rejouer ?\n");
    do {
      printf("1 pour oui 2 pour quitter \n");
      scanf("%d",&y);
    } while(y!=1&&y!=2);

  }
  else if (x==2) {
    printf("Jouer2vs2 en cours.... \n\n\n");
  }
  else if (x==3) {
    return 0;
  }
}
}
