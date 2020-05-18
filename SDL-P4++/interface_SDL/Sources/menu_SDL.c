/**
 * \file menu_SDL.c
 * \brief Ce Fichier contient tous les fonctions qui permet d'afficher le menu (et les fonctions pour sa conceptions) pour l'interface graphique SDL
 * \author Oussama Belkadi Fatih Ufacik Paul Riga
 * \version 1.0
 * \date 5 mai 2020
*/

#include "../Includes/SDL_puissance4.h"
#define PLAY 1
#define PAUSE 0




/**
 * \brief Cette fonction permet de savoir si la souris pointe dans la zone selectionne
 * \param SDL_Rect r : parametre zone selectionne
 * \param int x : coordonnée x dans laquelle la souris pointe
 * \param int y : coordonnée y dans laquelle la souris pointe
 * \return entier VRAI ou FAUX c'est à dire 1 ou 0
  * \author Oussama Belkadi Fatih Ufacik Paul Riga
 */
 int pointe_souris(SDL_Rect r, int x, int y){
     return (x>= r.x && x<= (r.x+r.w) && y>=r.y &&y<=(r.y+r.h));
 }

 /**
 * \brief fonction qui permet de configurer la SDL_Rect (la zone selectionner) et la position de l'élément
 * \param SDL_Rect r : parametre pour la zone selectionne
 * \param SDL_Texture* t : parametre pour la texture de l'interface graphique (SDL)
 * \param int x : position de x
 * \param int y : position de y
  * \author Oussama Belkadi Fatih Ufacik Paul Riga
 */
int position(SDL_Rect* r, SDL_Texture* t, int x, int y){
    r->x = x;
    r->y = y;
    SDL_QueryTexture(t, NULL, NULL, &(r->w), &(r->h));
    return 0;
}

/**
 * \fn int menu_SDL(void)
 * \brief Fonction qui permet d'afficher le menu avec l'interface graphique SDL et la lecture d'une musique et quitter le jeu.
 * \param void : elle retourne rien 
 * \return entier
 */
int menu_SDL(void){
    int x,y, i=0, j=0;
    SDL_Rect txtDestRect,txtMenuRect[4], imgBtnRect, imgBGRect, musicRect;
 
    // Une variable de couleur Blanche
    SDL_Color couleurBlanc = {255, 255, 255, 255};

    SDL_Texture *texte_tex = tex_text("./ttf_police/PoliceMenu.ttf",100,"Puissance 4++",couleurBlanc);

    SDL_Texture *texteMenu_tex[4];
    texteMenu_tex[0] = tex_text("./ttf_police/PoliceMenu.ttf",40,"1 vs 1",couleurBlanc);
    texteMenu_tex[1] = tex_text("./ttf_police/PoliceMenu.ttf",40,"2 vs 2",couleurBlanc);
    texteMenu_tex[2] = tex_text("./ttf_police/PoliceMenu.ttf",40,"1 vs IA",couleurBlanc);
    texteMenu_tex[3] = tex_text("./ttf_police/PoliceMenu.ttf",40,"Quitter",couleurBlanc);

    //position (emplacement) du titre
    position(&txtDestRect, texte_tex, 300, 10);

    //position (emplacement) du menu 
    for(j=0;j<4;j++){
        position(&txtMenuRect[j], texteMenu_tex[j], j==2 || j==3 ? 480 : 500, 165+90*j);
    }

    //chargement de l'image de fond
    SDL_Texture *image_BG_tex = tex_img_png("./image/red.png");
    //chargement de l'image bouton
    SDL_Texture *image_btn_tex = tex_img_png("./image/boutton_principale.png");
    //chargement de l'image bouton par dessus (utilisé quand la souris passe sur l'image)
    SDL_Texture *image_btnHover_tex = tex_img_png("./image/boutton_dessus.png");
    //image pour l'image play et pause
    SDL_Texture *image_play_tex = tex_img_png("./image/play_pause.png");
    //image play et pause
    SDL_Texture *image_pause_tex = tex_img_png("./image/play_pause.png");

    SDL_Texture *temp;
    SDL_Texture *temp_music = image_play_tex;
 
    //position (emplacement) pour la musique
    position(&musicRect, temp_music, 1000, 570);

        int running = 1;
        SDL_Event e;
        while(running) {

            SDL_GetMouseState(&x,&y);
            if(x<700 && 385<x && y<526 && 130<y) goto menu;

            while(SDL_PollEvent(&e)){
                switch(e.type) {
                    case SDL_QUIT:
                        return 0;
                    case SDL_MOUSEBUTTONDOWN:
                        if(pointe_souris(musicRect,x,y)){
                            son = !(son);
                        }
                    default:
                    menu:
                        effacer();

                        /*Image de fond*/
                        imgBGRect.x = 0;
                        imgBGRect.y = 0;
                        SDL_QueryTexture(image_BG_tex, NULL, NULL, &(imgBGRect.w), &(imgBGRect.h));
                        SDL_RenderCopy(renderer, image_BG_tex, NULL, &imgBGRect);

                        /* Ajout du texte en Blanc */
                        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

                        SDL_RenderCopy(renderer, texte_tex, NULL, &txtDestRect);

                        SDL_RenderDrawLine(renderer,0,130,1080,130);

                        if(son!=PLAY){
                            temp_music = image_pause_tex;
                            Mix_ResumeMusic();
                        }else{
                            temp_music = image_play_tex;
                            Mix_PauseMusic();
                        }

                        SDL_RenderCopy(renderer, temp_music, NULL, &musicRect);

                        //On positionne le premier bouton du,menu
                        imgBtnRect.x = 440;
                        imgBtnRect.y = 150;
                        SDL_QueryTexture(image_btnHover_tex, NULL, NULL, &(imgBtnRect.w), &(imgBtnRect.h));
                        for(i=0;i<4;i++){
                            if( pointe_souris(imgBtnRect,x,y) ){
                                temp = image_btnHover_tex;
                        				 if(e.type == SDL_MOUSEBUTTONDOWN){	 //lorque l'on clique sur un bouton
                        					effacer();
                        					return i;
                        				}
                            }else{
                                temp = image_btn_tex;
                            }
                            SDL_RenderCopy(renderer, temp, NULL, &imgBtnRect);
                            SDL_RenderCopy(renderer, texteMenu_tex[i], NULL, &(txtMenuRect[i]));
                            imgBtnRect.y += 90;
                        }

                        /* On fait le rendu ! */
                        menu();
                        break;
                }
            }
        }
    return 0;
}
