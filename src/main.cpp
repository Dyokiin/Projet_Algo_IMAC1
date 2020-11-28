#include "../lib/AffTxt.h"
using namespace std;



int main()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) return EXIT_FAILURE ;
	SDL_Window* window = SDL_CreateWindow("Reversi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000,1000, SDL_WINDOW_SHOWN);
	if(window == NULL) {
		cout << SDL_GetError();
		return 1; }									  
	
	SDL_Event e;
	bool quit = false;
	while (!quit){
		while(SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				quit = true;
			}
			if (e.type == SDL_KEYDOWN){
				quit = true;
			}
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				quit = true;
			}
		}
	}
	
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}
