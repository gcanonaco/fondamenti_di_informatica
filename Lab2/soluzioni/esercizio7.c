#include <stdio.h>
#define N1 50
#define N2 10
int main(){
    int i, A[N1], B[N2], j, flag;
    printf("Inserisci i numeri del primo vettore separati da spazi:\n");
    for(i=0; i<N1; i++)
        scanf("%d", &A[i]);
    printf("Inserisci i numeri del secondo vettore separati da spazi:\n");
    for(i=0; i<N2; i++)
        scanf("%d", &B[i]);
    for(i=0,j=0,flag=1; i<N1 && flag; i++)
            if(B[j]==A[i]){
                j++;
                if(j==N2)
                    flag=0;
            }
            else{
                if (j>0)
                    i = i-j;
                j=0;
            }
    if(flag)
        printf("0");
    else
        printf("1");
    return 0;

}
