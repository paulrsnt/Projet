/**
 * \file main_SDL.c
 * \brief Ce Fichier contient le fichier principale pour l'execution de l'interface graphique SDL
 * \author Oussama Belkadi Fatih Ufacik Paul Riga
 * \version 1.0
 * \date 5 mai 2020
 */

#include "./interface_SDL/SDL_puissance4.h"

#define IvI 0
#define IIvII 1
#define IvIA 2
#define QUITTER 3

/*Declaration variable globale*/
SDL_Window* pWindow = NULL;
SDL_Renderer *renderer=NULL;

int main(void)
{
    /* Initialisation */

    if (SDL_Init(SDL_INIT_VIDEO) != 0 ) {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }


	/* Initialisation de TTF */
	if(TTF_Init() == -1) {
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}

    /*Initialisation de Mixer*/
    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096)==-1){
        fprintf(stderr, "Erreur à l'initailisation de l'audio\n");
        exit(EXIT_FAILURE);
    }

    music = Mix_LoadMUS("./music_menu/puissance4.ogg");
    if(music == NULL){
        fprintf(stderr, "Erreur du chargement de l'audio : %s\n", Mix_GetError());
        exit(EXIT_FAILURE);
    }
    son=1;
    Mix_VolumeMusic(MIX_MAX_VOLUME/4);
    Mix_PlayMusic(music,-1);
    Mix_PauseMusic();
    

    
    /* Création de la fenêtre */
    pWindow = SDL_CreateWindow("Puissance 4++",SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               1080,
                               650,
                               SDL_WINDOW_SHOWN);

    if(!pWindow){
        fprintf(stderr, "Erreur à la création de la fenetre : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        fprintf(stderr, "Erreur à la création du renderer\n");
        exit(EXIT_FAILURE);
    }
    
    int gagnant = -1;
    joueur j1,j2,j3,j4;
    joueur ia;
    int mode_terminal = menu_SDL();
    
	switch(mode_terminal){
	case IvI: 				//lance le mode 1v1 dans le terminale à partir du menu SDL
		Mix_PauseMusic();
		SDL_DestroyWindow(pWindow);
		gagnant = JouerNormal1vs1(mat,j1,j2);
		break;
	case IIvII:				//lance le mode 2v2 dans le terminale à partir du menu SDL
		Mix_PauseMusic();
		SDL_DestroyWindow(pWindow);
		gagnant = JouerNormal2v2(mat,mat2,j1,j2,j3,j4);
		break;
	case IvIA:				//lance le mode 1vIA dans le terminale à partir du menu SDL
		Mix_PauseMusic();
		SDL_DestroyWindow(pWindow);
		gagnant = JouerNormal1vsIA(mat,j1,ia);
		break;
	default:
		Mix_PauseMusic();
		printf("Vous avez quitte l'interface graphique\n");
		break;
	}

    if(pWindow != NULL) SDL_DestroyWindow(pWindow);
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    TTF_Quit();
    SDL_Quit();

    return 0;
}

