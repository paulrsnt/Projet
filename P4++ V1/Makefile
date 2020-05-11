All = 1v1.o 1vIA.o 2v2.o jeu.o
src = ./Sources
inc = ./Includes
test = ./Test


clean : main Test1v1 Test2v2
	rm *.o ; rm $(test)/*.o ; rm $(src)/*.o 

main : $(All)
	gcc -Wall -g $(All) -o jeu

1v1.o : $(src)/1v1.c  $(inc)/1v1.h $(inc)/strD.h
	gcc -Wall -g -c $^

1vIA.o : $(src)/1vIA.c  $(inc)/1vIA.h $(inc)/strD.h
	gcc -Wall -g -c $^

2v2.o : $(src)/2v2.c $(inc)/2v2.h $(inc)/strD.h
	gcc -Wall -g -c $^

jeu.o : $(src)/jeu.c $(inc)/1v1.h $(inc)/1vIA.h $(inc)/2v2.h $(inc)/strD.h
	gcc -Wall -g -c $^



Test1v1 : $(src)/1v1.o $(test)/Test1v1.o
	gcc -Wall -g $(src)/1v1.o $(test)/Test1v1.o  -o Test1v1

Test1v1.o : $(test)/Test1v1.c $(src)/1v1.h $(src)/strD.h
	gcc -Wall -g -c $^


Test2v2 : $(src)/2v2.o $(test)/Test2v2.o
		gcc -Wall -g $(src)/2v2.o $(test)/Test2v2.o  -o Test2v2


Test2v2.o : $(test)/Test2v2.c $(src)/2v2.h $(src)/strD.h
	gcc -Wall -g -c $^
