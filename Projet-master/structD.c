#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structD.h"
/**

* \file structD.h
* \brief Programme contenant les stucture et variable constante du jeu du puissance 4++
* \author Aaron Amani Oussama Belkadi Fathi et Paul riga
* \version 1.0
* \date 17 fevrier 2020

*/

#define N  7
#define M  7


/**
 * \fn int grille_plein(char mat[N][M])
 * \brief fonction qui retourne 1 si la grille est pleine, 0 si elle ne l'est pas
 *
 * \param mat la grille du jeu.
 *
 * \return int.
*/
extern
int grille_plein(char mat[N][M]){
  int cpt=0;
  for (int i = 1; i < N; i++) {
    for (int y = 0; y < M; y++) {
      if (mat[i][y]=='R'||mat[i][y]=='J');
      else{
        return 0;
      }
    }
  }
  return 1;
}

/**
 * \fn int statut(int y, char mat[N][M])
 * \brief verifie le numero de colonne et retourne la ligne de disponible ou pas
 *
 * \param y numero de colonne.
 * \param mat la grille du jeu.
 *
 * \return int.
*/
extern
int statut(int y, char mat[N][M]){
  int x;

  for (x = N-1 ;(x < 0 || (mat[x][y]=='R'||mat[x][y]=='J' )); x--) ; /* on arrive au bout tant que l'emplacement est pris on remonte */

    return x ;

}

/**
 * \fn void initMatrice(char mat[N][M])
 * \brief fonction qui initialise la matrice
 *
 * \param mat la grille du jeu.
 *
 *
*/
extern
void initMatrice(char mat[N][M]){
/* fonction qui permet de initialiser la matrice */
	int i,j;

	for(i=1 ; i< N ; i++){
		for(j=0 ; j < M ; j++){
			mat[i][j] = ' ';
		}
	}
  for(j=0 ; j < M ; j++){	/* permet de faire une bordure dans la matrice qui vas permettre de ne pas sortir de la matrice */
      mat[0][j]= '*';
    }

}


/**
 * \fn void afficher_mat(char mat[N][M])
 * \brief fonction qui affiche la matrice du jeu
 *
 * \param mat la grille du jeu.
 *
 *
*/
extern
void afficher_mat(char mat[N][M]){
    int i, j;
    for(i=1;i<N;i++){
        for(j=0;j<M;j++){
            printf("| %c |", mat[i][j]);
        }
        printf("\n");
    }
}


/**
 * \fn void inserer(int y, int x, joueur t, char mat[N][M])
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
void inserer(int y, int x, joueur t, char mat[N][M]){
/* fonction qui permet de insérer un epièce dans la matrice */
  if (t.couleur=="rouge") {
    mat[x][y]='R';
  }
  else if (t.couleur=="jaune") {
    mat[x][y]='J';
  }

}


/**
 * \fn int gagnant_lignev2(char mat[N][M])
 * \brief fonction retourne 1 si les jaunes gagnent avec les pion en lignes ou 2 si les rouges gagnent avec les pion en lignes
 *
 * \param mat la grille du jeu.
 *
 * \return int.
*/
extern
int parcours_ligne(char mat[N][M]){
/* fonction verifiant si il y a un gagnant sur une ligne du plateau de jeu */
    int i, j;
    for (i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            /* toutes les combinaison en ligne pour le joueur rouge et retourne 1 si il a gagné */
            if(mat[i][j] == 'R')
            {

              if ((j-1)>=0 || (j-1)<=6 ) {
                if ((j+1)>=0 || (j+1)<=6 ) {
                  if ((j+2)>=0 || (j+2)<=6 ) {
                    if((mat[i][j] == mat[i][j-1]) && (mat[i][j] == mat[i][j+1]) && (mat[i][j] == mat[i][j+2]))
                    {
                      mat[i][j]='*';
                      mat[i][j-1]=mat[i][j] ;
                      mat[i][j+1]=mat[i][j];
                      mat[i][j+2]=mat[i][j];
                              system("clear");
                      afficher_mat(mat);
                      return 1;
                  }
                }
              }
            }

                else if ((j-1)>=0 || (j-1)<=6 ) {
                  if ((j-2)>=0 || (j-2)<=6 ) {
                    if ((j+1)>=0 || (j+1)<=6 ) {
                      if((mat[i][j] == mat[i][j-1]) && (mat[i][j] == mat[i][j-2]) && (mat[i][j] == mat[i][j+1]))
                      {
                        mat[i][j]='*';
                        mat[i][j-1]=mat[i][j] ;
                        mat[i][j-2]=mat[i][j];
                        mat[i][j+1]=mat[i][j];
                                system("clear");
                        afficher_mat(mat);
                        return 1;
                    }
                  }
                }
              }
                else if ((j-1)>=0 || (j-1)<=6 ) {
                  if ((j-2)>=0 || (j-2)<=6 ) {
                    if ((j-3)>=0 || (j-3)<=6 ) {
                      if((mat[i][j] == mat[i][j-1]) && (mat[i][j] == mat[i][j-2]) && (mat[i][j] == mat[i][j-3]))
                      {
                        mat[i][j]='*';
                        mat[i][j-1]=mat[i][j] ;
                        mat[i][j-2]=mat[i][j];
                        mat[i][j-3]=mat[i][j];
                                system("clear");
                        afficher_mat(mat);
                        return 1;
                    }
                  }
                }
              }
                else if ((j+1)>=0 || (j+1)<=6 ) {
                  if ((j+2)>=0 || (j+2)<=6 ) {
                    if ((j+3)>=0 || (j+3)<=6 ) {
                      if((mat[i][j] == mat[i][j+1]) && (mat[i][j] == mat[i][j+2]) && (mat[i][j] == mat[i][j+3]))
                      {
                        mat[i][j]='*';
                        mat[i][j+1]=mat[i][j] ;
                        mat[i][j+2]=mat[i][j];
                        mat[i][j+3]=mat[i][j];
                                system("clear");
                        afficher_mat(mat);
                        return 1;
                    }
                  }
                }
              }

            }
            /* toutes les combinaison en lignes pour le joueur jaune et retourne 2 si il a gagné */
            if(mat[i][j] ==  'J')
            {

              if ((j-1)>=0 || (j-1)<=6 ) {
                if ((j+1)>=0 || (j+1)<=6 ) {
                  if ((j+2)>=0 || (j+2)<=6 ) {
                    if((mat[i][j] == mat[i][j-1]) && (mat[i][j] == mat[i][j+1]) && (mat[i][j] == mat[i][j+2]))
                    {
                      mat[i][j]='*';
                      mat[i][j-1]=mat[i][j] ;
                      mat[i][j+1]=mat[i][j];
                      mat[i][j+2]=mat[i][j];
                              system("clear");
                      afficher_mat(mat);
                      return 2;
                  }
                }
              }
            }

                else if ((j-1)>=0 || (j-1)<=6 ) {
                  if ((j-2)>=0 || (j-2)<=6 ) {
                    if ((j+1)>=0 || (j+1)<=6 ) {
                      if((mat[i][j] == mat[i][j-1]) && (mat[i][j] == mat[i][j-2]) && (mat[i][j] == mat[i][j+1]))
                      {
                        mat[i][j]='*';
                        mat[i][j-1]=mat[i][j] ;
                        mat[i][j-2]=mat[i][j];
                        mat[i][j+1]=mat[i][j];
                                system("clear");
                        afficher_mat(mat);
                        return 2;
                    }
                  }
                }
              }
                else if ((j-1)>=0 || (j-1)<=6 ) {
                  if ((j-2)>=0 || (j-2)<=6 ) {
                    if ((j-3)>=0 || (j-3)<=6 ) {
                      if((mat[i][j] == mat[i][j-1]) && (mat[i][j] == mat[i][j-2]) && (mat[i][j] == mat[i][j-3]))
                      {
                        mat[i][j]='*';
                        mat[i][j-1]=mat[i][j] ;
                        mat[i][j-2]=mat[i][j];
                        mat[i][j-3]=mat[i][j];
                                system("clear");
                        afficher_mat(mat);
                        return 2;
                    }
                  }
                }
              }
                else if ((j+1)>=0 || (j+1)<=6 ) {
                  if ((j+2)>=0 || (j+2)<=6 ) {
                    if ((j+3)>=0 || (j+3)<=6 ) {
                      if((mat[i][j] == mat[i][j+1]) && (mat[i][j] == mat[i][j+2]) && (mat[i][j] == mat[i][j+3]))
                      {
                        mat[i][j]='*';
                        mat[i][j+1]=mat[i][j] ;
                        mat[i][j+2]=mat[i][j];
                        mat[i][j+3]=mat[i][j];
                                system("clear");
                        afficher_mat(mat);
                        return 2;
                    }
                  }
                }
              }

            }

        }
    }
    return 0;         /* aucun gagnant dans les lignes */
}


/**
 * \fn int gagnant_colonnev2(char mat[N][M])
 * \brief fonction retourne 1 si les jaunes gagnent avec les pion en colonnes ou 2 si les rouges gagnent avec les pion en colonnes
 *
 * \param mat la grille du jeu.
 *
 * \return int.
*/
extern
int parcours_colonne(char mat[N][M]){
/* fonction qui vérifie si il y a un gagnant sur les colonnes du plateau de jeu */
    int i, j;

    for (i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {

            /* toutes les combinaison en colonne pour le joueur rouge et retourne 1 si il a gagné */
             if(mat[i][j] == 'R')
             {

               if ((i-1)>=0 || (i-1)<=6 ) {
                 if ((i+1)>=0 || (i+1)<=6 ) {
                   if ((i+2)>=0 || (i+2)<=6 ) {
                     if((mat[i][j] == mat[i-1][j]) && (mat[i][j] == mat[i+1][j]) && (mat[i][j] == mat[i+2][j]))
                     {
                       mat[i][j]='*';
                       mat[i-1][j]=mat[i][j] ;
                       mat[i+1][j]=mat[i][j];
                       mat[i+2][j]=mat[i][j];
                               system("clear");
                       afficher_mat(mat);
                       return 1;
                   }
                 }
               }
             }

                 else if ((i-1)>=0 || (i-1)<=6 ) {
                   if ((i-2)>=0 || (i-2)<=6 ) {
                     if ((i+1)>=0 || (i+1)<=6 ) {
                       if((mat[i][j] == mat[i-1][j]) && (mat[i][j] == mat[i-2][j]) && (mat[i][j] == mat[i+1][j]))
                       {
                         mat[i][j]='*';
                         mat[i-1][j]=mat[i][j] ;
                         mat[i-2][j]=mat[i][j];
                         mat[i+1][j]=mat[i][j];
                                 system("clear");
                         afficher_mat(mat);
                         return 1;
                     }
                   }
                 }
               }
                 else if ((i-1)>=0 || (i-1)<=6 ) {
                   if ((i-2)>=0 || (i-2)<=6 ) {
                     if ((i-3)>=0 || (i-3)<=6 ) {
                       if((mat[i][j] == mat[i-1][j]) && (mat[i][j] == mat[i-2][j]) && (mat[i][j] == mat[i-3][j]))
                       {
                         mat[i][j]='*';
                         mat[i-1][j]=mat[i][j] ;
                         mat[i-2][j]=mat[i][j];
                         mat[i-3][j]=mat[i][j];
                                 system("clear");
                         afficher_mat(mat);
                         return 1;
                     }
                   }
                 }
               }
                 else if ((i+1)>=0 || (i+1)<=6 ) {
                   if ((i+2)>=0 || (i+2)<=6 ) {
                     if ((i+3)>=0 || (i+3)<=6 ) {
                       if((mat[i][j] == mat[i+1][j]) && (mat[i][j] == mat[i+2][j]) && (mat[i][j] == mat[i+3][j]))
                       {
                         mat[i][j]='*';
                         mat[i-1][j]=mat[i][j] ;
                         mat[i+2][j]=mat[i][j];
                         mat[i+3][j]=mat[i][j];
                                 system("clear");
                         afficher_mat(mat);
                         return 1;
                     }
                   }
                 }
               }

             }
            /* toutes les combinaison en colonne pour le joueur jaune et retourne 2 si il a gagné */
            if(mat[i][j] ==  'J')
            {

              if ((i-1)>=0 || (i-1)<=6 ) {
                if ((i+1)>=0 || (i+1)<=6 ) {
                  if ((i+2)>=0 || (i+2)<=6 ) {
                    if((mat[i][j] == mat[i-1][j]) && (mat[i][j] == mat[i+1][j]) && (mat[i][j] == mat[i+2][j]))
                    {
                      mat[i][j]='*';
                      mat[i-1][j]=mat[i][j] ;
                      mat[i+1][j]=mat[i][j];
                      mat[i+2][j]=mat[i][j];
                              system("clear");
                      afficher_mat(mat);
                      return 2;
                  }
                }
              }
            }

                else if ((i-1)>=0 || (i-1)<=6 ) {
                  if ((i-2)>=0 || (i-2)<=6 ) {
                    if ((i+1)>=0 || (i+1)<=6 ) {
                      if((mat[i][j] == mat[i-1][j]) && (mat[i][j] == mat[i-2][j]) && (mat[i][j] == mat[i+1][j]))
                      {
                        mat[i][j]='*';
                        mat[i-1][j]=mat[i][j] ;
                        mat[i-2][j]=mat[i][j];
                        mat[i+1][j]=mat[i][j];
                                system("clear");
                        afficher_mat(mat);
                        return 2;
                    }
                  }
                }
              }
                else if ((i-1)>=0 || (i-1)<=6 ) {
                  if ((i-2)>=0 || (i-2)<=6 ) {
                    if ((i-3)>=0 || (i-3)<=6 ) {
                      if((mat[i][j] == mat[i-1][j]) && (mat[i][j] == mat[i-2][j]) && (mat[i][j] == mat[i-3][j]))
                      {
                        mat[i][j]='*';
                        mat[i-1][j]=mat[i][j] ;
                        mat[i-2][j]=mat[i][j];
                        mat[i-3][j]=mat[i][j];
                                system("clear");
                        afficher_mat(mat);
                        return 2;
                    }
                  }
                }
              }
                else if ((i+1)>=0 || (i+1)<=6 ) {
                  if ((i+2)>=0 || (i+2)<=6 ) {
                    if ((i+3)>=0 || (i+3)<=6 ) {
                      if((mat[i][j] == mat[i+1][j]) && (mat[i][j] == mat[i+2][j]) && (mat[i][j] == mat[i+3][j]))
                      {
                        mat[i][j]='*';
                        mat[i-1][j]=mat[i][j] ;
                        mat[i+2][j]=mat[i][j];
                        mat[i+3][j]=mat[i][j];
                                system("clear");
                        afficher_mat(mat);
                        return 2;
                    }
                  }
                }
              }

            }

        }
    }
    return 0;             /* aucun gagnant dans les collonnes */
}

/**
 * \fn int gagnant_diagonalev2(char mat[N][M])
 * \brief fonction retourne 1 si les jaunes gagnent avec les pion en diagonale ou 2 si les rouges gagnent avec les pion en diagonale
 *
 * \param mat la grille du jeu.
 *
 * \return int.
*/

extern
int parcours_diagonale(char mat[N][M]){
/* fonction qui verifie si il y a un gagnant sur les diagonales du plateau de jeu */
    int i, j;
    for (i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            /* toutes les combinaison en diagonales pour le joueur rouge et retourne 1 si il a gagné */
            if(mat[i][j] == 'R')
            {

                  if ( ((i-1)>=0 && (i-1)<=6) && ((j+1)>=0 && (j+1)<=6) ) {
                    if ( ((i-2)>=0 && (i-2)<=6) && ((j+2)>=0 && (j+2)<=6) ) {
                      if ( ((i-3)>=0 && (i-3)<=6) && ((j+3)>=0 && (j+3)<=6) ) {
                        if((mat[i][j] == mat[i-1][j+1]) && (mat[i][j] == mat[i-2][j+2]) && (mat[i][j] == mat[i-3][j+3]))
                        {
                        mat[i][j]='*';
                        mat[i-1][j+1]=mat[i][j] ;
                        mat[i-2][j+2]=mat[i][j];
                        mat[i-3][j+3]=mat[i][j];
                                system("clear");
                        afficher_mat(mat);
                          return 1;

                      }
                    }
                  }


                }


                  if ( (i+1)>=0 && (i+1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                    if ( (i+2)>=0 && (i+2)<=6 && (j-2)>=0 && (j-2)<=6 ) {
                      if ( (i+3)>=0 && (i+3)<=6 && (j-3)>=0 && (j-3)<=6 ) {
                        if((mat[i][j] == mat[i+1][j-1]) && (mat[i][j] == mat[i+2][j-2]) && (mat[i][j] == mat[i+3][j-3]))
                        {
                        mat[i][j]='*';
                        mat[i+1][j-1]=mat[i][j];
                        mat[i+2][j-2]=mat[i][j];
                        mat[i+3][j-3]=mat[i][j];
                                system("clear");
                        afficher_mat(mat);
                          return 1;

                      }
                    }
                  }


                }

                  if ( (i+1)>=0 && (i+1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                    if ( (i-1)>=0 && (i-1)<=6 && (j+1)>=0 && (j+1)<=6 ) {
                      if ( (i-2)>=0 && (i-2)<=6 && (j+2)>=0 && (j+2)<=6 ) {
                        if((mat[i][j] == mat[i+1][j-1]) && (mat[i][j] == mat[i-1][j+1]) && (mat[i][j] == mat[i-2][j+2]))
                        {
                        mat[i][j]='*';
                        mat[i+1][j-1]=mat[i][j];
                        mat[i-1][j+1]=mat[i][j];
                        mat[i-2][j+2]=mat[i][j];
                                system("clear");
                        afficher_mat(mat);
                          return 1;

                      }
                    }
                  }
                }

                  if ( (i-1)>=0 && (i-1)<=6 && (j+1)>=0 && (j+1)<=6 ) {
                    if ( (i+1)>=0 && (i+1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                      if ( (i+2)>=0 && (i+2)<=6 && (j-2)>=0 && (j-2)<=6 ) {
                        if((mat[i][j] == mat[i-1][j+1]) && (mat[i][j] == mat[i+1][j-1]) && (mat[i][j] == mat[i+2][j-2]))
                        {
                        mat[i][j]='*';
                        mat[i-1][j+1]=mat[i][j]+1;
                        mat[i+1][j-1]=mat[i][j]+1;
                        mat[i+2][j-2]=mat[i][j]+1;
                        system("clear");
                        afficher_mat(mat);
                          return 1;

                      }
                    }
                  }

                }


                  if ( (i-1)>=0 && (i-1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                    if ( (i-2)>=0 && (i-2)<=6 && (j-2)>=0 && (j-2)<=6 ) {
                      if ( (i-3)>=0 && (i-3)<=6 && (j-3)>=0 && (j-3)<=6 ) {
                        if((mat[i][j] == mat[i-1][j-1]) && (mat[i][j] == mat[i-2][j-2]) && (mat[i][j] == mat[i-3][j-3]))
                        {
                        mat[i][j]='*';
                        mat[i-1][j-1]=mat[i][j];
                        mat[i-2][j-2]=mat[i][j];
                        mat[i-3][j-3]=mat[i][j];
                        afficher_mat(mat);
                          return 1;

                      }
                    }
                  }



                }


                  if ( ((i+1)>=0 && (i+1)<=6 )&& ((j+1)>=0 && (j+1)<=6) ) {
                    if ( ((i+2)>=0 && (i+2)<=6) && ((j+2)>=0 && (j+2)<=6) ) {
                      if ( ((i+3)>=0 && (i+3)<=6) && ((j+3)>=0 && (j+3)<=6) ) {
                        if((mat[i][j] == mat[i+1][j+1]) && (mat[i][j] == mat[i+2][j+2]) && (mat[i][j] == mat[i+3][j+3]))
                        {
                        mat[i][j]='*';
                        mat[i+1][j+1]=mat[i][j];
                        mat[i+2][j+2]=mat[i][j];
                        mat[i+3][j+3]=mat[i][j];
                        system("clear");
                        afficher_mat(mat);
                          return 1;

                      }
                    }
                  }
                }

                  if ( (i-1)>=0 && (i-1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                    if ( (i+1)>=0 && (i+1)<=6 && (j+1)>=0 && (j+1)<=6 ) {
                      if ( (i+2)>=0 && (i+2)<=6 && (j-2)>=0 && (j-2)<=6 ) {
                        if((mat[i][j] == mat[i-1][j-1]) && (mat[i][j] == mat[i+1][j+1]) && (mat[i][j] == mat[i+2][j+2]))
                        {
                        mat[i][j]='*';
                        mat[i-1][j-1]=mat[i][j];
                        mat[i+1][j+1]=mat[i][j];
                        mat[i+2][j-2]=mat[i][j];
                        system("clear");
                        afficher_mat(mat);
                          return 1;

                      }
                    }
                  }
                }

                  if ( (i+1)>=0 && (i+1)<=6 && (j+1)>=0 && (j+1)<=6 ) {
                    if ( (i-1)>=0 && (i-1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                      if ( (i-2)>=0 && (i-2)<=6 && (j-2)>=0 && (j-2)<=6 ) {
                        if((mat[i][j] == mat[i+1][j+1]) && (mat[i][j] == mat[i-1][j-1]) && (mat[i][j] == mat[i-2][j-2]))
                        {
                        mat[i][j]='*';
                        mat[i+1][j+1]=mat[i][j];
                        mat[i-1][j-1]=mat[i][j];
                        mat[i-2][j-2]=mat[i][j];
                        system("clear");
                        afficher_mat(mat);
                          return 1;

                      }
                    }
                  }
                }

            }
            /* toutes les combinaison en diagonales pour le joueur jaune et retourne 2 si il a gagné */
            if(mat[i][j] ==  'J')
            {

                if ( (i-1)>=0 && (i-1)<=6 && (j+1)>=0 && (j+1)<=6 ) {
                  if ( (i-2)>=0 && (i-2)<=6 && (j+2)>=0 && (j+2)<=6 ) {
                    if ( (i-3)>=0 && (i-3)<=6 && (j+3)>=0 && (j+3)<=6 ) {
                      if((mat[i][j] == mat[i-1][j+1]) && (mat[i][j] == mat[i-2][j+2]) && (mat[i][j] == mat[i-3][j+3]))
                      {
                      mat[i][j]='*';
                      mat[i-1][j+1]=mat[i][j] ;
                      mat[i-2][j+2]=mat[i][j];
                      mat[i-3][j+3]=mat[i][j];
                              system("clear");
                      afficher_mat(mat);
                        return 2;

                    }
                  }
                }
              }

                if ( (i+1)>=0 && (i+1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                  if ( (i+2)>=0 && (i+2)<=6 && (j-2)>=0 && (j-2)<=6 ) {
                    if ( (i+3)>=0 && (i+3)<=6 && (j-3)>=0 && (j-3)<=6 ) {
                      if((mat[i][j] == mat[i+1][j-1]) && (mat[i][j] == mat[i+2][j-2]) && (mat[i][j] == mat[i+3][j-3]))
                      {

                      mat[i][j]='*';
                      mat[i+1][j-1]=mat[i][j];
                      mat[i+2][j-2]=mat[i][j];
                      mat[i+3][j-3]=mat[i][j];
                              system("clear");
                      afficher_mat(mat);
                        return 2;

                    }
                  }
                }
              }

                if ( (i+1)>=0 && (i+1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                  if ( (i-1)>=0 && (i-1)<=6 && (j+1)>=0 && (j+1)<=6 ) {
                    if ( (i-2)>=0 && (i-2)<=6 && (j+2)>=0 && (j+2)<=6 ) {
                      if((mat[i][j] == mat[i+1][j-1]) && (mat[i][j] == mat[i-1][j+1]) && (mat[i][j] == mat[i-2][j+2]))
                      {
                      mat[i][j]='*';
                      mat[i+1][j-1]=mat[i][j];
                      mat[i-1][j+1]=mat[i][j];
                      mat[i-2][j+2]=mat[i][j];
                      system("clear");
                      afficher_mat(mat);
                        return 2;

                    }
                  }
                }
              }

                if ( (i-1)>=0 && (i-1)<=6 && (j+1)>=0 && (j+1)<=6 ) {
                  if ( (i+1)>=0 && (i+1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                    if ( (i+2)>=0 && (i+2)<=6 && (j-2)>=0 && (j-2)<=6 ) {
                      if((mat[i][j] == mat[i-1][j+1]) && (mat[i][j] == mat[i+1][j-1]) && (mat[i][j] == mat[i+2][j-2]))
                      {
                      mat[i][j]='*';
                      mat[i-1][j+1]=mat[i][j];
                      mat[i+1][j-1]=mat[i][j];
                      mat[i+2][j-2]=mat[i][j];
                      system("clear");
                      afficher_mat(mat);
                        return 2;

                    }
                  }
                }
              }

                if ( (i-1)>=0 && (i-1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                  if ( (i-2)>=0 && (i-2)<=6 && (j-2)>=0 && (j-2)<=6 ) {
                    if ( (i-3)>=0 && (i-3)<=6 && (j-3)>=0 && (j-3)<=6 ) {
                      if((mat[i][j] == mat[i-1][j-1]) && (mat[i][j] == mat[i-2][j-2]) && (mat[i][j] == mat[i-3][j-3]))
                      {
                      mat[i][j]='*';
                      mat[i-1][j-1]=mat[i][j];
                      mat[i-2][j-2]=mat[i][j];
                      mat[i-3][j-3]=mat[i][j];
                      afficher_mat(mat);
                        return 2;

                    }
                  }
                }
              }


                if ( (i+1)>=0 && (i+1)<=6 && (j+1)>=0 && (j+1)<=6 ) {
                  if ( (i+2)>=0 && (i+2)<=6 && (j+2)>=0 && (j+2)<=6 ) {
                    if ( (i+3)>=0 && (i+3)<=6 && (j+3)>=0 && (j+3)<=6 ) {
                      if((mat[i][j] == mat[i+1][j+1]) && (mat[i][j] == mat[i+2][j+2]) && (mat[i][j] == mat[i+3][j+3]))
                      {
                      mat[i][j]='*';
                      mat[i+1][j+1]=mat[i][j];
                      mat[i+2][j+2]=mat[i][j];
                      mat[i+3][j+3]=mat[i][j];
                      system("clear");
                      afficher_mat(mat);
                        return 2;

                    }
                  }
                }
              }

                if ( (i-1)>=0 && (i-1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                  if ( (i+1)>=0 && (i+1)<=6 && (j+1)>=0 && (j+1)<=6 ) {
                    if ( (i+2)>=0 && (i+2)<=6 && (j-2)>=0 && (j-2)<=6 ) {
                      if((mat[i][j] == mat[i-1][j-1]) && (mat[i][j] == mat[i+1][j+1]) && (mat[i][j] == mat[i+2][j+2]))
                      {
                      mat[i][j]='*';
                      mat[i-1][j-1]=mat[i][j];
                      mat[i+1][j+1]=mat[i][j];
                      mat[i+2][j-2]=mat[i][j];
                      system("clear");
                      afficher_mat(mat);
                        return 2;

                    }
                  }
                }
              }

                if ( (i+1)>=0 && (i+1)<=6 && (j+1)>=0 && (j+1)<=6 ) {
                  if ( (i-1)>=0 && (i-1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                    if ( (i-2)>=0 && (i-2)<=6 && (j-2)>=0 && (j-2)<=6 ) {
                      if((mat[i][j] == mat[i+1][j+1]) && (mat[i][j] == mat[i-1][j-1]) && (mat[i][j] == mat[i-2][j-2]))
                      {
                      mat[i][j]='*';
                      mat[i+1][j+1]=mat[i][j];
                      mat[i-1][j-1]=mat[i][j];
                      mat[i-2][j-2]=mat[i][j];
                      system("clear");
                      afficher_mat(mat);
                        return 2;

                    }
                  }
                }
              }
            }
        }
    }
    return 0;           /* aucun gagnant dans les diagonales */
}

/**
 * \fn void modifGagnant(char mat[N][M])
 * \brief fonction permettant de savoir qui a gagné en modifiant les caractère R ou J par '*'
 *
 * \param mat la grille du jeu.
 *
*/

extern
void modif(char mat[N][M]){

    parcours_ligne(mat);
    parcours_colonne(mat);
    parcours_diagonale(mat);

}




/**
 * \fn int gagnant_ligne(char mat[N][M])
 * \brief fonction retourne 1 si les jaunes gagnent avec les pion en lignes ou 2 si les rouges gagnent avec les pion en lignes
 *
 * \param mat la grille du jeu.
 *
 * \return int.
*/
extern
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

              if ((j-1)>=0 || (j-1)<=6 ) {
                if ((j+1)>=0 || (j+1)<=6 ) {
                  if ((j+2)>=0 || (j+2)<=6 ) {
                    if((mat[i][j] == mat[i][j-1]) && (mat[i][j] == mat[i][j+1]) && (mat[i][j] == mat[i][j+2]))
                    {

                      return 1;
                  }
                }
              }
            }

                else if ((j-1)>=0 || (j-1)<=6 ) {
                  if ((j-2)>=0 || (j-2)<=6 ) {
                    if ((j+1)>=0 || (j+1)<=6 ) {
                      if((mat[i][j] == mat[i][j-1]) && (mat[i][j] == mat[i][j-2]) && (mat[i][j] == mat[i][j+1]))
                      {

                        return 1;
                    }
                  }
                }
              }
                else if ((j-1)>=0 || (j-1)<=6 ) {
                  if ((j-2)>=0 || (j-2)<=6 ) {
                    if ((j-3)>=0 || (j-3)<=6 ) {
                      if((mat[i][j] == mat[i][j-1]) && (mat[i][j] == mat[i][j-2]) && (mat[i][j] == mat[i][j-3]))
                      {

                        return 1;
                    }
                  }
                }
              }
                else if ((j+1)>=0 || (j+1)<=6 ) {
                  if ((j+2)>=0 || (j+2)<=6 ) {
                    if ((j+3)>=0 || (j+3)<=6 ) {
                      if((mat[i][j] == mat[i][j+1]) && (mat[i][j] == mat[i][j+2]) && (mat[i][j] == mat[i][j+3]))
                      {

                        return 1;
                    }
                  }
                }
              }

            }
            /* toutes les combinaison en lignes pour le joueur jaune et retourne 2 si il a gagné */
            if(mat[i][j] ==  'J')
            {

              if ((j-1)>=0 || (j-1)<=6 ) {
                if ((j+1)>=0 || (j+1)<=6 ) {
                  if ((j+2)>=0 || (j+2)<=6 ) {
                    if((mat[i][j] == mat[i][j-1]) && (mat[i][j] == mat[i][j+1]) && (mat[i][j] == mat[i][j+2]))
                    {

                      return 2;
                  }
                }
              }
            }

                else if ((j-1)>=0 || (j-1)<=6 ) {
                  if ((j-2)>=0 || (j-2)<=6 ) {
                    if ((j+1)>=0 || (j+1)<=6 ) {
                      if((mat[i][j] == mat[i][j-1]) && (mat[i][j] == mat[i][j-2]) && (mat[i][j] == mat[i][j+1]))
                      {

                        return 2;
                    }
                  }
                }
              }
                else if ((j-1)>=0 || (j-1)<=6 ) {
                  if ((j-2)>=0 || (j-2)<=6 ) {
                    if ((j-3)>=0 || (j-3)<=6 ) {
                      if((mat[i][j] == mat[i][j-1]) && (mat[i][j] == mat[i][j-2]) && (mat[i][j] == mat[i][j-3]))
                      {

                        return 2;
                    }
                  }
                }
              }
                else if ((j+1)>=0 || (j+1)<=6 ) {
                  if ((j+2)>=0 || (j+2)<=6 ) {
                    if ((j+3)>=0 || (j+3)<=6 ) {
                      if((mat[i][j] == mat[i][j+1]) && (mat[i][j] == mat[i][j+2]) && (mat[i][j] == mat[i][j+3]))
                      {

                        return 2;
                    }
                  }
                }
              }

            }

        }
    }
    return 0;         /* aucun gagnant dans les lignes */
}


/**
 * \fn int gagnant_colonne(char mat[N][M])
 * \brief fonction retourne 1 si les jaunes gagnent avec les pion en colonnes ou 2 si les rouges gagnent avec les pion en colonnes
 *
 * \param mat la grille du jeu.
 *
 * \return int.
*/
extern
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

               if ((i-1)>=0 || (i-1)<=6 ) {
                 if ((i+1)>=0 || (i+1)<=6 ) {
                   if ((i+2)>=0 || (i+2)<=6 ) {
                     if((mat[i][j] == mat[i-1][j]) && (mat[i][j] == mat[i+1][j]) && (mat[i][j] == mat[i+2][j]))
                     {
;
                       return 1;
                   }
                 }
               }
             }

                 else if ((i-1)>=0 || (i-1)<=6 ) {
                   if ((i-2)>=0 || (i-2)<=6 ) {
                     if ((i+1)>=0 || (i+1)<=6 ) {
                       if((mat[i][j] == mat[i-1][j]) && (mat[i][j] == mat[i-2][j]) && (mat[i][j] == mat[i+1][j]))
                       {

                         return 1;
                     }
                   }
                 }
               }
                 else if ((i-1)>=0 || (i-1)<=6 ) {
                   if ((i-2)>=0 || (i-2)<=6 ) {
                     if ((i-3)>=0 || (i-3)<=6 ) {
                       if((mat[i][j] == mat[i-1][j]) && (mat[i][j] == mat[i-2][j]) && (mat[i][j] == mat[i-3][j]))
                       {

                         return 1;
                     }
                   }
                 }
               }
                 else if ((i+1)>=0 || (i+1)<=6 ) {
                   if ((i+2)>=0 || (i+2)<=6 ) {
                     if ((i+3)>=0 || (i+3)<=6 ) {
                       if((mat[i][j] == mat[i+1][j]) && (mat[i][j] == mat[i+2][j]) && (mat[i][j] == mat[i+3][j]))
                       {

                         return 1;
                     }
                   }
                 }
               }

             }
            /* toutes les combinaison en colonne pour le joueur jaune et retourne 2 si il a gagné */
            if(mat[i][j] ==  'J')
            {

              if ((i-1)>=0 || (i-1)<=6 ) {
                if ((i+1)>=0 || (i+1)<=6 ) {
                  if ((i+2)>=0 || (i+2)<=6 ) {
                    if((mat[i][j] == mat[i-1][j]) && (mat[i][j] == mat[i+1][j]) && (mat[i][j] == mat[i+2][j]))
                    {

                      return 2;
                  }
                }
              }
            }

                else if ((i-1)>=0 || (i-1)<=6 ) {
                  if ((i-2)>=0 || (i-2)<=6 ) {
                    if ((i+1)>=0 || (i+1)<=6 ) {
                      if((mat[i][j] == mat[i-1][j]) && (mat[i][j] == mat[i-2][j]) && (mat[i][j] == mat[i+1][j]))
                      {

                        return 2;
                    }
                  }
                }
              }
                else if ((i-1)>=0 || (i-1)<=6 ) {
                  if ((i-2)>=0 || (i-2)<=6 ) {
                    if ((i-3)>=0 || (i-3)<=6 ) {
                      if((mat[i][j] == mat[i-1][j]) && (mat[i][j] == mat[i-2][j]) && (mat[i][j] == mat[i-3][j]))
                      {

                        return 2;
                    }
                  }
                }
              }
                else if ((i+1)>=0 || (i+1)<=6 ) {
                  if ((i+2)>=0 || (i+2)<=6 ) {
                    if ((i+3)>=0 || (i+3)<=6 ) {
                      if((mat[i][j] == mat[i+1][j]) && (mat[i][j] == mat[i+2][j]) && (mat[i][j] == mat[i+3][j]))
                      {

                        return 2;
                    }
                  }
                }
              }

            }

        }
    }
    return 0;             /* aucun gagnant dans les collonnes */
}

/**
 * \fn int gagnant_diagonale(char mat[N][M])
 * \brief fonction retourne 1 si les jaunes gagnent avec les pion en diagonale ou 2 si les rouges gagnent avec les pion en diagonale
 *
 * \param mat la grille du jeu.
 *
 * \return int.
*/

extern
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

                  if ( ((i-1)>=0 && (i-1)<=6) && ((j+1)>=0 && (j+1)<=6) ) {
                    if ( ((i-2)>=0 && (i-2)<=6) && ((j+2)>=0 && (j+2)<=6) ) {
                      if ( ((i-3)>=0 && (i-3)<=6) && ((j+3)>=0 && (j+3)<=6) ) {
                        if((mat[i][j] == mat[i-1][j+1]) && (mat[i][j] == mat[i-2][j+2]) && (mat[i][j] == mat[i-3][j+3]))
                        {

                          return 1;

                      }
                    }
                  }


                }


                  if ( (i+1)>=0 && (i+1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                    if ( (i+2)>=0 && (i+2)<=6 && (j-2)>=0 && (j-2)<=6 ) {
                      if ( (i+3)>=0 && (i+3)<=6 && (j-3)>=0 && (j-3)<=6 ) {
                        if((mat[i][j] == mat[i+1][j-1]) && (mat[i][j] == mat[i+2][j-2]) && (mat[i][j] == mat[i+3][j-3]))
                        {

                          return 1;

                      }
                    }
                  }


                }

                  if ( (i+1)>=0 && (i+1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                    if ( (i-1)>=0 && (i-1)<=6 && (j+1)>=0 && (j+1)<=6 ) {
                      if ( (i-2)>=0 && (i-2)<=6 && (j+2)>=0 && (j+2)<=6 ) {
                        if((mat[i][j] == mat[i+1][j-1]) && (mat[i][j] == mat[i-1][j+1]) && (mat[i][j] == mat[i-2][j+2]))
                        {

                          return 1;

                      }
                    }
                  }
                }

                  if ( (i-1)>=0 && (i-1)<=6 && (j+1)>=0 && (j+1)<=6 ) {
                    if ( (i+1)>=0 && (i+1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                      if ( (i+2)>=0 && (i+2)<=6 && (j-2)>=0 && (j-2)<=6 ) {
                        if((mat[i][j] == mat[i-1][j+1]) && (mat[i][j] == mat[i+1][j-1]) && (mat[i][j] == mat[i+2][j-2]))
                        {

                          return 1;

                      }
                    }
                  }

                }


                  if ( (i-1)>=0 && (i-1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                    if ( (i-2)>=0 && (i-2)<=6 && (j-2)>=0 && (j-2)<=6 ) {
                      if ( (i-3)>=0 && (i-3)<=6 && (j-3)>=0 && (j-3)<=6 ) {
                        if((mat[i][j] == mat[i-1][j-1]) && (mat[i][j] == mat[i-2][j-2]) && (mat[i][j] == mat[i-3][j-3]))
                        {

                          return 1;

                      }
                    }
                  }



                }


                  if ( ((i+1)>=0 && (i+1)<=6 )&& ((j+1)>=0 && (j+1)<=6) ) {
                    if ( ((i+2)>=0 && (i+2)<=6) && ((j+2)>=0 && (j+2)<=6) ) {
                      if ( ((i+3)>=0 && (i+3)<=6) && ((j+3)>=0 && (j+3)<=6) ) {
                        if((mat[i][j] == mat[i+1][j+1]) && (mat[i][j] == mat[i+2][j+2]) && (mat[i][j] == mat[i+3][j+3]))
                        {

                          return 1;

                      }
                    }
                  }
                }

                  if ( (i-1)>=0 && (i-1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                    if ( (i+1)>=0 && (i+1)<=6 && (j+1)>=0 && (j+1)<=6 ) {
                      if ( (i+2)>=0 && (i+2)<=6 && (j-2)>=0 && (j-2)<=6 ) {
                        if((mat[i][j] == mat[i-1][j-1]) && (mat[i][j] == mat[i+1][j+1]) && (mat[i][j] == mat[i+2][j+2]))
                        {

                          return 1;

                      }
                    }
                  }
                }

                  if ( (i+1)>=0 && (i+1)<=6 && (j+1)>=0 && (j+1)<=6 ) {
                    if ( (i-1)>=0 && (i-1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                      if ( (i-2)>=0 && (i-2)<=6 && (j-2)>=0 && (j-2)<=6 ) {
                        if((mat[i][j] == mat[i+1][j+1]) && (mat[i][j] == mat[i-1][j-1]) && (mat[i][j] == mat[i-2][j-2]))
                        {

                          return 1;

                      }
                    }
                  }
                }

            }
            /* toutes les combinaison en diagonales pour le joueur jaune et retourne 2 si il a gagné */
            if(mat[i][j] ==  'J')
            {

                if ( (i-1)>=0 && (i-1)<=6 && (j+1)>=0 && (j+1)<=6 ) {
                  if ( (i-2)>=0 && (i-2)<=6 && (j+2)>=0 && (j+2)<=6 ) {
                    if ( (i-3)>=0 && (i-3)<=6 && (j+3)>=0 && (j+3)<=6 ) {
                      if((mat[i][j] == mat[i-1][j+1]) && (mat[i][j] == mat[i-2][j+2]) && (mat[i][j] == mat[i-3][j+3]))
                      {

                        return 2;

                    }
                  }
                }
              }

                if ( (i+1)>=0 && (i+1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                  if ( (i+2)>=0 && (i+2)<=6 && (j-2)>=0 && (j-2)<=6 ) {
                    if ( (i+3)>=0 && (i+3)<=6 && (j-3)>=0 && (j-3)<=6 ) {
                      if((mat[i][j] == mat[i+1][j-1]) && (mat[i][j] == mat[i+2][j-2]) && (mat[i][j] == mat[i+3][j-3]))
                      {

                        return 2;

                    }
                  }
                }
              }

                if ( (i+1)>=0 && (i+1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                  if ( (i-1)>=0 && (i-1)<=6 && (j+1)>=0 && (j+1)<=6 ) {
                    if ( (i-2)>=0 && (i-2)<=6 && (j+2)>=0 && (j+2)<=6 ) {
                      if((mat[i][j] == mat[i+1][j-1]) && (mat[i][j] == mat[i-1][j+1]) && (mat[i][j] == mat[i-2][j+2]))
                      {

                        return 2;

                    }
                  }
                }
              }

                if ( (i-1)>=0 && (i-1)<=6 && (j+1)>=0 && (j+1)<=6 ) {
                  if ( (i+1)>=0 && (i+1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                    if ( (i+2)>=0 && (i+2)<=6 && (j-2)>=0 && (j-2)<=6 ) {
                      if((mat[i][j] == mat[i-1][j+1]) && (mat[i][j] == mat[i+1][j-1]) && (mat[i][j] == mat[i+2][j-2]))
                      {

                        return 2;

                    }
                  }
                }
              }

                if ( (i-1)>=0 && (i-1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                  if ( (i-2)>=0 && (i-2)<=6 && (j-2)>=0 && (j-2)<=6 ) {
                    if ( (i-3)>=0 && (i-3)<=6 && (j-3)>=0 && (j-3)<=6 ) {
                      if((mat[i][j] == mat[i-1][j-1]) && (mat[i][j] == mat[i-2][j-2]) && (mat[i][j] == mat[i-3][j-3]))
                      {

                        return 2;

                    }
                  }
                }
              }


                if ( (i+1)>=0 && (i+1)<=6 && (j+1)>=0 && (j+1)<=6 ) {
                  if ( (i+2)>=0 && (i+2)<=6 && (j+2)>=0 && (j+2)<=6 ) {
                    if ( (i+3)>=0 && (i+3)<=6 && (j+3)>=0 && (j+3)<=6 ) {
                      if((mat[i][j] == mat[i+1][j+1]) && (mat[i][j] == mat[i+2][j+2]) && (mat[i][j] == mat[i+3][j+3]))
                      {

                        return 2;

                    }
                  }
                }
              }

                if ( (i-1)>=0 && (i-1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                  if ( (i+1)>=0 && (i+1)<=6 && (j+1)>=0 && (j+1)<=6 ) {
                    if ( (i+2)>=0 && (i+2)<=6 && (j-2)>=0 && (j-2)<=6 ) {
                      if((mat[i][j] == mat[i-1][j-1]) && (mat[i][j] == mat[i+1][j+1]) && (mat[i][j] == mat[i+2][j+2]))
                      {

                        return 2;

                    }
                  }
                }
              }

                if ( (i+1)>=0 && (i+1)<=6 && (j+1)>=0 && (j+1)<=6 ) {
                  if ( (i-1)>=0 && (i-1)<=6 && (j-1)>=0 && (j-1)<=6 ) {
                    if ( (i-2)>=0 && (i-2)<=6 && (j-2)>=0 && (j-2)<=6 ) {
                      if((mat[i][j] == mat[i+1][j+1]) && (mat[i][j] == mat[i-1][j-1]) && (mat[i][j] == mat[i-2][j-2]))
                      {

                        return 2;

                    }
                  }
                }
              }
            }
        }
    }
    return 0;           /* aucun gagnant dans les diagonales */
}


/**
 * \fn int qui_gagne(char mat[N][M])
 * \brief fonction retourne 1 si les jaunes  ou 2 si les rouges
 *
 * \param mat la grille du jeu.
 *
 * \return int.
*/

extern
int qui_gagne(char mat[N][M]){
/* fonction permettant de savoir qui a gagné en ayant 4 piece alignées. */

    int lig=0;
    int col=0;
    int diag=0;

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

            return 0;    /* égalité aucun joueur n'a gagné */
            }
        }
    }
}




/**
 * \fn void JouerNormal1vs1(char mat[N][M], joueur j1, joueur j2)
 * \brief fonction qui permet de jouer a 1vs1 en mode normal et retourne une lettre qui designe qui a gagné (r ou j)
 *
 * \param mat la grille du jeu.
 * \param j2 joueur 2.
 * \param j1 joueur 1.
 *
 * \return char
*/

extern
int JouerNormal1vs1(char mat[N][M], joueur j1, joueur j2){

double y=0;
int tmp = 0;
initMatrice(mat);

afficher_mat(mat);
printf("\n\n");

j1.couleur="rouge";
j2.couleur="jaune";

 while( qui_gagne(mat)==0){

  // tour du premier joueur de jouer

  do{
	 while(1){              /* verifie si le nombre entrée est bien un nombre entier et pas un nombre décimale */
       	   printf("Joueur 1 :Choisissez ou vous aller mettre votre piece (numero de colonne entre 1 et 7):\n");
           scanf("%lf",&y);
           tmp = (int)y;        /* on donne la valeur entière du nombre saisi (peut être aussi un nombre décimal) à la variable temporaire*/
           if(tmp == y){
             break;             /* on sort de la boucle si c'est un nombre entier */
           }
           else{
             printf("Veuillez saisir un entier\n");     /* sinon on redemande à l'utilisateur de saisir un nombre entier */
           }
         }

  	 if (statut(y-1,mat)==0) {
    	  printf("Erreur sur les coordonnée des y : la colonne %lf est rempli essayer une autre \n\n", y);
  	 }

  }while ((y<1||y>7) || statut(y-1,mat)==0);
  y--;

  inserer(y,statut(y,mat),j1,mat);                          //on insere la piece

  if (grille_plein(mat)) {
    printf("La grille est pleine match null \n");
    return(3);
  }

  system("clear");

  afficher_mat(mat);
  printf("\n\n");

  if(qui_gagne(mat)!=1){                              // on passe au tour suivant si et selement si le joueur 1 n'a pas gagner

    // tour du deuxieme joueur de jouer
    y=0;

    do{
	while(1){              /* verifie si le nombre entrée est bien un nombre entier et pas un nombre décimale */
         printf("Joueur2 : Choisissez ou vous aller mettre votre piece (numero de colonne entre 1 et 7):\n");    //rajouter cas y n'est pas un chiffre
         scanf("%lf",&y);
         tmp = (int)y;        /* on donne la valeur entière du nombre saisi (peut être aussi un nombre décimal) à la variable temporaire */
         if(tmp == y){
           break;             /* on sort de la boucle si c'est un nombre entier */
         }
         else{
           printf("Veuillez saisir un entier\n"); /* sinon on redemande à l'utilisateur de saisir un nombre entier */
         }
       	}

       if (statut(y-1,mat)==0) {
         printf("Erreur sur les coordonnée des y : la colonne %lf est rempli essayer une autre \n\n", y);
       }

    }while ((y<1||y>7) || statut(y-1,mat)==0);
    y--;

    inserer(y,statut(y,mat),j2,mat);

    if (grille_plein(mat)) {
      printf("LA GRILLE EST PLEINE : MATCH NULL \n");
      return(3);
    }

    system("clear");

    afficher_mat(mat);
    printf("\n\n");

  }

 } // tant qu'il n'y a pas de gangnant on continue de jouer

  if(qui_gagne(mat)==1){
    modif(mat);
    printf("LES ROUGES ONT GAGNÉS !! \n");
    return(1);
  }
  else if(qui_gagne(mat)==2){
    modif(mat);
    printf("LES JAUNES ONT GAGNÉS !! \n");
    return(0);
  }

}




/**
 * \fn void insererIA(int y, int x, joueur t, char mat[N][M])
 * \brief fonction qui permet a l'utilisateur d'inserer une piece
 *
 * \param ia structure representant le joueur
 * \param mat la grille du jeu.
 *
 *
*/

extern
void insererIA(joueur ia, char mat[N][M]){
  int i,j,ia_joue=0;
  int y;//CASE du tableau
  char *coul;
 /* Attaque */
 for(i=1;i!=N-1;i++){
      for(j=1;j!=N-1;j++){
          //TEST LIGNE (3 jetons)
          if('R' == mat[i][j] && 'R' == mat[i][j+1] &&'R' == mat[i][j+2] && ia_joue==0){
              if (i==7 && (mat[i][j+3] == ' ')){
                  inserer(j+3,statut(j+3,mat),ia,mat);
                  ia_joue=1;
                  break;
              }
              else if (i==7 && j>1 && (mat[i][j-1] == ' ')){
                  inserer(j-1,statut(j-1,mat),ia,mat);
                  ia_joue=1;
                  break;
              }
              else if (i<7 && (mat[i][j+3] == ' ') && (mat[i-1][j+3] != ' ')){
                  inserer(j+3,statut(j+3,mat),ia,mat);
                  ia_joue=1;
                  break;
              }
          }

          //TEST COLONNE
          //'R' 3 jetons
          else if('R' == mat[i][j] && 'R' == mat[i+1][j] && 'R' == mat[i+2][j] && ia_joue==0){
              if (mat[i+3][j] == ' '){
                  inserer(j,statut(j,mat),ia,mat);
                  ia_joue=1;
                  break;
                  }
          }

          //TEST 1ere DIAGONNALE
          else if('R' == mat[i][j] && 'R' == mat[i+1][j+1] &&'R' == mat[i+2][j+2] && ia_joue==0){
            if (i+3==N && mat[i+3][j+3] == ' ' ){
                inserer(j+3,statut(j+3,mat),ia,mat);
                ia_joue=1;
                break;
            }
            else if(i+3<N && mat[i+4][j+3] != ' ' && mat[i+3][j+3] == ' '){
              inserer(j+3,statut(j+3,mat),ia,mat);
              ia_joue=1;
              break;
            }
            else if (mat[i-1][j-1] == ' ' && mat[i][j-1] !=' '){
                inserer(j-1,statut(j-1,mat),ia,mat);
                ia_joue=1;
                break;
            }

          }
      }
  }


  for(j=1;j!=N-1;j++){
      for(i=N-1;i>=1;i--){
          //TEST 2eme Diagonnale
          if('R' == mat[i][j] &&'R' == mat[i-1][j+1] &&'R' == mat[i-2][j+2]&& ia_joue==0){
              if (mat[i-3][j+3] == ' ' && mat[i-2][j+3] !=' '){
                  inserer(j+3,statut(j+3,mat),ia,mat);
                  ia_joue=1;
                  break;
              }
              else if ((i+1)==N && mat[i+1][j-1] == ' '){
                  inserer(j-1,statut(j-1,mat),ia,mat);
                  ia_joue=1;
                  break;
              }
              else if ((i+1)<N && mat[i+1][j-1] == ' '&&mat[i+2][j-1] != ' ' ){
                  inserer(j-1,statut(j-1,mat),ia,mat);
                  ia_joue=1;
                  break;
              }
          }

      }
  }

  /* DEFENSE */
  for(i=1;i!=N-1;i++){
      for(j=1;j!=N-1;j++){
          //TEST ligne (3 jetons)
          if('J' == mat[i][j] && 'J' == mat[i][j+1] &&'J' == mat[i][j+2] && ia_joue==0){
            if (i==1){
              if(mat[i][j+3] == ' '){
                inserer(j+3,statut(j+3,mat),ia,mat);
                ia_joue=1;
                break;
              }
              else if(mat[i][j-1] == ' '){
                inserer(j-1,statut(j-1,mat),ia,mat);
                ia_joue=1;
                break;
              }
            }
            else if (i>1){
              if((mat[i][j+3] == ' ') && (mat[i-1][j+3] != ' ')){
                  inserer(j+3,statut(j+3,mat),ia,mat);
                  ia_joue=1;
                  break;
            }
              else if((mat[i][j-1] == ' ') && (mat[i-1][j-1] != ' ')){
                inserer(j-1,statut(j-1,mat),ia,mat);
                ia_joue=1;
                break;
              }
            }
          }

          //TEST colonne
          //'J'3 jetons
          else if('J' == mat[i][j] && 'J' == mat[i+1][j] && 'J' == mat[i+2][j] && ia_joue==0){
              if (mat[i+3][j] == ' '){
                  inserer(j+3,statut(j+3,mat),ia,mat);
                  ia_joue=1;
                  break;
                  }

          }

          //TEST 1ere DIAGONNALE
          else if('J' == mat[i][j] && 'J' == mat[i+1][j+1] &&'J' == mat[i+2][j+2] && ia_joue==0){
              if (i+3==N && mat[i+3][j+3] == ' ' ){
                  inserer(j+3,statut(j+3,mat),ia,mat);
                  ia_joue=1;
                  break;
              }
              else if(i+3<N && mat[i+4][j+3] != ' ' && mat[i+3][j+3] == ' '){
                inserer(j+3,statut(j+3,mat),ia,mat);
                ia_joue=1;
                break;
              }
              else if (mat[i-1][j-1] == ' ' && mat[i][j-1] !=' '){
                  inserer(j-1,statut(j-1,mat),ia,mat);
                  ia_joue=1;
                  break;
              }
          }
      }
  }

  for(j=1;j!=N-1;j++){
      for(i=N-1;i>=1;i--){
          //TEST 2eme Diagonnale
          if('J' == mat[i][j] &&'J' == mat[i-1][j+1] &&'J' == mat[i-2][j+2]&& ia_joue==0){
            if (mat[i-3][j+3] == ' ' && mat[i-2][j+3] !=' '){
                inserer(j+3,statut(j+3,mat),ia,mat);
                ia_joue=1;
                break;
            }
            else if ((i+1)==N && mat[i+1][j-1] == ' '){
                inserer(j-1,statut(j-1,mat),ia,mat);
                ia_joue=1;
                break;
            }
            else if ((i+1)<N && mat[i+1][j-1] == ' '&&mat[i+2][j-1] != ' ' ){
                inserer(j-1,statut(j-1,mat),ia,mat);
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
          if('R' == mat[i][j] && 'R' == mat[i][j+1] && ia_joue==0){
              if (mat[i][j+2] == ' '){
                  if(i==N ){
                    inserer(j+2,statut(j+2,mat),ia, mat);
                    ia_joue=1;
                    break;
                  }
                  else if(i<N && mat[i+1][j+2] != ' ' ){
                    inserer(j+2,statut(j+2,mat),ia, mat);
                    ia_joue=1;
                    break;
                  }
              }
              if (mat[i][j-1] == ' '){
                  if(i==N ){
                    inserer(j-1,statut(j-1,mat),ia, mat);
                    ia_joue=1;
                    break;
                  }
                  else if(i<N && mat[i+1][j-1] != ' ' ){
                    inserer(j-1,statut(j-1,mat),ia, mat);
                    ia_joue=1;
                    break;
                  }
              }
          }

          //TEST LIGNE
          //2 jetons
          else if('R' == mat[i][j] && 'R' == mat[i-1][j] && mat[i-2][j] == ' ' && ia_joue==0){
              inserer(j,statut(j,mat),ia,mat);
              ia_joue=1;
              break;
          }
      }
  }
  //Attaque si 1 jetons
   for(i=1;i!=N-1;i++){
      for(j=1;j!=N-1;j++){

          if('R' == mat[i][j] && ia_joue==0){
            //TEST ligne et colone (1 jetons)
              if (i==N){
                if(mat[i][j+1]){
                  inserer(j+1,statut(j+1,mat),ia,mat);
                  ia_joue=1;
                  break;
                }
                else if(mat[i][j-1]){
                  inserer(j-1,statut(j-1,mat),ia,mat);
                  ia_joue=1;
                  break;
                }
                else if(mat[i-1][j]==' '){
                  inserer(j,statut(j,mat),ia,mat);
                  ia_joue=1;
                  break;
                }
              }
              else if(i<N){
                if(mat[i][j+1] && mat[i-1][j+1]){
                  inserer(j+1,statut(j+1,mat),ia,mat);
                  ia_joue=1;
                  break;
                }
                else if(mat[i][j-1] && mat[i-1][j-1]){
                  inserer(j-1,statut(j-1,mat),ia,mat);
                  ia_joue=1;
                  break;
                }
                else if(mat[i-1][j]==' '){
                  inserer(j,statut(j,mat),ia,mat);
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

      inserer(y,statut(y,mat),ia,mat);
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
 * \fn void JouerNormal1vs1(char mat[N][M], joueur j1, joueur j2)
 * \brief fonction qui permet de jouer a 1vs1 en mode normal et retourne une lettre qui designe qui a gagné (r ou j)
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
       	   printf("Joueur 1 :Choisissez ou vous aller mettre votre piece (numero de colonne entre 1 et 7):\n");
           scanf("%lf",&y);
           tmp = (int)y;        /* on donne la valeur entière du nombre saisi (peut être aussi un nombre décimal) à la variable temporaire*/
           if(tmp == y){
             break;             /* on sort de la boucle si c'est un nombre entier */
           }
           else{
             printf("Veuillez saisir un entier\n");     /* sinon on redemande à l'utilisateur de saisir un nombre entier */
           }
         }

  	 if (statut(y-1,mat)==0) {
    	  printf("Erreur sur les coordonnée des y : la colonne %lf est rempli essayer une autre \n\n", y);
  	 }

  }while ((y<1||y>7) || statut(y-1,mat)==0);
  y--;

  inserer(y,statut(y,mat),j1,mat);                          //on insere la piece

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
    return(0);
  }


}
