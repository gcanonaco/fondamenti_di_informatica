//
//  lab03_boracchi
//
//  Created by ingconti on 22/10/2018.
//  Copyright © 2018 ingconti. All rights reserved.
//
/*
 Problema 3
 Scrivere un programma che richieda all'utente di riempire una matrice 3 x 3 di interi, la stampi, sostituisca nella matrice ogni numero dispari con il suo cubo e, infine, calcoli e stampi la media di tutti gli elementi della matrice così modificata.
 */

#define DIM 3

int main() {
    
    int i, j;
    int matrice[DIM][DIM];
    float media = 0;
    
    for (i=0; i <DIM; i++){
        for (j=0; j <DIM; j++){
            printf("dammi elemento (%d %d) ", i+1,j+1);
            scanf("%d", &matrice[i][j]);
        }
    }
    
    /*
    // stampa x controllo....
    for (i=0; i <DIM; i++){
        for (j=0; j <DIM; j++){
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
    */
    
    for (i=0; i <DIM; i++){
        for (j=0; j <DIM; j++){
            int elemento = matrice[i][j];
            if (elemento %2 == 1){
                // dispari..
                matrice[i][j] = elemento * elemento * elemento;
            }
        }
    }
    
    printf("\n");
    
    // stampa
    for (i=0; i <DIM; i++){
        for (j=0; j <DIM; j++){
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
    
    
    // nota.. potrei far anche un solo ciclo..
    for (i=0; i <DIM; i++){
        for (j=0; j <DIM; j++){
            int elemento = matrice[i][j];
            media+=elemento;
        }
    }
    
    
    media = media / (DIM*DIM);
    printf("media %f\n", media);
    return 0;
}





