//Prova a verificare se è corretto il risultato con c=100 i=4 e a=2
#include <stdio.h>

int main()
{
    float c, i;
    int a;
    printf("Inserisci capitale, interessi annui e durata dell'investimento separati da spazi: ");
    scanf("%f", &c);
    scanf("%f", &i);
    scanf("%d", &a);
    for(;a>0;a--)
        c += (c*i)/100;
    printf("Il montante è: %f", c);
    return 0;
}
