#include <iostream>
#include <SDL2/SDL.h>
#include "../../lib/joueur.h"
#include "../../lib/menus.h"
#include "../../lib/jeu.h"
#include "../../lib/jeton.h"
using namespace std;


int getPName(joueur * j,int n, SDL_Renderer *ren){
	return menuNom(n, j->nom, ren);
}

void score(joueur* j,  struct jeu* plateau){
	
	bool j1 = false;
	if(j->nom[4] == 1) j1 = !j1;
	
	for(int n=1; n<=8; n++){
		for(int m=1; m<=8; m++){
			if(plateau->board[n][m]->couleur == 1 && j1){ j->score +=1; }
			else if(plateau->board[n][m]->couleur == 2 && !j1){ j->score +=1; }
		}
	}
} 
