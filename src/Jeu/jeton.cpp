#include <iostream>
#include <SDL2/SDL.h>
#include "../../lib/jeu.h"
#include "../../lib/joueur.h"
#include "../../lib/jeton.h"

using namespace std;

void insere(int x, int y, int premier, int cb, struct jeu * plateau){
	int cbi = (premier-1) + cb ;
	int p = 0;
	
	plateau->board[x][y]->couleur = 0;
	
	for(int i=premier; i<=cbi; i++){
		
		p = i;
		if(i>=9) p -= 8;
		
		switch(p){
			case 1:
				
				plateau->board[x][y]->suivHaut = plateau->board[x][y-1];
				break;
			case 2:
				
				plateau->board[x][y]->suivHDroite = plateau->board[x+1][y-1];
				break;
			case 3:
				
				plateau->board[x][y]->suivDroite = plateau->board[x+1][y];
				break;
			case 4:
				
				plateau->board[x][y]->suivBDroite = plateau->board[x+1][y+1];
				break;
			case 5:
				
				plateau->board[x][y]->suivBas = plateau->board[x][y+1];
				break;
			case 6:
				
				plateau->board[x][y]->suivBGauche = plateau->board[x-1][y+1];
				break;
			case 7:
				
				plateau->board[x][y]->suivGauche = plateau->board[x-1][y];
				break;
			case 8:
				
				plateau->board[x][y]->suivHGauche = plateau->board[x-1][y-1];
				break;
		}
	}
}

void pose(int x, int y, struct jeu * plateau){
	
	switch(x){
		case 1:
			if(y==1){
				insere(x, y, 3, 3, plateau);
			} else if(y==8){
				insere(x, y, 1, 3, plateau);
			} else {
				insere(x, y, 1, 5, plateau);
			}
			break;
		case 8:
			if(y==1){
				insere(x, y, 5, 3, plateau);
			} else if(y==8){
				insere(x, y, 7, 3, plateau);
			} else {
				insere(x, y, 5, 5, plateau);
			}
			break;
		default:
			if(y!=1 && y!=8){
				insere(x, y, 1, 8, plateau);
			}
			break;
	}
	
	switch(y){
		case 1:
			if(x!=1 && x!=8){
				insere(x, y, 3, 5, plateau);
			}
			break;
		case 8:
			if(x!=1 && x!=8){
				insere(x, y, 7, 5, plateau);
			}
			break;
	} 
}	
