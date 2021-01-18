#ifndef AFFJEU_H
#define AFFJEU_H
#include "joueur.h"
#include "jeu.h"

void AffPlateau(struct jeu *plateau, SDL_Renderer *renderer, bool current);
void AffJoueur(joueur*j, SDL_Renderer *renderer);
void AffJeton(struct jeu* plateau, SDL_Renderer *renderer);
void AffCurrent(struct jeu* plateau, SDL_Renderer *renderer, bool current);


#endif 
