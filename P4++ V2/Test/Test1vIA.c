#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Includes/strD.h"
#include "../Includes/1v1.h"
#include "../Includes/1vIA.h"
#include "../Includes/parcours.h"



/**
* \file Test2v2.c
* \brief Programme qui test les parties du code du mode 1vIA du jeu du puissance 4++
* \author Aaron Amani
* \version 2.0
* \date 5 mai 2020
*/



int
main()
{

  printf( "Debut du programme des test sur les fonctions du mode 1vsIA du jeu \n" ) ;

// arranger

  joueur *j1,*ia;
  j1=malloc(sizeof(joueur));
  ia=malloc(sizeof(joueur));
  j1->couleur='R';
  ia->couleur='J';
  ia->x=0;
  ia->y=0;
  int grille_remplie=0;
  int en_ligne=0;
  int en_colonne=0;
  int en_diagonale=0;
  int colonne_rempli;
  int colonne_libre=0;
  int cordX=0;
  int cordY=0;
  int cordX2=0;
  int cordY2=0;
  int cordX3=0;
  int cordY3=0;

  char tab1[N][M];
  char tab2[N][M];
  char tab3[N][M];
  char tab4[N][M];
  char tab5[N][M];
  char tab6[N][M];
  char tab7[N][M];
  char tab8[N][M];
  char tab9[N][M];

  // agir

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      tab1[i][j]='R';
      }
  }


  initMatrice(tab2);
  insererMode1vsIA(1,6,j1,tab2);
  insererMode1vsIA(2,6,j1,tab2);
  insererMode1vsIA(3,6,j1,tab2);
  insererMode1vsIA(4,6,j1,tab2);

  initMatrice(tab3);
  insererMode1vsIA(1,6,j1,tab3);
  insererMode1vsIA(1,5,j1,tab3);
  insererMode1vsIA(1,4,j1,tab3);
  insererMode1vsIA(1,3,j1,tab3);

  initMatrice(tab4);
  insererMode1vsIA(1,6,j1,tab4);
  insererMode1vsIA(2,5,j1,tab4);
  insererMode1vsIA(3,4,j1,tab4);
  insererMode1vsIA(4,3,j1,tab4);

  initMatrice(tab5);
  insererMode1vsIA(1,6,j1,tab5);
  insererMode1vsIA(1,5,ia,tab5);
  insererMode1vsIA(1,4,j1,tab5);
  insererMode1vsIA(1,3,ia,tab5);
  insererMode1vsIA(1,2,j1,tab5);
  insererMode1vsIA(1,1,ia,tab5);

  initMatrice(tab6);
  insererMode1vsIA(1,6,j1,tab6);
  insererMode1vsIA(1,5,ia,tab6);
  insererMode1vsIA(1,4,j1,tab6);
  insererMode1vsIA(1,3,ia,tab6);
  insererMode1vsIA(1,2,j1,tab6);

  initMatrice(tab7);
  insererIA(ia,tab7);

  cordX=ia->x;
  cordY=ia->y;

  initMatrice(tab8);
  insererMode1vsIA(1,6,j1,tab8);
  insererIA(ia,tab8);

  cordX2=ia->x;
  cordY2=ia->y;

  initMatrice(tab9);
  for (int i = 1; i < N-1; i++) {
    for (int j = 1; j < M-1; j++) {

        if ((i==1) && (j==6));
        else{
          tab9[i][j]='R';
        }

      }
  }
  insererIA(ia,tab9);

  cordX3=ia->x;
  cordY3=ia->y;

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

    printf( "Test la fonction 'insererIA'  qui doit ajouter des coordonnées valide (dans la matrice) dans la structure joueur de l'ia \n\n" ) ;





    printf( "Dans une matrice vide \n\n" ) ;
    afficher_mat(tab7);
    printf("CordX = %d &&  CordY = %d\n\n",cordX,cordY );
    (  (cordX<N-1 && cordX>0) && (cordY<M-1 && cordY>0)  ? printf ("-->Reussi\n")  : printf("-->Raté\n") )  ;

    printf( "Dans une matrice avec un poin adverse \n\n" ) ;
    afficher_mat(tab8);
    printf("CordX2 = %d &&  CordY2 = %d\n\n",cordX2,cordY2 );
    (  (cordX2<N-1 && cordX2>0) && (cordY2<M-1 && cordY2>0)  ? printf ("-->Reussi\n")  : printf("-->Raté\n") )  ;


    printf( "Dans une matrice avec qu'une seule seule place de libre \n\n" ) ;
    afficher_mat(tab9);
    printf("CordX3 = %d &&  CordY3 = %d\n\n",cordX3,cordY3 );
    (  (cordX3<N-1 && cordX3>0) && (cordY3<M-1 && cordY3>0)  ? printf ("-->Reussi\n")  : printf("-->Raté\n") )  ;


  printf( "Fin du programme des test sur les fonctions du mode 1vsIA \n" ) ;



  free(j1);
  free(ia);
  return(0) ;
}
