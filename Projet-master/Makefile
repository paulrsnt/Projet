main : structD.o V2.o jeu.o
	gcc structD.o V2.o jeu.o  -o jeu ; ./jeu

structD.o : structD.c structD.h
		gcc -c structD.c

V2.o : V2.c V2.h
	gcc -c V2.c

jeu.o : jeu.c
	gcc -c jeu.c
