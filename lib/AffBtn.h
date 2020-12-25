#ifndef AFFBTN_H
#define AFFBTN_H
#include <SDL2/SDL.h>

void bouton(char* mot, float taille, int x, int y, SDL_Renderer* ren);
void boutonl(int n, float taille, int x, int y, SDL_Renderer* ren);
void btnSupp(int x, int y, SDL_Renderer* ren);
void lignH(int x, int y, int w, SDL_Renderer* ren);
void disque(int cx, int cy, int coul, SDL_Renderer* ren);

#endif 
