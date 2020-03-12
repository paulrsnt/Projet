#include<stdio.h>
#include<stdlib.h>

/*mettre la constante de N=6 et M=7 dans le .h*/

void initMatrice(int char[N][M]){
	int i,j;

	for(int i=0 ; i< N ; i++){
		for(int j=0 ; j < N ; j++){
			mat[i][j] = ' ';
		}
	}
