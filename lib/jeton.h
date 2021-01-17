#ifndef JETON_H
#define JETON_H
#include "jeu.h"

typedef struct jeton{
	int  couleur;
	jeton * precedent;
	jeton * suivant;
}Jeton;

void insereTete(struct jeu * plateau);
int pose(int x, int y, struct jeu * plateau);
int couleur(int x, int y, struct jeu * plateau);
jeton* jetonAt(int x, int y, struct jeu * plateau);
int peuPoser(int x, int y, int direction, struct jeu * plateau);
bool coupPossible(int x, int y, struct jeu * plateau);


#endif 
