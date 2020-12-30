#include <iostream>
#include <SDL2/SDL.h>
#include "../../lib/AffJeu.h"
#include "../../lib/AffBtn.h"
#include "../../lib/joueur.h"
#include "../../lib/jeu.h"
#include "../../lib/jeton.h"
using namespace std;


int jeu(int mode, SDL_Renderer * renderer){
	SDL_Event clic;
	int cx = 0;
	int cy = 0;
	bool game = true;
	Jeu * plateau;
	struct joueur* j1 = (struct joueur*)malloc((4*sizeof(char)+2*sizeof(int)));
	struct joueur* j2 = (struct joueur*)malloc((4*sizeof(char)+2*sizeof(int)));
	bool coup = false;
	
	if(mode == 1){
		if(getPName(j1, 1, renderer)==1){
			free((joueur *)j1);
			free((joueur *)j2);	
			return 1;
		}
		if(getPName(j2, 2, renderer)==1){
			free((joueur *)j1);
			free((joueur *)j2);
			return 1; 
		}
	}
	else {
		if(getPName(j1, 1, renderer)==1){
			free((joueur *)j1);
			free((joueur *)j2);	
			return 1;
		}
		j2->nom[0] = 'b';
		j2->nom[1] = 'o';
		j2->nom[2] = 't';
	}
	
	j1->nom[3] = 0;
	j2->nom[3] = 1;
	j1->jetons = 30;
	j2->jetons = 30;
	j1->score  = 0;
	j2->score  = 0;
	cout << "init joueurs" << endl;
	

	plateau = (Jeu*)malloc(sizeof(Jeu));
	cout << "mallocs plateau" << endl;
	initPlateau(plateau);
	plateau->j1 = j1;
	plateau->j2 = j2;
	plateau->current = true;
	
	
	pose(4,4,plateau);
	pose(5,5,plateau);
	plateau->current = !plateau->current;
	pose(4,5,plateau);
	pose(5,4,plateau);
	plateau->current = !plateau->current;
	
	AffJeton(plateau, renderer);

	while(game){

		while(SDL_PollEvent(&clic)){
			if (clic.type == SDL_QUIT){
				game = false;
			}
			if (clic.type == SDL_MOUSEBUTTONDOWN) {
				int x,y;
				SDL_GetMouseState(&x, &y);
			
				if(x > 750 && y > 850) game = false;
				
				for(int i=1; i<=8; i++){
					for(int j=1; j<=8; j++){
						if (x <= 250+i*65 && x >= 250+(i-1)*65){
							if(y <= 250+j*65 && y >= 250+(j-1)*65){
								coup = !coup;
								cx = i;
								cy = j;
								if(pose(cx,cy,plateau)!=1) plateau->current = !plateau->current;
								
								//else affiche erreur
							}
						}
					}
				}
			}				
		}
	
		
				
		score(j1, plateau);
		score(j2, plateau);
		
		
		AffCurrent(plateau, renderer);
		AffPlateau(plateau, renderer);
		AffJeton(plateau, renderer);
		AffJoueur(j1, renderer);
		AffJoueur(j2, renderer);
		
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 0,0,0,255); 		//clear render pour afficher le jeu
		SDL_RenderClear(renderer);
	}
	
	
	/* Liberation de toute la mémoire allouée ici */
	
	
	free((joueur *)j1);
	free((joueur *)j2);
	free(plateau);
	
	
	return 0;
}
	

/* Initialise le Plateau de jeu avec des jeton de couleur nulle */
void initPlateau(struct jeu * plateau){

	plateau->first = NULL;
	plateau->last = NULL;
	
	for(int i=1;i<=64;i++){
		insereTete(plateau);
	}
}


/* Trois fonctions qui permettent de passer des coordonées d'un jeton à sa position dans la liste chainee et vice versa */

int xytol(int x,int y){

	return (y-1)*8+x ;
}

int ltox(int l){
	
	if(l<=8 ) return l;
	else if(l<=16) l-=8;
	else if(l<=24) l-=16;
	else if(l<=32) l-=24;
	else if(l<=40) l-=32;
	else if(l<=48) l-=40;
	else if(l<=56) l-=48;
	else if(l<=64) l-=56;
	return l;
}
	
int ltoy(int l){

	int rtrn;
	if(l<=8 ) rtrn = 1;
	else if(l<=16) rtrn = 8;
	else if(l<=24) rtrn =16;
	else if(l<=32) rtrn =24;
	else if(l<=40) rtrn =32;
	else if(l<=48) rtrn =40;
	else if(l<=56) rtrn =48;
	else if(l<=64) rtrn =56;
	return rtrn;
}

