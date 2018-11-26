//
//  main.c
//  Lab7_es1
//
//  Created by ing.conti on 26/11/2018.
//  Copyright © 2018 ing.conti. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>


//Problema 1
//Partendo dal file lista.c si scriva una funzione che ricevute due liste di interi (senza ripetizioni) restituisce una lista contenente tutti e soli gli elementi divisibili per 3 delle due liste (senza ripetizioni).
//

typedef struct EL{
    int info;
    struct EL * prox;
} ElemLista;

typedef ElemLista * ListaDiElem;

int ListaVuota( ListaDiElem lista );
ListaDiElem InsInTesta( ListaDiElem lista, int elem );
ListaDiElem crea1(void);
ListaDiElem crea2(void);

void VisualizzaLista( ListaDiElem lista );

///// F. aggiunte:

int contiene(int n, ListaDiElem l);
ListaDiElem unisciSenzaRipetizioniImultipliDi3(ListaDiElem l1, ListaDiElem l2);


int main() {
    ListaDiElem lista=NULL,lista1=NULL,lista2=NULL;
    lista1=crea1();
    lista2=crea2();
    VisualizzaLista(lista1);
    printf("\n\n");
    VisualizzaLista(lista2);
    printf("\n\n");
    
    //inserire qui il codice
    
    lista = unisciSenzaRipetizioniImultipliDi3(lista1, lista2);
    VisualizzaLista(lista);
    printf("\n\n");
    
    return 0;
}


// ns funzione principale:

ListaDiElem unisciSenzaRipetizioniImultipliDi3(ListaDiElem l1, ListaDiElem l2){
    // per scelta scandiamo prima l1:
    // (per ipotesi l1 NON contiene doppioni.. se li contenesse basterebbe fare check con la f. "contiene", vedi aggiunta della 2' lista.)
    
    ListaDiElem newList = NULL;
    while (l1 != NULL) {
        int valore = l1->info;
        if (valore %3 == 0)
            newList = InsInTesta(newList, valore);
        l1=l1->prox;
    }
    
    // stessa logica, ma con un test in piu:
    while (l2 != NULL) {
        int valore = l2->info;
        if ((valore %3 == 0) && !contiene(valore, newList))
            newList = InsInTesta(newList, valore);
        l2=l2->prox;
    }

    return newList;
    
}

//  funzione accessoria:

int contiene(int n, ListaDiElem l){
    if (ListaVuota(l))
        return 0;
    
    if (l->info == n)
        return  1;
    
    // passo ricorsivo:
    return contiene(n, l->prox);
}



/////// f. accessorie gia fornite



void VisualizzaLista( ListaDiElem lista ) {
    if ( ListaVuota(lista) )
        printf(" ---| \n");
    else {
        printf(" %d ---> ",lista->info);
        VisualizzaLista(lista->prox);
    }
}

ListaDiElem InsInTesta( ListaDiElem lista, int elem ) {
    ListaDiElem punt;
    punt = (ListaDiElem) malloc(sizeof(ElemLista));
    punt->info = elem;
    punt->prox = lista;
    return  punt;
}

int ListaVuota( ListaDiElem lista ) {
    return lista == NULL;
}

ListaDiElem crea1() {
    ListaDiElem lis=NULL;
    lis=InsInTesta( lis, 2 );
    lis=InsInTesta( lis, 12 );
    lis=InsInTesta( lis, 1 );
    lis=InsInTesta( lis, 4 );
    lis=InsInTesta( lis, 8 );
    lis=InsInTesta( lis, 34 );
    lis=InsInTesta( lis, 78 );
    lis=InsInTesta( lis, 26 );
    lis=InsInTesta( lis, 33 );
    lis=InsInTesta( lis, 11 );
    lis=InsInTesta( lis, 67 );
    lis=InsInTesta( lis, 83 );
    lis=InsInTesta( lis, 92 );
    return lis;
}

ListaDiElem crea2() {
    ListaDiElem lis=NULL;
    lis=InsInTesta( lis, 2 );
    lis=InsInTesta( lis, 10 );
    lis=InsInTesta( lis, 15 );
    lis=InsInTesta( lis, 48 );
    lis=InsInTesta( lis, 82 );
    lis=InsInTesta( lis, 11 );
    lis=InsInTesta( lis, 92 );
    lis=InsInTesta( lis, 22 );
    lis=InsInTesta( lis, 36 );
    lis=InsInTesta( lis, 19 );
    lis=InsInTesta( lis, 69 );
    return lis;
}
