#include <stdio.h>
#include <stdlib.h>

#define N  6
#define M  7



char mat[N][M];


typedef struct joueurs_s {
  
  char * nom;
  char * couleur;

}joueur ;

int statut(int x, char mat[N][M]){
  int y;

  for (y = M ; (mat[x][y]==('R'||'J')) || (y > 0) ; y--) ; /* on arrive au bout tant que l'emplacement est pris on remonte */

    return y ;

}

void inserer(int x, int y, joueur t, char mat[N][M]){

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



void quigagne(char mat[N][M]){
//fonction permettant de savoir qui a gagné en ayant 4 piece alignées.

    int lig ;
    int col;
    int diag;

    lig = gagnant_ligne(mat);

    if(lig == 1)
    {
        printf("Le joueur possédant la couleur rouge à gagné avec un alignement en ligne\n");
    }
    else if(lig == 2)
    {
        printf("Le joueur possédant la couleur jaune à gagné avec un alignement en ligne \n");
    }
    else
    {
        col = gagnant_colonne(mat);

        if(col == 1)
        {
            printf("Le joueur possédant la couleur rouge à gagné avec un alignement en colonne \n");
        }
        else if(col == 2)
        {
            printf("Le joueur possédant la couleur jaune à gagné avec un alignement en colonne \n");
        }
        else
        {
            diag = gagnant_diagonale(mat);

            if(diag == 1)
            {
                printf("Le joueur possédant la couleur rouge à gagné avec un alignement en diagonale \n");
            }
            else if(diag == 2)
            {
                printf("Le joueur possédant la couleur jaune à gagné avec un alignement en diagonale \n");
            }
            else
            {
                printf("Il y a aucun gagnant dans cette partie !!!\n");
            }
        }
    }
}


void JouerNormal1vs1(char mat[N][M], joueur j1, joueur j2){

int x=0;


while( quiGagne(mat)!=1 ){        // tant qu'il n'y a pas de gangnant on continue de jouer

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

quiGagne(mat);

}



int main(){
joueur j1,j2;
JouerNormal1vs1(mat,j1,j2);

}
