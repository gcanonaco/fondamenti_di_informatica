//
//  es2_warm_up.c
//  lab4
//
//  Created by ing.conti on 18th oct, 2020
//

/*
 Problema 2 intro ai puntatori
 Scrivere un programma che richieda all'utente di riempire una stringa S1 di caratteri,
 cerchi al suo intero i caratteri numerici e li copi in una stringa S2 e stampi s2.
 NB: va scritto usando puntatori ed aritmetica die puntatori (Pointer arithmetic)
 */

#include <stdio.h>

#define DIM 128

int main(int argc, const char * argv[]) {
    
    char S1[DIM];
    //  caso di test:
    //char  S1[DIM] = "ab1 2 c d e 9";
    //  stampa: 129
    
    char S2[DIM];
    
    scanf("%s", S1);
    
    char * pnt1 = &S1[0];
    char * pnt2 = &S2[0];
    
    char ch = ' '; // ch sara' il carattere corrente. lo inzializiammo per poter innescafre il for
    // si puo' anche usare direttamente * pnt
    int fine;
    
    for (fine = 0; !fine; pnt1++) {
        ch = *pnt1;
        if (ch>='1' && ch <='9'){
            *pnt2 = ch;
            pnt2++;
        }else if (ch == '\0'){
            fine = 1;
        }
    }
    // terminamo correttamente s2:
    *pnt2 = '\0';
    
    printf("\n stampa: %s\n", S2);
    
    return 0;
}

