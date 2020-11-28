CC := g++

CFLAGS := `sdl2-config --libs --cflags` -O0 -Wall -lm

HDRS := lib/AffTxt.h
SRCS := src/main.c src/txt/AffTxt.cpp
OBJS := $(SRCS:.c=.o)
EXEC := Reversi

all: $(EXEC)

showfont: showfont.c makefile
	$(CC) -o $@ $@.c $(CFLAGS) $(LIBS)
	
glfont: glfont.c makefile
	$(CC) -o $@ $@.c $(CFLAGS) $(LIBS)

$(EXEC): $(OBJS) $(HDRS) makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

