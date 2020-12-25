#ifndef JOUEUR_H
#define JOUEUR_H

typedef struct joueur{
	char nom[4];
	int jetons;
	int score;
}Joueur;


int getPName(joueur * j, int n, SDL_Renderer *ren);



#endif 
