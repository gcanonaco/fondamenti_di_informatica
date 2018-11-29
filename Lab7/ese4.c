#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100
typedef struct _movie {
    char title[MAX_LEN];
    char type[MAX_LEN]; // Ad esempio: horror, action . . .
    int year;
// L’anno in cui è stato girato il film
} movie;
typedef struct nodo_s{
    movie m;
    struct nodo_s * next;
}nodo;
typedef nodo * lista;
lista add(lista);
lista search(lista, char []);
void print(lista);
lista removef(lista,lista);

lista add(lista l){
    movie m;
    int i;
    lista e=(lista)malloc(sizeof(nodo)), tmp, prec;
    printf("Inserire il titolo:");
    fgets(m.title,MAX_LEN, stdin);
    printf("Inserire il tipo:");
    fgets(m.type,MAX_LEN, stdin);
    printf("Inserire l'anno:");
    scanf("%d", &m.year);
    e->m = m;
    e->next = NULL;
    if (l == NULL)
        return e;
    tmp = l;
    prec = NULL;
    while(l->next!=NULL && l->m.year <= m.year){
        prec = l;
        l = l->next;
    }
    if (prec == NULL)
        if(l->m.year>m.year) {
            e->next = tmp;
            tmp = e;
        } else
            tmp->next = e;
    else if (l->next==NULL && l->m.year <= m.year)
        l->next=e;
    else{
        e->next = l;
        prec->next = e;
    }
    return tmp;
}
void print(lista l){
    while(l!=NULL) {
        printf("%s\n", l->m.title);
        l=l->next;
    }
    return;
}
lista search(lista l, char tit[]){
    while(l!=NULL && strcmp(tit, l->m.title)!=0)
        l=l->next;
    return l;
}
lista removef(lista films, lista e){
    lista h, tmp;
    if (films ==NULL)
        return NULL;
    if (films == e){
        tmp=e->next;
        free(e);
        return tmp;
    }
    h=films;
    while(h!= NULL && h->next!=e)
        h=h->next;
    if(h==NULL)
        return films;
    tmp=h->next->next;
    free(h->next);
    h->next=tmp;
    return films;
}

int main() {
    int d;
    char t[MAX_LEN];
    lista l=NULL,tmp, amico;

    do{
        l=add(l);
        printf("Inserisci 0 se vuoi smettere di inserire films: ");
        scanf("%d", &d);
        scanf("%*c");//per pulire il buffer
    }while (d);
    print(l);
    printf("Inserisci il titolo di un film precedentemente inserito:\n");
    fgets(t,MAX_LEN, stdin);
    removef(l,search(l,t));
    print(l);
    return 0;
}
