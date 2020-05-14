#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Includes/strD.h"
#include "../Includes/2v2.h"
#include "../Includes/parcours.h"



/**
* \file Test2v2.c
* \brief Programme qui teste les fonctions du mode 2v2 du jeu du puissance 4++
* \author Aaron Amani
* \version 2.0
* \date 5 mai 2020
*/


int
main()
{

  printf( "Debut du programme des test sur les fonctions du mode 2vs2 du jeu \n" ) ;

  joueur *j1,*j2,*j3,*j4;
  j1=malloc(sizeof(joueur));
  j2=malloc(sizeof(joueur));
  j3=malloc(sizeof(joueur));
  j4=malloc(sizeof(joueur));
  j1->couleur='R';
  j2->couleur='J';
  j3->couleur='R';
  j4->couleur='J';
  int grille_remplie=0;
  int en_ligne=0;
  int en_colonne=0;
  int en_diagonale=0;
  int colonne_rempli=0;
  int colonne_libre=0;
  char tab[N][M];
  char grille[N][M];


  initMatrice2v2(tab);
  for (int i = 1; i < N-1; i++) {
    for (int j = 1; j < M-1; j++) {
      tab[i][j]='R';
      }
  }
  grille_remplie=grille_plein2v2(tab);
  printf( "Test la fonction 'grille pleine 2v2' qui verifie que la matrice est remplie \n" ) ;
  afficher_mat2v2(tab);
  printf("\n");
  printf("grille_plein = %d\n",grille_remplie);
  (  grille_remplie ? printf ("-->Reussi\n") : printf("-->Raté\n") )  ;
  printf("\n");



  initMatrice2v2(tab);
  initMatrice2v2(grille);
  inserer2v2(1,6,j1,tab,grille,2);
  inserer2v2(2,6,j1,tab,grille,2);
  inserer2v2(3,6,j1,tab,grille,2);
  inserer2v2(4,6,j1,tab,grille,2);
  en_ligne=parcours(6,4,tab,j1);
  printf( "Test la fonction 'parcours' : quand on met 4 pions de même couleur en ligne \n" ) ;
  afficher_mat2v2(tab);
  printf("\n");
  afficher_mat2v2(grille);
  printf("\n");
  printf("parcours = %d\n",en_ligne);
  (  en_ligne  ? printf("-->Reussi\n") : printf ("-->Raté\n") )  ;
  printf("\n");



  initMatrice2v2(tab);
  initMatrice2v2(grille);
  inserer2v2(1,6,j1,tab,grille,2);
  inserer2v2(1,5,j1,tab,grille,2);
  inserer2v2(1,4,j1,tab,grille,2);
  inserer2v2(1,3,j1,tab,grille,2);
  en_colonne=parcours(3,1,tab,j1);
  printf( "Test la fonction 'parcours' : quand on met 4 pions de même couleur en colonne \n" ) ;
  afficher_mat2v2(tab);
  printf("\n");
  afficher_mat2v2(grille);
  printf("\n");
  printf("parcours = %d\n",en_colonne);
  (  en_colonne ? printf("-->Reussi\n") : printf ("-->Raté\n") )  ;
  printf("\n");



  initMatrice2v2(tab);
  initMatrice2v2(grille);
  inserer2v2(1,6,j1,tab,grille,2);
  inserer2v2(2,5,j1,tab,grille,2);
  inserer2v2(3,4,j1,tab,grille,2);
  inserer2v2(4,3,j1,tab,grille,2);
  en_diagonale=parcours(3,4,tab,j1);
  printf( "Test la fonction 'parcours' : quand on met 4 pions de même couleur en diagonale \n" ) ;
  afficher_mat2v2(tab);
  printf("\n");
  afficher_mat2v2(grille);
  printf("\n");
  printf("parcours = %d\n",en_diagonale);
  (  en_diagonale  ? printf("-->Reussi\n") : printf ("-->Raté\n") )  ;
  printf("\n");



  initMatrice2v2(tab);
  initMatrice2v2(grille);
  inserer2v2(1,6,j1,tab,grille,2);
  inserer2v2(1,5,j2,tab,grille,2);
  inserer2v2(1,4,j1,tab,grille,2);
  inserer2v2(1,3,j2,tab,grille,2);
  inserer2v2(1,2,j1,tab,grille,2);
  inserer2v2(1,1,j2,tab,grille,2);
  colonne_rempli=statut2v2(1,tab,2);
  printf( "Test la fonction 'statut 2v2': qui doit retourner -1 (FAUX) quand une colonne n'est pas disponible \n" ) ;
  afficher_mat2v2(tab);
  printf("\n");
  afficher_mat2v2(grille);
  printf("\n");
  printf("statut2v2 = %d\n",colonne_rempli);
  (  (colonne_rempli==-1) ? printf("-->Reussi\n") :  printf("-->Raté\n") )  ;
  printf("\n");



  initMatrice2v2(tab);
  initMatrice2v2(grille);
  inserer2v2(1,6,j1,tab,grille,2);
  inserer2v2(1,5,j2,tab,grille,2);
  inserer2v2(1,4,j1,tab,grille,2);
  inserer2v2(1,3,j2,tab,grille,2);
  inserer2v2(1,2,j1,tab,grille,2);
  colonne_libre=statut2v2(1,tab,2);
  printf( "Test la fonction 'statut 2v2': qui doit retourner la valeur de x (VRAI) donc le le numero de la ligne quand la colonne est disponible \n" ) ;
  afficher_mat2v2(tab);
  printf("\n");
  afficher_mat2v2(grille);
  printf("\n");
  printf("statut2v2 = %d\n",colonne_libre);
  (  colonne_libre  ? printf ("-->Reussi\n")  : printf("-->Raté\n") )  ;
  printf("\n");



  initMatrice2v2(tab);
  initMatrice2v2(grille);
  inserer2v2(1,6,j1,tab,grille,2);
  printf( "Test la fonction 'inserer2v2': qui doit inserer dans la bonne colonne (exemmple colonne: 1 ligne: 1) \n" ) ;
  afficher_mat2v2(tab);
  printf("\n");
  afficher_mat2v2(grille);
  printf("\n");
  (  tab[6][1]=='R'  ? printf ("-->Reussi\n")  : printf("-->Raté\n") )  ;
  printf("\n");


  initMatrice2v2(tab);
  initMatrice2v2(grille);
  inserer2v2(1,6,j1,tab,grille,2);
  inserer2v2(1,5,j2,tab,grille,2);
  inserer2v2(1,4,j1,tab,grille,2);
  inserer2v2(1,3,j2,tab,grille,2);
  inserer2v2(1,2,j1,tab,grille,2);
  inserer2v2(1,statut2v2(1,grille,3),j2,tab,grille,3);
  printf( "Test la fonction 'inserer2v2': qui doit inserer un pion plein dans la colonne 1 dans une colonne remplie de pieces creuses et doit les traverser.\n" ) ;
  afficher_mat2v2(tab);
  printf("\n");
  afficher_mat2v2(grille);
  printf("\n");
  printf("grille[6][1] = %c \n\n",grille[6][1]);
  (  grille[6][1]=='P'  ? printf ("-->Reussi\n")  : printf("-->Raté\n") )  ;
  printf("\n");


  initMatrice2v2(tab);
  initMatrice2v2(grille);
  inserer2v2(1,6,j1,tab,grille,2);
  inserer2v2(1,5,j1,tab,grille,2);
  inserer2v2(1,4,j1,tab,grille,2);
  inserer2v2(1,3,j2,tab,grille,1);
  inserer2v2(1,2,j1,tab,grille,2);
  printf( "Test la fonction 'inserer2v2' et 'parcours': on insere une piece bloquante 'B' dans la colonne 1, afin de bloquer le joueur 1 qui risque de gagner \n" ) ;
  afficher_mat2v2(tab);
  printf("\n");
  afficher_mat2v2(grille);
  printf("\n");
  printf("parcours = %d \n\n",parcours(2,1,tab,j1));

  ( parcours(2,1,tab,j1) ? printf ("-->Raté\n")  : printf("-->Reussi\n") )  ;
  printf("\n");







  printf( "Fin du programme des test sur les fonctions du mode 2vs2 \n" ) ;



  free(j1);
  free(j2);
  free(j3);
  free(j4);
  return(0) ;
}
