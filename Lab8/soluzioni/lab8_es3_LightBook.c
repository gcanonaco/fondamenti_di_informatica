//Esercizio 8.2 - lab8_es3_LightBook.c
//
//  Created by ing.conti on 22/11/20.
/*
 
 LightBook è un servizio online simile a Facebook. Per rappresentare i concetti di persona ed amicizia è stata definita una opportuna struttura dati e un array di persone
 typedef struct _persona {
     char nome[10], cognome[10]; // nome e cognome della persona
     struct _persona * amici[MAX_AMICI];  // array contenente gli indirizzi delle persone nella lista utenti che sono amici di questa persona
     int num_amici; // numero di amici contenuti nell'array amici
     struct _persona * next;
 } persona;
 persona * lista;
 Ciò che viene richiesto è di implementare una funzione inserisciPersone per aggiungere utenti a LightBook, una funzione aggiungiAmico per aggiungere un amico nell’array amici di una persona e una funzione ricorsiva calcolaPersoneRaggiungibili che, data una persona iniziale, permette di stampare a video la lista di tutte le persone che puo’ raggiungere quella persona passando attraverso la catena di amicizie. Si implementi un opportuno main per testare le funzioni sviluppate.



 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_AMICI 10

typedef struct _persona {
    char nome[10], cognome[10]; // nome e cognome della persona
    struct _persona * amici[MAX_AMICI];  // array contenente gli indirizzi delle persone nella lista utenti che sono amici di questa persona
    int num_amici; // numero di amici contenuti nell'array amici
    struct _persona * next;
} persona;


typedef persona * ListaDiPersone;


// PROTOS for required f.:
ListaDiPersone inserisciPersone(void);
bool aggiungiAmico( persona * amico, persona * allaPersona);  // will give back false if slots are full.
void calcolaPersoneRaggiungibili(persona *p, unsigned int currDepth);

// support f.:
ListaDiPersone inserisciSingolaPersona(ListaDiPersone lista, char * nome, char * cognome);
ListaDiPersone cercaSingolaPersona(ListaDiPersone lista, char * nome, char * cognome);
void VisualizzaLista(ListaDiPersone l,  bool fullDescr);
void StampaPersona(persona * p, bool fullDescr,  unsigned int indent);
void StampaAmiciDi(persona * p);


int main(void){
    ListaDiPersone lista = inserisciPersone();
    VisualizzaLista( lista, false );
    
    persona * amico = cercaSingolaPersona(lista, "Chiara", "Bianchi");
    persona * dest = cercaSingolaPersona(lista,  "Sergio", "Neri");

    printf("\nNeri before\n");
    StampaPersona(dest, false, 0);

    bool added = aggiungiAmico(amico, dest);

    if (added){
    printf("\nNeri after\n");
    StampaPersona(dest, true, 1);
    }
    
    persona * amico_deep_level = cercaSingolaPersona(lista,  "John",   "Doe");
    bool added2 = aggiungiAmico(amico_deep_level, amico); // Doe is a friend of Chiara

    printf("\nAfter adding all list:\n");
    VisualizzaLista( lista, false );

    printf("\ncalcolaPersoneRaggiungibili:\n");

    calcolaPersoneRaggiungibili(dest, 0);
    
    printf("\n");

}


void calcolaPersoneRaggiungibili(persona *p,  unsigned int currDepth){
    if (p == NULL)
        return;
    
    int i;
    persona * amico;
    for (i=0; i<p->num_amici; i++) {
        amico = p->amici[i];
        StampaPersona(amico, false, currDepth);
        calcolaPersoneRaggiungibili(amico, currDepth+1);
    }
}


void StampaPersona(persona *p, bool fullDescr, unsigned int indent){
    int i;
    for (i=0; i<indent; i++) {
        printf("    ");
    }

    printf("%s %s %d ", p->cognome, p->nome, p->num_amici);
    if (fullDescr){
        printf("\n    friends:\n");
        StampaAmiciDi(p);
    }
    else
        printf("\n");
}

void StampaAmiciDi(persona * p){
    int i;
    persona * amico;
    for (i=0; i<p->num_amici; i++) {
        amico = p->amici[i];
        StampaPersona(amico, false, 1);
    }
}


void VisualizzaLista(ListaDiPersone lista, bool fullDescr){
    if ( lista == NULL )
        return;
    
    StampaPersona(lista, false, false);
    VisualizzaLista(lista->next, fullDescr);
}


void clearAllFriends(persona *p){
    int i;
    for (i=0; i<MAX_AMICI; i++) {
        p->amici[i] = NULL;
    }
}


// usual "inserisci in testa"
ListaDiPersone inserisciSingolaPersona(ListaDiPersone lista, char * nome, char * cognome){

    ListaDiPersone nodo = (ListaDiPersone) malloc(sizeof(persona));
    clearAllFriends(nodo);
    nodo->num_amici = 0;
    strcpy(nodo->cognome, cognome);
    strcpy(nodo->nome, nome);
    nodo->next = lista;
    return  nodo;
}



ListaDiPersone inserisciPersone(void){
    ListaDiPersone result = NULL;
    result = inserisciSingolaPersona(result, "Mario",  "Rossi");
    result = inserisciSingolaPersona(result, "Sergio", "Neri");
    result = inserisciSingolaPersona(result, "Chiara", "Bianchi");
    result = inserisciSingolaPersona(result, "Anna",   "Gialli");
    result = inserisciSingolaPersona(result, "John",   "Doe");
    return result;
}


bool aggiungiAmico(persona * amico, persona * allaPersona)  // will givr back false if slots are full.
{
    if (allaPersona == NULL)
        return false;

    if (allaPersona->num_amici == MAX_AMICI)
        return false;
    
    int freeSlot = allaPersona->num_amici;
    allaPersona->amici[freeSlot] = amico;
    allaPersona->num_amici++;
    
    return true;
}

ListaDiPersone cercaSingolaPersona(ListaDiPersone lista, char * nome, char * cognome){
    if (lista == NULL)
        return NULL;
    
    if (strcmp(lista->cognome, cognome)==0 && strcmp(lista->nome, nome) == 0)
        return lista;
    
    return cercaSingolaPersona(lista->next, nome, cognome);
}
