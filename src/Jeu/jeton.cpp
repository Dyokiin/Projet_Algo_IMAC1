#include <iostream>
#include <SDL2/SDL.h>
#include "../../lib/jeu.h"
#include "../../lib/joueur.h"
#include "../../lib/jeton.h"
#include "../../lib/AffBtn.h"

using namespace std;



/* Colorie un jeton qui vient d'être posé */
int pose(int x, int y, struct jeu * plateau, bool current){
	
	if(couleur(x,y,plateau) == 2){
		if(!current){
			jetonAt(x, y, plateau)->couleur = 0;
		} else if(current){
			jetonAt(x, y, plateau)->couleur = 1;
		}
	} else return 1;
	
	return 0;
}


/* Renvoie le pointeur vers le jeton aux coordones demandees */
jeton* jetonAt(int x, int y, struct jeu * plateau){
	
	/*
	struct jeton *jet;
	jet = plateau->first;
	
	for(int pos = 1; pos<xytol(x, y); pos++){
		jet = jet->suivant;
	}
	*/
	
	return plateau->board[x][y];
}
	

/* Renvoie la couleur du jeton dont les coordonées ont été passées en paramètres */
int couleur(int x, int y, struct jeu * plateau){

	return jetonAt(x, y, plateau)->couleur;
}


/* RECURSION :  Renvoie 0 si un coup est possible a l'emplacement (x,y) par rapport à une direction 1 sinon */
int peuPoser(int x, int y, int direc, struct jeu * plateau, bool current){
	
	int coul;
	if(!current) coul = 0;
	else coul = 1;
	
	switch(direc){
		case 1:
			if(y == 1) return 1;
			else if(couleur(x,y-1,plateau)==coul) return 0;
			else if(couleur(x,y-1,plateau)==2) return 1;
			return peuPoser(x,y-1,direc,plateau, current);
			break;
		case 2:
			if(y == 1 || x == 8) return 1;
			else if(couleur(x+1,y-1,plateau)==coul) return 0;
			else if(couleur(x+1,y-1,plateau)==2) return 1;
			return peuPoser(x+1,y-1,direc,plateau, current);
			break;
		case 3:
			if(x == 8) return 1;
			else if(couleur(x+1,y,plateau)==coul) return 0;
			else if(couleur(x+1,y,plateau)==2) return 1;
			return peuPoser(x+1,y,direc,plateau, current);
			break;
		case 4:
			if(x == 8 || y == 8) return 1;
			else if(couleur(x+1,y+1,plateau)==coul) return 0;
			else if(couleur(x+1,y+1,plateau)==2) return 1;
			return peuPoser(x+1,y+1,direc,plateau, current);
			break;
		case 5:
			if(y == 8) return 1;
			else if(couleur(x,y+1,plateau)==coul) return 0;
			else if(couleur(x,y+1,plateau)==2) return 1;
			return peuPoser(x,y+1,direc,plateau, current);
			break;
		case 6:
			if(y == 8 || x == 1) return 1;
			else if(couleur(x-1,y+1,plateau)==coul) return 0;
			else if(couleur(x-1,y+1,plateau)==2) return 1;
			return peuPoser(x-1,y+1,direc,plateau, current);
			break;
		case 7:
			if( x == 1) return 1;
			else if(couleur(x-1,y,plateau)==coul) return 0;
			else if(couleur(x-1,y,plateau)==2) return 1;
			return peuPoser(x-1,y,direc,plateau, current);
			break;
		case 8:
			if(y == 1 || x == 1) return 1;
			else if(couleur(x-1,y-1,plateau)==coul) return 0;
			else if(couleur(x-1,y-1,plateau)==2) return 1;
			return peuPoser(x-1,y-1,direc,plateau, current);
			break;
	}

	return 1;
}


/* Indique si un coup peu être effectué par le joueur courrant sur une case donnée */ 
bool coupPossible(int x, int y, struct jeu * plateau, bool current){
	
	if(couleur(x,y,plateau) !=2) return false;
	bool cp1 = false;
	int cp2 = 1;
	int coul;
	if(!current) coul = 1;
	else coul = 0;
	
	for(int i=1; i<=8; i++){
		switch(i){
			case 1:
				if(y!=1 && couleur(x,y-1, plateau)==coul){
					if(peuPoser(x,y-1,1, plateau, current)==0) cp1 = true;
				} else cp2++;
				break;
			case 2:
				if(y!=1 && x!=8 && couleur(x+1,y-1, plateau)==coul){
					if(peuPoser(x+1,y-1,2, plateau, current)==0) cp1 = true;
				} else cp2++;
				break;
			case 3:
				if(x!=8 && couleur(x+1,y, plateau)==coul){
					if(peuPoser(x+1,y,3, plateau, current)==0) cp1 = true;
				} else cp2++;
				break;
			case 4:
				if(y!=8 && x!=8 && couleur(x+1,y+1, plateau)==coul){
					if(peuPoser(x+1,y+1,4, plateau, current)==0) cp1 = true;
				} else cp2++;
				break;	
			case 5:
				if(y!=8 && couleur(x,y+1, plateau)==coul){
					if(peuPoser(x,y+1,5, plateau, current)==0) cp1 = true;
				} else cp2++;
				break;
			case 6:
				if(y!=8 && x!=1 && couleur(x-1,y+1, plateau)==coul){
					if(peuPoser(x-1,y+1,6, plateau, current)==0) cp1 = true;
				} else cp2++;
				break;
			case 7:
				if(x!=1 && couleur(x-1,y, plateau)==coul){
					if(peuPoser(x-1,y,7, plateau, current)==0) cp1 = true;
				} else cp2++;
				break;
			case 8:
				if(y!=1 && x!=1 && couleur(x-1,y-1, plateau)==coul){
					if(peuPoser(x-1,y-1,8, plateau, current)==0) cp1 = true;
				} else cp2++;
				break;
		}
	}
	
	if(cp1 && cp2<=8) return true;
	return false;

}


/* Ajoute un jeton de couleur nulle en tête de la liste chainée de jeton INUTILE / PLUS DE LISTE CHAINEE
void insereTete(struct jeu * plateau){

	jeton * jet = (jeton*)malloc(sizeof(jeton));
	jet->couleur = 2;
	jet->suivant = plateau->first;
	jet->precedent = NULL;
	if(plateau->first) plateau->first->precedent = jet;
	else plateau->last = jet;
	plateau->first = jet;	
}
*/



