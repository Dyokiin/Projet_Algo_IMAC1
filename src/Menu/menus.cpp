#include "../../lib/AffTxt.h"
#include "../../lib/AffBtn.h"
#include <iostream>
#include <SDL2/SDL.h>
using namespace std;


#define MAX_CHAR 23

int menuPrincipal(SDL_Renderer *renderer){
	SDL_Event e;
	char titre[MAX_CHAR] = "bienvenue dans reversi";
	char nom1[MAX_CHAR] = "clement bourhis";
	char nom2[MAX_CHAR] = "theo arnauld des lions";
	char bouton1[MAX_CHAR] = "joueur vs joueur";
	char bouton2[MAX_CHAR] = "joueur vs machine";
	char bouton3[MAX_CHAR] = "quitter";
	
	AffTxt(titre, 1, 100, 30, renderer);

	bouton(bouton1, 1, 300, 300, renderer);
	bouton(bouton2, 1, 300, 400, renderer);
	bouton(bouton3, 1, 300, 500, renderer);
	AffTxt(nom1, 0.5, 30, 820, renderer);
	AffTxt(nom2, 0.5, 30, 850, renderer);
	
	while(SDL_PollEvent(&e)){
		if (e.type == SDL_QUIT){
			return 3;
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			int x,y;
			SDL_GetMouseState(&x, &y);
			cout << x << " " << y << endl;
			if(x >= 300 && x <= 825 && y >= 300 && y <= 350) return 1;
			else if(x >= 300 && x <= 825 && y >= 400 && y <= 450) return 2;
			else if(x >= 300 && x <= 525 && y >= 500 && y <= 550) return 3;

		}
	}

	return 0;

}


int menuJeu(int mode, SDL_Renderer *renderer){

	SDL_SetRenderDrawColor(renderer, 0,0,0,255); 		//clear render pour afficher le jeu
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	 					//Definition et affichage necessaire au jeu 
	SDL_Rect space;
	char titre[MAX_CHAR] = "reversi";
	char btnq[MAX_CHAR] = "quitter";
	
	SDL_SetRenderDrawColor(renderer, 255,0,0,255);
	bouton(btnq, 1, 750, 850, renderer);
	//SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 255,255,255,255);
	AffTxt(titre, 1, 400, 5, renderer);
	
	AffL(10, 1, 100, 250, renderer);
	AffChfr(1, 1, 130, 250, renderer);
	
	if (mode == 1) {
		AffL(10, 1, 850, 250, renderer);
		AffChfr(2, 1, 880, 250, renderer); 
	} else {
		DrawBot(850, 250, renderer);
	}
	
	/*board.x = 250;
	board.y = 250;
	board.h = 500;
	board.w = 500;
	SDL_SetRenderDrawColor(renderer, 132,235,152,92);
	SDL_RenderFillRect(renderer, &board); */
	
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
	
	SDL_RenderPresent(renderer);
	
	//jeu(mode);
	
	SDL_Delay(10000);
	
	return 0;
}
