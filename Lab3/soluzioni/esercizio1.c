//
//  lab03_boracchi
//
//  Created by ingconti on 22/10/2018.
//  Copyright © 2018 ingconti. All rights reserved.
//
/*
 
 
 Problema 1
 Scrivere un programma che richieda all'utente di riempire una matrice 3 x 3 di interi, la stampi, sostituisca nella matrice ogni
    numero pari con la sua metà e, infine, stampi la matrice così modificata.
 */

#define DIM 3

int main() {

    int i, j;
    int matrice[DIM][DIM];
    
    for (i=0; i <DIM; i++){
        for (j=0; j <DIM; j++){
            printf("dammi elemento (%d %d) ", i+1,j+1);
            scanf("%d", &matrice[i][j]);
        }
    }
    
    for (i=0; i <DIM; i++){
        for (j=0; j <DIM; j++){
            matrice[i][j]/=2;
        }
    }
    
    // stampa
    for (i=0; i <DIM; i++){
        for (j=0; j <DIM; j++){
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

