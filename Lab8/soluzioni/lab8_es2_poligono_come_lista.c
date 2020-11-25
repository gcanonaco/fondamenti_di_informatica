//Esercizio 8.2 - lab8_es2_poligono_come_lista.c
//
//  Created by ing.conti on 22/11/20.
/*
 
 Dato un punto nel piano cartesiano, individuato dalle coordinate intere x, y e da una lettera (ad esempio, A(5,2)), si chiede di definire un'opportuna struttura dati ed il relativo tipo punto_t che lo rappresenti. Si chiede poi di definire una nuova struttura dati che permetta di rappresentare un poligono come una lista di punti. Scrivere quindi un programma, che facendo uso della rappresentazione di poligono introdotta:
 
 1) acquisisca i vertici di un poligono
 2) calcoli il perimetro del poligono
 3) stampi a video il valore del perimetro calcolato.

 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double X;
    double Y;
    char   lettera;
} punto_t;

typedef struct nodo_t {
    punto_t punto;
    struct nodo_t *next;
} nodo_t;

typedef nodo_t* ListaDiPunti;

punto_t costruisciPunto(double x, double y, char ch);
ListaDiPunti Acquisisci(void);
ListaDiPunti Ultimo( ListaDiPunti lista );
ListaDiPunti InsInTesta( ListaDiPunti lista, punto_t pt);
void VisualizzaLista(ListaDiPunti lista);
double Distanza(punto_t p1, punto_t p2);
double LunghezzaSpezzata(ListaDiPunti lista);
double Perimetro(ListaDiPunti lista);

int main(void){
    ListaDiPunti lista = Acquisisci();
    VisualizzaLista( lista );
    
    printf("\n");
    
    double perim = Perimetro(lista);
    printf("%f \n",perim);

}

punto_t costruisciPunto(double x, double y, char ch){
    punto_t p;
    p.X = x;
    p.Y = y;
    p.lettera = ch;
    return p;
}

void StampaPunto(punto_t p){
    printf("[%c %f %f] ", p.lettera,  p.X, p.Y);
}


double Distanza(punto_t p1, punto_t p2) {
    return sqrt((p1.X - p2.X)*(p1.X - p2.X) + (p1.Y - p2.Y)*(p1.Y - p2.Y));
}

ListaDiPunti Acquisisci(){
    // lasciamo x es. il for di caricamento.
    // carichiamo con dati di test:
    ListaDiPunti L = NULL;
   // L = InsInTesta(L, costruisciPunto(0, 4, 'D') ); se commentato: stampa 12, se scommentato: 14
    L = InsInTesta(L, costruisciPunto(3, 4, 'C') );
    L = InsInTesta(L, costruisciPunto(3, 0, 'B') );
    L = InsInTesta(L, costruisciPunto(0, 0, 'A') );
    return L;
}

ListaDiPunti InsInTesta( ListaDiPunti lista, punto_t pt ) {
    ListaDiPunti nodo = (ListaDiPunti) malloc(sizeof(nodo));
    nodo->punto = pt;
    nodo->next = lista;
    return  nodo;
}


void VisualizzaLista( ListaDiPunti lista ) {
    if ( lista == NULL )
        return;
    
    StampaPunto(lista->punto);
    VisualizzaLista(lista->next);
}


ListaDiPunti Ultimo( ListaDiPunti lista ) {
    if ( lista == NULL )
        return NULL;
    
    if (lista->next == NULL)
        return  lista;
    
    return Ultimo(lista->next);
}

double LunghezzaSpezzata(ListaDiPunti lista){
    double tot = 0;
    if (lista == NULL)
        return tot;
    if (lista->next == NULL)
        return tot;
    tot = Distanza(lista->punto, lista->next->punto);
    tot += LunghezzaSpezzata(lista->next);

    return tot;

}

double Perimetro(ListaDiPunti lista) {
    
    double tot = LunghezzaSpezzata(lista);
    double chiusuraPoligono = 0;
    ListaDiPunti ultimo = Ultimo(lista);
    if (ultimo){
        chiusuraPoligono = Distanza(lista->punto, ultimo->punto);
    }
    return tot + chiusuraPoligono;

}
