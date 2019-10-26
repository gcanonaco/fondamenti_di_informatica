#include <stdio.h>
int main(int argc, char * argv[]){
    int n, l, i;
    do{
        printf("Inserisci il numero di cui vuoi calcolare la tabellina: ");
        scanf("%d", &n);
    }while(n <= 0);
    do{
        printf("Inserisci la lunghezza della tabellina: ");
        scanf("%d", &l);
    }while(l <= 0);
    for (i=1;i<l;i++){
        printf("%d ", n*i);
    }
    printf("%d", n*i);

    return 0;
}
