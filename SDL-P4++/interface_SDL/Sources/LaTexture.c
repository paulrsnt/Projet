/**
 * \file LaTexture.c
 * \brief Ce Fichier contient tous les fonctions qui transforme les images et textes en texture pour l'interface graphique SDL
 * \author Oussama Belkadi Fatih Ufacik Paul Riga
 * \version 2.0
 * \date 5 mai 2020
 */

#include "../Includes/SDL_puissance4.h"

/**
 * \fn SDL_Texture* tex_img_png(char * s, SDL_Renderer* renderer)
 * \brief Cette fonction transforme une image de format PNG en format texture pour pouvoir l'afficher dans la fenêtre de l'interface graphique SDL
 * \param s : on donne le chemin d'accès vers l'image PNG
 * \return Pointeur sur SDL_Texture
  * \author Oussama Belkadi Fatih Ufacik Paul Riga
 */
SDL_Texture* tex_img_png(char * s){

    SDL_RWops *rwop=SDL_RWFromFile(s, "rb");
	SDL_Surface *image=IMG_LoadPNG_RW(rwop);
	if(!image) {
	     printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}
	SDL_Texture *image_btn_tex = SDL_CreateTextureFromSurface(renderer, image);
	if(!image_btn_tex){
		fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(image); /* on a obtenue la texture, et on a plus besoin de l'image */
    return image_btn_tex;
}

/**
 * \fn SDL_Texture* tex_text(char * font, int taille, char* text, SDL_Color color)
 * \brief Cette fonction transforme du texte en format texture pour pouvoir l'afficher dans la fenêtre de l'interface graphique SDL
 * \param font : on donne le chemin d'accès vers la police d'écriture.
 * \param taille : taille de la police
 * \param text : texte
 * \param color : couleur pour le texte
 * \return Pointeur sur SDL_Texture
  * \author Oussama Belkadi Fatih Ufacik Paul Riga
 */
SDL_Texture *tex_text(char* font,int taille, char* text, SDL_Color color){
    TTF_Font *policeTitre = NULL;
	if( (policeTitre = TTF_OpenFont(font, taille)) == NULL){
        fprintf(stderr,"%s\n",font);
        fprintf(stderr, "erreur du chargement de la police\n");
        exit(EXIT_FAILURE);
    }
    SDL_Surface *texte = TTF_RenderUTF8_Blended(policeTitre, text, color);
    if(!texte){
        fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Texture *texte_tex = SDL_CreateTextureFromSurface(renderer, texte);
    if(!texte_tex){
        fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_FreeSurface(texte); /* on a obtenue la texture, et on a plus besoin du texte */
    TTF_CloseFont(policeTitre); 
    return texte_tex;
}
