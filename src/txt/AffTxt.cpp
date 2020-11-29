#include <iostream>
#include <SDL2/SDL.h>
#include <stdlib.h>

using namespace std;

#define H_MIN 3
#define L_MIN 25


void AffL(int n, int taille, int x, int y, SDL_Renderer* ren){

	SDL_SetRenderDrawColor(ren, 255,255,255,255);
	SDL_Rect rect;

	switch (n) {
		case 1:
			rect.x =x;
			rect.y =y;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+(taille*L_MIN);
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+(taille*L_MIN)/2;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			SDL_RenderPresent(ren);
			break;
		case 2:

			break;
		case 3:
			rect.x =x;
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.w =L_MIN*taille;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille;
			rect.w =L_MIN*taille;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			SDL_RenderPresent(ren);
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		case 13:
			break;
		case 14:
			break;
		case 15:
			break;
		case 16:
			break;
		case 17:
			break;
		case 18:
			break;
		case 19:
			break;
		case 20:
			break;
		case 21:
			break;
		case 22:
			break;
		case 23:
			break;
		case 24:
			break;
		case 25:
			break;
		case 26:
			break;
		default:
			break;
	}
}
