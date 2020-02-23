main : modeNormal.o  jeu.o
	gcc modeNormal.o jeu.o  -o jeu ; ./jeu

modeNormal.o : modeNormal.c structD.h
	gcc -c modeNormal.c

jeu.o : jeu.c
	gcc -c jeu.c
