#include "../lib/AffTxt.h"
using namespace std;



int main()
{
	if ((SDL_INIT_EVERYTHING) != 0) return EXIT_FAILURE;
	SDL_Window* win = SDL_CreateWindow("Reversi", SDL_WINDOWPOS_CENTERED, 													  SDL_WINDOWPOS_CENTERED,
	 											  1000,1000,0);
	 											  
	SDL_Delay(3000);
	
	
	SDL_Quit();
	return EXIT_SUCCESS;
}
