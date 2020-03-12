#include <stdio.h>
#include <stdlib.h>
#define N 6
#define M 7

void afficher_mat(char mat[N][M]){
/*fonction qui permet de afficher la matrice*/
    int i, j;
    for(i=0;i<N;i++){       /*parcour de la ligne*/
        for(j=0;j<M;j++){   /*parcour du colonnes*/
            printf("%c | ", mat[i][j]);
        }
        printf("\n");
    }
}



int main(){
    char mat[N][M];
    mat[5][0]='R';
    mat[5][1]='R';
    mat[5][2]='R';
    mat[5][3]='R';
    afficher_mat(mat);
    return 0;
}
