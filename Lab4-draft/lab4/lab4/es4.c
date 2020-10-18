//
//  es4.c
//  lab4
//
//  Created by ing.conti on 1718th oct, 2020
//
#include <stdio.h>
#define N 2

int main(){
    int i,j,k,t,A[N][N],ok=1;
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            do {
                ok=1;
                printf("Inserire un valore\n"); scanf("%d", &A[i][j]);
                
                // controlla le righe precedenti
                for (k=0; k<i && ok; k++)
                for (t=0; t<N && ok; t++)
                if (A[i][j] == A[k][t]) {
                    ok=0;
                    printf("duplicato\n");}
                // controlla la riga corrente
                for (t = 0; t < j && ok; t++)
                if(A[i][j] == A[i][t]){
                    ok=0;
                    printf("duplicato nella stessa riga\n");
                }
            }while (ok==0);
        }
    }
}
