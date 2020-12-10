#ifndef AFFTXT_H
#define AFFTXT_H
#include <SDL2/SDL.h>


void AffL(int n, float taille, int x, int y, SDL_Renderer* ren);
void AffTxt(char*mot, float taille, int x, int y, SDL_Renderer* ren);
void AffChfr(int chiffre, float taille, int x, int y, SDL_Renderer* ren);
void AffNb(int nb, float taille, int x, int y, SDL_Renderer* ren);

#endif 
