main : modeNormal.o 2vs2.o jeu.o 
	gcc modeNormal.o jeu.o 2vs2.o -o jeu ; ./jeu

modeNormal.o : modeNormal.c structD.h
	gcc -c modeNormal.c

2vs2.o : 2vs2.c structD.h
	gcc -c 2vs2.c

jeu.o : jeu.c
	gcc -c jeu.c
