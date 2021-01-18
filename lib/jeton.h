#ifndef JETON_H
#define JETON_H
#include "jeu.h"

typedef struct jeton{
	int  couleur;
	int x;
	int y;
}Jeton;

void insereTete(struct jeu * plateau);
int pose(int x, int y, struct jeu * plateau, bool current);
int couleur(int x, int y, struct jeu * plateau);
jeton* jetonAt(int x, int y, struct jeu * plateau);
int peuPoser(int x, int y, int direction, struct jeu * plateau, bool current);
bool coupPossible(int x, int y, struct jeu * plateau, bool current);


#endif 
