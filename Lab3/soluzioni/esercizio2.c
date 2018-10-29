//
//  lab03_boracchi
//
//  Created by ingconti on 22/10/2018.
//  Copyright © 2018 ingconti. All rights reserved.
//

/*
 
 Problema 2
 Scrivere un programma che richieda all'utente di riempire una matrice 3 x 3 di interi, la stampi, calcoli e stampi la media di tutti gli elementi divisibili per 3 della matrice stessa.

 */

#define DIM 3

int main() {
    
    int i, j;
    int matrice[DIM][DIM];
    float media = 0;
    int contDivisibili = 0;

    for (i=0; i <DIM; i++){
        for (j=0; j <DIM; j++){
            printf("dammi elemento (%d %d) ", i+1,j+1);
            scanf("%d", &matrice[i][j]);
        }
    }

    // stampa
    for (i=0; i <DIM; i++){
        for (j=0; j <DIM; j++){
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }

    for (i=0; i <DIM; i++){
        for (j=0; j <DIM; j++){
            int elemento = matrice[i][j];
            if (elemento %3 ==0){
                media+=elemento;
                contDivisibili++;
            }
        }
    }

    media = media / contDivisibili;
    printf("media %f\n", media);
    return 0;
}

