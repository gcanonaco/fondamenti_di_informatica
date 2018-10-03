//Prova a eseguire, ad esempio, il fattoriale di 17. Attenzione nel for anziché andare da 2 ad a-1 sarebbe più intelligente andare fino ad a/2 incluso.
#include <stdio.h>

int main(){
    int fatt=1;
    int a,i,flag=1;
    printf("Inserisci un numero: ");
    scanf("%d", &a);
    for(i=2; i<a && flag; i++)
        if(a % i == 0)
            flag = 0;
    if (flag)
        printf("%d è primo!\n",a);
    else
        printf("%d non è primo!\n",a);
    printf("Vuoi eseguire anche il fattoriale? [inserisci 0 per non eseguirlo!]");
    scanf("%d",&i);
    if(i){
        for(i=1; i<=a; i++)
            fatt *= i;
        printf("Il fattoriale di %d è: %ld",a,fatt);
    }
    return 0;
}
