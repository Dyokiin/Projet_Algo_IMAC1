#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>
#include "../../lib/jeu.h"
#include "../../lib/joueur.h"
#include "../../lib/jeton.h"

using namespace std;



/* Indique si une partie est actuellement sauvegardée */
bool saved(){
	bool issaved = true;
	
	ifstream saveFlux;
	saveFlux.open("src/Jeu/save/save.txt");
	string line;
	
	getline(saveFlux, line);
	int saved = stoi(line);
	if(saved == 3) issaved = false;
	
	saveFlux.close();
		
	return issaved;
}


/* Fonction permettant de sauvegarder l'état d'une partie de jeu */
int saveGame(int mode, struct jeu* plateau, bool current){
	
	ofstream saveFlux;
	saveFlux.open("src/Jeu/save/save.txt");
	
	saveFlux << current << endl;
	if(mode<=2){
		saveFlux << mode << endl;
	} else {
		saveFlux << mode - 2 << endl;
	}
	saveFlux << plateau->j1->nom[0] << plateau->j1->nom[1] << plateau->j1->nom[2] << endl << plateau->j1->jetons << endl;
	saveFlux << plateau->j2->nom[0] << plateau->j2->nom[1] << plateau->j2->nom[2] << endl << plateau->j2->jetons << endl;
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			saveFlux << plateau->board[i][j]->couleur << endl;
		}
	}

	saveFlux.close();

	return 0;
}


/* Fonction qui renvoie le mode de jeu de la partie sauvegardée */
int loadMode(){
	ifstream saveFlux;
	saveFlux.open("src/Jeu/save/save.txt");
	string line;
	
	for(int i=0;i<=1;i++){
		getline(saveFlux, line);
	}
	int mode = stoi(line); //on transforme le string en int
	
	saveFlux.close();
	
	return mode + 2;
}


/* Supprime la save */
void delSave(){
	
	ofstream saveFlux;
	saveFlux.open("src/Jeu/save/save.txt");
	
	saveFlux << 3 << endl;



}


/* Charge la partie sauvegardée */
bool loadGame(struct jeu * plateau){
	int i = 0;
	int j = 0;
	char nm[4];
	int jtns =0;
	bool current;
	
	ifstream saveFlux;
	saveFlux.open("src/Jeu/save/save.txt");
	string line;

	getline(saveFlux, line);
	jtns = stoi(line);
	if(jtns) current = true;
	else current = false;
	
	getline(saveFlux, line);
	
	getline(saveFlux, line);
	strcpy(nm, line.c_str());
	getline(saveFlux, line);
	jtns = stoi(line);
	
	plateau->j1->nom[0] = nm[0];
	plateau->j1->nom[1] = nm[1];
	plateau->j1->nom[2] = nm[2];
	plateau->j1->nom[3] = 0;
	plateau->j1->jetons = jtns ;


	getline(saveFlux, line);
	strcpy(nm, line.c_str());
	getline(saveFlux, line);
	jtns = stoi(line);
	
	plateau->j2->nom[0] = nm[0];
	plateau->j2->nom[1] = nm[1];
	plateau->j2->nom[2] = nm[2];
	plateau->j2->nom[3] = 1;
	plateau->j2->jetons = jtns ;
	
	for(i=1;i<=8;i++){
		for(j=1;j<=8;j++){
			getline(saveFlux, line);
			jtns = stoi(line);
			plateau->board[i][j]->couleur = jtns;
		}
	}
	
	saveFlux.close();
	
	return current;
}
