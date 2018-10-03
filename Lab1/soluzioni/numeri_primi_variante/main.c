// Dato un numero n arbistrario stampare a video la sequenza dei primi n numeri primi
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
