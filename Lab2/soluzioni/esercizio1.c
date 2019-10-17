#include <stdio.h>
#define N 10
int main(){
    int idx, i, v[N], acc;
    printf("Inserisci i valori dell'array separati da spazi\n");
    for(i=0;i<N;i++)
        scanf("%d", &v[i]);
    printf("Inserisci l'indice\n");
    scanf("%d", &idx);
    for(acc=0,i=0;i<idx;i++)
        acc+=v[i];
    printf("somma: %d\n", acc);
    for(acc=1,i=idx+1; i<N; i++)
        acc*=v[i];
    printf("prodotto: %d\n", acc);
    return 0;
}
