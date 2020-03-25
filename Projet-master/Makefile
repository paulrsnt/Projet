clean : main
	rm *.o ; ./jeu

main : 1v1.o 1vIA.o 2v2.o jeu.o
	gcc 1v1.o 1vIA.o 2v2.o jeu.o  -o jeu 

1v1.o : 1v1.c  1v1.h strD.h
	gcc -c 1v1.c

1vIA.o : 1vIA.c  1vIA.h strD.h
	gcc -c 1vIA.c

2v2.o : 2v2.c 2v2.h strD.h
	gcc -c 2v2.c

jeu.o : jeu.c 1v1.h 1vIA.h 2v2.h strD.h
	gcc -c jeu.c


