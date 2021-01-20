#ifndef SAVE_H
#define SAVE_H
#include "jeu.h"



bool saved();
int saveGame(int mode, struct jeu* plateau, bool current);
int loadMode();
void delSave();
bool loadGame(struct jeu * plateau);



#endif
