//
//  es1.c
//  LAB3
//
//  Created by ing.conti on 13/10/20.
//

#include <stdio.h>

/*

 Problema 2
 Scrivere un programma che chiede due sequenze di caratteri all’utente, e conta quante volte nella prima stringa è contenuta interamente la seconda.

 */


#define STRING_SIZE 1024

int main(int argc, const char * argv[]) {

    int i;
    // lasciamo all' utente l' inserimento delle due stringhe, bigString e littleString ...
    
    // pre-carichiamo il vettore per svere casi noti:
    char bigString[STRING_SIZE]    = "sotto la panca la capra";
    char littleString[STRING_SIZE] = "la";

    //calcoliamo subito la lunghezza effettiva della 2' stirnga:
    int littleStringLen;
    for (i=0; littleString[i] != '\0'; i++) {
        // empty loop, aspettimao '\0'
    }
    
    littleStringLen = i;
    
    int equal_till_now_count = 0;
..
    
    printf("Hello, World!\n");
    return 0;
}
