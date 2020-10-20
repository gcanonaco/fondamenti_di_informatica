//
//  es1.c
//  lab4
//
//  Created by ing.conti on 1718th oct, 2020
/*
Problema 1
Scrivere un programma che richieda all'utente di riempire una matrice 3 x 3 di interi, la stampi, sostituisca nella matrice ogni numero pari con la sua metà e, infine, stampi la matrice così modificata.

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
    
    int r,c;
    for (r=0; r<DIM; r++) {
        for (c=0; c<DIM; c++) {
            printf("\ndammi elem %d %d: ", r, c);
            scanf("%d", &matr[r][c]);
        }
    }

    printf("\n 1' stampa:\n");
    for (r=0; r<DIM; r++) {
        printf("\n"); // andiamo a capo ad ogni riga
        for (c=0; c<DIM; c++) {
            printf("%2d ", matr[r][c]); // 2%d == 2 cifre decimale
        }
    }
    
    printf("\n sostituisco..\n");
    for (r=0; r<DIM; r++) {
        for (c=0; c<DIM; c++) {
            if ( matr[r][c] % 2 == 0 )
                matr[r][c] /= 2;
        }
    }
    

    printf("\n 2' stampa:\n");
    for (r=0; r<DIM; r++) {
        printf("\n"); // andiamo a capo ad ogni riga
        for (c=0; c<DIM; c++) {
            printf("%2d ", matr[r][c]);
        }
    }
    


    return 0;
}

