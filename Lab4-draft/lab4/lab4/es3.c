//  es3.c
//  lab4
//  Created by ing.conti on 1718th oct, 2020

#include <stdio.h>
/*
 Scrivere un programma che generi una matrice 3x3 inserendo dei numeri progressivi in ogni cella,
 la stampi e poi la trasformi in una matrice triangolare superiore
 avente come elementi le somme degli elementi simmetrici rispetto alla diagonale principale.
 */

#define DIM 3
int main(int argc, const char * argv[]) {

    int matr[DIM][DIM];

    // parte inziale simile ad ed 2.. usiamo pointer, si puo' fare ANCHE con indici..
    int * pnt_inizio = &matr[0][0];
    int * pnt_fine = pnt_inizio + DIM * DIM;
    int * pnt;

    int offset, r, c;
    for (pnt = pnt_inizio; pnt < pnt_fine; pnt++) {
        offset = pnt - pnt_inizio;
        *pnt = offset+1; // caricheremo numeri da 1 a 9
    }

    printf("\n 1' stampa:\n");
    for (pnt = pnt_inizio; pnt < pnt_fine; pnt++) {
        offset = pnt - pnt_inizio;
        c = offset % DIM;
        r = offset / DIM;
        if (c == 0)
            printf("\n"); // andiamo a capo ad ogni riga
        printf("%5d ", *pnt);
    }
    
    printf("\n");
    for(r=0;r<DIM;r++)
        for(c=r;c<DIM;c++){
            if(r!=c){
                matr[r][c]+=matr[c][r];
                matr[c][r]=0;
            }
        }
        
    printf("\n 2' stampa:\n");
    for (pnt = pnt_inizio; pnt < pnt_fine; pnt++) {
        offset = pnt - pnt_inizio;
        c = offset % DIM;
        r = offset / DIM;
        if (c == 0)
            printf("\n"); // andiamo a capo ad ogni riga
        printf("%5d ", *pnt);
    }

    return 0;
}

