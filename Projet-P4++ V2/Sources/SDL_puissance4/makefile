CC=gcc
OPTS=-g -o
CFLAGS=-W -Wall
SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=./lib/
SDLINC_DIR=${SDL_DIR}/include
INT_SDL=./interface_SDL/


PUISSANCE4_O=menu_SDL.o main_SDL.o LaTexture.o 1v1.o 1vIA.o 2v2.o 
LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer


PROG=puissance4_SDL

all: clean puissance4++

puissance4++: ${PUISSANCE4_O}

	gcc -o ${PROG} $(PUISSANCE4_O) ${LIBS} ${INCLUDES} ${CFLAGS}

main_SDL.o: ./main_SDL.c ${INT_SDL}SDL_puissance4.h
	gcc -o main_SDL.o -c ./main_SDL.c ${CFLAGS}

LaTexture.o: ${INT_SDL}LaTexture.c ${INT_SDL}SDL_puissance4.h
	gcc -o LaTexture.o -c ${INT_SDL}LaTexture.c ${CFLAGS}

	

1v1.o: ${INT_SDL}1v1.c ${INT_SDL}SDL_puissance4.h
	gcc -o 1v1.o -c ${INT_SDL}1v1.c ${CFLAGS}

1vIA.o: ${INT_SDL}1vIA.c ${INT_SDL}SDL_puissance4.h
	gcc -o 1vIA.o -c ${INT_SDL}1vIA.c ${CFLAGS}

2v2.o: ${INT_SDL}2v2.c ${INT_SDL}SDL_puissance4.h
	gcc -o 2v2.o -c ${INT_SDL}2v2.c ${CFLAGS}		

menu_SDL.o: ${INT_SDL}menu_SDL.c ${INT_SDL}LaTexture.c ${INT_SDL}SDL_puissance4.h
	gcc -o menu_SDL.o -c ${INT_SDL}menu_SDL.c ${CFLAGS}

clean:
	rm -f *.o
	rm -f obj/*.o
	rm -f ${PROG}
	@echo "\033[31m clean ended succesfully "

