#include <stdio.h>
#define N 5
int main(){
    int i, A[N], B[N];
    printf("Inserisci la prima sequenza separata da spazi:\n");
    for(i=0; i<N; i++)
        scanf("%d", &A[i]);
    printf("Inserisci la secondo sequenza separata da spazi:\n");
    for(i=0; i<N; i++)
        scanf("%d", &B[i]);
    for(i=0;i<N;i++)
        printf("%d %d ",A[i],B[N-i-1]);
    return 0;
}
