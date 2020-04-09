#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "strD.h"
#include "1v1.h"
#include "1vIA.h"



/**
 * \fn void insererMode1vsIA(int y, int x, joueur t, char mat[N][M])
 * \brief fonction qui permet a l'utilisateur d'inserer une piece
 *
 * \param y numero de la colonne
 * \param x numero de la ligne
 * \param t structure representant le joueur
 * \param mat la grille du jeu.
 *
 *
*/
extern
void insererMode1vsIA(int y, int x, joueur t, char mat[N][M]){
/* fonction qui permet de insérer un epièce dans la matrice */
  if (t.couleur=="rouge") {
    mat[x][y]='R';
  }
  else if (t.couleur=="jaune") {
    mat[x][y]='J';
  }

}




/**
 * \fn void insererIA(joueur t, char mat[N][M])
 * \brief fonction qui permet a l'utilisateur d'inserer une piece
 *
 * \param ia structure representant le joueur
 * \param mat la grille du jeu.
 *
 *
*/

extern void insererIA(joueur ia, char mat[N][M]){
  int i,j,ia_joue=0;
  int y;//CASE du tableau
  char *coul;

  /* Attaque*/
  for(i=1;i!=N-1;i++){
      for(j=1;j!=N-1;j++){
          //TEST ligne (3 jetons)
          if(mat[i][j]=='J' && mat[i][j+1]=='J' && mat[i][j+2]=='J' && ia_joue==0){
            if (i==N){
              if((j+3)<=M && mat[i][j+3] == ' '){
                insererMode1vsIA(j+3,statut(j+3,mat),ia,mat);
                ia_joue=1;
                break;
              }
              else if(j>1 && mat[i][j-1] == ' '){
                insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);
                ia_joue=1;
                break;
              }
            }
            else if (i<N){
              if((j+3)<=M && (mat[i][j+3] == ' ') && (mat[i-1][j+3] != ' ')){
                  insererMode1vsIA(j+3,statut(j+3,mat),ia,mat);
                  ia_joue=1;
                  break;
            }
              else if(j>1 && (mat[i][j-1] == ' ') && (mat[i-1][j-1] != ' ')){
                insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);
                ia_joue=1;
                break;
              }
            }
          }

          //TEST colonne
          //'J'3 jetons
          else if(mat[i][j]== 'J' && mat[i+1][j]== 'J' && mat[i+2][j]=='J' && ia_joue==0){
              if (mat[i+3][j] == ' '){
                  insererMode1vsIA(j+3,statut(j+3,mat),ia,mat);
                  ia_joue=1;
                  break;
                  }

          }

          //TEST 1ere DIAGONNALE
          else if(mat[i][j]=='J' && mat[i+1][j+1]=='J' && mat[i+2][j+2]=='J' && ia_joue==0){
              if (i+3==N && mat[i+3][j+3] == ' ' ){
                  insererMode1vsIA(j+3,statut(j+3,mat),ia,mat);
                  ia_joue=1;
                  break;
              }
              else if(i+3<N && mat[i+4][j+3] != ' ' && mat[i+3][j+3] == ' '){
                insererMode1vsIA(j+3,statut(j+3,mat),ia,mat);
                ia_joue=1;
                break;
              }
              else if (i>1 && mat[i-1][j-1] == ' ' && mat[i][j-1] !=' '){
                  insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);
                  ia_joue=1;
                  break;
              }
          }
          else if(mat[i][j]=='J' && mat[i+1][j+1]=='J' &&mat[i+3][j+3]=='J' && ia_joue==0){
            if(mat[i+2][j+2]=='J' && mat[i+3][j+2]==!' '){
              insererMode1vsIA(j+2,statut(j+2,mat),ia,mat);
              ia_joue=1;
              break;
            }

          }
          else if(mat[i][j]=='J' && mat[i+2][j+2]=='J' &&mat[i+3][j+3]=='J' && ia_joue==0){
            if(mat[i+1][j+1]=='J' && mat[i+2][j+1]==!' '){
              insererMode1vsIA(j+1,statut(j+1,mat),ia,mat);
              ia_joue=1;
              break;
            }

          }
        }
      }

  for(j=1;j!=N-1;j++){
      for(i=N-1;i>=1;i--){
          //TEST 2eme Diagonnale
          if(mat[i][j]=='J' && mat[i-1][j+1]=='J' && mat[i-2][j+2]=='J' && ia_joue==0){
            if ((i-3)>=1 && mat[i-3][j+3] == ' ' && mat[i-2][j+3] !=' '){
                insererMode1vsIA(j+3,statut(j+3,mat),ia,mat);
                ia_joue=1;
                break;
            }
            else if ((i+1)==N && mat[i+1][j-1] == ' '){
                insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);
                ia_joue=1;
                break;
            }
            else if ((i+1)<N && mat[i+1][j-1] == ' ' && mat[i+2][j-1] != ' ' ){
                insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);
                ia_joue=1;
                break;
            }
          }
          else if(mat[i][j]=='J' && mat[i-1][j+1]=='J' &&mat[i-3][j+3]=='J' && ia_joue==0){
            if(mat[i-2][j+2]=='J' && mat[i-1][j+2]==!' '){
              insererMode1vsIA(j+2,statut(j+2,mat),ia,mat);
              ia_joue=1;
              break;
            }

          }
          else if(mat[i][j]=='J' && mat[i-2][j+2]=='J' &&mat[i-3][j+3]=='J' && ia_joue==0){
            if(mat[i-1][j+1]=='J' && mat[i][j+1]==!' '){
              insererMode1vsIA(j+1,statut(j+1,mat),ia,mat);
              ia_joue=1;
              break;
            }

          }

      }
  }
 /* Défense */
 for(i=1;i!=N-1;i++){
      for(j=1;j!=N-1;j++){
          //TEST LIGNE (3 jetons)
          if(mat[i][j] == 'R'  && mat[i][j+1]=='R'  &&mat[i][j+2]=='R' && ia_joue==0){
            if(i==N){
              if ((j+3)<= M && (mat[i][j+3] == ' ')){
                  insererMode1vsIA(j+3,statut(j+3,mat),ia,mat);
                  ia_joue=1;
                  break;
              }
              else if (j>1 && (mat[i][j-1] == ' ')){
                  insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);
                  ia_joue=1;
                  break;
              }
            }
            else if(i<N){
              if ((j+3)<=M && (mat[i][j+3] == ' ') && (mat[i+1][j+3] != ' ')){
                  insererMode1vsIA(j+3,statut(j+3,mat),ia,mat);
                  ia_joue=1;
                  break;
              }
              else if (j>1 && (mat[i][j-1] == ' ') && (mat[i+1][j-1] != ' ')){
                  insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);
                  ia_joue=1;
                  break;
              }
            }

          }
          else if(mat[i][j] == 'R'  && mat[i][j+1]=='R'  &&mat[i][j+3]=='R' && ia_joue==0){
            if(i==N){
              insererMode1vsIA(j+2,statut(j+2,mat),ia,mat);
              ia_joue=1;
              break;
            }
            else if(i<N){
              if(mat[i+1][j+2] != ' '){
                insererMode1vsIA(j+2,statut(j+2,mat),ia,mat);
                ia_joue=1;
                break;
              }
            }
          }

          else if(mat[i][j] == 'R'  && mat[i][j+2]=='R'  &&mat[i][j+3]=='R' && ia_joue==0){
            if(i==N){
              insererMode1vsIA(j+1,statut(j+1,mat),ia,mat);
              ia_joue=1;
              break;
            }
            else if(i<N){
              if(mat[i+1][j+1] != ' '){
                insererMode1vsIA(j+1,statut(j+1,mat),ia,mat);
                ia_joue=1;
                break;
              }
            }
          }

          //TEST COLONNE
          //'R' 3 jetons
          else if(mat[i][j]=='R' && mat[i+1][j]=='R' && mat[i+2][j]=='R' && ia_joue==0){
              if (mat[i+3][j] == ' '){
                  insererMode1vsIA(j,statut(j,mat),ia,mat);
                  ia_joue=1;
                  break;
                  }
          }

          //TEST 1ere DIAGONNALE
          else if(mat[i][j]=='R' && mat[i+1][j+1]=='R' &&mat[i+2][j+2]=='R' && ia_joue==0){
            if ((i+3)==N && mat[i+3][j+3] == ' ' ){
                insererMode1vsIA(j+3,statut(j+3,mat),ia,mat);
                ia_joue=1;
                break;
            }
            else if((i+3)<N && mat[i+4][j+3] != ' ' && mat[i+3][j+3] == ' '){
              insererMode1vsIA(j+3,statut(j+3,mat),ia,mat);
              ia_joue=1;
              break;
            }
            else if (i>1 && mat[i-1][j-1] == ' ' && mat[i][j-1] !=' '){
                insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);
                ia_joue=1;
                break;
            }

          }
      }
  }


  for(j=1;j!=N-1;j++){
      for(i=N-1;i>=1;i--){
          //TEST 2eme Diagonnale
          if(mat[i][j]=='R' && mat[i-1][j+1]=='R' && mat[i-2][j+2]=='R' && ia_joue==0){
              if ((i-3)>=1 && mat[i-3][j+3] == ' ' && mat[i-2][j+3] !=' '){
                  insererMode1vsIA(j+3,statut(j+3,mat),ia,mat);
                  ia_joue=1;
                  break;
              }
              else if ((i+1)==N && mat[i+1][j-1] == ' '){
                  insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);
                  ia_joue=1;
                  break;
              }
              else if ((i+1)<N && mat[i+1][j-1] == ' ' && mat[i+2][j-1] != ' ' ){
                  insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);
                  ia_joue=1;
                  break;
              }
          }

      }
  }




  /*Ia+*/
  //ATTAQUE si 2 jetons egaux
  for(i=1;i<=N-1;i++){
      for(j=1;j<=N-1;j++){
          //TEST ligne (2 jetons)
          if(mat[i][j]=='J' && mat[i][j+1]=='J' && ia_joue==0){
              if (mat[i][j+2] == ' '){
                  if(i==N ){
                    insererMode1vsIA(j+2,statut(j+2,mat),ia, mat);
                    ia_joue=1;
                    break;
                  }
                  else if(i<N && mat[i+1][j+2] != ' ' ){
                    insererMode1vsIA(j+2,statut(j+2,mat),ia, mat);
                    ia_joue=1;
                    break;
                  }
              }
              if (mat[i][j-1] == ' '){
                  if(i==N ){
                    insererMode1vsIA(j-1,statut(j-1,mat),ia, mat);
                    ia_joue=1;
                    break;
                  }
                  else if(i<N && mat[i+1][j-1] != ' ' ){
                    insererMode1vsIA(j-1,statut(j-1,mat),ia, mat);
                    ia_joue=1;
                    break;
                  }
              }
          }

          //TEST LIGNE
          //2 jetons
          else if(mat[i][j]=='J' && mat[i-1][j]=='J' && mat[i-2][j] == ' ' && ia_joue==0){
              insererMode1vsIA(j,statut(j,mat),ia,mat);
              ia_joue=1;
              break;
          }
      }
  }
  //Attaque si 1 jetons
   for(i=1;i!=N-1;i++){
      for(j=1;j!=N-1;j++){

          if(mat[i][j]=='J' && ia_joue==0){
            //TEST ligne et colone (1 jetons)
              if (i==N){
                if(mat[i][j+1]){
                  insererMode1vsIA(j+1,statut(j+1,mat),ia,mat);
                  ia_joue=1;
                  break;
                }
                else if(mat[i][j-1]){
                  insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);
                  ia_joue=1;
                  break;
                }
                else if(mat[i-1][j]==' '){
                  insererMode1vsIA(j,statut(j,mat),ia,mat);
                  ia_joue=1;
                  break;
                }
              }
              else if(i<N){
                if(mat[i][j+1] && mat[i-1][j+1]){
                  insererMode1vsIA(j+1,statut(j+1,mat),ia,mat);
                  ia_joue=1;
                  break;
                }
                else if(mat[i][j-1] && mat[i-1][j-1]){
                  insererMode1vsIA(j-1,statut(j-1,mat),ia,mat);
                  ia_joue=1;
                  break;
                }
                else if(mat[i-1][j]==' '){
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
      coul=ia.couleur;
      y=rand()%6+1;

      insererMode1vsIA(y,statut(y,mat),ia,mat);
      ia_joue=1;
      }






/*  int y=0 ,x=-1;
  const int MAX = (p+1) , MIN = (p-1) ;
// Génération du nombre aléatoire
while (x==-1) {
  do {
    srand(time(NULL));
    y = (rand() % (MAX - MIN ) + MIN);
  } while(y<0||y>6);
  x = statut(y,mat);
}
  if (ia.couleur=="rouge") {
    mat[x][y]='R';
  }
  else if (ia.couleur=="jaune") {
    mat[x][y]='J';
  }
*/
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
*/


extern int JouerNormal1vsIA(char mat[N][M], joueur j1, joueur ia){

double y=0;
int tmp = 0;
int m=1;
initMatrice(mat);

afficher_mat(mat);
printf("\n\n");

j1.couleur="rouge";
ia.couleur="jaune";

 while( qui_gagne(mat)==0){
   y=0;
  // tour du premier joueur de jouer

  do{
	 while(1){              /* verifie si le nombre entrée est bien un nombre entier et pas un nombre décimale */
       	   printf("Joueur 1 :Choisissez ou vous aller mettre votre piece (numero de colonne entre 1 et %d):\n",(M-2));
           scanf("%lf",&y);
           tmp = (int)y;        /* on donne la valeur entière du nombre saisi (peut être aussi un nombre décimal) à la variable temporaire*/
           if(tmp == y){
             break;             /* on sort de la boucle si c'est un nombre entier */
           }
           else{
             printf("Veuillez saisir un entier\n");     /* sinon on redemande à l'utilisateur de saisir un nombre entier */
           }
         }

  	 if (statut(y,mat)==0) {
    	  printf("Erreur sur les coordonnée des y : la colonne %lf est rempli essayer une autre \n\n", y);
  	 }

  }while ((y<1||y>(M-2)) || statut(y,mat)==0);


  insererMode1vsIA(y,statut(y,mat),j1,mat);                          //on insere la piece

  system("clear");

  afficher_mat(mat);
  printf("\n\n");

  if (grille_plein(mat)) {
    printf("LA GRILLE EST PLEINE : MATCH NULL \n");
    return(3);
  }


  if(qui_gagne(mat)!=1){                              // on passe au tour suivant si et selement si le joueur 1 n'a pas gagner

    // tour de l'IA de jouer


    insererIA(ia,mat);

    system("clear");

    afficher_mat(mat);
    printf("\n\n");

    if (grille_plein(mat)) {
      printf("LA GRILLE EST PLEINE : MATCH NULL \n");
      return(3);
    }

  }

 } // tant qu'il n'y a pas de gangnant on continue de jouer

  if(qui_gagne(mat)==1){
    modif(mat);
    printf("LES ROUGES ONT GAGNÉS !! \n");
    return(1);
  }
  else if(qui_gagne(mat)==2){
    modif(mat);
    printf("LES JAUNES (IA) ONT GAGNÉS !! \n");
    return(2);
  }


}
