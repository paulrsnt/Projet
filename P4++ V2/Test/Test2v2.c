#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Includes/strD.h"
#include "../Includes/2v2.h"
#include "../Includes/parcours.h"



/**
* \file Test2v2.c
* \brief Programme qui test les parties du code du mode 2v2 du jeu du puissance 4++
* \author Aaron Amani
* \version 2.0
* \date 5 mai 2020
*/


int
main()
{

  printf( "Debut du programme des test sur les fonctions du mode 2vs2 du jeu \n" ) ;

// arranger

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

  char tab1[N][M];
  char tab2[N][M];
  char tab3[N][M];
  char tab4[N][M];
  char tab5[N][M];
  char tab6[N][M];

  char grille2[N][M];
  char grille3[N][M];
  char grille4[N][M];
  char grille5[N][M];
  char grille6[N][M];

  // agir

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      tab1[i][j]='R';
      }
  }

  initMatrice2v2(tab2);
  initMatrice2v2(grille2);
  inserer2v2(1,6,j1,tab2,grille2,2);
  inserer2v2(2,6,j1,tab2,grille2,2);
  inserer2v2(3,6,j1,tab2,grille2,2);
  inserer2v2(4,6,j1,tab2,grille2,2);

  initMatrice2v2(tab3);
  initMatrice2v2(grille3);
  inserer2v2(1,6,j1,tab3,grille3,2);
  inserer2v2(1,5,j1,tab3,grille3,2);
  inserer2v2(1,4,j1,tab3,grille3,2);
  inserer2v2(1,3,j1,tab3,grille3,2);

  initMatrice2v2(tab4);
  initMatrice2v2(grille4);
  inserer2v2(1,6,j1,tab4,grille4,2);
  inserer2v2(2,5,j1,tab4,grille4,2);
  inserer2v2(3,4,j1,tab4,grille4,2);
  inserer2v2(4,3,j1,tab4,grille4,2);

  initMatrice2v2(tab5);
  initMatrice2v2(grille5);

  inserer2v2(1,6,j1,tab5,grille5,2);
  inserer2v2(1,5,j2,tab5,grille5,2);
  inserer2v2(1,4,j1,tab5,grille5,2);
  inserer2v2(1,3,j2,tab5,grille5,2);
  inserer2v2(1,2,j1,tab5,grille5,2);
  inserer2v2(1,1,j2,tab5,grille5,2);

  initMatrice2v2(tab6);
  initMatrice2v2(grille6);
  inserer2v2(1,6,j1,tab6,grille6,2);
  inserer2v2(1,5,j2,tab6,grille6,2);
  inserer2v2(1,4,j1,tab6,grille6,2);
  inserer2v2(1,3,j2,tab6,grille6,2);
  inserer2v2(1,2,j1,tab6,grille6,2);



  grille_remplie=grille_plein2v2(tab1);

  en_ligne=parcours(6,4,tab2,j1);

  en_colonne=parcours(3,1,tab3,j1);

  en_diagonale=parcours(3,4,tab4,j1);

  colonne_rempli=statut2v2(1,tab5,2);

  colonne_libre=statut2v2(1,tab6,2);


// audither

  printf( "Test la fonction 'grille pleine 2v2' \n" ) ;
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
  (  (colonne_rempli==-1) ? printf("-->Reussi\n") :  printf("-->Raté\n") )  ;



    printf( "Test la fonction 'statut 2v2' qui doit retourner la valeur de x (VRAI) \n" ) ;
    (  colonne_libre  ? printf ("-->Reussi\n")  : printf("-->Raté\n") )  ;



  printf( "Fin du programme des test sur les fonctions du mode 2vs2 \n" ) ;



  free(j1);
  free(j2);
  free(j3);
  free(j4);
  return(0) ;
}
