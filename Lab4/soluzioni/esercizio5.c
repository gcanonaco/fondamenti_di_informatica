#include <stdio.h>
#define N 3
void analizzaMatrice(int [][N]);
int isMaxRigaColonna(int, int, int [][N]);
int isMaxDiag(int, int, int [][N]);
int main() {
    int i,j,M[N][N];
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            scanf("%d", &M[i][j]);

    analizzaMatrice(M);

    return 0;
}

void analizzaMatrice(int M[][N]){
    int i, j;
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            if(isMaxRigaColonna(i,j,M) && isMaxDiag(i,j,M))
                printf("(%d, %d, %d)\n", M[i][j], i, j);
}
int isMaxRigaColonna(int i, int j, int M[][N]){
    int max = M[i][j], h=0, k=0,d;
    for(d=0; d<N; d++)
        if(M[h+d][j]>max || M[i][k+d]>max)
            return 0;
    return 1;
}
int isMaxDiag(int i, int j, int M[][N]){
    int max=M[i][j], min, d;
    if(i<j)
        min=i;
    else
        min=j;
    for(d=0; d<N; d++) {
        if (i - min + d >= 0 && i - min + d < N && j - min + d >= 0 && j - min + d < N && M[i - min + d][j - min + d] > max)
            return 0;
        if (i + min - d >= 0 && i + min - d < N && j - min + d >= 0 && j - min + d < N && M[i + min - d][j - min + d] > max)
            return 0;
    }
    return 1;
}
