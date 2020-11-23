
//  Lab7_unisci_2liste_mutipli_3
//  Created by ing.conti on 22/11/20.
/*
 
 Partendo dal file lista.c si scriva una funzione che ricevute due liste di interi (senza ripetizioni) restituisce una lista contenente tutti e soli gli elementi divisibili per 3 delle due liste (senza ripetizioni).
 */

#include<stdio.h>
#include<stdlib.h>

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


// proto ns funzione
ListaDiElem Unisci(ListaDiElem head, ListaDiElem lista1, ListaDiElem lista2);
// f di appoggio:
ListaDiElem AggiungiMultipliDi3NonPresenti(ListaDiElem allaLista, ListaDiElem daLista);
int Presente(int n, ListaDiElem listaDaEsplorare);


int main() {
    ListaDiElem lista=NULL,lista1=NULL,lista2=NULL;
    lista1=crea1();
    lista2=crea2();
    VisualizzaLista(lista1);
    printf("\n\n");
    VisualizzaLista(lista2);
    printf("\n\n");
    
    //inserire qui il codice
    lista = Unisci(lista, lista1, lista2);
    printf("\nUNITE: \n");

    VisualizzaLista(lista);
    printf("\n\n");
    
    return 0;
}

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
    lis=InsInTesta( lis, 15 );
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


// SOLUZIONE
ListaDiElem Unisci(ListaDiElem head, ListaDiElem lista1, ListaDiElem lista2)
{
    ListaDiElem result=head;
    result = AggiungiMultipliDi3NonPresenti(result, lista1);
    
    VisualizzaLista(result);

    result = AggiungiMultipliDi3NonPresenti(result, lista2);
    
    return result;
}

// f di appoggio:
ListaDiElem AggiungiMultipliDi3NonPresenti(ListaDiElem allaLista, ListaDiElem daLista)
{
    int n, presente;
    ListaDiElem result = allaLista;
    if (daLista == NULL)
        return  result;
    
    n = daLista->info;
    presente = Presente(n, allaLista);
    if  (!presente && n % 3 == 0 )
        result = InsInTesta(result, n);

    // in ogni caso ricorriamo:
    result = AggiungiMultipliDi3NonPresenti(result, daLista->prox);

    return result;
}


int Presente(int n, ListaDiElem listaDaEsplorare)
{
    if (listaDaEsplorare == NULL)
        return 0;
    
    if (listaDaEsplorare->info == n)
        return  1;

    return Presente(n, listaDaEsplorare->prox);
}




