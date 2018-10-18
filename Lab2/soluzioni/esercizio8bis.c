#include <stdio.h>
#define N1 10
#define N2 4
int main(){
    int i, A[N1], B[N2], j, flag, I[N2], h;
    printf("Inserisci i numeri del primo vettore separati da spazi:\n");
    for(i=0; i<N1; i++)
        scanf("%d", &A[i]);
    printf("Inserisci i numeri del secondo vettore separati da spazi:\n");
    for(i=0; i<N2; i++)
        scanf("%d", &B[i]);
    for(i=0; i<N2; i++)
        I[i]=-1;
    for(j=0; j<N2;j++)
        for(i=0; i<N1; i++)
                if(B[j]==A[i]){
                    for(h=0, flag=1;h<j && flag;h++)
                        if(I[h]==i)
                            flag=0;
                    if(flag)
                        I[j]=i;
                }
    if(I[N2-1]==-1)
        printf("0");
    else
        printf("1");
    return 0;

}
