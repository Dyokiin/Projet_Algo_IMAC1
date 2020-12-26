#include "../../lib/AffTxt.h"
#include "../../lib/AffBtn.h"
#include "../../lib/jeu.h"
#include "../../lib/joueur.h"
#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

#define MAX_CHAR 23


void AffPlateau(int mode, SDL_Renderer *renderer){

	 					//Definition et affichage necessaire au jeu 
	SDL_Rect space;
	char titre[MAX_CHAR] = "reversi";
	char btnq[MAX_CHAR] = "quitter";
	
	SDL_SetRenderDrawColor(renderer, 255,0,0,255);
	bouton(btnq, 1, 750, 850, renderer);
	SDL_SetRenderDrawColor(renderer, 255,255,255,255);
	AffTxt(titre, 1, 400, 5, renderer);
	
	for(int i=0; i<500; i+=65){
		for(int j=0; j<500; j+=65){
			space.x = 250 + i;
			space.y = 250 + j;
			space.w = 60;
			space.h = 60;
			SDL_SetRenderDrawColor(renderer, 139,245,70,94);
			SDL_RenderFillRect(renderer, &space);
		}
	}

}

void AffJoueur(joueur*j, SDL_Renderer *renderer){

	SDL_SetRenderDrawColor(renderer, 255,255,255,255);
	if(j->nom[3] == 1){
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
