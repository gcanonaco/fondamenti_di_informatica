/*  Si scriva un programma in grado di decidere se un numero dato dall’utente è primo. Si ricorda che un numero è
primo se non è divisibile per nessuno dei valori compresi tra il numero stesso e 1.
*/
#include<stdio.h>
int main()
{
    int p_primo, flag, i;
    printf("Inserisci un numero intero: ");
    scanf("%d", &p_primo);
    for(i=2,flag=1;i<=p_primo/2 && flag;i++){
        if(p_primo%i==0)
                flag=0;
    }
    if(flag){
        printf("Primo");
    }else{
        printf("Non è primo");
    }
    return 0;
}
