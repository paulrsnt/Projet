main : modeNormal.o 2v2.o jeu.o
	gcc modeNormal.o jeu.o 2v2.o -o jeu ; ./jeu

modeNormal.o : modeNormal.c structD.h
	gcc -c modeNormal.c

2v2.o : 2v2.c 
	gcc -c 2v2.c

jeu.o : jeu.c
	gcc -c jeu.c
