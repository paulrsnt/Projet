#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Includes/strD.h"
#include "../Includes/1v1.h"
#include "../Includes/parcours.h"



/**
* \file Test1v1.c
* \brief Programme qui test les parties du code du mode 1v1 du jeu du puissance 4++
* \author Aaron Amani
* \version 2.0
* \date 5 mai 2020
*/


int
main()
{

  printf( "Debut du programme des test sur les fonctions du mode 1vs1 du jeu \n" ) ;

// arranger

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

  char tab1[N][M];
  char tab2[N][M];
  char tab3[N][M];
  char tab4[N][M];
  char tab5[N][M];
  char tab6[N][M];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      tab1[i][j]='R';
      }
  }

  // agir

  initMatrice(tab2);
  inserer(1,6,j1,tab2);
  inserer(2,6,j1,tab2);
  inserer(3,6,j1,tab2);
  inserer(4,6,j1,tab2);

  initMatrice(tab3);
  inserer(1,6,j1,tab3);
  inserer(1,5,j1,tab3);
  inserer(1,4,j1,tab3);
  inserer(1,3,j1,tab3);

  initMatrice(tab4);
  inserer(1,6,j1,tab4);
  inserer(2,5,j1,tab4);
  inserer(3,4,j1,tab4);
  inserer(4,3,j1,tab4);

  initMatrice(tab5);
  inserer(1,6,j1,tab5);
  inserer(1,5,j2,tab5);
  inserer(1,4,j1,tab5);
  inserer(1,3,j2,tab5);
  inserer(1,2,j1,tab5);
  inserer(1,1,j2,tab5);

  initMatrice(tab6);
  inserer(1,6,j1,tab6);
  inserer(1,5,j2,tab6);
  inserer(1,4,j1,tab6);
  inserer(1,3,j2,tab6);
  inserer(1,2,j1,tab6);

  grille_remplie=grille_plein(tab1);

  en_ligne=parcours(6,4,tab2,j1);

  en_colonne=parcours(3,1,tab3,j1);

  en_diagonale=parcours(3,4,tab4,j1);

  colonne_rempli=statut(1,tab5);

  colonne_libre=statut(1,tab6);


// audither

  printf( "Test la fonction 'grille pleine' \n" ) ;
  (  grille_remplie ? printf ("-->Reussi\n") : printf("-->Raté\n") )  ;


//--------------TEST LIGNE-----------------------------------------------


  printf( "Test la fonction 'parcours' (4 pions de même couleur en ligne) \n" ) ;
  (  en_ligne  ? printf("-->Reussi\n") : printf ("-->Raté\n") )  ;


  //--------------TEST COLONNE-----------------------------------------------

    printf( "Test la fonction 'parcours' (4 pions de même couleur en colonne) \n" ) ;
    (  en_colonne ? printf("-->Reussi\n") : printf ("-->Raté\n") )  ;

  //--------------TEST DIAGONALE-----------------------------------------------


    printf( "Test la fonction 'parcours' (4 pions de même couleur en diagonale) \n" ) ;
    (  en_diagonale  ? printf("-->Reussi\n") : printf ("-->Raté\n") )  ;


  //--------------TEST SUR LA FONCTION STATUT -----------------------------------------------


    printf( "Test la fonction 'statut' qui doit retourner 0 (FAUX) \n" ) ;
    (  (colonne_rempli==0) ? printf("-->Reussi\n") :  printf("-->Raté\n") )  ;



    printf( "Test la fonction 'statut' qui doit retourner la valeur de x (VRAI) \n" ) ;
    (  colonne_libre  ? printf ("-->Reussi\n")  : printf("-->Raté\n") )  ;



  printf( "Fin du programme des test sur les fonctions du mode 1vs1 \n" ) ;



  free(j1);
  free(j2);
  return(0) ;
}
