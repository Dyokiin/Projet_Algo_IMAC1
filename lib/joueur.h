#ifndef JOUEUR_H
#define JOUEUR_H

typedef struct joueur{
	char nom[4];
	int jetons;
	int score;
}Joueur;


int getPName(joueur * j, int n, SDL_Renderer *ren);
//bool currentPlay(struct jeu* plateau);
void score(struct jeu* plateau);
void roboto(struct jeu* plateau);


#endif 
