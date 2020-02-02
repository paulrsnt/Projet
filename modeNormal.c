#include <stdio.h>
#include <stdlib.h>
#include "structD.h"


int statut(int x, mat[N][M]){

  for (int y = M ; (mat[x][y]==("R"||"J")) || (y < 0) ; y--) ; /* on arrive au baout tant que l'emplacement est pris on remonte */

  if (y=>0) {          /* si les coordonnée sur l'axe des y est dans la grille alors on le retourne */
    return y ;
  }
  else{               /* sinon on retourne -1 */
    return -1;
  }

}

void inserer(int x, int y, joueur t, mat[N][M]){

  if (t.couleur=="rouge") {
    mat[x][y]=1;
  }
  else if (t.couleur=="jauge") {
    mat[x][y]=2;
  }

}

int quiGagne(mat[N][M],joueur t){       // fonction qui verifie les pions du joueur pour savoir si il a gagner ou pas

}



void JouerNormal1vs1(char mat[N][M], joueur j1, joueur j2){

int x=0;
while( quiGagne(mat,j1)==1 || quiGagne(mat,j2)==1 ){        // tant qu'il n'y a pas de gangnant on continue de jouer

  // tour du premier joueur de jouer

  do{

    printf("Joueur 1 :Choisissez ou vous aller mettre votre piece (numero de colonne entre 0 et 6):\n");
    scanf("%d",&x);

  if (statut(x)==-1) {
    printf("Erreur sur les coordonnée des y : la colonne %d est rempli essayer une autre \n",&x);
  }

  }while ((x<0||x>6) || statut(x)==-1);

  inserer(x,statut(x),j1,mat);                          //on insere la piece

  if(quiGagne(mat,j1)==0){                              // on passe au tour suivant si et selement si le joueur 1 n'a pas gagner

    // tour du deuxieme joueur de jouer
    x=0;

    do{

      printf("Joueur2 : Choisissez ou vous aller mettre votre piece (numero de colonne entre 0 et 6):\n");
      scanf("%d",&x);

    if (statut(x)==-1) {
      printf("Erreur sur les coordonnée des y : la colonne %d est rempli essayer une autre \n",&x);
    }

    }while ((x<0||x>6) || statut(x)==-1);

    inserer(x,statut(x),j2,mat);
  }

}

if (quiGagne(mat,j1)==1) {
  printf("Le joueur 1 a gagner !!!! \n", );
}

else if (quiGagne(mat,j2)==1) {
  printf("Le joueur 2 a gagner !!!! \n", );
}


}
