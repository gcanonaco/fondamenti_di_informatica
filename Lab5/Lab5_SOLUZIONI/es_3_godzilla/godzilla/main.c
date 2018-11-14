//
//  main.c
//  godzilla
//
//  Created by ing.conti on 12/11/2018.
//  Copyright © 2018 ing.conti. All rights reserved.
//

#include <stdio.h>

#define M 10
#define N 10

typedef enum {S, C, G} Casella;


void dopo_godzilla(Casella mondo[M][N], int i, int j) {
    if (mondo[i][j] == C) {
        mondo[i][j] = G;
        if (i+1 < M)  dopo_godzilla(mondo,i+1,j);
        if (i-1 >= 0) dopo_godzilla(mondo,i-1,j);
        if (j+1 < N)  dopo_godzilla(mondo,i,j+1);
        if (j-1 >= 0) dopo_godzilla(mondo,i,j-1);
    }
}

void stampa_casella(Casella c) {
    switch (c) {
        case S:
            printf("S ");
            break;
        case C:
            printf("C ");
            break;
        case G:
            printf("G ");
            break;
    }
}

void stampa_mondo(Casella mondo[M][N]) {
    int i,j;
    for (i=0; i<M; i++) {
        for (j=0; j<N; j++) {
            stampa_casella(mondo[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Casella mondo[N][N] = {
        {C,C,C,C,C,C,C,C,C,C},
        {C,C,C,C,C,C,C,S,C,C},
        {S,S,S,S,S,S,S,S,C,C},
        {C,S,C,C,C,C,C,S,C,C},
        {C,C,S,C,C,C,C,S,C,C},
        {C,C,S,S,S,C,C,S,S,S},
        {S,S,S,S,S,C,C,S,C,C},
        {C,C,S,C,C,S,S,S,C,C},
        {C,C,S,C,C,C,C,S,C,C},
        {C,C,S,C,C,C,C,S,C,C}
        
    };
    int i,j;
    
    i=4;
    j=4;
    
    printf("Mondo prima di Godzilla:\n\n");
    stampa_mondo(mondo);
    dopo_godzilla(mondo,i,j);
    
    printf("\n\nMondo dopo Godzilla:\n\n");
    stampa_mondo(mondo);
    
}
