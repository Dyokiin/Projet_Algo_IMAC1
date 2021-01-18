#include <iostream>
#include <SDL2/SDL.h>
#include "../../lib/joueur.h"
#include "../../lib/menus.h"
#include "../../lib/jeu.h"
#include "../../lib/jeton.h"
using namespace std;


/* Permet d'obtenir le nom d'un joueur */
int getPName(joueur * j,int n, SDL_Renderer *ren){
	return menuNom(n, j->nom, ren);
}


/* Permet de calculer les score des joueurs */
void score(struct jeu* plateau){
	int scr1 = 0;
	int scr2 = 0;
	for(int ii=1; ii<=8; ii++){
		for(int jj=1; jj<=8; jj++){
			if(couleur(ii, jj, plateau) == 0){
				scr1 += 1;
			} else if(couleur(ii, jj, plateau) == ) scr2 += 1;
		}
	}
	plateau->j1->score = scr1;
	plateau->j2->score = scr2;
}

