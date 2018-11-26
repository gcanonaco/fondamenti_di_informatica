//
//  main.c
//  lab6_es3_array_liste
//
//  Created by ing.conti on 19/11/2018.
//  Copyright © 2018 ing.conti. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>

/*
 Problema 3
 Scrivere una funzione f (e main per chiamarla) che riceve un array di 5 interi e alloca una lista di 5 elementi contenente gli elementi dell’array in ordine inverso. Si utilizzino pure le funzioni viste a lezione.
 
 
 */

#define MAX_ELEMS   5

typedef struct EL {
    int info;
    struct EL * prox;
} ElemLista;

typedef ElemLista * ListaDiElem;


ListaDiElem convertiArrALista(int arr[])
{
    int i;
    ListaDiElem testa = NULL;
    ListaDiElem temp = NULL;
    
    for (i=0; i<MAX_ELEMS; i++) {
        // allochiamo in OGNI caso..
        temp = (ListaDiElem)malloc(sizeof(ElemLista));
        temp->info = arr[i];
        temp->prox = NULL;  // azzeriamo.. cosi vale anche x ultimo inserimemnto, oltre che x primo
        
        if (testa != NULL) {
            temp->prox = testa;
        }
        // in ogni caso:
        testa = temp;
    }
    
    return testa;
}

int main() {
    // carichiamo array senza I/O:
    int arr[MAX_ELEMS] = { 10, 20, 30, 40, 50 };
    
    ListaDiElem testa = convertiArrALista(arr);
    
    // stampa:
    
    ListaDiElem temp = testa;   // NON perdiamo la testa...
    while (temp) {
        printf("%d\n", temp->info);
        temp=temp->prox;
    }
    
    printf("done!\n");
    return 0;
}
