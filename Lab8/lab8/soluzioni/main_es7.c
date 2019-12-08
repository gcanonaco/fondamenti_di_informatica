//
//  main_es7.c
//  lab9
//
//  Created by ing.conti on 11/12/2018.
//  Copyright © 2018 ing.conti. All rights reserved.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>



// partiamo da es 6 e cambiamo alcuni tipi/campi/var
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
ListaDiElem crea1(void);


// la ns funzione:

tree insertInTree(tree t, ListaDiElem lista);



int main()
{
    tree alb1 = NULL;
    // test con numeri:
    alb1 = insertInTreeAnInt(alb1, 10);
    alb1 = insertInTreeAnInt(alb1, 3);
    alb1 = insertInTreeAnInt(alb1, 30);
    alb1 = insertInTreeAnInt(alb1, 300);
    alb1 = insertInTreeAnInt(alb1, 3000);
    print(alb1);
    printf("\n");
    
    tree alb2 = NULL;
    // test con numeri:
    alb2 = insertInTreeAnInt(alb2, 10);
    alb2 = insertInTreeAnInt(alb2, 3);
    alb2 = insertInTreeAnInt(alb2, 30);
    alb2 = insertInTreeAnInt(alb2, 3000);
    alb2 = insertInTreeAnInt(alb2, 300);
    print(alb2);
    printf("\n");
    
    
    //ora lista:
    //(prendiamo da es lab 8:
    ListaDiElem lista=crea1();
    printf("\n");
    VisualizzaLista(lista);
    
    tree alb3 = NULL;
    alb3 = insertInTree(alb3, lista);
    print(alb3);
    
    return 0;
}



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

ListaDiElem crea1() {
    ListaDiElem lis=NULL;
    lis=InsInTesta( lis, 300 );
    lis=InsInTesta( lis, 3000 );
    lis=InsInTesta( lis, 30 );
    lis=InsInTesta( lis, 3);
    lis=InsInTesta( lis, 10 );

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
