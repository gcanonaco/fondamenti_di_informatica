#include<stdio.h>
#define N 3
int main(){
    int M[N][N], i, j, R[N][N], h, k;
    printf("Inserisci la matrice:\n");
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            scanf("%d", &M[i][j]);
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            R[i][j]=0;
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            for(h=i-1;h<i+2; h++)
                if(h>=0 && h<N)
                    for(k=j-1; k<j+2; k++)
                        if(k>=0 && k<N)
                            R[i][j]+=M[h][k];
    for(i=0; i<N; i++){
        for(j=0; j<N; j++)
            printf("%d ", R[i][j]);
        printf("\n");
    }

    return 0;
}
