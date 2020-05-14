
/**
 * \file SDL_puissance4.h
 * \brief Ce Fichier contient tous les des fonctions fonctions pour le sdl
 * \author Oussama Belkadi Fatih Ufacik Paul Riga
 * \version 2.0
 * \date 5 mai 2020
 */



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

#endif
