/* Dato un numero n arbitrario stampare a video la sequenza dei primi n numeri primi.
Si può fare di meglio che andare fino a p_primo/2? sqrt(p_primo)... perchè?*/
#include <stdio.h>

int main()
{
    int n, c=0, i, p_primo=1, flag;
    printf("Inserisci un numero n: ");
    scanf("%d", &n);
    while(c<n){
        for(i=2,flag=1;i<=p_primo/2 && flag;i++){
            if(p_primo%i==0)
                flag=0;
        }
        if(flag){
            c++;
            printf("%d ", p_primo);
        }
        p_primo++;
    }
    return 0;
}
