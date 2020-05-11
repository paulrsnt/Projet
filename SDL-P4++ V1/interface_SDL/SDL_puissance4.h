#ifndef __SDL_JEU_H__
#define __SDL_JEU_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#define menu() (SDL_RenderPresent(renderer))
#define effacer() (SDL_RenderClear(renderer))
#define N  8
#define M  9

/**
* \struct joueurs_s
* \brief stucture afin de definir les joueur
*
*/

typedef struct joueurs_s {

  char couleur ;

}joueur ;

char mat[N][M];
char mat2[N][M];

extern SDL_Window* pWindow;
extern SDL_Renderer *renderer;
Mix_Music *music;
int son; /*la music*/

/*entête pour les textures*/
SDL_Texture* tex_img_png(char * s);
SDL_Texture* tex_text(char* font,int size, char* s, SDL_Color color);

/*entête pour le menu et ses fonctions*/
int menu_SDL(void);
int pointe_souris(SDL_Rect r, int x, int y);
int position(SDL_Rect* r, SDL_Texture* t, int x, int y);

/*entête pour le jeu terminale*/

/*1vs1*/
extern int grille_plein(char mat[N][M]);
extern int statut(int y, char mat[N][M]);
extern void initMatrice(char mat[N][M]);
extern void afficher_mat(char mat[N][M]);
extern void inserer(int y, int x, joueur t, char mat[N][M]);
extern int parcours_ligne(char mat[N][M]);
extern int parcours_colonne(char mat[N][M]);
extern int parcours_diagonale(char mat[N][M]);
extern void modif(char mat[N][M]);
extern int gagnant_ligne(char mat[N][M]);
extern int gagnant_colonne(char mat[N][M]);
extern int gagnant_diagonale(char mat[N][M]);
extern int qui_gagne(char mat[N][M]);
extern int JouerNormal1vs1(char mat[N][M], joueur j1, joueur j2);

/*1vsIA*/
extern void insererMode1vsIA(int y, int x, joueur t, char mat[N][M]);
extern void insererIA(joueur ia, char mat[N][M]);
extern int JouerNormal1vsIA(char mat[N][M], joueur j1, joueur ia);

/*2vs2*/
extern int statut2v2(int y, char mat[N][M], int p);
extern int grille_plein2v2(char mat[N][M]);
extern void initMatrice2v2(char mat[N][M]);
extern void afficher_mat2v2(char mat[N][M]);
extern void inserer2v2(int x, int y, joueur t, char mat[N][M],char mat2[N][M], int p);
extern int gagnant_ligne2v2(char mat[N][M]);
extern int gagnant_colonne2v2(char mat[N][M]);
extern int gagnant_diagonale2v2(char mat[N][M]);
extern int quigagne2v2(char mat[N][M]);
extern int JouerNormal2v2(char mat[N][M],char mat2[N][M], joueur j1, joueur j2, joueur j3, joueur j4);


#endif
