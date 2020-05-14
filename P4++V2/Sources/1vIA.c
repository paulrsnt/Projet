#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Includes/strD.h"
#include "../Includes/1v1.h"
#include "../Includes/1vIA.h"
#include "../Includes/parcours.h"


/**
* \file 1vIA.c
* \brief Programme regroupant les fonctions du mode 1vIA du jeu du puissance 4++
* \author Aaron Amani, Fatih Ufacik et Paul Riga
* \version 2.0
* \date 5 mai 2020
*/



/**
 * \fn void insererMode1vsIA(int y, int x, joueur t, char mat[N][M])
 * \brief fonction qui permet a l'utilisateur d'inserer une piece
 *
 * \param y numero de la colonne
 * \param x numero de la ligne
 * \param t structure representant le joueur
 * \param mat la grille du jeu.
 *
 * \author Aaron Amani
*/

void insererMode1vsIA(int y, int x, joueur *t, char mat[N][M]){
/* fonction qui permet de insérer un epièce dans la matrice */
  if (t->couleur=='J') {
    mat[x][y]='J';
  }
  else if (t->couleur=='R') {
    mat[x][y]='R';
  }

}




/**
 * \fn void insererIA(joueur t, char mat[N][M])
 * \brief fonction qui permet a l'IA d'inserer une piece
 *
 * \param ia structure representant le joueur
 * \param mat la grille du jeu.
 *
 *\author Paul Riga, Fatih Ufacik
*/

 void insererIA(joueur *ia, char mat[N][M]){
  int i,j,ia_joue=0;
  int y;//CASE du tableau
 /* Attaque */
 for(i=1;i!=N-1;i++){
      for(j=1;j!=M-1;j++){
          //TEST LIGNE (3 jetons)
          if(mat[i][j] == 'J' && mat[i][j+1] == 'J' && mat[i][j+2] == 'J' && ia_joue==0){
            if(i==6){
              if ((j+3)<N && (mat[i][j+3] == ' ')){

                ia->x=j+3;
                ia->y=statut(j+3,mat); if(ia->y==0){break;}
                  insererMode1vsIA(j+3,statut(j+3,mat),ia,mat);

                  ia_joue=1;
                  break;
              }
              else if (j>1 && (mat[i][j-1] == ' ')){

                ia->x=j-1;
                ia->y=statut(j-1,mat); if(ia->y==0){break;}
                  insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);

                  ia_joue=1;
                  break;
              }
            }

            else if(i<6){
              if((j+3)<N && (mat[i][j+3] == ' ') && (mat[i-1][j+3] != ' ')){

                ia->x=j+3;
                ia->y=statut(j+3,mat); if(ia->y==0){break;}
                insererMode1vsIA(j+3,statut(j+3,mat),ia,mat);

                ia_joue=1;
                break;
              }
              else if(j>1 && (mat[i][j-1] == ' ') && (mat[i-1][j-1] != ' ')){

                ia->x=j-1;
                ia->y=statut(j-1,mat); if(ia->y==0){break;}
                insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);

                ia_joue=1;
                break;
              }
            }



          }

          //TEST COLONNE
          //'J' 3 jetons
          else if(mat[i][j] == 'J' && mat[i-1][j] == 'J' && mat[i-2][j] == 'J' && ia_joue==0){
              if (mat[i-3][j] == ' '){

                ia->x=j;
                ia->y=statut(j,mat); if(ia->y==0){break;}
                  insererMode1vsIA(j,statut(j,mat),ia,mat);

                  ia_joue=1;
                  break;
                  }
          }

          //TEST 1ere DIAGONNALE
          else if(mat[i][j] == 'J' && mat[i+1][j+1] == 'J' && mat[i+2][j+2] == 'J' && ia_joue==0){
            if ((i+3)==6 && mat[i+3][j+3] == ' ' ){

              ia->x=j+3;
              ia->y=statut(j+3,mat); if(ia->y==0){break;}
                insererMode1vsIA(j+3,statut(j+3,mat),ia,mat);

                ia_joue=1;
                break;
            }
            else if((i+3)<6 && mat[i+4][j+3] != ' ' && mat[i+3][j+3] == ' '){

              ia->x=j+3;
              ia->y=statut(j+3,mat); if(ia->y==0){break;}
              insererMode1vsIA(j+3,statut(j+3,mat),ia,mat);

              ia_joue=1;
              break;
            }
            else if(i>1 && mat[i-1][j-1] == ' ' && mat[i][j-1] !=' '){

              ia->x=j-1;
              ia->y=statut(j-1,mat); if(ia->y==0){break;}
                insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);

                ia_joue=1;
                break;
            }

          }
      }
  }


  for(j=1;j!=M-1;j++){
      for(i=N-1;i>=1;i--){
          //TEST 2eme Diagonnale
          if(mat[i][j] == 'J' && mat[i-1][j+1] == 'J' && mat[i-2][j+2] == 'J' && ia_joue==0){
              if (mat[i-3][j+3] == ' ' && mat[i-2][j+3] !=' '){

                ia->x=j+3;
                ia->y=statut(j+3,mat); if(ia->y==0){break;}
                  insererMode1vsIA(j+3,statut(j+3,mat),ia,mat);

                  ia_joue=1;
                  break;
              }
              else if ((i+1)==N && mat[i+1][j-1] == ' '){

                ia->x=j-1;
                ia->y=statut(j-1,mat); if(ia->y==0){break;}
                  insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);

                  ia_joue=1;
                  break;
              }
              else if ((i+1)<N && mat[i+1][j-1] == ' '&&mat[i+2][j-1] != ' ' ){

                ia->x=j-1;
                ia->y=statut(j-1,mat); if(ia->y==0){break;}
                  insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);

                  ia_joue=1;
                  break;
              }
          }

      }
  }

  /* DEFENSE */
  for(i=1;i!=N-1;i++){
      for(j=1;j!=M-1;j++){
          //TEST ligne (3 jetons)
          if(mat[i][j] == 'R' && mat[i][j+1] == 'R' &&mat[i][j+2]== 'R' && ia_joue==0){
            if (i==6){
              if(mat[i][j+3] == ' '){

                ia->x=j+3;
                ia->y=statut(j+3,mat); if(ia->y==0){break;}
                insererMode1vsIA(j+3,statut(j+3,mat),ia,mat);

                ia_joue=1;
                break;
              }
              else if(mat[i][j-1] == ' '){

                ia->x=j-1;
                ia->y=statut(j-1,mat); if(ia->y==0){break;}
                insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);

                ia_joue=1;
                break;
              }
            }
            else if (i<6){
              if((j+3)<=7 && (mat[i][j+3] == ' ') && (mat[i-1][j+3] != ' ')){


                ia->x=j+3;
                ia->y=statut(j+3,mat); if(ia->y==0){break;}
                  insererMode1vsIA(j+3,statut(j+3,mat),ia,mat);

                  ia_joue=1;
                  break;
            }
              else if(j>1 && (mat[i][j-1] == ' ') && (mat[i-1][j-1] != ' ')){

                ia->x=j-1;
                ia->y=statut(j-1,mat); if(ia->y==0){break;}
                insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);

                ia_joue=1;
                break;
              }
            }
          }

          //TEST colonne
          //'R'3 jetons
          else if(mat[i][j] == 'R' && mat[i+1][j] == 'R' && mat[i+2][j] == 'R' && ia_joue==0){
              if ((i-1)>0 && mat[i-1][j] == ' '){

                ia->x=j;
                ia->y=statut(j,mat); if(ia->y==0){break;}
                  insererMode1vsIA(j,statut(j,mat),ia,mat);

                  ia_joue=1;
                  break;
                  }

          }

          //TEST 1ere DIAGONNALE
          else if(mat[i][j] == 'R' && mat[i+1][j+1] == 'R' && mat[i+2][j+2] == 'R' && ia_joue==0){
              if (i+3==6 && mat[i+3][j+3] == ' ' ){

                ia->x=j+3;
                ia->y=statut(j+3,mat); if(ia->y==0){break;}
                  insererMode1vsIA(j+3,statut(j+3,mat),ia,mat);

                  ia_joue=1;
                  break;
              }
              else if(i+3<6 && mat[i+4][j+3] != ' ' && mat[i+3][j+3] == ' '){

                ia->x=j+3;
                ia->y=statut(j+3,mat); if(ia->y==0){break;}
                insererMode1vsIA(j+3,statut(j+3,mat),ia,mat);

                ia_joue=1;
                break;
              }
              else if (i>1 && mat[i-1][j-1] == ' ' && mat[i][j-1] !=' '){

                ia->x=j-1;
                ia->y=statut(j-1,mat); if(ia->y==0){break;}
                  insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);

                  ia_joue=1;
                  break;
              }
          }
      }
  }

  for(j=1;j!=M-1;j++){
      for(i=N-1;i>=1;i--){
          //TEST 2eme Diagonnale
          if(mat[i][j] == 'R' && mat[i-1][j+1] == 'R' && mat[i-2][j+2] == 'R' && ia_joue==0){
            if ((i-3)>=1 && mat[i-3][j+3] == ' ' && mat[i-2][j+3] !=' '){

              ia->x=j+3;
              ia->y=statut(j+3,mat); if(ia->y==0){break;}
                insererMode1vsIA(j+3,statut(j+3,mat),ia,mat);

                ia_joue=1;
                break;
            }
            else if ((i+1)==6 && mat[i+1][j-1] == ' '){

              ia->x=j-1;
              ia->y=statut(j-1,mat); if(ia->y==0){break;}
                insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);

                ia_joue=1;
                break;
            }
            else if ((i+1)<6 && mat[i+1][j-1] == ' '&&mat[i+2][j-1] != ' ' ){

              ia->x=j-1;
              ia->y=statut(j-1,mat); if(ia->y==0){break;}
                insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);

                ia_joue=1;
                break;
            }
          }

      }
  }


  /*Ia+*/
  //Attaque si 2 jetons egaux
  for(i=1;i<=N-1;i++){
      for(j=1;j<=N-1;j++){
          //TEST ligne (2 jetons)
          if(mat[i][j] == 'J' && mat[i][j+1] == 'J' && ia_joue==0){
              if (mat[i][j+2] == ' '){
                  if(i==6 ){

                    ia->x=j+2;
                    ia->y=statut(j+2,mat); if(ia->y==0){break;}
                    insererMode1vsIA(j+2,statut(j+2,mat),ia, mat);

                    ia_joue=1;
                    break;
                  }
                  else if(i<6 && mat[i+1][j+2] != ' ' ){
                    ia->x=j+2;
                    ia->y=statut(j+2,mat); if(ia->y==0){break;}
                    insererMode1vsIA(j+2,statut(j+2,mat),ia, mat);

                    ia_joue=1;
                    break;
                  }
              }
              if (mat[i][j-1] == ' '){
                  if(i==6 ){
                    ia->x=j-1;
                    ia->y=statut(j-1,mat); if(ia->y==0){break;}
                    insererMode1vsIA(j-1,statut(j-1,mat),ia, mat);

                    ia_joue=1;
                    break;
                  }
                  else if(i<6 && mat[i+1][j-1] != ' ' ){
                    ia->x=j-1;
                    ia->y=statut(j-1,mat); if(ia->y==0){break;}
                    insererMode1vsIA(j-1,statut(j-1,mat),ia, mat);

                    ia_joue=1;
                    break;
                  }
              }
          }

          //TEST COLONNE
          //2 jetons
          else if('J' == mat[i][j] && 'J' == mat[i-1][j] && mat[i-2][j] == ' ' && ia_joue==0){

            ia->x=j;
            ia->y=statut(j,mat); if(ia->y==0){break;}
              insererMode1vsIA(j,statut(j,mat),ia,mat);

              ia_joue=1;
              break;
          }

          //TEST 1ere Diagonnale

          else if(mat[i][j] == 'R' && mat[i+1][j+1] == 'R' && ia_joue==0){
              if (i+2==6 && mat[i+2][j+2] == ' ' ){

                  ia->x=j+2;
                  ia->y=statut(j+2,mat); if(ia->y==0){break;}
                  insererMode1vsIA(j+2,statut(j+2,mat),ia,mat);

                  ia_joue=1;
                  break;
              }
              else if(i+2<6 && mat[i+3][j+2] != ' ' && mat[i+2][j+2] == ' '){

                ia->x=j+2;
                ia->y=statut(j+2,mat); if(ia->y==0){break;}
                insererMode1vsIA(j+2,statut(j+2,mat),ia,mat);

                ia_joue=1;
                break;
              }
              else if (i>1 && mat[i-1][j-1] == ' ' && mat[i][j-1] !=' '){

                  ia->x=j-1;
                  ia->y=statut(j-1,mat); if(ia->y==0){break;}
                  insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);

                  ia_joue=1;
                  break;
              }
          }

      }
  }
  for(j=1;j!=M-1;j++){
      for(i=N-1;i>=1;i--){
          //TEST 2eme Diagonnale
          if(mat[i][j] == 'R' && mat[i-1][j+1] == 'R' && ia_joue==0){
            if ((i-2)>=1 && mat[i-2][j+2] == ' ' && mat[i-1][j+2] !=' '){
                ia->x=j+2;
                ia->y=statut(j+2,mat); if(ia->y==0){break;}
                insererMode1vsIA(j+2,statut(j+2,mat),ia,mat);

                ia_joue=1;
                break;
            }
            else if ((i+1)==6 && mat[i+1][j-1] == ' '){
                ia->x=j-1;
                ia->y=statut(j-1,mat); if(ia->y==0){break;}
                insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);

                ia_joue=1;
                break;
            }
            else if ((i+1)<6 && mat[i+1][j-1] == ' '&&mat[i+2][j-1] != ' ' ){
                ia->x=j-1;
                ia->y=statut(j-1,mat); if(ia->y==0){break;}
                insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);

                ia_joue=1;
                break;
            }
          }

      }
  }
  //Attaque si 1 jetons
   for(i=1;i!=N-1;i++){
      for(j=1;j!=M-1;j++){

          if('J' == mat[i][j] && ia_joue==0){
            //TEST ligne et colone (1 jetons)
              if (i==N){
                if(mat[i][j+1]){
                  ia->x=j+1;
                  ia->y=statut(j+1,mat); if(ia->y==0){break;}
                  insererMode1vsIA(j+1,statut(j+1,mat),ia,mat);

                  ia_joue=1;
                  break;
                }
                else if(mat[i][j-1]){
                  ia->x=j-1;
                  ia->y=statut(j-1,mat); if(ia->y==0){break;}
                  insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);

                  ia_joue=1;
                  break;
                }
                else if(mat[i-1][j]==' '){
                  ia->x=j;
                  ia->y=statut(j,mat); if(ia->y==0){break;}
                  insererMode1vsIA(j,statut(j,mat),ia,mat);

                  ia_joue=1;
                  break;
                }
              }
              else if(i<N){
                if(mat[i][j+1] && mat[i-1][j+1]){
                  ia->x=j+1;
                  ia->y=statut(j+1,mat); if(ia->y==0){break;}
                  insererMode1vsIA(j+1,statut(j+1,mat),ia,mat);

                  ia_joue=1;
                  break;
                }
                else if(mat[i][j-1] && mat[i-1][j-1]){
                  ia->x=j-1;
                  ia->y=statut(j-1,mat); if(ia->y==0){break;}
                  insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);

                  ia_joue=1;
                  break;
                }
                else if(mat[i-1][j]==' '){
                  ia->x=j;
                  ia->y=statut(j,mat); if(ia->y==0){break;}
                  insererMode1vsIA(j,statut(j,mat),ia,mat);

                  ia_joue=1;
                  break;
                }
              }


          }




      }
  }

 /* Si l'ia ne sais pas quoi jouer random*/


 if(ia_joue==0){
      y=rand()%6+1;

      ia->x=y;
      ia->y=statut(y,mat);
      insererMode1vsIA(y,statut(y,mat),ia,mat);

      ia_joue=1;
      }


}





/**
 * \fn void JouerNormal1vsIA(char mat[N][M], joueur j1, joueur j2)
 * \brief fonction qui permet de jouer a 1vsIA en mode normal
 *
 * \param mat la grille du jeu.
 *
 * \param j1 joueur 1.
 *
 * \return int
 *
 * \author Aaron Amani
*/


 int JouerNormal1vsIA(char mat[N][M], joueur *j1, joueur *ia){


  j1->couleur='R';
  ia->couleur='J';
  ia->x=0;
  ia->y=0;
  char y_string[100];
  int y=-1;
  int rouge=0,jaune=0;

  initMatrice(mat);
  afficher_mat(mat);
  printf("\n\n");



 while(1){
   y=0;
  // tour du premier joueur de jouer

  do{
	 /* verifie si le nombre entrée est bien un nombre entier et pas un nombre décimale */
       	   printf("Joueur 1 :Choisissez ou vous aller mettre votre piece (numero de colonne entre 1 et %d):\n",(M-2));
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
  insererMode1vsIA(y,statut(y,mat),j1,mat);                          //on insere la piece
  rouge=parcours(x,y,mat,j1);

  system("clear");
  afficher_mat(mat);
  printf("\n\n");

  if (grille_plein(mat)) {
    printf("LA GRILLE EST PLEINE : MATCH NULL \n");
    return(3);
  }


  if(rouge==0){                              // on passe au tour suivant si et selement si le joueur 1 n'a pas gagner

    // tour de l'IA de jouer


    insererIA(ia,mat);
    jaune=parcours(ia->y,ia->x,mat,ia);

    system("clear");
    afficher_mat(mat);
    printf("\n\n");

    if (grille_plein(mat)) {
      printf("LA GRILLE EST PLEINE : MATCH NULL \n");
      return(3);
    }

  }
// tant qu'il n'y a pas de gangnant on continue de jouer

  if(rouge==1){

    printf("LES ROUGES ONT GAGNÉS !! \n");
    return(1);
  }
  else if(jaune==1){

    printf("LES JAUNES (IA) ONT GAGNÉS !! \n");
    return(2);
  }
}

return(0);
}
