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
	
