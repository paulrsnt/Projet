#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Includes/strD.h"
#include "../Includes/2v2.h"

int
main()
{

  printf( "Debut du programme des test sur les fonctions du mode 1vs1 du jeu \n" ) ;


  joueur j1,j2;
  j1.couleur='R';
  j2.couleur='J';

  char mat[N][M];
  char mat2[N][M];

  // on remplissage de la matrice
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      mat[i][j]='R';
      }
  }

  printf( "Test sur les fonctions de base \n\n" ) ;

  printf( "Test affichage de la matrice pleine \n" ) ;
   afficher_mat2v2(mat);
   printf( "\n");

  printf( "Test la fonction 'grille pleine' \n" ) ;
  (  grille_plein2v2(mat) ? printf ("-->OK\n") : printf("-->KO\n") )  ;


//--------------TEST LIGNE-----------------------------------------------
  initMatrice2v2(mat); initMatrice2v2(mat2);
  inserer2v2(1,6,j1,mat,mat2,2);
  inserer2v2(2,6,j1,mat,mat2,2);
  inserer2v2(3,6,j1,mat,mat2,2);
  inserer2v2(4,6,j1,mat,mat2,2);


  printf( "Test affichage de la matrice \n" ) ;
   afficher_mat2v2(mat); afficher_mat2v2(mat2);
   printf( "\n");

  printf( "Test la fonction 'gagnant_ligne2v2' \n" ) ;
  (  gagnant_ligne2v2(mat)  ? printf("-->OK\n") : printf ("-->KO\n") )  ;


  //--------------TEST COLONNE-----------------------------------------------
    initMatrice2v2(mat); initMatrice2v2(mat2);
    inserer2v2(1,6,j1,mat,mat2,2);
    inserer2v2(1,5,j1,mat,mat2,2);
    inserer2v2(1,4,j1,mat,mat2,2);
    inserer2v2(1,3,j1,mat,mat2,2);


    printf( "Test affichage de la matrice \n" ) ;
     afficher_mat2v2(mat); afficher_mat2v2(mat2);
     printf( "\n");

    printf( "Test la fonction 'gagnant_colonne2v2' \n" ) ;
    (  gagnant_colonne2v2(mat) ? printf("-->OK\n") : printf ("-->KO\n") )  ;

  //--------------TEST DIAGONALE-----------------------------------------------
    initMatrice2v2(mat); initMatrice2v2(mat2);
    inserer2v2(1,6,j1,mat,mat2,2);
    inserer2v2(2,5,j1,mat,mat2,2);
    inserer2v2(3,4,j1,mat,mat2,2);
    inserer2v2(4,3,j1,mat,mat2,2);

    printf( "Test affichage de la matrice \n" ) ;
     afficher_mat2v2(mat); afficher_mat2v2(mat2);
     printf( "\n");

    printf( "Test la fonction 'gagnant_diagonale2v2' \n" ) ;
    (  gagnant_diagonale2v2(mat)  ? printf("-->OK\n") : printf ("-->KO\n") )  ;





  //--------------TEST SUR LA FONCTION statut2v2 -----------------------------------------------

    initMatrice2v2(mat); initMatrice2v2(mat2);
    inserer2v2(1,6,j1,mat,mat2,2);
    inserer2v2(1,5,j2,mat,mat2,2);
    inserer2v2(1,4,j1,mat,mat2,2);
    inserer2v2(1,3,j2,mat,mat2,2);
    inserer2v2(1,2,j1,mat,mat2,2);
    inserer2v2(1,1,j2,mat,mat2,2);
    afficher_mat2v2(mat); afficher_mat2v2(mat2);

    printf( "Test la fonction 'statut2v2' qui doit retourner -1 si on veut inserer dans la premiere colonne(FAUX)  \n" ) ;
    (  (statut2v2(1,mat2,2)==-1)  ? printf ("-->OK\n")  : printf("-->KO\n") )  ;

    initMatrice2v2(mat); initMatrice2v2(mat2);
    inserer2v2(1,6,j1,mat,mat2,2);
    inserer2v2(1,5,j2,mat,mat2,2);
    inserer2v2(1,4,j1,mat,mat2,2);
    inserer2v2(1,3,j2,mat,mat2,2);
    inserer2v2(1,2,j1,mat,mat2,2);
    afficher_mat2v2(mat); afficher_mat2v2(mat2);


    printf( "Test la fonction 'statut2v2' qui doit retourner la valeur de x si on veut inserer dans la premiere colonne (VRAI) \n" ) ;
    (  (statut2v2(1,mat2,2)!=-1)  ? printf ("-->OK\n")  : printf("-->KO\n") )  ;

/*------------------TEST sur les types de pieces --------------------*/

printf( "Test ( écrasement de ma pièce ) la fonction 'statut2v2' doit retourner la valeur de 6 si on veut inserer dans la premiere colonne avec une pleine sachant qu'il y a que des creuse \n" ) ;
(  (statut2v2(1,mat2,3)==6)  ? printf ("-->OK\n")  : printf("-->KO\n") )  ;



  printf( "Fin du programme des test sur les fonctions du mode 1vs1 \n" ) ;

  return(0) ;
}
