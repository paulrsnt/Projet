#include <stdio.h>
#include <stdlib.h>
#include "structD.h"

int statut(int x, char mat[N][M],piece p){

  for (int y = M ; (mat[x][y]==("R"||"J")) || (y < 0) ; y--) ; /* on arrive au bout tant que l'emplacement est pris on remonte */

  if (y=>0) {          /* si les coordonnée sur l'axe des y est dans la grille alors on le retourne */
    return y ;
  }
  else{               /* sinon on retourne -1 */
    return -1;
  }

}

void inserer(int x, int y, joueur t, char mat[N][M], piece p){

  if (t.couleur=="rouge") {
	if(piece p=1){
		mat[x][y]="RB"; /*Rouge bloquante*/
	}
	if(piece p=2){
		mat[x][y]="RC"; /*Rouge creuse*/
	}
	if(piece p=3){
		mat[x][y]="RP"; /*Rouge pleine*/
  }
  if (t.couleur=="jaune") {
	if(piece p=1){
		mat[x][y]="JB";
	}
	if(piece p=2){
		mat[x][y]="JC";
	}
	if(piece p=3){
		mat[x][y]="JP";
  }

}

int quiGagne(char mat[N][M],joueur t){       // fonction qui verifie les pions du joueur pour savoir si il a gagner ou pas

}



void Jouer2vs2(char mat[N][M], joueur j1, joueur j2, joueur j3, joueur j4, piece P1){

int x=0;
int TypePiece=0;


while( quiGagne(mat,j1)!=1 || quiGagne(mat,j2)!=1 || quiGagne(mat,j3)!=1 || quiGagne(mat,j4)!=1 ){        // tant qu'il n'y a pas de gangnant on continue de jouer

  // tour du premier joueur de jouer

  do{
    printf("Joueur 1 :Choisissez le type de votre piece (1 = bloquante , 2 = creuse , 3 = pleine):\n");
    scanf("%d",&TypePiece);
    printf("Joueur 1 :Choisissez ou vous aller mettre votre piece (numero de colonne entre 0 et 6):\n");
    scanf("%d",&x);

  if (statut(x,mat[N][M],P1)==-1) {
    printf("Erreur sur les coordonnée des y : la colonne %d est rempli essayer une autre \n",&x);
  }

  }while ((x<0||x>6) || statut(x,mat[N][M],P1)==-1 || TypePiece != 1 || TypePiece != 2 ||TypePiece != 3 );

  inserer(x,statut(x,mat[N][M],P1),j1,mat,P1);                          //on insere la piece

  if(quiGagne(mat,j1)==0){                              // on passe au tour suivant si et selement si le joueur 1 n'a pas gagner

    // tour du deuxieme joueur de jouer
    x=0;

    do{
      printf("Joueur 2 :Choisissez le type de votre piece (1 = bloquante , 2 = creuse , 3 = pleine):\n");
      scanf("%d",&TypePiece);
      printf("Joueur2 : Choisissez ou vous aller mettre votre piece (numero de colonne entre 0 et 6):\n");
      scanf("%d",&x);

    if (statut(x,mat[N][M],P1)==-1) {
      printf("Erreur sur les coordonnée des y : la colonne %d est rempli essayer une autre \n",&x);
    }

    }while ((x<0||x>6) || statut(x,mat[N][M],P1)==-1 || TypePiece != 1 || TypePiece != 2 ||TypePiece != 3 );

    inserer(x,statut(x,mat[N][M],P1),j1,mat,P1);
  }

    x=0;

    do{
      printf("Joueur 3 :Choisissez le type de votre piece (1 = bloquante , 2 = creuse , 3 = pleine):\n");
      scanf("%d",&TypePiece);
      printf("Joueur3 : Choisissez ou vous aller mettre votre piece (numero de colonne entre 0 et 6):\n");
      scanf("%d",&x);

    if (statut(x,mat[N][M],P1)==-1) {
      printf("Erreur sur les coordonnée des y : la colonne %d est rempli essayer une autre \n",&x);
    }

    }while ((x<0||x>6) || statut(x,mat[N][M],P1)==-1 || TypePiece != 1 || TypePiece != 2 ||TypePiece != 3 );

    inserer(x,statut(x,mat[N][M],P1),j1,mat,P1);
  }

    x=0;

    do{
      printf("Joueur 4 :Choisissez le type de votre piece (1 = bloquante , 2 = creuse , 3 = pleine):\n");
      scanf("%d",&TypePiece);
      printf("Joueur4 : Choisissez ou vous aller mettre votre piece (numero de colonne entre 0 et 6):\n");
      scanf("%d",&x);

    if (statut(x,mat[N][M],P1)==-1) {
      printf("Erreur sur les coordonnée des y : la colonne %d est rempli essayer une autre \n",&x);
    }

    }while ((x<0||x>6) || statut(x,mat[N][M],P1)==-1 || TypePiece != 1 || TypePiece != 2 ||TypePiece != 3 );

    inserer(x,statut(x,mat[N][M],P1),j1,mat,P1);
  }

}

if (quiGagne(mat,j1)==1) {
  printf("Le joueur 1 et 2 ont gagnés !!!! \n", );
}

else if (quiGagne(mat,j2)==1) {
  printf("Le joueur 1 et 2 ont gagnés !!!! \n", );
}

else if (quiGagne(mat,j3)==1) {
  printf("Le joueur 3 et 4 ont gagnés !!!! \n", );
}

else if (quiGagne(mat,j4)==1) {
  printf("Le joueur 3 et 4 ont gagnés !!!! \n", );
}


}
