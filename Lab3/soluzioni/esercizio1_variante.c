//
//  es1.c
//  LAB3
//
//  Created by ing.conti on 13/10/20.
//

#include <stdio.h>

/*

 Problema 1
 Scrivere un programma che riceva in ingresso dall'utente un vettore di 5 caratteri tutti minuscoli. Il programma dica all'utente se le lettere contenute nel vettore sono in ordine alfabetico.
 */


#define ARR_SIZE 5
int main(int argc, const char * argv[]) {

    // lasciamo all' utente l' inserimento dei char, gia visto...
    // il vettore andrebbe dichiarato come:
    // char vett[ARR_SIZE];
    
    // pre-carichiamo il vettore per avere casi noti:
    char vett[ARR_SIZE] = {'a', 'b', 'c', 'm', 'z'};

    // riprovare utilizzando invece (il prg deve stamapre "NON ORDINATI": (va commentata la riga prec)
    //char vett[ARR_SIZE] = {'k', 'b', 'c', 'm', 'z'};


    int i;
    int ordered_till_now = 1; // flag che mettermeo a false se salta ordine

    // facciamo un "giro" in meno,
    // altrimenti sforiamo arrray.
    // il for termina anche se salta ordine (inutile ciclare..)
    for (i=0; i< (ARR_SIZE-1) && ordered_till_now; i++) {
        if (vett[i+1]<=vett[i]){
            ordered_till_now = 0;
        }
    }

    if (ordered_till_now)
        printf(" ORDINATI!\n");
    else
        printf("NON ORDINATI!\n");
    return 0;
}
