#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Includes/strD.h"
#include "../Includes/1v1.h"
#include "../Includes/1vIA.h"
#include "../Includes/parcours.h"



/**
* \file Test1vIA.c
* \brief Programme qui teste les fonctions du mode 1vIA du jeu du puissance 4++
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


  printf( "Test la fonction 'insererMode1vsIA': qui doit inserer dans la bonne colonne (exemmple colonne: 1 ligne: 1) \n" ) ;
  initMatrice(tab);
  insererMode1vsIA(1,6,j1,tab);
  afficher_mat(tab);
  printf("\n");
  printf("tab[6][1] = %c \n\n",tab[6][1]);
  (  tab[6][1]=='R'  ? printf ("-->Reussi\n")  : printf("-->Raté\n") )  ;
  printf("\n");



  printf( "Test la fonction 'parcours' : quand on met 4 pions de même couleur en ligne \n" ) ;
  initMatrice(tab);
  insererMode1vsIA(1,6,j1,tab);
  insererMode1vsIA(2,6,j1,tab);
  insererMode1vsIA(3,6,j1,tab);
  insererMode1vsIA(4,6,j1,tab);
  en_ligne=parcours(6,4,tab,j1);
  afficher_mat(tab);
  printf("\n");
  printf("parcours = %d\n",en_ligne);
  (  en_ligne  ? printf("-->Reussi\n") : printf ("-->Raté\n") )  ;
  printf("\n");



  printf( "Test la fonction 'parcours' : quand on met 4 pions de même couleur en colonne \n" ) ;
  initMatrice(tab);
  insererMode1vsIA(1,6,j1,tab);
  insererMode1vsIA(1,5,j1,tab);
  insererMode1vsIA(1,4,j1,tab);
  insererMode1vsIA(1,3,j1,tab);
  en_colonne=parcours(3,1,tab,j1);
  afficher_mat(tab);
  printf("\n");
  printf("parcours = %d\n",en_colonne);
  (  en_colonne ? printf("-->Reussi\n") : printf ("-->Raté\n") )  ;
  printf("\n");


  printf( "Test la fonction 'parcours' : quand on met 4 pions de même couleur en diagonale \n" ) ;
  initMatrice(tab);
  insererMode1vsIA(1,6,j1,tab);
  insererMode1vsIA(2,5,j1,tab);
  insererMode1vsIA(3,4,j1,tab);
  insererMode1vsIA(4,3,j1,tab);
  en_diagonale=parcours(3,4,tab,j1);
  afficher_mat(tab);
  printf("\n");
  printf("parcours = %d\n",en_diagonale);
  (  en_diagonale  ? printf("-->Reussi\n") : printf ("-->Raté\n") )  ;
  printf("\n");



  printf( "Test la fonction 'statut' qui doit retourner 0 (FAUX) parce que la colonne n'est pas disponible \n" ) ;
  initMatrice(tab);
  insererMode1vsIA(1,6,j1,tab);
  insererMode1vsIA(1,5,ia,tab);
  insererMode1vsIA(1,4,j1,tab);
  insererMode1vsIA(1,3,ia,tab);
  insererMode1vsIA(1,2,j1,tab);
  insererMode1vsIA(1,1,ia,tab);
  colonne_rempli=statut(1,tab);
  afficher_mat(tab);
  printf("\n");
  printf("statut = %d\n",colonne_rempli);
  (  (colonne_rempli==0) ? printf("-->Reussi\n") :  printf("-->Raté\n") )  ;
  printf("\n");


  printf( "Test la fonction 'statut' qui doit retourner la valeur de x (VRAI) donc le numero de la ligne quand la colonne est disponible \n" ) ;
  initMatrice(tab);
  insererMode1vsIA(1,6,j1,tab);
  insererMode1vsIA(1,5,ia,tab);
  insererMode1vsIA(1,4,j1,tab);
  insererMode1vsIA(1,3,ia,tab);
  insererMode1vsIA(1,2,j1,tab);
  colonne_libre=statut(1,tab);
  afficher_mat(tab);
  printf("\n");
  printf("statut = %d\n",colonne_libre);
  (  colonne_libre  ? printf ("-->Reussi\n")  : printf("-->Raté\n") )  ;
  printf("\n");



  printf( "Test la fonction 'insererIA'  qui doit ajouter des coordonnées dans la structure joueur de l'ia afin d'ajouter un pion dans une matrice vide \n\n" ) ;
  initMatrice(tab);
  insererIA(ia,tab);
  cordX=ia->x;
  cordY=ia->y;
  afficher_mat(tab);
  printf("\n");
  printf("CordX = %d &&  CordY = %d\n\n",cordX,cordY );
  (  (cordX<N-1 && cordX>0) && (cordY<M-1 && cordY>0)  ? printf ("-->Reussi\n")  : printf("-->Raté\n") )  ;
  printf("\n");



  printf( "Test la fonction 'insererIA'  qui doit ajouter des coordonnées dans la structure joueur de l'ia afin d'ajouter un pion dans une matrice avec un poin adverse \n\n" ) ;
  initMatrice(tab);
  insererMode1vsIA(1,6,j1,tab);
  insererIA(ia,tab);
  cordX=ia->x;
  cordY=ia->y;
  afficher_mat(tab);
  printf("\n");
  printf("CordX = %d &&  CordY = %d\n\n",cordX,cordY );
  (  (cordX<N-1 && cordX>0) && (cordY<M-1 && cordY>0)  ? printf ("-->Reussi\n")  : printf("-->Raté\n") )  ;
  printf("\n");



  printf( "Test la fonction 'insererIA'  qui doit ajouter des coordonnées dans la structure joueur de l'ia afin d'ajouter un pion dans une matrice avec qu'une seule seule place de libre \n\n" ) ;
  initMatrice(tab);
  for (int i = 1; i < N-1; i++) {
    for (int j = 1; j < M-1; j++) {

        if ((i==1) && (j==6));
        else{
          tab[i][j]='R';
        }

      }
  }
  insererIA(ia,tab);
  afficher_mat(tab);
  printf("\n");
  printf("CordX = %d &&  CordY = %d\n\n",cordX,cordY );
  (  (cordX<N-1 && cordX>0) && (cordY<M-1 && cordY>0)  ? printf ("-->Reussi\n")  : printf("-->Raté\n") )  ;
  printf("\n");


  printf( "Test la fonction 'insererIA'(DEFENSE): l'ia doit se defendre en bloquant le joueur qui risque de gagner (en ligne, en colonne ou en diagonale) \n" ) ;
  initMatrice(tab);
  insererMode1vsIA(1,6,j1,tab);
  insererMode1vsIA(1,5,j1,tab);
  insererMode1vsIA(1,4,j1,tab);
  insererIA(ia,tab);
  afficher_mat(tab);
  printf("\n");
  printf("tab[3][1] = %c \n\n",tab[3][1]);
  (  tab[3][1]=='J'  ? printf ("-->Reussi\n")  : printf("-->Raté\n") )  ;
  printf("\n");


  initMatrice(tab);
  insererMode1vsIA(1,6,j1,tab);
  insererMode1vsIA(2,6,j1,tab);
  insererMode1vsIA(3,6,j1,tab);
  insererIA(ia,tab);
  afficher_mat(tab);
  printf("\n");
  printf("tab[6][4] = %c \n\n",tab[6][4]);
  (  tab[6][4]=='J'  ? printf ("-->Reussi\n")  : printf("-->Raté\n") )  ;
  printf("\n");


  initMatrice(tab);
  insererMode1vsIA(1,6,j1,tab);
  tab[6][2]='J';
  insererMode1vsIA(3,6,j1,tab);
  tab[6][4]='J';
  insererMode1vsIA(4,5,j1,tab);
  tab[4][4]='J';
  insererMode1vsIA(2,5,j1,tab);
  tab[5][3]='J';
  insererMode1vsIA(3,4,j1,tab);

  insererIA(ia,tab);
  afficher_mat(tab);
  printf("\n");
  printf("tab[3][4] = %c \n\n",tab[3][4]);
  (  tab[3][4]=='J'  ? printf ("-->Reussi\n")  : printf("-->Raté\n") )  ;
  printf("\n");


  printf( "Test la fonction 'insererIA'(ATTAQUE): l'ia doit attaquer quand il peut gagner contre le joueur adverse (en ligne, en colonne ou en diagonale) \n" ) ;
  initMatrice(tab);
  tab[6][1]='J';
  tab[6][2]='J';
  tab[6][3]='J';
  insererIA(ia,tab);
  afficher_mat(tab);
  printf("\n");
  printf("tab[6][4] = %c \n\n",tab[6][4]);
  (  tab[6][4]=='J'  ? printf ("-->Reussi\n")  : printf("-->Raté\n") )  ;
  printf("\n");


  initMatrice(tab);
  tab[6][1]='J';
  tab[5][1]='J';
  tab[4][1]='J';
  insererIA(ia,tab);
  afficher_mat(tab);
  printf("\n");
  printf("tab[3][1] = %c \n\n",tab[3][1]);
  (  tab[3][1]=='J'  ? printf ("-->Reussi\n")  : printf("-->Raté\n") )  ;
  printf("\n");


  initMatrice(tab);

  tab[6][1]='J';
  insererMode1vsIA(2,6,j1,tab);
  tab[6][3]='J';
  insererMode1vsIA(4,6,j1,tab);
  tab[4][3]='J';
  insererMode1vsIA(4,4,j1,tab);
  tab[5][2]='J';
  insererMode1vsIA(3,5,j1,tab);
  tab[4][4]='J';
  insererMode1vsIA(4,5,j1,tab);

  insererIA(ia,tab);
  afficher_mat(tab);
  printf("\n");
  printf("tab[3][4] = %c \n\n",tab[3][4]);
  (  tab[3][4]=='J'  ? printf ("-->Reussi\n")  : printf("-->Raté\n") )  ;
  printf("\n");



  printf( "Fin du programme des test sur les fonctions du mode 1vsIA \n" ) ;



  free(j1);
  free(ia);
  return(0) ;
}
