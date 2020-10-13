//
//  es1.c
//  LAB3
//
//  Created by ing.conti on 13/10/20.
//

#include <stdio.h>

/*
 
 Problema 4
 Definiamo il grado minimo g e il grado massimo G di una parola P rispettivamente come il minimo e il massimo numero di occorrenze delle lettere di P in P.  Ad esempio:
 POLENTA    g=1, G=1  ( tutte le lettere della parola compaiono in essa una e una sola volta )
 ORGOGLIO    g=1, G=3  ( R, L, I compaiono una sola volta, O compare tre volte )
 MAMMA       g=2, G=3  ( A compare due volte, M compare tre volte )
 G e g valgono convenzionalmente 0 per la parola vuota (cioè per una parola priva di caratteri).
 Si scriva un programma C che legge una stringa di lunghezza generica che rappresenta P, calcola G e g, e li stampa.
 
 
 */

#define STRING_SIZE 128

int main(int argc, const char * argv[]) {
    
    // lasciamo all' utente l' inserimento della due stringa.
    
    // pre-carichiamo il vettore per avere casi noti:
    char P[STRING_SIZE]    = "POLENTA";
    // poi scommentare uno per volta le 2 righe seguenti per provare.. se non si fa uso di scanf...
    //char P[STRING_SIZE]    = "ORGOGLIO";
    //char P[STRING_SIZE]    = "MAMMA";
    
    unsigned int g=0;
    unsigned int G=0;
    // g e G sono un simili a un min ed un Max..
    
    //calcoliamo subito la lunghezza effettiva della stringa:
    int len;
    for (len=0; P[len] != '\0'; len++) {
        // empty loop, aspettiamo '\0'
    }
    
    int i,k, cont;
    
    for (i=0; i<len; i++) {
        cont = 0;
        for (k=i; k<len;k++) {
            if (P[i] == P[k])
                cont++;
        }
        //debug:
        printf("%d\n", cont);
        
        if (g == 0) // primo giro..
            g = cont;
        
        // g e G sono molti simili a un min ed un Max..
        if (cont>G){
            //passimo g in G:
            g = G;
            // aggiorniamo G (come se fosse il max..)
            G = cont;
        }
    }
    
    printf("g=%d;  G=%d\n", g, G);
    return 0;
}
