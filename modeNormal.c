#include <stdio.h>
#include <stdlib.h>
#include "structD.h"


int statut(int y, char mat[N][M]){
  int x;

  for (x = N-1 ;(x < 0 || (mat[x][y]=='R'||mat[x][y]=='J' )); x--) ; /* on arrive au bout tant que l'emplacement est pris on remonte */

    return x ;

}

void initMatrice(char mat[N][M]){
/* fonction qui permet de insérer un epièce dans la matrice */
	int i,j;

	for(i=1 ; i< N ; i++){
		for(j=0 ; j < M ; j++){
			mat[i][j] = 'o';
		}
	}
  for(j=0 ; j < M ; j++){
      mat[0][j]= '*';
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
    /* fonction verifiant si il y a un gagnant sur une ligne du plateau de jeu */
    int i, j;
    for (i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            /* toutes les combinaison en ligne pour le joueur rouge et retourne 1 si il a gagné */
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
            /* toutes les combinaison en lignes pour le joueur jaune et retourne 2 si il a gagné */
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
    return 0;         /* aucun gagnant dans les lignes */
}


int gagnant_colonne(char mat[N][M]){
/* fonction qui vérifie si il y a un gagnant sur les colonnes du plateau de jeu */
    int i, j;

    for (i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {

            /* toutes les combinaison en colonne pour le joueur rouge et retourne 1 si il a gagné */
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
            /* toutes les combinaison en colonne pour le joueur jaune et retourne 2 si il a gagné */
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
    return 0;             /* aucun gagnant dans les collonnes */
}


int gagnant_diagonale(char mat[N][M]){
/* fonction qui verifie si il y a un gagnant sur les diagonales du plateau de jeu */
    int i, j;
    for (i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            /* toutes les combinaison en diagonales pour le joueur rouge et retourne 1 si il a gagné */
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
            /* toutes les combinaison en diagonales pour le joueur jaune et retourne 2 si il a gagné */
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
    return 0;           /* aucun gagnant dans les diagonales */
}



int qui_gagne(char mat[N][M]){
/* fonction permettant de savoir qui a gagné en ayant 4 piece alignées. */

    int lig ;
    int col;
    int diag;

    lig = gagnant_ligne(mat);

    if(lig == 1)
    {
        return 1;               /* joueur Rouge a gagné */
    }
    else if(lig == 2)
    {
          return 2;             /* joueur Jaune a gagné */
    }
    else                        /* si il n'y a pas de gagnant avec un alignement en ligne on regarde les collonnes */
    {
        col = gagnant_colonne(mat);

        if(col == 1)
        {
            return 1;           /* joueur Rouge a gagné */
        }
        else if(col == 2)
        {
            return 2;           /* joueur Jaune a gagné */
        }
        else                    /* si il n'y a pas de gagnant avec un alignement en collonne on regarde les diagonales */
        {
            diag = gagnant_diagonale(mat);

            if(diag == 1)
            {
                return 1;           /* joueur Rouge a gagné */
            }
            else if(diag == 2)
            {
                return 2;           /* joueur Jaune a gagné */
            }
            else                    /* si il n'y a pas de gagnant avec un alignement en diagonale */
            {
                return 0;           /* égalité aucun joueur n'a gagné */
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

while( quigagne(mat)==0){        // tant qu'il n'y a pas de gangnant on continue de jouer

  // tour du premier joueur de jouer

  do{

    printf("Joueur 1 :Choisissez ou vous aller mettre votre piece (numero de colonne entre 1 et 7):\n");
    scanf("%i",&y);

  if (statut(y-1,mat)==0) {
    printf("Erreur sur les coordonnée des y : la colonne %i est rempli essayer une autre \n\n",y);
  }

}while ((y<1||y>7) || statut(y-1,mat)==0);
  y--;
  inserer(y,statut(y,mat),j1,mat);                          //on insere la piece

  afficher_mat(mat);

  if(quigagne(mat)!=1){                              // on passe au tour suivant si et selement si le joueur 1 n'a pas gagner

    // tour du deuxieme joueur de jouer
    y=0;

    do{

      printf("Joueur2 : Choisissez ou vous aller mettre votre piece (numero de colonne entre 1 et 7):\n");    //rajouter cas y n'est pas un chiffre
      scanf("%i",&y);

    if (statut(y-1,mat)==0) {
      printf("Erreur sur les coordonnée des y : la colonne %i est rempli essayer une autre \n\n",y);
    }

  }while ((y<1||y>7) || statut(y-1,mat)==0);
    y--;
    inserer(y,statut(y,mat),j2,mat);
    afficher_mat(mat);
  }

}

if(quigagne(mat)==1){
  printf("le joueur qui a les rouges a gagné ");
}
else if(quigagne(mat)==2){
  printf("le joueur qui a les jaunes a gagné ");
}

}
