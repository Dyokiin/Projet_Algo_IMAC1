#include <iostream>
#include <SDL2/SDL.h>
#include "../../lib/joueur.h"
#include "../../lib/menus.h"
using namespace std;


int getPName(joueur * j,int n, SDL_Renderer *ren){
	return menuNom(n, j->nom, ren);
}
