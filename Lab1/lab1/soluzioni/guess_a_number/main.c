#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int n,r;
    srand(time(0));
    r = rand()%10;
    do{
        printf("Indovina?[inserisci un intero tra 0 e 9]\n");
        scanf("%d", &n);
        if (r>n)
            printf("Il numero da indovinare è maggiore di quello inserito\n");
        else if (r<n)
            printf("Il numero da indovinare è minore di quello inserito\n");
    }while(r != n);

    return 0;
}
