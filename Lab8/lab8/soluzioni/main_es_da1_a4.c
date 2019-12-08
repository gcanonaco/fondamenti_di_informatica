
#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo {
    int val;
    struct s_nodo *left;
    struct s_nodo *right;
} nodo;
typedef nodo *albero;


albero creaAlbero(void);
albero createVal(int val);

void print(albero t);

// per comodita le f. daranno f1.. f4 x ogni problema
int f1(albero t);
int f2(albero t);
int f3_max(albero t);

// es 4'
//serve f. accessorie e lista, vedi lab8.

typedef struct EL{
    int info;
    struct EL * prox;
} ElemLista;


typedef ElemLista * ListaDiElem;
ListaDiElem InsInTesta( ListaDiElem lista, int elem );
void VisualizzaLista( ListaDiElem lista );
int ListaVuota( ListaDiElem lista );

ListaDiElem f4(ListaDiElem testa, albero t, int livello);


int main(){
    albero alb = creaAlbero();

//                            7
//                           / \
//                          /   \
//                         /     \
//                        /       \
//                       /         \
//                      /           \
//                     3             8
//                    / \           / \
//                   /   \         /   \
//                  /     \       /     \
//                 9      10     5       12
//                                      /  \
//                                     11   6

    print(alb);
    
    int ris1=f1(alb);
    printf("\nproblema 1: %d\n", ris1); //deve uscire: 36

    int ris2=f2(alb);
    printf("\nproblema 2: %d\n", ris2); //deve uscire: 30
    
    int ris3=f3_max(alb);
    printf("\nproblema 3: %d\n", ris3); // //deve uscire: 12
    
    //problema 4:
    ListaDiElem testa = f4(NULL, alb, 0);
    VisualizzaLista(testa);
    // deve stampare in output:
    // 12 --->  5 --->  10 --->  9 --->  7 --->  ---|
    
    
    
    return 0;
}


// sostanzialmente e' la print modificata... :)
int f1(albero t) {
    
    if(t==NULL)
        return 0;
    
    int ris;
    int sx = f1(t->left);
    int val = t->val;
    int dx = f1(t->right);
    if (val % 2 == 0)
        ris = sx+val+dx;
    else
        ris = sx+dx;
    return ris;
}

// sostanzialmente e' la f1 modificata... :)
int f2(albero t) {
    
    if(t==NULL)
        return 0;
    
    int ris;
    int sx = f2(t->left);
    int val = t->val;
    int dx = f2(t->right);
    if (val % 3 == 0)
        ris = sx+val+dx;
    else
        ris = sx+dx;
    return ris;
}


// per ipotesi tutti valori > 0 nell' albero.
int f3_max(albero t) {
    
    if(t==NULL)
        return 0;
    
    int maxSX = f3_max(t->left);
    int maxDX = f3_max(t->right);
    int val = t->val;

    if (val>maxSX && val>maxDX)
        return val;
    
    if (maxSX>val && maxSX>maxDX)
        return maxSX;
    
    return maxDX;
}



//es 4
// ancora e' una variante piu complessa della stampa...
ListaDiElem f4(ListaDiElem testa, albero t, int livello){
    if(t==NULL)
        return testa;
    
    if (livello %2 == 0)
        testa = InsInTesta(testa, t->val);
    
    testa = f4(testa, t->left, livello+1);
    
    testa = f4(testa, t->right, livello+1);

    return testa;
    
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
    return tmp;
}

void print(albero t){
    if(t==NULL)
        return;
    printf(" (");
    print(t->left);
    printf(" %d ", t->val);
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


