#ifndef JEU_H
#define JEU_H
#include "joueur.h"
#include "jeton.h"

typedef struct jeu{
	jeton* first;
	jeton* last;
	joueur *j1;
	joueur *j2;
	bool current;
}Jeu;
	

int jeu(int mode, SDL_Renderer * renderer);
void initPlateau(struct jeu * plateau);
int xytol(int x, int y);
int ltox(int l);
int ltoy(int l);
int prise(int x, int y, int direc, struct jeu * plateau);

#endif 
