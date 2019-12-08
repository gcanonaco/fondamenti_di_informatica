#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo {
    int val;
    struct s_nodo *left;
    struct s_nodo *right;
    // aggiungiamo campo profondita:
    // (serve solo x ES 5)
    int profondita;
} nodo;
typedef nodo *albero;


albero creaAlbero(void);
albero createVal(int val);

void print(albero t);


typedef struct EL{
    int info;
    struct EL * prox;
    
} ElemLista;


typedef ElemLista * ListaDiElem;
ListaDiElem InsInTesta( ListaDiElem lista, int elem );
void VisualizzaLista( ListaDiElem lista );
int ListaVuota( ListaDiElem lista );

void f5(albero t, int livello);


int main(){
    albero alb = creaAlbero();
    print(alb);
    
    //problema 5:
    f5(alb, 0);
    printf("\n----\n");
    print(alb);
    return 0;
}



//es 5
// ancora e' una variante piu complessa di altri es precedenti, si puo' partire dalla print.
// modificata x stampare profondita:
void f5(albero t, int livello){
    if(t==NULL)
        return;
    
    t->profondita = livello;
    f5(t->left, livello+1);
    f5(t->right, livello+1);
}

//////

albero creaAlbero() {
    albero tmp = createVal(7);
    tmp->left = createVal(3);
    tmp->left->left = createVal(9);
    tmp->left->right = createVal(10);
    tmp->right = createVal(8);
    tmp->right->left = createVal(5);
    tmp->right->right = createVal(12);
    tmp->right->right->left = createVal(11);
    tmp->right->right->right = createVal(6);
    
    return tmp;
}

albero createVal(int val) {
    albero tmp = malloc(sizeof(nodo));
    tmp->val = val;
    tmp->left = NULL;
    tmp->right = NULL;
    // azzeriamo: (cosi alla stampa inziale da valori corretti)
    tmp->profondita = 0;
    return tmp;
}

// modificata x stampare profondita:
void print(albero t){
    if(t==NULL)
        return;
    printf(" (");
    print(t->left);
    printf(" %d[%d]", t->val, t->profondita);
    print(t->right);
    printf(") ");
}



//da es lab 8

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
