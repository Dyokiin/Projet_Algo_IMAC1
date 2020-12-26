#ifndef JEU_H
#define JEU_H
#include "joueur.h"
#include "jeton.h"

typedef struct jeu{
	joueur j1;
	joueur j2;
	jeton * board[8][8];
}Jeu;


	

int jeu(int mode, SDL_Renderer * renderer);

#endif 
