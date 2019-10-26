#include <stdio.h>

int main(int argc, char* argv[]){
    int n1, n2, minore, i;
    printf("Inserisci il primo numero: ");
    scanf("%d", &n1);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &n2);

    if (n1<n2)
        minore = n1;
    else
        minore = n2;
    printf("Divisori comuni: ");
    for (i=1; i<=(int)(minore/2); i++)
        if (n1 % i == 0 && n2 % i == 0)
            printf("%d ", i);

    if(n1 % minore == 0 && n2 % minore == 0)
        printf("%d",minore);

}
