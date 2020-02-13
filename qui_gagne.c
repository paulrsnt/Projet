#include <stdio.h>
#include <stdlib.h>
#define N 6
#define M 7

typedef struct joueurs_s {

  char * nom;
  char * couleur;

}joueur_t;

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



void quigagne(char mat[N][M]){
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

void init_mat(char mat[N][M]){
  int i,j;
  for ( i = 0; i < N; i++) {
    for ( j = 0; j < M; j++) {
      mat[i][j]='o';
    }
  }
}


int main(){
    char mat[N][M];
    init_mat(mat);
    //mat[0][0]='R';
    mat[1][4]='T';
    mat[2][4]='T';
    mat[3][4]='T';
    mat[4][4]='T';
    afficher_mat(mat);

    quigagne(mat);
    return 0;
}
