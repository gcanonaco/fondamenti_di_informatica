/*Nel seguente esercizio troverete una soluzione che è una variante di quella richiesta dalla traccia. Vengono utilizzati i caratteri
anziché i numeri per scegliere che operazione effettuare. Questo implica l'inserimento di uno spazio nella scanf di acquisizione del carattere che seleziona l'operazione, e ciò è necessario perché altrimenti nel buffer di input rimarrebbe un ritorno a capo quando si inserisce il carattere stesso e si va ad acquisire gli altri dati di input rovinando la lettura e interpretazione di questi ultimi. trovate anche il costrutto switch che non avete ancora fatto a lezione, ma che non aggiunge nulla di nuovo. Sarebbe la stessa cosa fare tanti if uno per ogni caso.*/
#include <stdio.h>
int main(int argc, char* argv[]){
    int i;
    char op, esc;
    float n1, n2, acc;
    do{
        do{
            printf("Inserisci operazione +,-,*,/,^: ");
            scanf(" %c", &op);
            if (op != '+' && op != '-' && op != '*' && op != '/' && op != '^')
                printf("Attenzione: operazione non valida!\n");
        }while(op != '+' && op != '-' && op != '*' && op != '/' && op != '^');
        printf("Inserisci il primo operando: ");
        scanf("%f", &n1);
        printf("Inserisci il secondo operando: ");
        scanf("%f", &n2);
        switch (op){
            case '^':
                    if(n2>0 && n2 - (int)n2 == 0){
                        for(acc = 1, i = 0; i < (int)n2; i++)
                            acc = n1*acc;
                        printf("%f\n",acc);
                    }else
                        printf("Attenzione: l'operazione di potenza è gestita solo per esponenti interi positivi.\n");
                    break;
            case '+':
                    printf("%f\n",n1+n2);
                    break;
            case '-':
                    printf("%f\n",n1-n2);
                    break;
            case '*':
                    printf("%f\n",n1*n2);
                    break;
            default:
                    if(n2 != 0)
                        printf("%f\n",n1/n2);
                    else
                        printf("Attenzione: la divisione per zero non esiste\n");
                    break;
        }
        printf("Inserisci 'c' per continuare a fare conti, qualsiasi altro carattere ti fara' uscire: \n");
        scanf(" %c", &esc);
    }while(esc == 'c');

    return 0;
}
