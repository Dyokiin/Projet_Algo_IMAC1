#include "../../lib/AffTxt.h"
#include "../../lib/AffBtn.h"
#include "../../lib/jeu.h"
#include "../../lib/joueur.h"
#include "../../lib/jeton.h"
#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

#define MAX_CHAR 23

/* Permet l'Affichage du plateau vert */
void AffPlateau(struct jeu *plateau, SDL_Renderer *renderer){

	SDL_Rect space;
	char titre[MAX_CHAR] = "reversi";
	char btnq[MAX_CHAR] = "quitter";
	
	SDL_SetRenderDrawColor(renderer, 255,0,0,255);
	bouton(btnq, 1, 750, 850, renderer);
	SDL_SetRenderDrawColor(renderer, 255,255,255,255);
	AffTxt(titre, 1, 400, 5, renderer);
	
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			space.x = 250 + i*65;
			space.y = 250 + j*65;
			space.w = 60;
			space.h = 60;
			SDL_SetRenderDrawColor(renderer, 139,245,70,94);
			SDL_RenderFillRect(renderer, &space);
			
		}
	}

}


/* Permet l'affichage d'un joueur à sa position */
void AffJoueur(joueur*j, SDL_Renderer *renderer){

	SDL_SetRenderDrawColor(renderer, 255,255,255,255);
	if(j->nom[3] == 0){
		AffTxt(j->nom, 1, 80, 250, renderer);
		AffNb(j->jetons, 1, 80, 300, renderer);
		AffNb(j->score, 1, 80, 400, renderer);
	} else {
		if(j->nom[0] == 'b' && j->nom[1] == 'o' && j->nom[2] == 't'){
			DrawBot(830, 250, renderer);
			AffNb(j->jetons, 1, 830, 300, renderer);
			AffNb(j->score, 1, 830, 400, renderer);
		} else {
			AffTxt(j->nom, 1, 830, 250, renderer);
			AffNb(j->jetons, 1, 830, 300, renderer);
			AffNb(j->score, 1, 830, 400, renderer);
		}
	}
	
}


/* Permet l'affichage des jetons à leur position sur le plateau */
void AffJeton(struct jeu* plateau, SDL_Renderer *renderer){

	int coul;	
	
	for(int i=1; i<=8; i++){
		for(int j=1; j<=8; j++){
			coul = couleur(i, j, plateau);
			disque(250+(i-1)*65+30, 250+(j-1)*65+30, coul, renderer);
		}
	}
}


/* Permet l'affichage d'une flèche indiquant le joueur courrant */
void AffCurrent(struct jeu* plateau, SDL_Renderer *renderer){
	
	int flch = 0;
	
	if(!currentPlay(plateau)) flch = 750;
	
	SDL_SetRenderDrawColor(renderer, 255,0,0,255);
	SDL_RenderDrawLine(renderer, 125+flch, 150, 125+flch, 245);
	SDL_RenderDrawLine(renderer, 100+flch, 225, 125+flch, 245);
	SDL_RenderDrawLine(renderer, 150+flch, 225, 125+flch, 245);
}
