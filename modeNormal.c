#include <stdio.h>
#include <stdlib.h>
#include "structD.h"


int statut(int x, char mat[N][M]){

  for (int y = M ; (mat[x][y]==("R"||"J")) || (y > 0) ; y--) ; /* on arrive au bout tant que l'emplacement est pris on remonte */

    return y ;

}

void inserer(int x, int y, joueur t, char mat[N][M]){

  if (t.couleur=="rouge") {
    mat[x][y]="R";
  }
  else if (t.couleur=="jaune") {
    mat[x][y]="J";
  }

}

int quiGagne(char mat[N][M],joueur j){       // fonction qui verifie les pions du joueur pour savoir si il a gagner ou pas
  int i,j=0;
  int cptL = 0;
  int cptD = 0;
  int cptC = 0;


  if(j.couleur = 'R'){
      for( i = 0; i < N || cptL<4; i++) {

        for(j = 0; j < M || cptL<4; j++) {

          if(mat[i][j] == 'R'){

            cptL ++;
          }

          if (mat[i][j] == 'J') {
            cptL = 0;
          }
        }
        cptL = 0;
      }

      for( i = 0; i < M || cptC<4; i++) {

        for(j = 0; j < N || cptC<4; j++) {

          if(mat[i][j] == 'R'){

            cptC ++;
          }

          if (mat[i][j] == 'J') {
            cptC = 0;
          }
        }
        cptC = 0;
      }


      for( i = N; i > 0 || cptD<4; i++) {

        for(j = M; j > 0 || cptD<4; j++) {

          if (mat[i][j] == 'R') {

          }

        }

      }








  }





}



void JouerNormal1vs1(char mat[N][M], joueur j1, joueur j2){

int x=0;


while( quiGagne(mat,j1)!=1 || quiGagne(mat,j2)!=1 ){        // tant qu'il n'y a pas de gangnant on continue de jouer

  // tour du premier joueur de jouer

  do{

    printf("Joueur 1 :Choisissez ou vous aller mettre votre piece (numero de colonne entre 0 et 6):\n");
    scanf("%d",&x);

  if (statut(x,mat)==-1) {
    printf("Erreur sur les coordonnée des y : la colonne %d est rempli essayer une autre \n",&x);
  }

}while ((x<0||x>6) || statut(x,mat)==-1);

  inserer(x,statut(x,mat),j1,mat);                          //on insere la piece

  if(quiGagne(mat,j1)==0){                              // on passe au tour suivant si et selement si le joueur 1 n'a pas gagner

    // tour du deuxieme joueur de jouer
    x=0;

    do{

      printf("Joueur2 : Choisissez ou vous aller mettre votre piece (numero de colonne entre 0 et 6):\n");
      scanf("%d",&x);

    if (statut(x,mat)==-1) {
      printf("Erreur sur les coordonnée des y : la colonne %d est rempli essayer une autre \n",&x);
    }

  }while ((x<0||x>6) || statut(x,mat)==-1);

    inserer(x,statut(x,mat),j2,mat);
  }

}

if (quiGagne(mat,j1)==1) {
  printf("Le joueur 1 a gagner !!!! \n", );
}

else if (quiGagne(mat,j2)==1) {
  printf("Le joueur 2 a gagner !!!! \n", );
}


}
