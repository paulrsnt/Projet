CC=gcc
OPTS=-g -o
CFLAGS=-W -Wall
SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=./lib/
SDLINC_DIR=${SDL_DIR}/include
SOURCES_SDL=./interface_SDL/Sources/
INCLUDES_SDL=./interface_SDL/Includes/
SOURCES_P4=../P4++V2/Sources/
INCLUDES_P4=../P4++V2/Includes/
PUISSANCE4_O=menu_SDL.o main_SDL.o LaTexture.o 1v1.o 1vIA.o 2v2.o parcours.o
LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
PROG=puissance4_SDL



all: clean puissance4++ clean2

puissance4++: ${PUISSANCE4_O}

	gcc -o ${PROG} $^ ${LIBS} ${INCLUDES} ${CFLAGS}


main_SDL.o: ${SOURCES_SDL}main_SDL.c ${INCLUDES_SDL}SDL_puissance4.h
	gcc -c $^ ${CFLAGS}

LaTexture.o: ${SOURCES_SDL}LaTexture.c ${INCLUDES_SDL}SDL_puissance4.h
	gcc -c $^ ${CFLAGS}



1v1.o: ${SOURCES_P4}1v1.c  ${INCLUDES_P4}1v1.h ${INCLUDES_P4}strD.h
	gcc -c $^ ${CFLAGS}

1vIA.o: ${SOURCES_P4}1vIA.c ${INCLUDES_P4}1vIA.h ${INCLUDES_P4}strD.h
	gcc -c $^ ${CFLAGS}

2v2.o: ${SOURCES_P4}2v2.c ${INCLUDES_P4}2v2.h ${INCLUDES_P4}strD.h
	gcc -c $^ ${CFLAGS}


parcours.o: ${SOURCES_P4}parcours.c ${INCLUDES_P4}parcours.h ${INCLUDES_P4}strD.h
	gcc -c $^ ${CFLAGS}




menu_SDL.o: ${SOURCES_SDL}menu_SDL.c ${SOURCES_SDL}LaTexture.c ${INCLUDES_SDL}SDL_puissance4.h
	gcc -c $^ ${CFLAGS}

clean:
	rm -f *.o
	rm -f obj/*.o
	rm -f ${PROG}
	@echo "\033[31m clean ended succesfully "

clean2:
	rm -f *.o
	rm -f obj/*.o
