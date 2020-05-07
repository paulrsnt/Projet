#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Includes/2v2.h"
#include "../Includes/strD.h"
#include "../Includes/parcours.h"

/**

* \file 2v2.c
* \brief Programme contenant les fonctions du mode 2v2 du jeu du puissance 4++
* \author Aaron Amani Oussama Belkadi Fatih Ufacik et Paul riga
* \version 1.0
* \date 5 mai 2020

*/


//
// Blocante = mur appeller B dans la grille
// Creuse = mur appeller C dans la grille
// Pleine = mur appeller P dans la grille
//


/**
 * \fn int grille_plein2v2(char mat[N][M])
 * \brief fonction qui retourne 1 si la grille est pleine, 0 si elle ne l'est pas
 *
 * \param mat la grille du jeu.
 *
 * \return int.
 *
 *\author Aaron Amani
*/
extern int grille_plein2v2(char mat[N][M]){

  for (int i = 1; i < (N-1); i++) {
    for (int y = 1; y < (M-1); y++) {
      if (mat[i][y]=='R'||mat[i][y]=='J'||mat[i][y]=='B');
      else{
        return 0;
      }
    }
  }
  return 1;
}

/**
 * \fn int statut2v2(int y, char mat[N][M],int pc)
 * \brief verifie le numero de colonne et retourne la ligne de disponible ou pas
 *
 * \param y numero de colonne.
 * \param mat la grille du jeu.
 * \param int p indice de la piece.
 *
 * \return int.
 *
 *\author Aaron Amani, Paul riga
*/

extern int statut2v2(int y, char mat[N][M],int pc){

  int x;

  /* for (x = N-1 ;(x < 0 || (mat[x][y]=='R'||mat[x][y]=='J' )); x--) ;  on arrive au bout tant que l'emplacement est pris on remonte */

  if (pc==1 || pc==2) { /* int bloquante */

    for (x = (N-2) ;( (mat[x][y]!=' ' ) && (x >= 0) )  ; x--) ;
  }

  else if (pc==3) { /* int pleine */

    for (x = 1 ; ( ((mat[x][y]!='B' )&&(mat[x][y]!='P' ))&&(x<N-2) )  ; x++);

    if ((mat[x][y]=='B')||(mat[x][y]=='P')) {
      x--;
    }
    if (mat[x][y]=='*'){
      return -1;
    }
  }

  return x ;

}

/**
 * \fn void initMatrice2v2(char mat[N][M])
 * \brief fonction qui initialise la matrice
 *
 * \param mat la grille du jeu.
 *
 * \author Fatih Ufacik
*/
extern void initMatrice2v2(char mat[N][M]){
/* fonction qui permet de initialiser la matrice */
	int i,j;

	for(i=0 ; i< N ; i++){
		for(j=0 ; j < M ; j++){


      if (i==0 || i==(N-1) || j==0 || j==(M-1) ) {
        mat[i][j]= '*';
      }
      else {
        mat[i][j] = ' ';
      }

		}
	}

}


/**
 * \fn void afficher_mat2v2(char mat[N][M])
 * \brief fonction qui affiche la matrice du jeu
 *
 * \param mat la grille du jeu.
 *
 * \author Oussama Belkadi
*/

extern void afficher_mat2v2(char mat[N][M]){
    int i, j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("| %c |", mat[i][j]);
        }
        printf("\n");
    }
}


/**
 * \fn void inserer2v2(int y, int x, joueur *t, char mat[N][M], char mat2[N][M] ,int pc)
 * \brief fonction qui permet a l'utilisateur d'inserer une piece
 *
 * \param y numero de la colonne
 * \param x numero de la ligne
 * \param t structure representant le joueur
 * \param mat la grille du jeu representant la couleur des pieces .
 * \param mat2 la grille du jeu representant le type de la pieces .
 * \param int p indice de la piece.
 *
 * \author Oussama Belkadi, Aaron Amani
*/

extern void inserer2v2(int y, int x, joueur *t, char mat[N][M], char mat2[N][M],int pc){
/* fonction qui permet de insérer un epièce dans la matrice */


  if (pc==1) {
    mat2[x][y]='B';
    mat[x][y]='B';
  }
  else if (pc==2 && t->couleur=='J') {
    mat2[x][y]='C';
    mat[x][y]='J';

  }
  else if (pc==3 && t->couleur=='J') {
    mat2[x][y]='P';
    mat[x][y]='J';
  }

  else if (pc==2 && t->couleur=='R') {
    mat2[x][y]='C';
    mat[x][y]='R';

  }

  else if (pc==3 && t->couleur=='R') {
    mat2[x][y]='P';
    mat[x][y]='R';
  }



}

/**
 * \fn int JouerNormal2v2(char mat[N][M], char mat2[N][M], joueur *j1, joueur *j2, joueur *j3, joueur *j4)
 * \brief fonction qui permet de jouer a 1vs1 en mode normal et retourne une lettre qui designe qui a gagné (r ou j)
 *
 * \param mat la grille du representant les couleurs des pices.
 * \param mat2 la grille du jeu representant les types des pieces.
 * \param j1 joueur 1.
 * \param j2 joueur 2.
 * \param j3 joueur 3.
 * \param j4 joueur 4.
 *
 * \return int
 * \author Oussama Belkadi, Aaron Amani
*/

extern int JouerNormal2v2(char mat[N][M],char mat2[N][M], joueur *j1, joueur *j2, joueur *j3, joueur *j4){

  char y_string[100];
  int y=-1;
  int rouge=0,jaune=0;
  int pc=0;


  initMatrice2v2(mat);
  initMatrice2v2(mat2);

  afficher_mat2v2(mat2);
  printf("\n");
  afficher_mat2v2(mat2);

  printf("\n\n");

  j1->couleur='R';
  j2->couleur='J';
  j3->couleur='R';
  j4->couleur='J';

   while(1){

    // tour du premier joueur de jouer

    do{

            printf("Joueur 1 :Choisissez type de piece  : 1 bloquante, 2 creuse, 3 pleine ):\n");
            scanf("%d",&pc);

                   /* verifie si le nombre entrée est bien un nombre entier et pas un nombre décimale */
         	   printf("Joueur 1 :Choisissez ou vous aller mettre votre piece (numero de colonne entre 1 et %d):\n",(M-2));
             scanf("%s",y_string);

             y = atoi(y_string);

             if(y == 0){
               printf("Erreur sur la collonne : %s  est un caractere ou une chaine de caractere donc c'est une colonne invalide veuillez saisir en entier !! \n\n", y_string);
             }
             else if((y<1) || (y>(M-2))){
               printf("Erreur sur le coordonnée de la colonne : %s vous avez selectionner une colonne en dehors de la grille du jeu !! \n\n", y_string);
             }
             else if (statut2v2(y,mat2,pc)==-1) {
             	  printf("Erreur sur les coordonnée des y : la colonne %d est rempli essayer une autre \n\n", y);
           	}


    }while ((y<1||y>(M-2)) || statut2v2(y,mat2,pc)==-1 || (pc<1||pc>3) );


    int x=statut2v2(y,mat,pc);
    inserer2v2(y,statut2v2(y,mat2,pc),j1,mat,mat2,pc);                          //on insere la int
    rouge=parcours(x,y,mat,j1);

    if (grille_plein2v2(mat)) {
      printf("LA GRILLE EST PLEINE : MATCH NULL \n");
      return(3);
    }

    system("clear");

    afficher_mat2v2(mat);
    printf("\n");
    afficher_mat2v2(mat2);

    printf("\n\n");

    if(rouge==0){

      // tour du deuxieme joueur de jouer
      y=0;

      do{

              printf("Joueur 2 :Choisissez type de piece  : 1 bloquante, 2 creuse, 3 pleine ):\n");
              scanf("%d",&pc);

                     /* verifie si le nombre entrée est bien un nombre entier et pas un nombre décimale */
           	   printf("Joueur 2 :Choisissez ou vous aller mettre votre pice (numero de colonne entre 1 et %d):\n",(M-2));
               scanf("%s",y_string);

               y = atoi(y_string);

               if(y == 0){
                 printf("Erreur sur la collonne : %s  est un caractere ou une chaine de caractere donc c'est une colonne invalide veuillez saisir en entier !! \n\n", y_string);
               }
               else if((y<1) || (y>(M-2))){
                 printf("Erreur sur le coordonnée de la colonne : %s vous avez selectionner une colonne en dehors de la grille du jeu !! \n\n", y_string);
               }
               else if (statut2v2(y,mat2,pc)==-1) {
               	  printf("Erreur sur les coordonnée des y : la colonne %d est rempli essayer une autre \n\n", y);
             	}


      }while ((y<1||y>(M-2)) || statut2v2(y,mat2,pc)==-1 || (pc<1||pc>3) );


      int x=statut2v2(y,mat,pc);
      inserer2v2(y,statut2v2(y,mat2,pc),j2,mat,mat2,pc);                          //on insere la int
      jaune=parcours(x,y,mat,j2);

      if (grille_plein2v2(mat)) {
        printf("LA GRILLE EST PLEINE : MATCH NULL \n");
        return(3);
      }

      system("clear");

      afficher_mat2v2(mat);
        printf("\n");
      afficher_mat2v2(mat2);
      printf("\n\n");
    }

    if(jaune==0 && rouge==0){

        // tour du deuxieme joueur de jouer
        y=0;

        do{

                printf("Joueur 3 :Choisissez type de piece  : 1 bloquante, 2 creuse, 3 pleine ):\n");
                scanf("%d",&pc);

                       /* verifie si le nombre entrée est bien un nombre entier et pas un nombre décimale */
             	   printf("Joueur 3 :Choisissez ou vous aller mettre votre piece (numero de colonne entre 1 et %d):\n",(M-2));
                 scanf("%s",y_string);

                 y = atoi(y_string);

                 if(y == 0){
                   printf("Erreur sur la collonne : %s  est un caractere ou une chaine de caractere donc c'est une colonne invalide veuillez saisir en entier !! \n\n", y_string);
                 }
                 else if((y<1) || (y>(M-2))){
                   printf("Erreur sur le coordonnée de la colonne : %s vous avez selectionner une colonne en dehors de la grille du jeu !! \n\n", y_string);
                 }
                 else if (statut2v2(y,mat2,pc)==-1) {
                 	  printf("Erreur sur les coordonnée des y : la colonne %d est rempli essayer une autre \n\n", y);
               	}


        }while ((y<1||y>(M-2)) || statut2v2(y,mat2,pc)==-1 || (pc<1||pc>3) );

        int x=statut2v2(y,mat,pc);
        inserer2v2(y,statut2v2(y,mat2,pc),j3,mat,mat2,pc);                          //on insere la int
        rouge=parcours(x,y,mat,j3);

        if (grille_plein2v2(mat)) {
          printf("LA GRILLE EST PLEINE : MATCH NULL \n");
          return(3);
        }

        system("clear");

        afficher_mat2v2(mat);
          printf("\n");
        afficher_mat2v2(mat2);
        printf("\n\n");} // on passe au tour suivant si et selement si le joueur 1 n'a pas gagner

    if(jaune==0 && rouge==0){

        // tour du deuxieme joueur de jouer
        y=0;

        do{

                printf("Joueur 4 :Choisissez type de piece  : 1 bloquante, 2 creuse, 3 pleine ):\n");
                scanf("%d",&pc);

                       /* verifie si le nombre entrée est bien un nombre entier et pas un nombre décimale */
             	   printf("Joueur 4 :Choisissez ou vous aller mettre votre piece (numero de colonne entre 1 et %d):\n",(M-2));
                 scanf("%s",y_string);

                 y = atoi(y_string);

                 if(y == 0){
                   printf("Erreur sur la collonne : %s  est un caractere ou une chaine de caractere donc c'est une colonne invalide veuillez saisir en entier !! \n\n", y_string);
                 }
                 else if((y<1) || (y>(M-2))){
                   printf("Erreur sur le coordonnée de la colonne : %s vous avez selectionner une colonne en dehors de la grille du jeu !! \n\n", y_string);
                 }
                 else if (statut2v2(y,mat2,pc)==-1) {
                 	  printf("Erreur sur les coordonnée des y : la colonne %d est rempli essayer une autre \n\n", y);
               	}


        }while ((y<1||y>(M-2)) || statut2v2(y,mat2,pc)==-1 || (pc<1||pc>3) );


        int x=statut2v2(y,mat,pc);
        inserer2v2(y,statut2v2(y,mat2,pc),j4,mat,mat2,pc);                          //on insere la int
        jaune=parcours(x,y,mat,j4);

        if (grille_plein2v2(mat)) {
          printf("LA GRILLE EST PLEINE : MATCH NULL \n");
          return(3);
        }

        system("clear");

        afficher_mat2v2(mat);
          printf("\n");
        afficher_mat2v2(mat2);
        printf("\n\n");} // on passe au tour suivant si et selement si le joueur 1 n'a pas gagner


   // tant qu'il n'y a pas de gangnant on continue de jouer

    if(rouge==1){

      printf("LES ROUGES ONT GAGNÉS !! \n");
      return(1);
    }
    else if(jaune==1){

      printf("LES JAUNES ONT GAGNÉS !! \n");
      return(2);
    }
}
return(0);
}
