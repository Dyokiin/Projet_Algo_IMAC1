#include "../lib/AffTxt.h"
#include "../lib/menus.h"
#include "../lib/jeu.h"
#include "../lib/save.h"
#include <iostream>
#include <SDL2/SDL.h>

using namespace std;



int main(){

	/* Initialisation de la fenêtre et du renderer SDL */
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool quit = false;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		cout << SDL_GetError() << endl;
		goto Quit; }
	window = SDL_CreateWindow("Reversi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000,1000, SDL_WINDOW_SHOWN);
	if(window == NULL) {
		cout << SDL_GetError() << endl;
		goto Quit; }
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL){
		cout << SDL_GetError() << endl;
		goto Quit; }

	
	/* Affichage du menu prencipal et lancement du jeu */
	while (!quit){
		
		switch (menuPrincipal(renderer)) {
			case 1:
				jeu(1, renderer);
				break;
			case 2:
				jeu(2, renderer);
				break;
			case 3:
				quit = true;
				break;
			case 4:
				if(saved()) jeu(loadMode(), renderer);
				break;
			case 0:
				break;
			default:
				quit = true;
				break;
		}

		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 0,0,0,255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255,255,255,255);
	}
	
	
	/* Si le renderer et la fenetre ont bien été créés, on les supprimes et on quitte le programme */
Quit:
	if(renderer != NULL) 
		SDL_DestroyRenderer(renderer);
	if(window != NULL)
		SDL_DestroyWindow(window);
	SDL_Quit();
	
	return EXIT_SUCCESS;
}
