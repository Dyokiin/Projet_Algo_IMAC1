#include <iostream>
#include <SDL2/SDL.h>
#include "../../lib/jeu.h"
#include "../../lib/joueur.h"
#include "../../lib/jeton.h"
#include "../../lib/AffBtn.h"

using namespace std;

/* Ajoute un jeton de couleur nulle en tête de la liste chainée de jeton */
void insereTete(struct jeu * plateau){

	jeton * jet = (jeton*)malloc(sizeof(jeton));
	jet->couleur = 2;
	jet->suivant = plateau->first;
	jet->precedent = NULL;
	if(plateau->first) plateau->first->precedent = jet;
	else plateau->last = jet;
	plateau->first = jet;	
}


/* Colorie un jeton qui vient d'être posé */
int pose(int x, int y, struct jeu * plateau){
	
	if(couleur(x,y,plateau) == 2){
		if(currentPlay(plateau)){
			jetonAt(x, y, plateau)->couleur = 0;
		} else if(!currentPlay(plateau)){
			jetonAt(x, y, plateau)->couleur = 1;
		}
	} else return 1;
	
	return 0;
}


/* Renvoie le pointeur vers le jeton aux coordones demandees */
jeton* jetonAt(int x, int y, struct jeu * plateau){
	
	struct jeton *jet = (struct jeton*)malloc(sizeof(jeton));
	jet = plateau->first;
	
	for(int pos = 1; pos<xytol(x, y); pos++){
		jet = jet->suivant;
	}
	
	return jet;
}
	

/* Renvoie la couleur du jeton dont les coordonées ont été passées en paramètres */
int couleur(int x, int y, struct jeu * plateau){

	return jetonAt(x, y, plateau)->couleur;
}


/* Renvoie 0 si un coup est possible a l'emplacement (x,y) 1 sinon */
int peuPoser(int x, int y, struct jeu * plateau){
	

	return 0;
}


