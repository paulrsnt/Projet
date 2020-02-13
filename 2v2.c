#include <stdio.h>
#include <stdlib.h>
#include "structD.h"

int statut2v2(int y, char mat[N][M], piece p){

	int x=0;
   /* on arrive au bout tant que l'emplacement est pris on remonte */

	if(p==1){
		if(mat[x][y]!=('o')){
			return -1;
		}
		else{
			for (y=M ; (mat[x][y]!=('o')) || (y > 0) ; y--) ;
  			return y;
		}
  		
  	}
  	else if( p==2){
  		y=0;
		if(mat[x][y]!=('o')||mat[x][y]!=("RP")||mat[x][y]!=("JP")){
			return -1;
		}
		else {
			for(y=M ; ( mat[x][y]!=('o') || mat[x][y]!=("RP") || mat[x][y]!=("JP") ) || (y > 0) ; y--);
			return y;
		}
  		return y;

  	}              /* sinon on retourne -1 */
    
  	else if( p==3){
  		y=0;
		if(mat[x][y]!=('o')||mat[x][y]!=("RC")||mat[x][y]!=("JC")){
			return -1;
		}
		else {
			for(y=M ; ( mat[x][y]!=('o') || mat[x][y]!=("RC") || mat[x][y]!=("JC") ) || (y > 0) ; y--);
			return y;
		}
  		return y;

  	}

}

void inserer2v2(int x, int y, joueur t, char mat[N][M], piece p){

  if (t.couleur=="rouge") {
	if( p==1){
		mat[x][y]="RB"; /*Rouge bloquante*/
	}
	if(p==2){
		mat[x][y]="RC"; /*Rouge creuse*/
	}
	if(p==3){
		mat[x][y]="RP"; /*Rouge pleine*/
  }
  if (t.couleur=="jaune") {
	if(p==1){
		mat[x][y]="JB";
	}
	if(p==2){
		mat[x][y]="JC";
	}
	if(p==3){
		mat[x][y]="JP";
  }

}

int gagnant_ligne2v2(char mat[N][M]){
    //fonction verifiant si il y a un gagnant sur une ligne du plateau de jeu
    int i, j;
    for (i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            //returne 1 si le joueur rouge a gagneé
            if(mat[i][j] == "RC" || mat[i][j] == "RP" || mat[i][j] == "RB" )
            {
                if((mat[i][j] == mat[i][j-1]) && (mat[i][j] == mat[i][j+1]) && (mat[i][j]== mat[i][j+2]))
                {
                    return 1;
                }
                else if((mat[i][j] == mat[i][j-1]) && (mat[i][j] == mat[i][j-2]) && (mat[i][j] == mat[i][j+1]))
                {
                    return 1;
                }
                else if((mat[i][j] == mat[i][j-1]) && (mat[i][j] == mat[i][j-2]) && (mat[i][j] == mat[i][j-3]))
                {
                    return 1;
                }
                else if((mat[i][j] == mat[i][j+1]) && (mat[i][j] == mat[i][j+2]) && (mat[i][j] == mat[i][j+3]))
                {
                    return 1;
                }

            }
            //returne 2 si le joueur jaune a gagneé
            if(mat[i][j] == "JC" || mat[i][j] == "JP" || mat[i][j] == "JB")
            {
                if((mat[i][j] == mat[i][j-1]) && (mat[i][j] == mat[i][j+1]) && (mat[i][j] == mat[i][j+2]))
                {
                    return 2;
                }
                if((mat[i][j] == mat[i][j-1]) && (mat[i][j] == mat[i][j-2]) && (mat[i][j] == mat[i][j+1]))
                {
                    return 2;
                }
                if((mat[i][j] == mat[i][j-1]) && (mat[i][j] == mat[i][j-2]) && (mat[i][j] == mat[i][j-3]))
                {
                    return 2;
                }
                if((mat[i][j] == mat[i][j+1]) && (mat[i][j] == mat[i][j+2]) && (mat[i][j] == mat[i][j+3]))
                {
                    return 2;
                }


            }

        }
    }
    return 0;
}


int gagnant_colonne2v2(char mat[N][M]){
//fonction permettant de voir si il y a un gagnant sur les colonnes du plateau de jeu
    int i, j;

    for (i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {

            //returne 1 si le joueur rouge a gagneé
             if(mat[i][j] == "RC" || mat[i][j] == "RP" || mat[i][j] == "RB" )
            {
                if((mat[i][j] == mat[i+1][j]) && (mat[i][j] == mat[i-1][j]) && (mat[i][j] == mat[i-2][j]))
                {
                     return 1;
                }
                if((mat[i][j] == mat[i+1][j]) && (mat[i][j] == mat[i+2][j]) && (mat[i][j] == mat[i+3][j]))
                {
                    return 1;
                }
                if((mat[i][j] == mat[i-1][j]) && (mat[i][j] == mat[i+1][j]) && (mat[i][j] == mat[i+2][j]))
                {
                    return 1;
                }
                if((mat[i][j] == mat[i-1][j]) && (mat[i][j] == mat[i-2][j]) && (mat[i][j] == mat[i-3][j]))
                {
                    return 1;
                }
            }
            //returne 2 si le joueur jaune a gagneé
            if(mat[i][j] == "JC" || mat[i][j] == "JP" || mat[i][j] == "JB")
            {
                if((mat[i][j] == mat[i+1][j]) && (mat[i][j] == mat[i-1][j]) && (mat[i][j] == mat[i-2][j]))
                {
                    return 2;
                }
                if((mat[i][j] == mat[i+1][j]) && (mat[i][j] == mat[i+2][j]) && (mat[i][j] == mat[i+3][j]))
                {
                    return 2;
                }
                if((mat[i][j] == mat[i-1][j]) && (mat[i][j] == mat[i+1][j]) && (mat[i][j] == mat[i+2][j]))
                {
                    return 2;
                }
                if((mat[i][j] == mat[i-1][j]) && (mat[i][j] == mat[i-2][j]) && (mat[i][j] == mat[i-3][j]))
                {
                    return 2;
                }
            }

        }
    }
    return 0;
}


int gagnant_diagonale2v2(char mat[N][M]){
//fonction verifiant si il y a un gagnant sur une diagonale du plateau de jeu
    int i, j;
    for (i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            //returne 1 si le joueur rouge a gagné
            if(mat[i][j] == "RC" || mat[i][j] == "RP" || mat[i][j] == "RB")
            {
                if((mat[i][j] == mat[i-1][j+1]) && (mat[i][j] == mat[i-2][j+2]) && (mat[i][j] == mat[i-3][j+3]))
                {
                    return 1;
                }
                if((mat[i][j] == mat[i+1][j-1]) && (mat[i][j] == mat[i+2][j-2]) && (mat[i][j] == mat[i+3][j-3]))
                {
                    return 1;
                }
                if((mat[i][j] == mat[i+1][j-1]) && (mat[i][j] == mat[i-1][j+1]) && (mat[i][j] == mat[i-2][j+2]))
                {
                    return 1;
                }
                if((mat[i][j] == mat[i-1][j+1]) && (mat[i][j] == mat[i+1][j-1]) && (mat[i][j] == mat[i+2][j-2]))
                {
                    return 1;
                }
                if((mat[i][j] == mat[i-1][j-1]) && (mat[i][j] == mat[i-2][j-2]) && (mat[i][j] == mat[i-3][j-3]))
                {
                    return 1;
                }
                if((mat[i][j] == mat[i+1][j+1]) && (mat[i][j] == mat[i+2][j+2]) && (mat[i][j] == mat[i+3][j+3]))
                {
                    return 1;
                }
                if((mat[i][j] == mat[i-1][j-1]) && (mat[i][j] == mat[i+1][j+1]) && (mat[i][j] == mat[i+2][j+2]))
                {
                    return 1;
                }
                if((mat[i][j] == mat[i+1][j+1]) && (mat[i][j] == mat[i-1][j-1]) && (mat[i][j] == mat[i-2][j-2]))
                {
                    return 1;
                }

            }
            //returne 2 si le joueur jaune a gagné
            if(mat[i][j] == "JC" || mat[i][j] == "JP" || mat[i][j] == "JB")
            {
                if((mat[i][j] == mat[i-1][j+1]) && (mat[i][j] == mat[i-2][j+2]) && (mat[i][j] == mat[i-3][j+3]))
                {
                    return 2;
                }
                if((mat[i][j] == mat[i+1][j-1]) && (mat[i][j] == mat[i+2][j-2]) && (mat[i][j] == mat[i+3][j-3]))
                {
                    return 2;
                }
                if((mat[i][j] == mat[i+1][j-1]) && (mat[i][j] == mat[i-1][j+1]) && (mat[i][j] == mat[i-2][j+2]))
                {
                    return 2;
                }
                if((mat[i][j] == mat[i-1][j+1]) && (mat[i][j] == mat[i+1][j-1]) && (mat[i][j] == mat[i+2][j-2]))
                {
                    return 2;
                }
                if((mat[i][j] == mat[i-1][j-1]) && (mat[i][j] == mat[i-2][j-2]) && (mat[i][j] == mat[i-3][j-3]))
                {
                    return 2;
                }
                if((mat[i][j] == mat[i+1][j+1]) && (mat[i][j] == mat[i+2][j+2]) && (mat[i][j] == mat[i+3][j+3]))
                {
                    return 2;
                }
                if((mat[i][j] == mat[i-1][j-1]) && (mat[i][j] == mat[i+1][j+1]) && (mat[i][j] == mat[i+2][j+2]))
                {
                    return 2;
                }
                if((mat[i][j] == mat[i+1][j+1]) && (mat[i][j] == mat[i-1][j-1]) && (mat[i][j] == mat[i-2][j-2]))
                {
                    return 2;
                }
            }

        }
    }
    return 0;
}



int quigagne2v2(char mat[N][M]){
//fonction permettant de savoir qui a gagné en ayant 4 piece alignées.

    int lig ;
    int col;
    int diag;

    lig = gagnant_ligne2v2(mat);

    if(lig == 1)
    {
        return 1;
    }
    else if(lig == 2)
    {
        return 2;
    }
    else
    {
        col = gagnant_colonne2v2(mat);

        if(col == 1)
        {
            return 1;
        }
        else if(col == 2)
        {
            return 2;
        }
        else
        {
            diag = gagnant_diagonale2v2(mat);

            if(diag == 1)
            {
                return 1;
            }
            else if(diag == 2)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
    }
}


void Jouer2vs2(char mat[N][M], joueur j1, joueur j2, joueur j3, joueur j4, piece P1){

int x=0;
int TypePiece=0;

j1.couleur="rouge";
j2.couleur="jaune";
j3.couleur="rouge";
j4.couleur="jaune";

while( quigagne2v2(mat)!=1 || quigagne2v2(mat)!=2){        // tant qu'il n'y a pas de gangnant on continue de jouer

  // tour du premier joueur de jouer

  do{
    printf("Joueur 1 (equipe rouge) :Choisissez le type de votre piece (1 = bloquante , 2 = creuse , 3 = pleine):\n");
    scanf("%d",&TypePiece);
    printf("Joueur 1 :Choisissez ou vous aller mettre votre piece (numero de colonne entre 0 et 6):\n");
    scanf("%d",&x);

  if (statut2v2(x,mat,P1)==-1) {
    printf("Erreur sur les coordonnée des y : la colonne %d est rempli essayer une autre \n",&x);
  }

  }while ((x<0||x>6) || statut2v2(x,mat,P1)==-1 || TypePiece != 1 || TypePiece != 2 ||TypePiece != 3 );

  inserer2v2(x,statut2v2(x,mat,P1),j1,mat,P1);                          //on insere la piece

  if(quigagne2v2(mat)==0){                              // on passe au tour suivant si et selement si le joueur 1 n'a pas gagner

    // tour du deuxieme joueur de jouer
    x=0;

    do{
      printf("Joueur 2 (equipe jaune) :Choisissez le type de votre piece (1 = bloquante , 2 = creuse , 3 = pleine):\n");
      scanf("%d",&TypePiece);
      printf("Joueur2 : Choisissez ou vous aller mettre votre piece (numero de colonne entre 0 et 6):\n");
      scanf("%d",&x);

    if (statut2v2(x,mat,P1)==-1) {
      printf("Erreur sur les coordonnée des y : la colonne %d est rempli essayer une autre \n",&x);
    }

    }while ((x<0||x>6) || statut2v2(x,mat,P1)==-1 || TypePiece != 1 || TypePiece != 2 ||TypePiece != 3 );

    inserer2v2(x,statut2v2(x,mat,P1),j1,mat,P1);
  }

    x=0;

    do{
      printf("Joueur 3 (equipe rouge) :Choisissez le type de votre piece (1 = bloquante , 2 = creuse , 3 = pleine):\n");
      scanf("%d",&TypePiece);
      printf("Joueur3 : Choisissez ou vous aller mettre votre piece (numero de colonne entre 0 et 6):\n");
      scanf("%d",&x);

    if (statut2v2(x,mat,P1)==-1) {
      printf("Erreur sur les coordonnée des y : la colonne %d est rempli essayer une autre \n",&x);
    }

    }while ((x<0||x>6) || statut2v2(x,mat,P1)==-1 || TypePiece != 1 || TypePiece != 2 ||TypePiece != 3 );

    inserer2v2(x,statut2v2(x,mat,P1),j1,mat,P1);
  }

    x=0;

    do{
      printf("Joueur 4 (equipe jaune) :Choisissez le type de votre piece (1 = bloquante , 2 = creuse , 3 = pleine):\n");
      scanf("%d",&TypePiece);
      printf("Joueur4 : Choisissez ou vous aller mettre votre piece (numero de colonne entre 0 et 6):\n");
      scanf("%d",&x); 

    if (statut2v2(x,mat,P1)==-1) {
      printf("Erreur sur les coordonnée des y : la colonne %d est rempli essayer une autre \n",&x);
    }

    }while ((x<0||x>6) || statut2v2(x,mat,P1)==-1 || TypePiece != 1 || TypePiece != 2 ||TypePiece != 3 );

    inserer2v2(x,statut2v2(x,mat,P1),j1,mat,P1);
  }

}

if (quigagne2v2(mat)==1) {
  printf("Le joueur 1 et 3 ont gagnés !!!! \n", );
}


else if (quigagne2v2(mat)==1) {
  printf("Le joueur 2 et 4 ont gagnés !!!! \n", );
}


}
