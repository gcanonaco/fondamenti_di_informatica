//
//  main_es8.c
//  lab9
//
//  Created by ing.conti on 11/12/2018.
//  Copyright © 2018 ing.conti. All rights reserved.
//

// preso da es7 e aggiunte f.



#include <stdio.h>
#include <string.h>
#include <stdlib.h>



// partiamo da es6 e cambiamo alcuni tipi/campi/var
typedef struct ET {
    int dato;
    struct ET * left, * right;
} BinaryTreeNode;


// per comodita:
typedef enum  {
    FALSE = 0,
    TRUE = 1
} BOOL;

typedef BinaryTreeNode * tree;

// copiamo f. di supporto da altri es:
tree createVal(int val);
void print(tree t);

//f. ausiliaria, per rendere piu leggbile
tree insertInTreeAnInt(tree t, int val);


//f. accessorie e lista, vedi lab8.

typedef struct EL{
    int info;
    struct EL * prox;
} ElemLista;


typedef ElemLista * ListaDiElem;
ListaDiElem InsInTesta( ListaDiElem lista, int elem );
void VisualizzaLista( ListaDiElem lista );
int ListaVuota( ListaDiElem lista );
ListaDiElem crea1(void);   // modificata con valori presi da testo: 5,7,2,1,8,9,3


// da es 8
tree insertInTree(tree t, ListaDiElem lista);

// funzioni accessorie:
ListaDiElem sorted(ListaDiElem head);
ListaDiElem minL(ListaDiElem head);
// non serve.. ListaDiElem maxL(ListaDiElem head);
ListaDiElem removeFrom(ListaDiElem head, ListaDiElem this);
int listLength(ListaDiElem head);

ListaDiElem getAtPosition(ListaDiElem head, int position);
ListaDiElem removeAfter(ListaDiElem head, ListaDiElem this);

// la ns. funzione:



int main()
{
    
    //ora lista:
    //(prendiamo da es lab 8:
    ListaDiElem lista=crea1();   // modificata con valori presi da testo: 5,7,2,1,8,9,3
    

    printf("\n");
    VisualizzaLista(lista);
    
    // testiamo min:
    ListaDiElem pMin = minL(lista);
    printf("min = %d\n", pMin->info);
    
    
    /*
    // testiamo cancellazione:
    lista = removeFrom(lista, pMax);
    VisualizzaLista(lista);
    
    lista = removeFrom(lista, pMin);
    VisualizzaLista(lista);
    */
    
   ListaDiElem listaOrd = sorted(lista);
   VisualizzaLista(listaOrd);
    // e fin qui abbimo la lista ordinata:
    // cerchimo il mediano:
    // per fr cio devo sapere la lunghezza della lista e
    // ottenere il puntatore all' elem di mezzo,
    // spezzare in due la lista nella posizone del mediano
    // (poi andra fatto ricorsivamente..)
    int len = listLength(listaOrd);
    
    ListaDiElem median = getAtPosition(listaOrd, len/2);
    printf("\n%d\n", median->info);
    //ora la seconda parte inzia da median..
    // la prima parte inzia dalistaOrd, ma devo rimuovere DOPO median:
    ListaDiElem seconfHalf = median;
    ListaDiElem firstHalf = removeAfter(listaOrd, median);
    
    VisualizzaLista(firstHalf);
    VisualizzaLista(seconfHalf);

    // ora...
    
    tree alb3 = NULL;
    //alb3 = insertInTree(alb3, lista);
    print(alb3);
    
    return 0;
}



// funzioni accessorie:

ListaDiElem removeFrom(ListaDiElem head, ListaDiElem this)
{
    if (head == NULL)
        return  NULL;
    if (this == head)
        return head->prox;
    
    head->prox = removeFrom(head->prox, this);
    return head;
}

ListaDiElem sorted(ListaDiElem head){
    if (head == NULL)
        return NULL;
    
    if (head->prox==NULL)
        return head;
    
    ListaDiElem pMin = minL(head);
    if (head == pMin){
        head->prox = sorted(head->prox);
        return head;
    }
    // rimuoviamo il min:
    ListaDiElem cleanedUp = removeFrom(head, pMin);

    // for debug:
    //VisualizzaLista(cleanedUp);

    pMin->prox = sorted(cleanedUp);
    
    return pMin;
 }



ListaDiElem minL(ListaDiElem head){
    if (head == NULL){
        return NULL;
    }
    int primoval = head->info;
    ListaDiElem P_min_sulla_coda = minL(head->prox);
    if (P_min_sulla_coda  == NULL)
        return head;
    
    if (primoval<P_min_sulla_coda->info)
        return head;
    return P_min_sulla_coda;
}

/* non serve...
ListaDiElem maxL(ListaDiElem head){
    if (head == NULL){
        return NULL;
    }
    int primoval = head->info;
    ListaDiElem P_max_sulla_coda = maxL(head->prox);
    if (P_max_sulla_coda  == NULL)
        return head;
    
    if (primoval>P_max_sulla_coda->info)
        return head;
    return P_max_sulla_coda;
}
*/

int listLength(ListaDiElem head){
    if (head == NULL)
        return 0;
    return 1+listLength(head->prox);
}

ListaDiElem getAtPosition(ListaDiElem head, int position){
    if (head == NULL)
        return NULL;
    if (position == 0)
        return head;
    return getAtPosition(head->prox, position-1);
}


ListaDiElem removeAfter(ListaDiElem head, ListaDiElem this){

    if (head == NULL)
        return NULL;
    if (head == this)
        return NULL;
    head->prox = removeAfter(head->prox, this);
    return head;
}

//////  f. altro lab.

tree createVal(int val) {
    tree tmp = malloc(sizeof(BinaryTreeNode));
    tmp->dato = val;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

// modificata x stampare nuovo tipo:
void print(tree t){
    if(t==NULL)
        return;
    printf(" (");
    print(t->left);
    printf("%d", t->dato);
    print(t->right);
    printf(") ");
}

//f. ausiliaria, per rendere piu leggbile
tree insertInTreeAnInt(tree t, int val){
    
    tree tmp = createVal(val);
    if (t == NULL)
        return tmp;
    
    if (val<=t->dato){
        // ins a SX
        // ho due casi: sottoalbero esistente oppure NULL
        if (t->left == NULL){
            t->left = tmp;
        }
        else{
            insertInTreeAnInt(t->left, val);
        }
        return t;
    }
    
    // idem x DX:
    // ho due casi: sottoalbero esistente oppure NULL
    if (t->right == NULL){
        t->right = tmp;
    }
    else{
        insertInTreeAnInt(t->right, val);
    }
    return t;

}


// la ns funzione:

tree insertInTree(tree t, ListaDiElem lista){
    if (lista==NULL)
        return t;

    tree temp = insertInTreeAnInt(t, lista->info);

    
    return insertInTree(temp, lista->prox);
}



//lab 8:

int ListaVuota( ListaDiElem lista ) {
    return lista == NULL;
}


// modificata x valori da testo: 5,7,2,1,8,9,3
ListaDiElem crea1() {
    ListaDiElem lis=NULL;
    lis=InsInTesta( lis, 5 );
    lis=InsInTesta( lis, 7 );
    lis=InsInTesta( lis, 2 );
    lis=InsInTesta( lis, 1);
    lis=InsInTesta( lis, 8 );
    lis=InsInTesta( lis, 9 );
    lis=InsInTesta( lis, 3 );

    return lis;
}

ListaDiElem InsInTesta( ListaDiElem lista, int elem ) {
    ListaDiElem punt;
    punt = (ListaDiElem) malloc(sizeof(ElemLista));
    punt->info = elem;
    punt->prox = lista;
    return  punt;
}

void VisualizzaLista( ListaDiElem lista ) {
    if ( ListaVuota(lista) )
        printf(" ---| \n");
    else {
        printf(" %d ---> ",lista->info);
        VisualizzaLista(lista->prox);
    }
}
