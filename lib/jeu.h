#ifndef JEU_H
#define JEU_H
#include "joueur.h"
#include "jeton.h"

typedef struct jeu{
	joueur *j1;
	joueur *j2;
	plateau * board;
}Jeu;

typedef struct plateau{
	jeton * pos[8][8];
}

	

int jeu(int mode, SDL_Renderer * renderer);
void initPlateau(struct jeu * plateau);

#endif 
