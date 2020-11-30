#include "../lib/AffTxt.h"
#include <iostream>
#include <SDL2/SDL.h>
using namespace std;



int main()
{
	SDL_Event e;
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
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	if(renderer == NULL){
		cout << SDL_GetError() << endl;
		goto Quit; }
		
	

	while (!quit){
		
		char Hello[23] = "koxynelle";
		AffTxt(Hello, 1, 20,190, renderer);
		
		while(SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				quit = true;
			}
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				quit = true;
			}
		}
	}
	
	
Quit:
	if(renderer != NULL) 
		SDL_DestroyRenderer(renderer);
	if(window != NULL)
		SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}
