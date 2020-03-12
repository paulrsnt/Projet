main : structD.o 2v2.o jeu.o
	gcc structD.o 2v2.o jeu.o  -o jeu ; ./jeu

structD.o : structD.c structD.h
		gcc -c structD.c

2v2.o : 2v2.c 2v2.h
	gcc -c 2v2.c

jeu.o : jeu.c
	gcc -c jeu.c 
