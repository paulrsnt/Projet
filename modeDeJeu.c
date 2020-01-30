#include<stdio.h>
#include<stdlib.h>

void ModeDeJeu(int n){
  int Pnormal,Pameliorer;

  printf("selectionnez un mode de jeu : ");

  do{
    printf("Tapez 1 pour le puissance 4 normal ou 2 pour le puissance 4++");
    scanf("%d",&n);
  }while(n!=1 || n!=2);

  if(n==1){
    do{
      printf("Tapez 1 pour jouer contre l'ordinateur ou 2 pour en local.");
      scanf("%d",&Pnormal);
    }while(n!=1 || n!=2);
  }

  if(n==2){
    do{
      printf("Tapez 1 pour jouer contre l'ordinateur ou 2 pour jouer en 1v1 local ou 3 pour jouer en 2v2 local.");
      scanf("%d",&Pameliorer);
    }while(n!=1 || n!=2 || n!=3);
  }

}
