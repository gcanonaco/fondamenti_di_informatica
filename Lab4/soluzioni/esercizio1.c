#include <stdio.h>
#define N 10
float mean(int *, int);
int main(){
    int x[N], i;
    printf("Inserisci il vettore:\n");
    for(i=0; i<N; i++)
        scanf("%d", &x[i]);
    printf("\n media: %f", mean(x, N));
    return 0;
}
float mean(int * x, int dim){
    int i,acc;
    for(i=0, acc=0; i<dim; i++)
        acc += x[i];
    return (float)acc/dim;
}
