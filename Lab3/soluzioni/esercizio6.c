#include<stdio.h>
#define N 5
int main(){
    int M[N][N], v[N], i, j, r, c, d, ri, ci, di, flag, dd, ddi;
    printf("Inserisci la matrice:\n");
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            scanf("%d", &M[i][j]);
    printf("Inserisci il vettore:\n");
    for(i=0; i<N; i++)
        scanf("%d", &v[i]);
    for(i=0, d=1, di=1, dd=1, ddi=1, flag=0; i<N && !flag && (d || di || dd || ddi); i++){
        if(M[i][i]!=v[i])
            d=0;
        if(M[N-i-1][N-i-1]!=v[i])
            di=0;
        if(M[i][N-i-1]!=v[i])
            dd=0;
        if(M[N-i-1][i]!=v[i])
            ddi=0;
        for(j=0,r=1,c=1; j<N && (r || ri || c || ci ); j++){
            if(M[i][j]!=v[j])
                r=0;
            if(M[i][N-j-1]!=v[j])
                ri=0;
            if(M[j][i]!=v[j])
                c=0;
            if(M[N-j-1][i]!=v[j])
                ci=0;
        }
        if(r || c || ri || ci)
            flag=1;
    }
    if(flag || d || di || dd || ddi)
        printf("1\n");
    else
        printf("0\n");
    return 0;



}
