#include <stdio.h>
#define N 3
int main(){
    int i,j,M[N][N],c=1,h;
    for(i=0,h=0;i<N;i++){
        for(j=0;j<N;j++){
            M[i][j] = c+h;
            h++;
            printf("%3d", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<N;i++)
        for(j=i;j<N;j++){
            if(i!=j){
                M[i][j]+=M[j][i];
                M[j][i]=0;
            }
        }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            printf("%3d",M[i][j]);
        printf("\n");
    }
    return 0;
}
