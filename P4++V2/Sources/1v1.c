#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Includes/strD.h"
#include "../Includes/1v1.h"
#include "../Includes/parcours.h"

/**

* \file 1v1.c
* \brief Programme regroupant les fonctions du mode 1v1 du jeu du puissance 4++
* \author Aaron Amani Oussama Belkadi Fatih Ufacik et Paul riga
* \version 2.0
* \date 5 mai 2020

*/


/**
 * \fn int grille_plein(char mat[N][M])
 * \brief fonction qui retourne 1 si la grille est pleine, 0 si elle ne l'est pas
 *
 * \param mat la grille du jeu.
 *
 * \return int.
 *
 *\author Aaron Amani
 *
*/


 int grille_plein(char mat[N][M]){

  for (int i = 1; i < (N-1); i++) {
    for (int y = 1; y < (M-1); y++) {
      if ((mat[i][y]=='R')||(mat[i][y]=='J'));
      else{
        return 0;
      }
    }
  }
  return 1;
}


/**
 * \fn int statut(int y, char mat[N][M])
 * \brief verifie le numero de colonne et retourne la ligne de disponible ou pas
 *
 * \param y numero de colonne.
 * \param mat la grille du jeu.
 *
 * \return int.
 *
 *\author Aaron Amani, Paul Riga
*/


 int statut(int y, char mat[N][M]){
  int x;

  for (x = N-2 ;(x < 0 || (mat[x][y]=='R'||mat[x][y]=='J' )); x--) ; /* on arrive au bout tant que l'emplacement est pris on remonte */


if(mat[x][y]=='*'){
	return x=0;

}

    return x ;

}

/**
 * \fn void initMatrice(char mat[N][M])
 * \brief fonction qui initialise la matrice
 *
 * \param mat la grille du jeu.
 *
 *
 *\author Fatih Ufacik
 *
*/

 void initMatrice(char mat[N][M]){
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
 * \fn void afficher_mat(char mat[N][M])
 * \brief fonction qui affiche la matrice du jeu
 *
 * \param mat la grille du jeu.
 * \author Oussama Belkadi
 *
*/
 void afficher_mat(char mat[N][M]){
    int i, j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("| %c |", mat[i][j]);
        }
        printf("\n");
    }
}


/**
 * \fn void inserer(int y, int x, joueur *t, char mat[N][M])
 * \brief fonction qui permet a l'utilisateur d'inserer une piece
 *
 * \param y numero de la colonne
 * \param x numero de la ligne
 * \param t structure representant le joueur
 * \param mat la grille du jeu.
 *
 *\author Oussama Belkadi
*/
 void inserer(int y, int x, joueur *t, char mat[N][M]){

  if (t->couleur=='R') {
    mat[x][y]='R';
  }
  else if (t->couleur=='J') {
    mat[x][y]='J';
  }

}


/**
 * \fn void JouerNormal1vs1(char mat[N][M], joueur *j1, joueur *j2)
 * \brief fonction qui permet de jouer a 1vs1 en mode normal et retourne un chiffre qui designe qui a gagné (1 pour les rouges ou 2 pour les jaunes)
 *
 * \param mat la grille du jeu.
 * \param j2 joueur 2.
 * \param j1 joueur 1.
 *
 * \return int
 *
 *\author Aaron Amani Fatih Ufacik
*/

 int JouerNormal1vs1(char mat[N][M], joueur *j1, joueur *j2){

j1->couleur='R';
j2->couleur='J';

char y_string[100];
int y=-1;
int rouge=0,jaune=0;

initMatrice(mat);
afficher_mat(mat);

printf("\n\n");

 while(1){

  // tour du premier joueur *de jouer

  do{
	               /* verifie si le nombre entrée est bien un nombre entier et pas un nombre décimale */
       	   printf("joueur 1 :Choisissez ou vous aller mettre votre piece (numero de colonne entre 1 et %d):\n",(M-2));
           scanf("%s",y_string);
           y = atoi(y_string);
           if(y == 0){
             printf("Erreur sur la collonne : %s  est une lettre donc c'est une colonne invalide veuillez saisir en entier !! \n\n", y_string);
           }
           else if((y<1) || (y>(M-2))){
             printf("Erreur sur le coordonnée de la colonne : %s vous avez selectionner une colonne en dehors de la grille du jeu !! \n\n", y_string);
           }
           else if (statut(y,mat)==0) {
             printf("Erreur sur la colonne : la colonne %d est rempli essayer une autre !! \n\n", y);
           }
  }while ((y<1||y>(M-2)) || statut(y,mat)==0);


  int x=statut(y,mat);
  inserer(y,x,j1,mat);
  rouge=parcours(x,y,mat,j1);

  if (grille_plein(mat)) {
    printf("La grille est pleine match null \n");
    return(3);
  }

  system("clear");
  afficher_mat(mat);

  printf("\n\n");



  if(rouge==0){                              // on passe au tour suivant si et selement si le joueur *1 n'a pas gagner

    // tour du deuxieme joueur *de jouer
    y=0;

    do{
	            /* verifie si le nombre entrée est bien un nombre entier et pas un nombre décimale */
         printf("Joueur 2 : Choisissez ou vous aller mettre votre piece (numero de colonne entre 1 et %d):\n",(M-2));    //rajouter cas y n'est pas un chiffre
         scanf("%s",y_string);
             y = atoi(y_string);
             if(y == 0){
               printf("Erreur sur la collonne : %s  est une lettre donc c'est une colonne invalide veuillez saisir en entier !! \n\n", y_string);
             }
             else if((y<1) || (y>(M-2))){
               printf("Erreur sur le coordonnée de la colonne : %s vous avez selectionner une colonne en dehors de la grille du jeu !! \n\n", y_string);
             }
             else if (statut(y,mat)==0) {
               printf("Erreur sur la colonne : la colonne %d est rempli essayer une autre !! \n\n", y);
             }

    }while ((y<1||y>(M-2)) || statut(y,mat)==0);

    int x=statut(y,mat);
    inserer(y,x,j2,mat);
    jaune=parcours(x,y,mat,j2);

    if (grille_plein(mat)) {
      printf("LA GRILLE EST PLEINE : MATCH NULL \n");
      return(3);
    }

    system("clear");

    afficher_mat(mat);
    printf("\n\n");



  }

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
