#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Includes/strD.h"
#include "../Includes/1v1.h"
#include "../Includes/parcours.h"



/**
* \file Test1v1.c
* \brief Programme qui teste les fonctions du mode 1v1 du jeu du puissance 4++
* \author Aaron Amani
* \version 2.0
* \date 5 mai 2020
*/


int
main()
{

  printf( "Debut du programme des test sur les fonctions du mode 1vs1 du jeu \n" ) ;


  joueur *j1,*j2;
  j1=malloc(sizeof(joueur));
  j2=malloc(sizeof(joueur));
  j1->couleur='R';
  j2->couleur='J';

  int grille_remplie=0;
  int en_ligne=0;
  int en_colonne=0;
  int en_diagonale=0;
  int colonne_rempli;
  int colonne_libre=0;
  char tab[N][M];

  printf( "Test la fonction 'grille pleine' qui doit etre vrai quand une matrice est pleine\n" ) ;
  initMatrice(tab);
  for (int i = 1; i < N-1; i++) {
    for (int j = 1; j < M-1; j++) {
      tab[i][j]='R';
      }
  }
  grille_remplie=grille_plein(tab);
  afficher_mat(tab);
  printf("\n");
  printf("grille_plein = %d\n",grille_remplie);
  (  grille_remplie ? printf ("-->Reussi\n") : printf("-->Raté\n") )  ;
  printf("\n");


  printf( "Test la fonction 'inserer': qui doit inserer le pion d'un joueur dans la bonne colonne (exemmple colonne: 1 ligne: 1) \n" ) ;
  initMatrice(tab);
  inserer(1,6,j1,tab);
  afficher_mat(tab);
  printf("\n");
  printf("tab[6][1] = %c \n\n",tab[6][1]);
  (  tab[6][1]=='R'  ? printf ("-->Reussi\n")  : printf("-->Raté\n") )  ;
  printf("\n");



  printf( "Test la fonction 'parcours' : quand on met 4 pions de même couleur en ligne \n" ) ;
  initMatrice(tab);
  inserer(1,6,j1,tab);
  inserer(2,6,j1,tab);
  inserer(3,6,j1,tab);
  inserer(4,6,j1,tab);
  en_ligne=parcours(6,4,tab,j1);
  afficher_mat(tab);
  printf("\n");
  printf("parcours = %d\n",en_ligne);
  (  en_ligne  ? printf("-->Reussi\n") : printf ("-->Raté\n") )  ;
  printf("\n");



  printf( "Test la fonction 'parcours' : quand on met 4 pions de même couleur en colonne \n" ) ;
  initMatrice(tab);
  inserer(1,6,j1,tab);
  inserer(1,5,j1,tab);
  inserer(1,4,j1,tab);
  inserer(1,3,j1,tab);
  en_colonne=parcours(3,1,tab,j1);
  afficher_mat(tab);
  printf("\n");
  printf("parcours = %d\n",en_colonne);
  (  en_colonne ? printf("-->Reussi\n") : printf ("-->Raté\n") )  ;
  printf("\n");


  printf( "Test la fonction 'parcours' : quand on met 4 pions de même couleur en diagonale \n" ) ;
  initMatrice(tab);
  inserer(1,6,j1,tab);
  inserer(2,5,j1,tab);
  inserer(3,4,j1,tab);
  inserer(4,3,j1,tab);
  en_diagonale=parcours(3,4,tab,j1);
  afficher_mat(tab);
  printf("\n");
  printf("parcours = %d\n",en_diagonale);
  (  en_diagonale  ? printf("-->Reussi\n") : printf ("-->Raté\n") )  ;
  printf("\n");



  printf( "Test la fonction 'statut' qui doit retourner 0 (FAUX) parce que la colonne n'est pas disponible \n" ) ;
  initMatrice(tab);
  inserer(1,6,j1,tab);
  inserer(1,5,j2,tab);
  inserer(1,4,j1,tab);
  inserer(1,3,j2,tab);
  inserer(1,2,j1,tab);
  inserer(1,1,j2,tab);
  colonne_rempli=statut(1,tab);
  afficher_mat(tab);
  printf("\n");
  printf("statut = %d\n",colonne_rempli);
  (  (colonne_rempli==0) ? printf("-->Reussi\n") :  printf("-->Raté\n") )  ;
  printf("\n");


  printf( "Test la fonction 'statut' qui doit retourner la valeur de x (VRAI) donc le numero de la ligne quand la colonne est disponible \n" ) ;
  initMatrice(tab);
  inserer(1,6,j1,tab);
  inserer(1,5,j2,tab);
  inserer(1,4,j1,tab);
  inserer(1,3,j2,tab);
  inserer(1,2,j1,tab);
  colonne_libre=statut(1,tab);
  afficher_mat(tab);
  printf("\n");
  printf("statut = %d\n",colonne_libre);
  (  colonne_libre  ? printf ("-->Reussi\n")  : printf("-->Raté\n") )  ;
  printf("\n");


  printf( "Fin du programme des test sur les fonctions du mode 1vs1 \n" ) ;



  free(j1);
  free(j2);
  return(0) ;
}
