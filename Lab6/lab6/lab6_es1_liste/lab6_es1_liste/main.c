//
//  main.c
//  labv6_es1_liste
//
//  Created by ing.conti on 19/11/2018.
//  Copyright © 2018 ing.conti. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

/*
 Dichiarare e popolare una lista composta da tre interi inseriti dall’utente. Stampare a video la somma di tutti gli elementi della lista così costruita. Evitare di usare le funzioni viste in aula.
 
 
 */

#define MAX_N 3

typedef struct EL {
    int info;
    struct EL * prox;
} ElemLista;

typedef ElemLista * ListaDiElem;


// f. di appoggio x leggere:
int leggi(int prog){
    int n;
    printf("\ndammi il %d' numero: ", prog+1);
    scanf("%d", &n);
    return n;
}



int main() {
    
    ListaDiElem testa = NULL;
    int i,n;
    ListaDiElem temp;
    
    for (i=0; i<MAX_N; i++) {
        n = leggi(i);
        // allochiamo in OGNI caso..
        temp = (ListaDiElem)malloc(sizeof(ElemLista));
        temp->info = n;
        temp->prox = NULL;  // azzeriamo.. cosi vale anche x ultimo inserimemnto, olteew xche x primo
        
        if (testa != NULL) {
            temp->prox = testa;
        }
        
        // in ogni caso:
        testa = temp;

    }
    
    // stampa:
    temp = testa;   // NON perdiamo la testa...
    while (temp) {
        printf("%d\n", temp->info);
        temp=temp->prox;
    }
    
    printf("done!\n");
    return 0;
}
