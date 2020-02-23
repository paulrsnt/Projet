#include <stdio.h>
#include <stdlib.h>
#include "structD.h"


/**
*
* \file jeu.c
* \brief Programme permettant de jouer au puissance 4++
* \author Aaron Amani Oussama Belkadi Fathi et Paul riga
* \version 1.0
* \date 17 fevrier 2020
*
*/

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

printf("CHOISISSEZ UN MODE DE JEU : \n\n");

while(x!=3){

  do {
    printf("LOCAL 1 VS 1 : Appuyer sur la touche 1 \n\n");
    printf("LOCAL 1 VS AI : Appuyer sur la touche 2 \n\n");
    printf("LOCAL 2 VS 2 : Appuyer sur la touche 3 \n\n");
    printf("QUITTER LE JEU : Appuyer sur la touche 4 \n\n");


    scanf("%d",&x);

    system("clear");

    if((x!=1)&&(x!=2)&&(x!=3)&&(x!=4)){
      printf("Veuillez taper sur les touches 1, 2 , 3 ou 4 !! \n\n\n");

    }

  } while((x!=1)&&(x!=2)&&(x!=3)&&(x!=4));

  joueur j1,j2;

  if(x==1){
    int rouge=0,jaune=0;
    int y=0;
    while (y!=2) {

      if (JouerNormal1vs1(mat,j1,j2)==1) {
        rouge++;
      }
      else{
        jaune++;
      }
      printf("\n\n");
      printf("Rouge : %d \n",rouge);
      printf("\n\n");
      printf("Jaune : %d \n",jaune);
      printf("\n\n");
      printf("Voulez vous rejouer ?\n");
      do {
        printf("Taper 1 pour rejouer, taper 2 pour quitter ce mode \n");
        scanf("%d",&y);
        system("clear");
      } while((y!=1)&&(y!=2));
    }

  }



  else if (x==2) {

    int y=0;
    while (y!=2) {

      /*JouerNormal1vsIA(mat,j1);*/
      printf("\n\n");
      printf("Voulez vous rejouer ?\n");
      do {
        printf("Taper 1 pour rejouer, taper 2 pour quitter ce mode \n");
        scanf("%d",&y);
        system("clear");
      } while((y!=1)&&(y!=2));
    }

  }


  else if (x==3) {
    joueur j3,j4;
    piece p;
    Jouer2vs2(mat,j1,j2,j3,j4,p);
  }



  else if (x==4) {
    return 0;
  }
}
}
