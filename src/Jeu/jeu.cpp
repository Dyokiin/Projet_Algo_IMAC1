#include <iostream>
#include <SDL2/SDL.h>
#include "../../lib/AffJeu.h"
#include "../../lib/AffTxt.h"
#include "../../lib/AffBtn.h"
#include "../../lib/joueur.h"
#include "../../lib/jeu.h"
#include "../../lib/jeton.h"
using namespace std;



int jeu(int mode, SDL_Renderer * renderer){

	SDL_Event clic;
	int cx = 0;
	int cy = 0;
	int fin =0;
	bool game = true;
	bool coup = false;
	bool current = false; 
	Jeu * plateau;
	struct joueur* j1 = (struct joueur*)malloc((4*sizeof(char)+2*sizeof(int)));
	struct joueur* j2 = (struct joueur*)malloc((4*sizeof(char)+2*sizeof(int)));

	
	/* Menu Nom joueur avec possibilité de quitter */	
		
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
	
	/* Initialisation Joueurs et Plateau */
	
	j1->nom[3] = 0;
	j2->nom[3] = 1;
	j1->jetons = 30;
	j2->jetons = 30;
	j1->score  = 0;
	j2->score  = 0;

	plateau = (Jeu*)malloc( 2*sizeof(joueur) + 64*sizeof(jeton));
	initPlateau(plateau);
	plateau->j1 = j1;
	plateau->j2 = j2;
	
	
	/* Pose des 4 Premiers jetons sans passer par la vérification de coup possible */
	
	pose(4,4,plateau, current);
	pose(5,5,plateau, current);
	current = !current;
	pose(4,5,plateau, current);
	pose(5,4,plateau, current);
	current = !current;
	
	plateau->board[8][2]->couleur=2;
	
	
	/* Boucle principale du jeu | Une boucle = une frame */

	while(game){
		
		/* Boucle d'évènement pour savoir où le joueur clic et agir en fonction */
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
								if(coupPossible(cx,cy,plateau, current)){
									if(pose(cx,cy,plateau, current)!=1){
										for(int cpt=1;cpt<=8;cpt++){
											prise(cx,cy,cpt,plateau, current);
										}
										if(!current) plateau->j1->jetons--;
										else plateau->j2->jetons--;
										current = !current;
										fin = 0;
									}
								}
							}
						}
					}
				}
			}				
		}
	
	
		/* On passe le tour si coup impossible pour le joueur et on vérifie que le jeu n'est pas finit */
		for(int m=1; m<=8; m++){
			for(int n=1; n<=8; n++){
				if(coupPossible(m,n, plateau, current)) coup = true ;
			}
		}
		if(!coup){
			current = !current;
			coup = false;
			fin++;
		}
		if(fin >= 2){
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			char end[23] = "gagne";
			char endname[3];
			if(plateau->j1->score > plateau->j2->score){
				endname[0] = plateau->j1->nom[0];
				endname[1] = plateau->j1->nom[1];
				endname[2] = plateau->j1->nom[2];
			} else { 
				endname[0] = plateau->j2->nom[0];
				endname[1] = plateau->j2->nom[1];
				endname[2] = plateau->j2->nom[2];
			}
			AffNom(endname, 1.5, 310, 175, renderer);
			AffTxt(end, 1.5, 470, 175, renderer);
		}
				 
		
		/* Calcul des scores des joueurs */
				
		score(plateau);
		
		
		/* Affichage de tout les éléments puis nettoyage du renderer */
		
		AffJeton(plateau, renderer);
		AffCurrent(plateau, renderer, current);
		AffPlateau(plateau, renderer, current);
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
	//freePlateau(plateau);
	free(plateau);
	
	return 0;
}
	

/* Initialise le Plateau de jeu avec des jeton de couleur nulle */
void initPlateau(struct jeu * plateau){

	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			Jeton *jet = (Jeton*)malloc(sizeof(Jeton));
			jet->couleur = 2;
			jet->x = i;
			jet->y = j;
			
			plateau->board[i][j] = jet;
		}
	}
}


/* Libère toute la mémoire allouée pour les jetons */
void freePlateau(struct jeu * plateau){

	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			free((jeton*)plateau->board[i][j]);
		}
	}
}


/* Permet de modifer la couleur des jetons pris après un coup */
int prise(int x, int y,int direc, struct jeu * plateau, bool current){
	
	int coul;
	if(!current) coul = 0;
	else coul = 1;
	
	switch(direc){
		case 1:
			if(y == 1) return 1;
			else if(couleur(x,y-1,plateau)==coul){
				jetonAt(x,y,plateau)->couleur=coul;				
				return 0;
			} else if(couleur(x,y-1,plateau)==2) return 1;
			if(prise(x,y-1,direc,plateau, current)==0){
				jetonAt(x,y,plateau)->couleur=coul;
				return 0;
			}
			break;
		case 2:
			if(y == 1 || x == 8) return 1;
			else if(couleur(x+1,y-1,plateau)==coul){
				jetonAt(x,y,plateau)->couleur=coul;
				return 0;
			} else if(couleur(x+1,y-1,plateau)==2) return 1;
			if(prise(x+1,y-1,direc,plateau, current)==0){
				jetonAt(x,y,plateau)->couleur=coul;
				return 0;
			}
			break;
		case 3:
			if(x == 8) return 1;
			else if(couleur(x+1,y,plateau)==coul){
				jetonAt(x,y,plateau)->couleur=coul;
				return 0;
			} else if(couleur(x+1,y,plateau)==2) return 1;
			if(prise(x+1,y,direc,plateau, current)==0){
				jetonAt(x,y,plateau)->couleur=coul;
				return 0;
			}
			break;
		case 4:
			if(x == 8 || y == 8) return 1;
			else if(couleur(x+1,y+1,plateau)==coul){
				jetonAt(x,y,plateau)->couleur=coul;
				return 0;
			} else if(couleur(x+1,y+1,plateau)==2) return 1;
			if(prise(x+1,y+1,direc,plateau, current)==0){
				jetonAt(x,y,plateau)->couleur=coul;
				return 0;
			}
			break;
		case 5:
			if(y == 8) return 1;
			else if(couleur(x,y+1,plateau)==coul){
				jetonAt(x,y,plateau)->couleur=coul;
				return 0;
			} else if(couleur(x,y+1,plateau)==2) return 1;
			if(prise(x,y+1,direc,plateau, current)==0){
				jetonAt(x,y,plateau)->couleur=coul;
				return 0;
			}
			break;
		case 6:
			if(y == 8 || x == 1) return 1;
			else if(couleur(x-1,y+1,plateau)==coul){
				jetonAt(x,y,plateau)->couleur=coul;
				return 0;
			} else if(couleur(x-1,y+1,plateau)==2) return 1;
			if(prise(x-1,y+1,direc,plateau, current)==0){
				jetonAt(x,y,plateau)->couleur=coul;
				return 0;
			}
			break;
		case 7:
			if( x == 1) return 1;
			else if(couleur(x-1,y,plateau)==coul){
				jetonAt(x,y,plateau)->couleur=coul;
				return 0;
			} else if(couleur(x-1,y,plateau)==2) return 1;
			if(prise(x-1,y,direc,plateau, current)==0){
				jetonAt(x,y,plateau)->couleur=coul;
				return 0;
			}
			break;
		case 8:
			if(y == 1 || x == 1) return 1;
			else if(couleur(x-1,y-1,plateau)==coul){
				jetonAt(x,y,plateau)->couleur=coul;
				return 0;
			} else if(couleur(x-1,y-1,plateau)==2) return 1;
			if(prise(x-1,y-1,direc,plateau, current)==0){
				jetonAt(x,y,plateau)->couleur=coul;
				return 0;
			}
			break;
	}

	return 1;
}


/* Trois fonctions qui permettent de passer des coordonées d'un jeton à sa position dans la liste chainee et vice versa */
//INUTILE : PLUS DE LISTE CHAINEE
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

