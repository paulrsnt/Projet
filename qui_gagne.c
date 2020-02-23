#include <stdio.h>
#include <stdlib.h>
#define N 7
#define M 7

typedef struct joueurs_s {

  char * nom;
  char * couleur;

}joueur_t;


/**
 * \fn int gagnant_ligne(char mat[N][M])
 * \brief fonction retourne 1 si les jaunes gagnent avec les pion en lignes ou 2 si les rouges gagnent avec les pion en lignes
 *
 * \param mat la grille du jeu.
 *
 * \return int.
*/

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
 * \fn int gagnant_colonne(char mat[N][M])
 * \brief fonction retourne 1 si les jaunes gagnent avec les pion en colonnes ou 2 si les rouges gagnent avec les pion en colonnes
 *
 * \param mat la grille du jeu.
 *
 * \return int.
*/

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
 * \fn int gagnant_diagonale(char mat[N][M])
 * \brief fonction retourne 1 si les jaunes gagnent avec les pion en diagonale ou 2 si les rouges gagnent avec les pion en diagonale
 *
 * \param mat la grille du jeu.
 *
 * \return int.
*/


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
 * \fn int qui_gagne(char mat[N][M])
 * \brief fonction retourne 1 si les jaunes  ou 2 si les rouges
 *
 * \param mat la grille du jeu.
 *
 * \return int.
*/


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
