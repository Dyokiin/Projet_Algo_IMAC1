#include <iostream>
#include <SDL2/SDL.h>
#include "../../lib/AffJeu.h"
#include "../../lib/AffBtn.h"
#include "../../lib/joueur.h"
#include "../../lib/jeu.h"
using namespace std;


int jeu(int mode, SDL_Renderer * renderer){
	SDL_Event clic;
	int cx = 0;
	int cy = 0;
	bool game = true;
	
	struct joueur * j1 = (struct joueur*)malloc((4*sizeof(char)+2*sizeof(int)));
	struct joueur * j2 = (struct joueur*)malloc((4*sizeof(char)+2*sizeof(int)));
	
	if(mode == 1){
		if(getPName(j1, 1, renderer)==1){
			free((joueur *)j1);
			free((joueur *)j2);	
			return 1;
		}
		if(getPName(j2, 2, renderer)==1){
			free((joueur *)j1);
			free((joueur *)j2);
			return 1; 
		}
	}
	else {
		if(getPName(j1, 1, renderer)==1){
			free((joueur *)j1);
			free((joueur *)j2);	
			return 1;
		}
		j2->nom[0] = 'b';
		j2->nom[1] = 'o';
		j2->nom[2] = 't';
	}
	
	j1->nom[3] = 1;
	j2->nom[3] = 2;
	j1->jetons = 30;
	j2->jetons = 30;
	j1->score  = 0;
	j2->score  = 0;

	while(game){

		while(SDL_PollEvent(&clic)){
			if (clic.type == SDL_QUIT){
				game = false;
			}
			if (clic.type == SDL_MOUSEBUTTONDOWN) {
				int x,y;
				SDL_GetMouseState(&x, &y);
			
				if(x > 750 && y > 850) game = false;
				
				for(int i=1; i<=8; i++){
					for(int j=1; j<=8; j++){
						if (x <= 250+i*65 && x >= 250+(i-1)*65){
							if(y <= 250+j*65 && y >= 250+(j-1)*65){
								cx = i;
								cy = j;
								cout << cx << " " << cy << endl;
							}
						}
					}
				}
			}				
		}
	
	
	
		AffPlateau(mode, renderer);
		AffJoueur(j1, renderer);
		AffJoueur(j2, renderer);
		
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 0,0,0,255); 		//clear render pour afficher le jeu
		SDL_RenderClear(renderer);
	}
	
	
	free((joueur *)j1);
	free((joueur *)j2);
	
	
	return 0;
}
	



