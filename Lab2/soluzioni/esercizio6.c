/*  Scrivere un programma che chiede un numero all’utente e ne stampa a video la scomposizione in fattori primi.
    Esempi: 27=3^3 12=2^2*3 36=2^2*3^2 120=2^3*3*5
*/
#include<stdio.h>
#include<math.h>
int main()
{
    int n, a=0, b, stop=0;
    printf("Inserisci un numero intero: ");
    scanf("%d", &n);
    while(n%2==0){
        a++;
        n=n/2;
    }
    printf("2^%d * ", a);
    a=sqrt(n)+1;
    do{
        b=a*a - n;
        if (sqrt(b) - (int)(sqrt(b))==0)
            stop = 1;
        else
            a++;
    }while(!stop);
    b=sqrt(b);
    printf("%d * %d", a-b, a+b);
    return 0;
}
