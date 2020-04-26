#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Includes/strD.h"
#include "../Includes/1v1.h"

int
main()
{

  printf( "Debut du programme des test sur les fonctions du mode 1vs1 du jeu \n" ) ;

  joueur j1,j2;
  j1.couleur='R';
  j2.couleur='J';

  char tab[N][M];
  // on remplissage de la matrice
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      tab[i][j]='R';
      }
  }

  printf( "Test sur les fonctions de base \n\n" ) ;

  printf( "Test affichage de la matrice \n" ) ;
   afficher_mat(tab);
   printf( "\n");

  printf( "Test la fonction 'grille pleine' \n" ) ;
  (  grille_plein(tab) ? printf ("-->OK\n") : printf("-->KO\n") )  ;


//--------------TEST LIGNE-----------------------------------------------
  initMatrice(tab);
  inserer(1,6,j1,tab);
  inserer(2,6,j1,tab);
  inserer(3,6,j1,tab);
  inserer(4,6,j1,tab);


  printf( "Test affichage de la matrice \n" ) ;
   afficher_mat(tab);
   printf( "\n");

  printf( "Test la fonction 'gagnant_ligne' \n" ) ;
  (  gagnant_ligne(tab)  ? printf("-->OK\n") : printf ("-->KO\n") )  ;


  //--------------TEST COLONNE-----------------------------------------------
    initMatrice(tab);
    inserer(1,6,j1,tab);
    inserer(1,5,j1,tab);
    inserer(1,4,j1,tab);
    inserer(1,3,j1,tab);


    printf( "Test affichage de la matrice \n" ) ;
     afficher_mat(tab);
     printf( "\n");

    printf( "Test la fonction 'gagnant_colonne' \n" ) ;
    (  gagnant_colonne(tab) ? printf("-->OK\n") : printf ("-->KO\n") )  ;

  //--------------TEST DIAGONALE-----------------------------------------------
    initMatrice(tab);
    inserer(1,6,j1,tab);
    inserer(2,5,j1,tab);
    inserer(3,4,j1,tab);
    inserer(4,3,j1,tab);

    printf( "Test affichage de la matrice \n" ) ;
     afficher_mat(tab);
     printf( "\n");

    printf( "Test la fonction 'gagnant_diagonale' \n" ) ;
    (  gagnant_diagonale(tab)  ? printf("-->OK\n") : printf ("-->KO\n") )  ;





  //--------------TEST SUR LA FONCTION STATUT -----------------------------------------------

    initMatrice(tab);
    inserer(1,6,j1,tab);
    inserer(1,5,j2,tab);
    inserer(1,4,j1,tab);
    inserer(1,3,j2,tab);
    inserer(1,2,j1,tab);
    inserer(1,1,j2,tab);

    printf( "Test la fonction 'statut' qui doit retourner 0 (FAUX) \n" ) ;
    (  statut(1,tab)  ? printf ("-->KO\n")  : printf("-->OK\n") )  ;


    initMatrice(tab);
    inserer(1,6,j1,tab);
    inserer(1,5,j2,tab);
    inserer(1,4,j1,tab);
    inserer(1,3,j2,tab);
    inserer(1,2,j1,tab);


    printf( "Test la fonction 'statut' qui doit retourner la valeur de x (VRAI) \n" ) ;
    (  statut(1,tab)  ? printf ("-->OK\n")  : printf("-->KO\n") )  ;



  printf( "Fin du programme des test sur les fonctions du mode 1vs1 \n" ) ;

  return(0) ;
}
