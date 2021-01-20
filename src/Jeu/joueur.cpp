#include <iostream>
#include <SDL2/SDL.h>
#include <stdlib.h>
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
			} else if(couleur(ii, jj, plateau) == 1) scr2 += 1;
		}
	}
	plateau->j1->score = scr1;
	plateau->j2->score = scr2;
}



/* Joueur IA / Machine / ne sait pas trop ce qu'il fait mais le fait */
void roboto(struct jeu* plateau){	
	
	SDL_Delay(500);
	
	int lalaetla = 0;
	int jysuis = 0;
	time_t t;
	int icicestbien = 0;
	
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			if(coupPossible(i,j, plateau, true) && couleur(i,j,plateau)==2)  lalaetla ++;
		}
	}
	
	srand((unsigned) time(&t));
	icicestbien = rand() %lalaetla +1;
	
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			if(coupPossible(i,j, plateau, true)){
				jysuis ++;
				if(jysuis==icicestbien){
					if(pose(i,j,plateau, true)!=1){
						for(int cpt=1;cpt<=8;cpt++){
							prise(i,j,cpt,plateau, true);
						}
					} else jysuis--;
				}
			}
		}
	}
}
