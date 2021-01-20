#include "../../lib/AffTxt.h"
#include "../../lib/AffBtn.h"
#include "../../lib/jeu.h"
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
	char bouton4[MAX_CHAR] = "charger une partie";
	
	AffTxt(titre, 1, 100, 30, renderer);
	bouton(bouton1, 1, 300, 300, renderer);
	bouton(bouton2, 1, 300, 400, renderer);
	bouton(bouton3, 1, 300, 600, renderer);
	bouton(bouton4, 1, 300, 500, renderer);
	AffTxt(nom1, 0.5, 30, 820, renderer);
	AffTxt(nom2, 0.5, 30, 850, renderer);
	
	while(SDL_PollEvent(&e)){
		if (e.type == SDL_QUIT){
			return 3;
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			int x,y;
			SDL_GetMouseState(&x, &y);
			if(x >= 300 && x <= 825 && y >= 300 && y <= 350) return 1;
			else if(x >= 300 && x <= 825 && y >= 400 && y <= 450) return 2;
			else if(x >= 300 && x <= 825 && y >= 500 && y <= 550) return 4;
			else if(x >= 300 && x <= 525 && y >= 600 && y <= 650) return 3; 

		}
	}

	return 0;

}

int menuNom(int n, char*nom, SDL_Renderer *renderer){

	SDL_Event l;
	bool name = true;
	int cpt = 0;
	char titre[MAX_CHAR] = "nom joueur";
	char bouton2[MAX_CHAR] = "valider";
	char bouton3[MAX_CHAR] = "quitter";
	
	
	while(name){		
		while(SDL_PollEvent(&l)){
			if (l.type == SDL_QUIT){
				return 1;
			}
			if (l.type == SDL_MOUSEBUTTONDOWN) {
				int x,y;
				SDL_GetMouseState(&x, &y);
				if(x > 750 && y > 850) return 1;
				if(x > 750 && y > 800 && y < 830){
					if(cpt == 3) return 0;
				}
				
				for(int i=1; i<=2; i++){
					for(int j=1; j<=13; j++){
						if (x <= 260+j*37 && x >= 250+(j-1)*37){
							if(y <= 205+i*40 && y >= 205+(i-1)*40){
								if(cpt<3){
									nom[cpt] = (char)((j+(i-1)*13)+96) ;
									cpt++;
								}
							}
						} else if(x<=775 && x>=740 && y<=275 && y>=240){
							if(cpt>0) cpt--;
							nom[cpt] = ' ';
						}
					}
				}
			}				
		}
		
		SDL_SetRenderDrawColor(renderer, 255,255,255,255);
		for(int i=1; i<=2 ; i++) {
			for(int j=1; j<=13; j++) {
				boutonl( j+(i-1)*13, 1, 260+(j-1)*37, 205+(i-1)*40, renderer);
			}
		}
		
		btnSupp(260+13*37, 245, renderer);
		AffTxt(titre, 1, 100, 30, renderer);
		AffChfr(n, 1, 405, 30, renderer);
		AffTxt(nom, 1, 450, 100, renderer);
		bouton(bouton2, 1, 750, 800, renderer);
		
		SDL_SetRenderDrawColor(renderer, 255,0,0,255);
		bouton(bouton3, 1, 750, 850, renderer);
	
		SDL_SetRenderDrawColor(renderer, 255,255,255,255);
		SDL_RenderDrawLine(renderer, 450, 105, 475, 105);
		SDL_RenderDrawLine(renderer, 480, 105, 505, 105);
		SDL_RenderDrawLine(renderer, 510, 105, 535, 105);
		
		SDL_RenderPresent(renderer);
	
	
		SDL_SetRenderDrawColor(renderer, 0,0,0,255); 		//clear render pour afficher le jeu
		SDL_RenderClear(renderer);
	}
	
	
	return 0;

}
	
	



