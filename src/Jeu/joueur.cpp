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


/* Permet de calculer le score du joueur passé en parametre */
void score(joueur* j,  struct jeu* plateau){
	int scr = 0;
	for(int ii=1; ii<=8; ii++){
		for(int jj=1; jj<=8; jj++){
			if(couleur(ii, jj, plateau) == j->nom[3] ){
				scr += 1;
			}
		}
	}
	j->score = scr;
}


/* Renvoie le numéro du joueur en train de jouer */
bool currentPlay(struct jeu* plateau){
	return plateau->current;
}
