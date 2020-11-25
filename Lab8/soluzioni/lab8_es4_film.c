//  lab8_es4_film
//
//  Created by ing.conti on 19/11/2020.
//  Copyright © 2018 ing.conti. All rights reserved.

#include <stdio.h>
#include <string.h>

/*
Problema 5
Costruite un programma per gestire una lista di film. Per immagazzinare i film dovete usare la seguente struttura:
typedef struct _movie { char title[200]; char type[200]; int year; } movie;
Per immagazzinare i film che vengono inseriti dall’utente dovete usare un array. In questo caso, il dato contenuto in ogni casella dell’array non sarà un semplice char o un int, ma una struttura di tipo movie. Nell’array i nuovi film devono essere inseriti in modo ordinato a seconda dell’anno in cui è stato girato il film (prima i film più vecchi poi quelli più nuovi).
movie film[100];
int numFilm;
numFilm servirà a sapere quante caselle dell’array sono effettivamente usate
Per questo progetto implementate le funzioni che devono essere richiamate opportunamente in un apposito main di test:
• int add(movie f[],int numFilm) //chiede i dati per un nuovo film, lo aggiunge nella posizione corretta e restituisce il numero di film aggiornato.
• void print(movie f[],int numFilm) //stampa la lista dei film.
• movie search(movie f[],int numFilm, char * title) //cerca un film nella lista in base al titolo e restituisce l’elemento dell’array che contiene tale film.
• int delete(movie f[],int numFilm,char * title) //rimuove un film senza lasciare buchi e restituisce il numero di film aggiornato.
*/


typedef struct _movie {
    char title[200];
    char type[200];
    int year;
} movie;


#define MAX_FILMS 100

// prototipi:

int add(movie f[],int numFilm); //chiede i dati per un nuovo film, lo aggiunge nella posizione corretta e restituisce il numero di film aggiornato.

void print(movie f[],int numFilm); //stampa la lista dei film.

movie search(movie f[],int numFilm, char * title); //cerca un film nella lista in base al titolo e restituisce l’elemento dell’array che contiene tale film.

int delete(movie f[],int numFilm,char * title); //rimuove un film senza lasciare buchi e restituisce il numero di film aggiornato.


int main(int argc, const char * argv[]) {

    int numFilm=0;

    movie film[MAX_FILMS];
    int i;
    for (i=0; i<6; i++) {
        numFilm = add(film, numFilm);
    }
    
    print(film, numFilm);
    
    printf("Done!\n");
    return 0;
}


// f. di appoggio:
movie readMovie()
{
    movie m;
    printf("titolo: ");
    scanf("%s", m.title);
    printf("tipo: ");
    scanf("%s", m.type);
    printf("anno: ");
    scanf("%d", &m.year);
    return m;
}


// fake f. add per testare velocemente:
// from : https://www.hollywoodreporter.com/lists/100-best-films-ever-hollywood-favorites-818512/item/seven-samurai-hollywoods-100-favorite-818479

movie fakeReadMovie(){
    static int presi = 0;
    movie films[MAX_FILMS] = {
        {"The Seven Samurai", "guerra", 1954},
        { "Bonnie and Clyde", "gangster", 1967},
        { "Reservoir Dogs", "dramma", 1992},
        { "Airplane!", "comico" , 1980},
        { "Pan's Labyrinth!", "mith" , 2006},
        {"Doctor Zhivago", "drama", 1965},
    };
    movie m = films[presi];
    presi++;
    return m;
}


// f. di appoggio: se array per definizione ordinato, cerco con FOR dove inserirlo:
int posizInserimento(int anno, movie f[], int numFilm){
    int i;
    for (i=0; i<numFilm; i++) {
        if  (anno <f[i].year){
            return i;
        }
    }
    return numFilm;

}

// f. di appoggio:
// un array e' cmq un array di puntatori.. non mi serve dire da dove... gli passo quello corretto..
// ma attenzione al  numero elemewnti!
// ma devo partire dal FONDO
// per ipotesi (vedi la add) gia ho testato che HO SPAZIO in fondo.
void scalaInSu(movie f[], int numFilm){
    int i;
    
    //printf("\n========\n");
    //print(f, numFilm);

    for (i=0; i<numFilm; i++) {
        f[numFilm-i] = f[numFilm-i-1];
    }
    
    //print(f, numFilm+1);

}

int add(movie f[],int numFilm) //chiede i dati per un nuovo film, lo aggiunge nella posizione corretta e restituisce il numero di film aggiornato.
{
    if (numFilm == MAX_FILMS-1){
        printf("al max! impossibile aggiungere\n");
        return numFilm;
    }

    // chiamata reale:
    //movie m = readMovie();
    
    // fake x testare:
    movie m = fakeReadMovie();

    int nuovaPos = posizInserimento(m.year, f, numFilm);
    if (nuovaPos == numFilm){
        f[numFilm] = m;
    }else{
        scalaInSu(f+nuovaPos, numFilm-nuovaPos);
        f[nuovaPos] = m;
    }

    // x testare:
    print(f, numFilm+1);

    return numFilm+1;
}

// f. di "apppoggio": stampa singolo film:
void printFilm(movie f)
{
    printf("%-20s %-20s %5d\n", f.title, f.type, f.year );
}


void print(movie f[],int numFilm) //stampa la lista dei film.
{
    printf("\n-------\n");
    int i;
    for (i=0; i<numFilm; i++) {
        printFilm(f[i]);
    }
}



/*
movie search(movie f[],int numFilm, char * title) //cerca un film nella lista in base al titolo e restituisce l’elemento dell’array che contiene tale film.
{
    
}


int delete(movie f[],int numFilm,char * title) //rimuove un film senza lasciare buchi e restituisce il numero di film aggiornato.
{
    
    
}
*/
