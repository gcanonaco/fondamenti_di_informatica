//
//  main.c
//  Lab6_es6_flatten_list
//
//  Created by ing.conti on 08/12/2019.
//  Copyright © 2019 ing.conti. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


 
// Problema 6
// Sia data la seguente definizione di lista:

 typedef struct nodo_t {
     int e;
     struct nodo_t *next;
     struct nodo_t *down;
 } nodo;

//dove attraverso il puntatore down si contempla la possibilità di annidare liste una dentro l’altra a qualsiasi livello di profondità. Si richiede di scrivere una funzione flatten che data in ingresso una lista della tipologia sopra specificata ne restituisce la sua versione “appiattita”.
// Per la versione “appiattita” si utilizzi la seguente struttura dati:

typedef struct nodo_f_t{
     int e;
     struct nodo_f_t *next;
 }nodo_f;

 
 //some usweful tyopedefs to make it cleaner:

typedef nodo        *deepList;
typedef nodo_f      *flatList;



// as from schema we have linear list (with an usual "next" AND a "vertical" list hung.
// let's break up in simoler, smaller problems also the construction of list.
// to be easy, we write a function that adds at END of list:
//
// a) a new node
// b) an int value
// c) a sublist (can be eventually null)
// we also need a "findLast" f. for flatten list
// and a f. to print flattened list
 
// PROTOS:
deepList buildMyInputList(void);
deepList buildInputList(deepList head, int e, deepList subList, deepList rightList);
flatList flatten(deepList head);
flatList findLast(flatList head);
void print(flatList head);

int main(int argc, const char * argv[]) {

    // first part (not related directly.. let's build inoput list:
    
    deepList dl = buildMyInputList();
    
    // now flatten it:
    
    flatList fl = flatten(dl);
    print(fl);
    
    return 0;
}




deepList buildMyInputList(void){
    // let's add some additional vars to make building cleaner:

    deepList L2_3 = buildInputList(NULL, 2, buildInputList(NULL, 3, NULL, NULL), NULL);
    
    // build "4" sub list:
    deepList L14_15 = buildInputList(NULL, 14, NULL, buildInputList(NULL, 15, NULL, NULL) );
    
    // build "5" sub list:
    deepList L5 = NULL; // for now.
    
    deepList L4 = buildInputList(NULL,4, L5, L14_15);
    
    deepList L1 = buildInputList(NULL, 1, L2_3, L4);
    
    // let's stop now and write algorithm ...
    // we should got 1 2 3 4 5 14 and 15.
    
    //let for exercise to add remaining values...
    
    
    return L1;
    
}

deepList buildInputList(deepList head, int e, deepList subList, deepList rightList ){

    deepList newNode = (deepList)malloc(sizeof(nodo));
    newNode->down = subList;
    newNode->next = rightList;
    newNode->e = e;
    
    // two cases: we have no top level, (head is NULL...) OR we have head:
    if (head == NULL) {
        return newNode;
    }
    
    head->down = newNode;
    return head;
    
}


flatList flatten(deepList head){
    if (head == NULL){
        return NULL;
    }
    // allocate a node, in every case:
    flatList newNode = (flatList)malloc(sizeof(nodo_f));
    // and copy:
    newNode->e = head->e;
    // clear next:
    newNode->next = NULL;
    
    // now visit in deep first:
    newNode->next = flatten(head->down);
    // and now at right, BUT we have to find LAST elem:
    
   flatList last = findLast(newNode);
    
   last->next = flatten(head->next);
    return newNode;
}



flatList findLast(flatList head){
    if (head == NULL){
        return NULL;
    }
    
    if (head->next == NULL)
        return head;
    
    return findLast(head->next);
    
}



void print(flatList head){
    while (head) {
        printf("%d\n", head->e);
        head=head->next;
    }
}
