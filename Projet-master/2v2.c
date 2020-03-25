#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "strD.h"



//
//
//
// Blocante = mur appeller B dans la grille
//
//

/**

* \file structD.h
* \brief Programme contenant les stucture et variable constante du jeu du puissance 4++
* \author Aaron Amani Oussama Belkadi Fathi et Paul riga
* \version 1.0
* \date 17 fevrier 2020

*/


/**
 * \fn int grille_plein(char mat[N][M])
 * \brief fonction qui retourne 1 si la grille est pleine, 0 si elle ne l'est pas
 *
 * \param mat la grille du jeu.
 *
 * \return int.
*/
extern
int grille_plein2v2(char mat[N][M]){
  int cpt=0;
  for (int i = 1; i < (N-1); i++) {
    for (int y = 1; y < (M-1); y++) {
      if (mat[i][y]=='R'||mat[i][y]=='J'||mat[i][y]=='B');
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
int statut2v2(int y, char mat[N][M],int p){

  int x;

  /* for (x = N-1 ;(x < 0 || (mat[x][y]=='R'||mat[x][y]=='J' )); x--) ;  on arrive au bout tant que l'emplacement est pris on remonte */

  if (p==1 || p==2) { /* int bloquante */

    for (x = N-1 ;( (mat[x][y]!=' ' ) && (x >= 0) )  ; x--) ;
  }

  else if (p==3) { /* int pleine */

    for (x = 0 ;  (x < N-1) && ((mat[x][y]!='B')&&(mat[x][y]!='P') )  ; x++);

    if ((mat[x][y]=='B')||(mat[x][y]=='P')) {
      x--;
    }
    if (mat[x][y]=='*') {

      return -1;
    }
  }



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
void initMatrice2v2(char mat[N][M]){
/* fonction qui permet de initialiser la matrice */
	int i,j;

	for(i=0 ; i< N ; i++){
		for(j=0 ; j < M ; j++){


      if (i==0 || i==(N-1) || j==0 || j==(M-1) ) {
        mat[i][j]= '*';
      }
      else {
        mat[i][j] = ' ';
      }

		}
	}

}


/**
 * \fn void afficher_mat2v2(char mat[N][M])
 * \brief fonction qui affiche la matrice du jeu
 *
 * \param mat la grille du jeu.
 *
 *
*/
extern
void afficher_mat2v2(char mat[N][M]){
    int i, j;
    for(i=0;i<N;i++){
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
void inserer2v2(int y, int x, joueur t, char mat[N][M], char mat2[N][M],int p){
/* fonction qui permet de insérer un epièce dans la matrice */


  if (p==1) {
    mat2[x][y]='B';
    mat[x][y]='B';
  }
  else if (p==2 && t.couleur=="jaune") {
    mat2[x][y]='C';
    mat[x][y]='J';

  }
  else if (p==3 && t.couleur=="jaune") {
    mat2[x][y]='P';
    mat[x][y]='J';
  }

  else if (p==2 && t.couleur=="rouge") {
    mat2[x][y]='C';
    mat[x][y]='R';

  }

  else if (p==3 && t.couleur=="rouge") {
    mat2[x][y]='P';
    mat[x][y]='R';
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
int parcours_ligne2v2(char mat[N][M]){
/* fonction verifiant si il y a un gagnant sur une ligne du plateau de jeu */
    int i, j;
    for (i = 1; i < (N-1); i++)
    {
        for(j = 1; j < (M-1); j++)
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
                      afficher_mat2v2(mat);
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
                        afficher_mat2v2(mat);
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
                        afficher_mat2v2(mat);
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
                        afficher_mat2v2(mat);
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
                      afficher_mat2v2(mat);
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
                        afficher_mat2v2(mat);
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
                        afficher_mat2v2(mat);
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
                        afficher_mat2v2(mat);
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
int parcours_colonne2v2(char mat[N][M]){
/* fonction qui vérifie si il y a un gagnant sur les colonnes du plateau de jeu */
    int i, j;

    for (i = 1; i < (N-1); i++)
    {
        for(j = 1; j < (M-1); j++)
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
                       afficher_mat2v2(mat);
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
                         afficher_mat2v2(mat);
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
                         afficher_mat2v2(mat);
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
                         afficher_mat2v2(mat);
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
                      afficher_mat2v2(mat);
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
                        afficher_mat2v2(mat);
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
                        afficher_mat2v2(mat);
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
                        afficher_mat2v2(mat);
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
int parcours_diagonale2v2(char mat[N][M]){
/* fonction qui verifie si il y a un gagnant sur les diagonales du plateau de jeu */
    int i, j;
    for (i = 1; i < (N-1); i++)
    {
        for(j = 1; j < (M-1); j++)
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
                        afficher_mat2v2(mat);
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
                        afficher_mat2v2(mat);
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
                        afficher_mat2v2(mat);
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
                        afficher_mat2v2(mat);
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
                        afficher_mat2v2(mat);
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
                        afficher_mat2v2(mat);
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
                        afficher_mat2v2(mat);
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
                        afficher_mat2v2(mat);
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
                      afficher_mat2v2(mat);
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
                      afficher_mat2v2(mat);
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
                      afficher_mat2v2(mat);
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
                      afficher_mat2v2(mat);
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
                      afficher_mat2v2(mat);
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
                      afficher_mat2v2(mat);
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
                      afficher_mat2v2(mat);
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
                      afficher_mat2v2(mat);
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
void modif2v2(char mat[N][M]){

    parcours_ligne2v2(mat);
    parcours_colonne2v2(mat);
    parcours_diagonale2v2(mat);

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
int gagnant_ligne2v2(char mat[N][M]){
/* fonction verifiant si il y a un gagnant sur une ligne du plateau de jeu */
    int i, j;
    for (i = 1; i < (N-1); i++)
    {
        for(j = 1; j < (M-1); j++)
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
int gagnant_colonne2v2(char mat[N][M]){
/* fonction qui vérifie si il y a un gagnant sur les colonnes du plateau de jeu */
    int i, j;

    for (i = 1; i < (N-1); i++)
    {
        for(j = 1; j < (M-1); j++)
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
int gagnant_diagonale2v2(char mat[N][M]){
/* fonction qui verifie si il y a un gagnant sur les diagonales du plateau de jeu */
    int i, j;
    for (i = 1; i < (N-1); i++)
    {
        for(j = 1; j < (M-1); j++)
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
int qui_gagne2v2(char mat[N][M]){
/* fonction permettant de savoir qui a gagné en ayant 4 piece alignées. */

    int lig=0;
    int col=0;
    int diag=0;

    lig = gagnant_ligne2v2(mat);

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
        col = gagnant_colonne2v2(mat);

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
            diag = gagnant_diagonale2v2(mat);

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
int JouerNormal2v2(char mat[N][M],char mat2[N][M], joueur j1, joueur j2, joueur j3, joueur j4,int p){

  int pc ;
  double y=0;
  int tmp = 0;

  initMatrice2v2(mat);
  initMatrice2v2(mat2);

  afficher_mat2v2(mat2);
  printf("\n");
  afficher_mat2v2(mat2);

  printf("\n\n");

  j1.couleur="rouge";
  j2.couleur="jaune";
  j3.couleur="rouge";
  j4.couleur="jaune";

   while( qui_gagne2v2(mat)==0){

    // tour du premier joueur de jouer

    do{
  	 while(1){
            printf("Joueur 1 :Choisissez type de piece  : 1 bloquante, 2 creuse, 3 pleine ):\n");
            scanf("%d",&pc);

                   /* verifie si le nombre entrée est bien un nombre entier et pas un nombre décimale */
         	   printf("Joueur 1 :Choisissez ou vous aller mettre votre int (numero de colonne entre 1 et %d):\n",(M-2));
             scanf("%lf",&y);
             tmp = (int)y;        /* on donne la valeur entière du nombre saisi (peut être aussi un nombre décimal) à la variable temporaire*/
             if(tmp == y){
               break;             /* on sort de la boucle si c'est un nombre entier */
             }
             else{
               printf("Veuillez saisir un entier\n");     /* sinon on redemande à l'utilisateur de saisir un nombre entier */
             }
           }

           if ((y<1 || y>(M-2))) {
             printf(" Erreur sur les coordonnée des y : Vous avez selectionner une colonne en dehors de la grille du jeu \n");
           }

          else if (statut2v2(y,mat2,p)==-1) {
      	  printf("Erreur sur les coordonnée des y : la colonne %lf est rempli essayer une autre \n\n", y);
    	 }

    }while ((y<1||y>(M-2)) || statut2v2(y,mat2,p)==-1 || (pc<1||pc>3) );


    if (pc==1) {
      p=1;
    }
    if (pc==2) {
      p=2;
    }
    if (pc==3) {
      p=3;
    }

    inserer2v2(y,statut2v2(y,mat2,p),j1,mat,mat2,p);                          //on insere la int

    if (grille_plein2v2(mat)) {
      printf("LA GRILLE EST PLEINE : MATCH NULL \n");
      return(3);
    }

    system("clear");

    afficher_mat2v2(mat);
    printf("\n");
    afficher_mat2v2(mat2);

    printf("\n\n");

    if(qui_gagne2v2(mat)!=1){

      // tour du deuxieme joueur de jouer
      y=0;

      do{
    	 while(1){
              printf("Joueur 2 :Choisissez type de piece  : 1 bloquante, 2 creuse, 3 pleine ):\n");
              scanf("%d",&pc);

                     /* verifie si le nombre entrée est bien un nombre entier et pas un nombre décimale */
           	   printf("Joueur 2 :Choisissez ou vous aller mettre votre int (numero de colonne entre 1 et %d):\n",(M-2));
               scanf("%lf",&y);
               tmp = (int)y;        /* on donne la valeur entière du nombre saisi (peut être aussi un nombre décimal) à la variable temporaire*/
               if(tmp == y){
                 break;             /* on sort de la boucle si c'est un nombre entier */
               }
               else{
                 printf("Veuillez saisir un entier\n");     /* sinon on redemande à l'utilisateur de saisir un nombre entier */
               }
             }

             if ((y<1 || y>(M-2))) {
               printf(" Erreur sur les coordonnée des y : Vous avez selectionner une colonne en dehors de la grille du jeu \n");
             }

            else if (statut2v2(y,mat2,p)==-1) {
        	  printf("Erreur sur les coordonnée des y : la colonne %lf est rempli essayer une autre \n\n", y);
      	 }

      }while ((y<1||y>(M-2)) || statut2v2(y,mat2,p)==-1 || (pc<1||pc>3) );


      if (pc==1) {
        p=1;
      }
      if (pc==2) {
        p=2;
      }
      if (pc==3) {
        p=3;
      }

      inserer2v2(y,statut2v2(y,mat2,p),j2,mat,mat2,p);                          //on insere la int

      if (grille_plein2v2(mat)) {
        printf("LA GRILLE EST PLEINE : MATCH NULL \n");
        return(3);
      }

      system("clear");

      afficher_mat2v2(mat);
        printf("\n");
      afficher_mat2v2(mat2);
      printf("\n\n");
    }

    if(qui_gagne2v2(mat)!=1){

        // tour du deuxieme joueur de jouer
        y=0;

        do{
      	 while(1){
                printf("Joueur 3 :Choisissez type de piece  : 1 bloquante, 2 creuse, 3 pleine ):\n");
                scanf("%d",&pc);

                       /* verifie si le nombre entrée est bien un nombre entier et pas un nombre décimale */
             	   printf("Joueur 3 :Choisissez ou vous aller mettre votre int (numero de colonne entre 1 et %d):\n",(M-2));
                 scanf("%lf",&y);
                 tmp = (int)y;        /* on donne la valeur entière du nombre saisi (peut être aussi un nombre décimal) à la variable temporaire*/
                 if(tmp == y){
                   break;             /* on sort de la boucle si c'est un nombre entier */
                 }
                 else{
                   printf("Veuillez saisir un entier\n");     /* sinon on redemande à l'utilisateur de saisir un nombre entier */
                 }
               }

           if ((y<1 || y>(M-2))) {
             printf(" Erreur sur les coordonnée des y : Vous avez selectionner une colonne en dehors de la grille du jeu \n");
           }

          else if (statut2v2(y,mat2,p)==-1) {
          	  printf("Erreur sur les coordonnée des y : la colonne %lf est rempli essayer une autre \n\n", y);
        	 }

        }while ((y<1||y>(M-2)) || statut2v2(y,mat2,p)==-1 || (pc<1||pc>3) );


        if (pc==1) {
          p=1;
        }
        if (pc==2) {
          p=2;
        }
        if (pc==3) {
          p=3;
        }

        inserer2v2(y,statut2v2(y,mat2,p),j3,mat,mat2,p);                          //on insere la int

        if (grille_plein2v2(mat)) {
          printf("LA GRILLE EST PLEINE : MATCH NULL \n");
          return(3);
        }

        system("clear");

        afficher_mat2v2(mat);
          printf("\n");
        afficher_mat2v2(mat2);
        printf("\n\n");} // on passe au tour suivant si et selement si le joueur 1 n'a pas gagner

    if(qui_gagne2v2(mat)!=1){

        // tour du deuxieme joueur de jouer
        y=0;

        do{
      	 while(1){
                printf("Joueur 4 :Choisissez type de piece  : 1 bloquante, 2 creuse, 3 pleine ):\n");
                scanf("%d",&pc);

                       /* verifie si le nombre entrée est bien un nombre entier et pas un nombre décimale */
             	   printf("Joueur 4 :Choisissez ou vous aller mettre votre piece (numero de colonne entre 1 et %d):\n",(M-2));
                 scanf("%lf",&y);
                 tmp = (int)y;        /* on donne la valeur entière du nombre saisi (peut être aussi un nombre décimal) à la variable temporaire*/
                 if(tmp == y){
                   break;             /* on sort de la boucle si c'est un nombre entier */
                 }
                 else{
                   printf("Veuillez saisir un entier\n");     /* sinon on redemande à l'utilisateur de saisir un nombre entier */
                 }
               }


            if ((y<1 || y>(M-2))) {
              printf(" Erreur sur les coordonnée des y : Vous avez selectionner une colonne en dehors de la grille du jeu \n");
            }

           else if (statut2v2(y,mat2,p)==-1) {
          	  printf("Erreur sur les coordonnée des y : la colonne %lf est rempli essayer une autre \n\n", y);
        	 }

        }while ((y<1||y>(M-2)) || statut2v2(y,mat2,p)==-1 || (pc<1||pc>3) );


        if (pc==1) {
          p=1;
        }
        if (pc==2) {
          p=2;
        }
        if (pc==3) {
          p=3;
        }

        inserer2v2(y,statut2v2(y,mat2,p),j4,mat,mat2,p);                          //on insere la int

        if (grille_plein2v2(mat)) {
          printf("LA GRILLE EST PLEINE : MATCH NULL \n");
          return(3);
        }

        system("clear");

        afficher_mat2v2(mat);
          printf("\n");
        afficher_mat2v2(mat2);
        printf("\n\n");} // on passe au tour suivant si et selement si le joueur 1 n'a pas gagner

   }
   // tant qu'il n'y a pas de gangnant on continue de jouer

    if(qui_gagne2v2(mat)==1){
      modif2v2(mat);
      printf("LES ROUGES ONT GAGNÉS !! \n");
      return(1);
    }
    else if(qui_gagne2v2(mat)==2){
      modif2v2(mat);
      printf("LES JAUNES ONT GAGNÉS !! \n");
      return(2);
    }

}
