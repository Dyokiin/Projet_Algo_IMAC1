#include <iostream>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <string.h>
#include "../../lib/AffTxt.h"

using namespace std;



void bouton(char* mot, float taille, int x, int y, SDL_Renderer* ren){
	
	SDL_Rect btn;
	
	btn.x = x-2;
	btn.y = y-2;
	btn.h = 25*taille +5*taille +2;
	btn.w = AffTxt(mot, taille, x, y, ren) + 2;
	
	SDL_RenderDrawRect(ren, &btn);
	
}

void boutonl(int n, float taille, int x, int y, SDL_Renderer* ren){
	SDL_Rect btn;
	
	btn.x = x -2;
	btn.y = y -2;
	btn.h = 25*taille +5*taille +2;
	btn.w = 25*taille +5*taille +2;
	SDL_RenderDrawRect(ren, &btn);
	AffL(n, taille, x, y, ren);
}

void btnSupp(int x, int y, SDL_Renderer* ren){

	SDL_Rect btn;
	
	btn.x = x;
	btn.y = y;
	btn.h = 32;
	btn.w = 32;
	SDL_RenderDrawRect(ren, &btn);
	btn.x = x+12;
	btn.y = y +8;
	btn.h = 16;
	btn.w = 16;
	SDL_RenderDrawRect(ren, &btn);
	SDL_RenderDrawLine(ren, x+4, y+16, x+12, y+8);
	SDL_RenderDrawLine(ren, x+4, y+16, x+12, y+24);
	SDL_RenderDrawLine(ren, x+16, y+12, x+24, y+20);
	SDL_RenderDrawLine(ren, x+16, y+20, x+24, y+12);

}
	

// Le code qui suit permet d afficher des disques

void lignH(int x, int y, int w, SDL_Renderer* ren){
	SDL_Rect r;
	
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = 1;
	
	SDL_RenderFillRect(ren, &r);
}

void disque(int cx, int cy, int coul, SDL_Renderer* ren){
	int d, y, x;
	
	d = 3 - (2 * 25);
	x = 0;
	y = 25;
	
	if(!coul){
		SDL_SetRenderDrawColor(ren, 255,255,255,255);
		while(y >= x){
			lignH(cx-x, cy-y, 2*x+1, ren);
			lignH(cx-x, cy+y, 2*x+1, ren);
			lignH(cx-y, cy-x, 2*y+1, ren);
			lignH(cx-y, cy+x, 2*y+1, ren);
		
			if(d<0) d = d+(4*x) + 6;
			else {
				d = d+4*(x-y)+10;
				y--;
			}
		
			x++;
		}
	}
	if(coul){
		SDL_SetRenderDrawColor(ren, 0,0,0,255);
		while(y >= x){
			lignH(cx-x, cy-y, 2*x+1, ren);
			lignH(cx-x, cy+y, 2*x+1, ren);
			lignH(cx-y, cy-x, 2*y+1, ren);
			lignH(cx-y, cy+x, 2*y+1, ren);
		
			if(d<0) d = d+(4*x) + 6;
			else {
				d = d+4*(x-y)+10;
				y--;
			}
		
			x++;
		}
	}
	
	SDL_RenderPresent(ren);
		
}
	
