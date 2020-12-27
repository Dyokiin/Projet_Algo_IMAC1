#ifndef JETON_H
#define JETON_H
#include "jeu.h"

typedef struct jeton{
	int couleur;
	jeton * suivHaut;
	jeton * suivHDroite;
	jeton * suivDroite ;
	jeton * suivBDroite;
	jeton * suivBas;
	jeton * suivBGauche;
	jeton * suivGauche ;
	jeton * suivHGauche;
}Jeton;


void insere(int x,int y, int start, int until, struct jeu * plateau);
void pose(int x, int y, struct jeu * plateau);



#endif 
