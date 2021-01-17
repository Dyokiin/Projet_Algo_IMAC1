CC := g++

CFLAGS := `sdl2-config --libs --cflags` -O0 -Wall -lm

HDRS := lib/AffTxt.h lib/menus.h lib/AffBtn.h lib/jeu.h lib/joueur.h lib/AffJeu.h lib/jeton.h
SRCS := src/main.cpp src/Affichage/AffTxt.cpp src/Menu/menus.cpp src/Affichage/AffBtn.cpp src/Affichage/AffJeu.cpp src/Jeu/jeu.cpp src/Jeu/joueur.cpp src/Jeu/jeton.cpp
OBJS := $(SRCS:.c=.o)
EXEC := Reversi

all: $(EXEC)

showfont: showfont.c makefile
	$(CC) -o $@ $@.c $(CFLAGS) $(LIBS)
	
glfont: glfont.c makefile
	$(CC) -o $@ $@.c $(CFLAGS) $(LIBS)

$(EXEC): $(OBJS) $(HDRS) makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

