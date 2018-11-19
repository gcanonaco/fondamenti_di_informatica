//
//  main.c
//  lavb6_es2_liste
//
//  Created by ing.conti on 19/11/2018.
//  Copyright © 2018 ing.conti. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

/*
Generalizzare il problema precedente per permettere l’inserimento di un numero n di elementi definito dall’utente a runtime. Si utilizzino le funzioni viste a lezione per operare sulle liste
 
 */


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
    int i,n, max;
    ListaDiElem temp;
    
    printf("\ndammi il n di elementi: ");
    scanf("%d", &max);
    
    for (i=0; i<max; i++) {
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
