#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_AMICI 100
typedef struct _persona {
    char nome[10], cognome[10]; // nome e cognome della persona
    struct _persona * amici[MAX_AMICI]; // array contenente gli indirizzi delle persone nella lista utenti che sono amici di questa persona
    int num_amici; // numero di amici contenuti nell'array amici
    struct _persona * next;
} persona;
typedef persona * lista;
typedef struct nodo_s{
    lista p;
    struct nodo_s * next;
}nodo_t;

lista aggiungi_persona(lista, char [], char []);
void aggiungi_amico(lista, lista);
nodo_t * calcola_persone_raggiungibili(lista, nodo_t *);
nodo_t * aggiungi_in_testa(nodo_t *, lista);
int is_in(lista, nodo_t *);
lista find_person(lista, char [], char []);

nodo_t * aggiungi_in_testa(nodo_t * n, lista l){
    nodo_t * e = (nodo_t *)malloc(sizeof(nodo_t));
    e->p = l;
    e->next = n;
    return e;
}

int is_in(lista l, nodo_t * n){
    while(n!=NULL){
        if(n->p==l)
            return 1;
        n=n->next;
    }
    return 0;
}


lista aggiungi_persona(lista l, char nome[], char cognome[]){
    lista tmp;
    lista e = (lista)malloc(sizeof(persona));
    strcpy(e->nome, nome);
    strcpy(e->cognome, cognome);
    e->num_amici = 0;
    e->next = NULL;
    if (l == NULL)
        return e;
    tmp = l;
    while(l->next!=NULL)
        l=l->next;
    l->next=e;
    return tmp;
}
void aggiungi_amico(lista dest, lista src){
    int i,flag=0;
    if (dest->num_amici<MAX_AMICI && src->num_amici<MAX_AMICI) {
        for(i=0; !flag && i<dest->num_amici; i++){
            if(dest->amici[i]==src)
                flag=1;
        }
        if(flag==1) {
            printf("Amico già presente\n");
            return;
        }
        dest->amici[dest->num_amici] = src;
        ++(dest->num_amici);
        src->amici[src->num_amici] = dest;
        ++(src->num_amici);
    }else{
        printf("Raggiunta capienza massima!");
    }
    return;
}
nodo_t * calcola_persone_raggiungibili(lista l, nodo_t * rag){
    int i;
    if (!is_in(l, rag))
        rag = aggiungi_in_testa(rag, l);
    for(i=0; i<l->num_amici; i++)
        if (!is_in(l->amici[i], rag))
            rag = calcola_persone_raggiungibili(l->amici[i], rag);
    return rag;
}
lista find_person(lista l, char n[], char c[]){
    while(l!=NULL){
        if(strcmp(l->nome,n) == 0 && strcmp(l->cognome, c) == 0)
            return l;
        l=l->next;
    }
    return NULL;
}



int main() {
    int d;
    char n[10], c[10];
    lista l=NULL,tmp, amico;
    nodo_t * pers_rag=NULL;

    do{
        printf("Aggiungi una persona:\n");
        printf("Nome: ");
        scanf("%s", n);
        printf("Cognome: ");
        scanf("%s", c);
        l=aggiungi_persona(l, n, c);
        printf("Inserisci 0 se vuoi smettere di inserire persone: ");
        scanf("%d", &d);
    }while (d);
    tmp=l;
    while(tmp!=NULL){
        printf("vuoi inserire degli amici per %s %s? 1 si 0 no\n ", tmp->nome, tmp->cognome);
        scanf("%d", &d);
        while(d){
            printf("Inserisci il nome dell'amico: ");
            scanf("%s", n);
            printf("Inserisci il cognome dell'amico: ");
            scanf("%s", c);
            amico = find_person(l, n, c);
            if (amico != NULL)
                aggiungi_amico(tmp, amico);
            else
                printf("%s %s non è nei nostri registri!\n ", n, c);
            printf("vuoi inserire altri amici per %s %s? 1 si 0 no\n ", tmp->nome, tmp->cognome);
            scanf("%d", &d);
        }
        tmp=tmp->next;
    }
    printf("Inserisci il nome e poi il cognome della persona di cui vuoi calcolare le persone raggiungibili\n");
    printf("Nome:");
    scanf("%s", n);
    printf("Cognome:");
    scanf("%s", c);
    amico = find_person(l, n, c);
    pers_rag = calcola_persone_raggiungibili(amico, pers_rag);
    while(pers_rag!=NULL){
        printf("%s %s\n", pers_rag->p->nome, pers_rag->p->cognome);
        pers_rag=pers_rag->next;
    }

    return 0;
}
