#include<stdio.h>
#include<stdlib.h>

typedef struct _simpleListNode {
    int data;
    struct _simpleListNode * next;
} simpleListNode;
typedef simpleListNode * simpleList;
typedef struct _listOfListsNode {
    int data;
    simpleList sideList;
    struct _listOfListsNode * next;
} listOfListsNode;
typedef listOfListsNode * listOfLists;

int ListaVuota(listOfLists lista);
listOfLists InsInTesta(listOfLists, int);
simpleList inserisci_in_coda(simpleList, int);
listOfLists crea1();
simpleList  crea2();
void VisualizzaLista( listOfLists lista );
void VisualizzaListaSemplice(simpleList);
simpleList flatten(listOfLists);
simpleList addSideList(simpleList, simpleList);

int main() {
    listOfLists lista=NULL;
    simpleList flattenList = NULL;
    lista=crea1();

    VisualizzaLista(lista);
    printf("\n\n");

    flattenList = flatten(lista);

    VisualizzaListaSemplice(flattenList);

    printf("\n\n");
    return 0;
}

simpleList addSideList(simpleList l, simpleList sidel){
    simpleList tmp=l;
    if(l==NULL)
        return sidel;
    tmp=l;
    while(tmp->next!=NULL)
        tmp=tmp->next;
    tmp->next=sidel;
    return l;
}

simpleList flatten(listOfLists l){
    listOfLists tmp;
    simpleList res=NULL;
    while(l!=NULL){
        res = inserisci_in_coda(res, l->data);
        if(l->sideList!=NULL)
            res = addSideList(res, l->sideList);
        tmp=l;
        l=l->next;
        free(tmp);
    }
    return res;
}


void VisualizzaLista( listOfLists lista ) {
    if ( ListaVuota(lista) )
        printf(" ---| \n");
    else {
        printf(" %d ---> ",lista->data);
        if(lista->sideList!=NULL) {
            printf("( ");
            VisualizzaListaSemplice(lista->sideList);
            printf(")");
        }
        VisualizzaLista(lista->next);
    }
}

void VisualizzaListaSemplice(simpleList lista){
    if(lista==NULL)
        printf("---|");
    else{
        printf(" %d ---> ",lista->data);
        VisualizzaListaSemplice(lista->next);
    }
}

listOfLists InsInTesta(listOfLists lista, int elem) {
    listOfLists punt;
    punt = (listOfLists) malloc(sizeof(listOfListsNode));
    punt->data = elem;
    punt->next = lista;
    punt->sideList = NULL;
    return  punt;
}
simpleList inserisci_in_coda(simpleList l, int e){
    simpleList punt, tmp;
    punt = (simpleList) malloc(sizeof(simpleListNode));
    punt->data = e;
    punt->next = NULL;
    if(l==NULL)
        return punt;
    tmp=l;
    while(tmp->next!=NULL)
        tmp=tmp->next;
    tmp->next=punt;
    return  l;
}

int ListaVuota( listOfLists lista ) {
    return lista == NULL;
}

listOfLists crea1() {
    listOfLists lis=NULL;
    lis=InsInTesta( lis, 2 );
    lis->sideList=crea2();
    lis=InsInTesta( lis, 12 );
    lis=InsInTesta( lis, 1 );
    lis=InsInTesta( lis, 4 );
    lis=InsInTesta( lis, 8 );
    lis=InsInTesta( lis, 34 );
    lis->sideList = crea2();
    lis=InsInTesta( lis, 78 );
    lis=InsInTesta( lis, 26 );
    lis=InsInTesta( lis, 33 );
    lis=InsInTesta( lis, 11 );
    lis=InsInTesta( lis, 67 );
    lis=InsInTesta( lis, 83 );
    lis=InsInTesta( lis, 92 );
    return lis;
}

simpleList crea2() {
    simpleList lis=NULL;
    lis=inserisci_in_coda( lis, 2 );
    lis=inserisci_in_coda( lis, 10 );
    lis=inserisci_in_coda( lis, 15 );
    return lis;
}
