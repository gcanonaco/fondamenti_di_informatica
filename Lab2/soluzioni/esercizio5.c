#include<stdio.h>
#define N 51
int main(){
    char s[N];
    int pila, i, errore;
    printf("Inserisci stringa:\n");
    scanf("%s", s);
    for(pila=0, i=0, errore=0; errore==0 && s[i]!='\0' && i<N; i++){
        if(s[i]=='(')
            pila++;
        if(s[i]==')')
            if(pila>0)
                pila--;
            else
                errore = 1;
    }
    if(errore==0)
        printf("Stringa ben parentesizzata!\n");
    else
        printf("C'è qualcosa che non va!\n");
    return 0;

}
