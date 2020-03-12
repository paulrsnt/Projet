#include <stdio.h>
#include <stdlib.h>
#include "modeNormal.h"
#include "structD.h"

/**

* \file modeNormal1vs1.c
* \brief Programme la fonction du jeu normal 1vs1 en local du puissance 4++
* \author Aaron Amani Oussama Belkadi Fathi et Paul riga
* \version 1.0
* \date 17 fevrier 2020

*/

/**
 * \fn void JouerNormal1vs1(char mat[N][M], joueur j1, joueur j2)
 * \brief fonction qui permet de jouer a 1vs1 en mode normal et retourne une lettre qui designe qui a gagné (r ou j)
 *
 * \param mat la grille du jeu.
 * \param j2 joueur 2.
 * \param j1 joueur 1.
 *
 * \return char
*/

extern 
int JouerNormal1vs1(char mat[N][M], joueur j1, joueur j2){

double y=0;
int tmp = 0;
initMatrice(mat);

afficher_mat(mat);
printf("\n\n");

j1.couleur="rouge";
j2.couleur="jaune";

 while( qui_gagne(mat)==0){

  // tour du premier joueur de jouer

  do{
	 while(1){              /* verifie si le nombre entrée est bien un nombre entier et pas un nombre décimale */
       	   printf("Joueur 1 :Choisissez ou vous aller mettre votre piece (numero de colonne entre 1 et 7):\n");
           scanf("%lf",&y);
           tmp = (int)y;        /* on donne la valeur entière du nombre saisi (peut être aussi un nombre décimal) à la variable temporaire*/
           if(tmp == y){
             break;             /* on sort de la boucle si c'est un nombre entier */
           }
           else{
             printf("Veuillez saisir un entier\n");     /* sinon on redemande à l'utilisateur de saisir un nombre entier */
           }
         }

  	 if (statut(y-1,mat)==0) {
    	  printf("Erreur sur les coordonnée des y : la colonne %lf est rempli essayer une autre \n\n", y);
  	 }

  }while ((y<1||y>7) || statut(y-1,mat)==0);
  y--;

  inserer(y,statut(y,mat),j1,mat);                          //on insere la piece

  if (grille_plein(mat)) {
    printf("La grille est pleine match null \n");
    break;
  }

  system("clear");

  afficher_mat(mat);
  printf("\n\n");

  if(qui_gagne(mat)!=1){                              // on passe au tour suivant si et selement si le joueur 1 n'a pas gagner

    // tour du deuxieme joueur de jouer
    y=0;

    do{
	while(1){              /* verifie si le nombre entrée est bien un nombre entier et pas un nombre décimale */
         printf("Joueur2 : Choisissez ou vous aller mettre votre piece (numero de colonne entre 1 et 7):\n");    //rajouter cas y n'est pas un chiffre
         scanf("%lf",&y);
         tmp = (int)y;        /* on donne la valeur entière du nombre saisi (peut être aussi un nombre décimal) à la variable temporaire */
         if(tmp == y){
           break;             /* on sort de la boucle si c'est un nombre entier */
         }
         else{
           printf("Veuillez saisir un entier\n"); /* sinon on redemande à l'utilisateur de saisir un nombre entier */
         }
       	}

       if (statut(y-1,mat)==0) {
         printf("Erreur sur les coordonnée des y : la colonne %lf est rempli essayer une autre \n\n", y);
       }

    }while ((y<1||y>7) || statut(y-1,mat)==0);
    y--;

    inserer(y,statut(y,mat),j2,mat);

    if (grille_plein(mat)) {
      printf("LA GRILLE EST PLEINE : MATCH NULL \n");
      break;
    }

    system("clear");

    afficher_mat(mat);
    printf("\n\n");

  }

 } // tant qu'il n'y a pas de gangnant on continue de jouer

  if(qui_gagne(mat)==1){
    modif(mat);
    printf("LES ROUGES ONT GAGNÉS !! \n");
    return(1);
  }
  else if(qui_gagne(mat)==2){
    modif(mat);
    printf("LES JAUNES ONT GAGNÉS !! \n");
    return(0);
  }

}
