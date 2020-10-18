//
//  es2.c
//  lab4
//
//  Created by ing.conti on 1718th oct, 2020
//

/*
Problema 1
 Scrivere un programma che richieda all'utente di riempire una matrice 3 x 3 di interi,
 la stampi, calcoli e stampi la media di tutti gli elementi divisibili per 3 della matrice stessa.
 NB: va scritto usando puntatori ed aritmetica die puntatori (Pointer arithmetic)
*/

#include <stdio.h>

#define DIM 3

int main(int argc, const char * argv[]) {

    int matr[DIM][DIM];
    /* caso di test:
    int matr[DIM][DIM] = {1,2,3,4,5,6,7,8,9};
    rimouvere il dopo for di lettura.. deve uscire:
    
     2' stampa:
     1  1  3
     2  5  3
     7  4  9
     */
    
    int * pnt_inizio = &matr[0][0];
    int * pnt_fine = pnt_inizio + DIM * DIM;
    int * pnt;

    // per motivi didattici e per vedere riga e colonna, ricreiamo qui le v.
    // con un po' di "Pointer arithmetic"
    int offset, r, c;
    
    for (pnt = pnt_inizio; pnt < pnt_fine; pnt++) {
        offset = pnt - pnt_inizio;
        c = offset % DIM;
        r = offset / DIM;
        printf("\ndammi elem  %d %d:", r, c);
        scanf("%d", pnt);
    }

    printf("\n 1' stampa:\n");
    for (pnt = pnt_inizio; pnt < pnt_fine; pnt++) {
        offset = pnt - pnt_inizio;
        c = offset % DIM;
        r = offset / DIM;
        if (c == 0)
            printf("\n"); // andiamo a capo ad ogni riga
        printf("%2d ", *pnt);// 2%d == 2 cifre decimale
    }

    printf("\n sostituisco..\n");
    for (pnt = pnt_inizio; pnt < pnt_fine; pnt++) {
        if (*pnt % 2 == 0)
            *pnt /= 2;
    }

    printf("\n 2' stampa:\n");
    for (pnt = pnt_inizio; pnt < pnt_fine; pnt++) {
        offset = pnt - pnt_inizio;
        c = offset % DIM;
        r = offset / DIM;
        if (c == 0)
            printf("\n"); // andiamo a capo ad ogni riga
        printf("%2d ", *pnt);// 2%d == 2 cifre decimale
    }

    return 0;
}

