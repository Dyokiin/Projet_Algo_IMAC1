#include "../../lib/AffTxt.h"
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

	AffTxt(bouton1, 1, 300, 300, renderer);

	AffTxt(bouton2, 1, 300, 400, renderer);

	AffTxt(bouton3, 1, 300, 500, renderer);

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
