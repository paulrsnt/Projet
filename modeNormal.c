#include <stdio.h>
#include <stdlib.h>

#define N  6
#define M  7



char mat[N][M];


typedef struct joueurs_s {
  
  char * nom;
  char * couleur;

}joueur ;

int statut(int y, char mat[N][M]){
  int x;

  for (x = M-1 ; (((mat[x][y]==('R'))||((mat[x][y]==('J'))) || (x < 0) ; x--) ; /* on arrive au bout tant que l'emplacement est pris on remonte */

    return x ;

}

void initMatrice(char mat[N][M]){
	int i,j;

	for(int i=0 ; i< N ; i++){
		for(int j=0 ; j < M ; j++){
			mat[i][j] = 'o';
		}
	}
}
  
void afficher_mat(char mat[N][M]){
/*fonction qui permet de afficher la matrice*/
    int i, j;
    for(i=0;i<N;i++){       /*parcour de la ligne*/
        for(j=0;j<M;j++){   /*parcour du colonnes*/
            printf("%c | ", mat[i][j]);
        }
        printf("\n");
    }
}

void inserer(int y, int x, joueur t, char mat[N][M]){

  if (t.couleur=="rouge") {
    mat[x][y]='R';
  }
  else if (t.couleur=="jaune") {
    mat[x][y]='J';
  }

}

int gagnant_ligne(char mat[N][M]){
    //fonction verifiant si il y a un gagnant sur une ligne du plateau de jeu
    int i, j;
    for (i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            //returne 1 si le joueur rouge a gagneé
            if(mat[i][j] == 'R')
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
            if(mat[i][j] ==  'J')
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


int gagnant_colonne(char mat[N][M]){
//fonction permettant de voir si il y a un gagnant sur les colonnes du plateau de jeu
    int i, j;

    for (i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {

            //returne 1 si le joueur rouge a gagneé
             if(mat[i][j] == 'R')
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
            if(mat[i][j] ==  'J')
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


int gagnant_diagonale(char mat[N][M]){
//fonction verifiant si il y a un gagnant sur une diagonale du plateau de jeu
    int i, j;
    for (i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            //returne 1 si le joueur rouge a gagné
            if(mat[i][j] == 'R')
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
            if(mat[i][j] ==  'J')
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



int quigagne(char mat[N][M]){
//fonction permettant de savoir qui a gagné en ayant 4 piece alignées.

    int lig ;
    int col;
    int diag;

    lig = gagnant_ligne(mat);

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
        col = gagnant_colonne(mat);

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
            diag = gagnant_diagonale(mat);

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


void JouerNormal1vs1(char mat[N][M], joueur j1, joueur j2){

int y=0;
initMatrice(mat);
afficher_mat(mat);
j1.couleur="rouge";
j2.couleur="jaune";
while( quiGagne(mat)==0){        // tant qu'il n'y a pas de gangnant on continue de jouer

  // tour du premier joueur de jouer

  do{

    printf("Joueur 1 :Choisissez ou vous aller mettre votre piece (numero de colonne entre 0 et 6):\n");
    scanf("%i",&y);

  if (statut(y,mat)==-1) {
    printf("Erreur sur les coordonnée des y : la colonne %ls est rempli essayer une autre \n",&y);
  }

}while ((y<0||y>6) || statut(y,mat)==-1);

  inserer(y,statut(y,mat),j1,mat);                          //on insere la piece
  
  afficher_mat(mat);
  
  if(quiGagne(mat)!=1){                              // on passe au tour suivant si et selement si le joueur 1 n'a pas gagner

    // tour du deuxieme joueur de jouer
    y=0;

    do{

      printf("Joueur2 : Choisissez ou vous aller mettre votre piece (numero de colonne entre 0 et 6):\n");
      scanf("%i",&y);

    if (statut(y,mat)==-1) {
      printf("Erreur sur les coordonnée des y : la colonne %ls est rempli essayer une autre \n",&y);
    }

  }while ((y<0||y>6) || statut(y,mat)==-1);

    inserer(y,statut(y,mat),j2,mat);
    afficher_mat(mat);
  }

}

if(quiGagne(mat)==1){
  printf("le joueur qui a les rouges a gagné ");
}
else if(quiGagne(mat)==2){
  printf("le joueur qui a les jaunes a gagné ");
}

}



int main(){
  
joueur j1,j2;
  
JouerNormal1vs1(mat,j1,j2);

}
