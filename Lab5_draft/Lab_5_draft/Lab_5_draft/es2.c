//
//  es2.c
//  Lab_5_draft
//
//  Created by ing.conti on 23/10/20.
/*

 Es2
 a)    si scriva una funzione  “stampaPunto” che effettui la stessa STAMPA dell’ es 1 ma con 3 decimali. La f. ricevera’ in ingresso un parametro P di tipo punto
 b)    si scriva una f. “stampaPunto2” che pero’ riceva il punto per indirizzo(reference)

 */


#include <stdio.h>

typedef struct {
    float x;
    float y;
} punto;

void stampaPunto(punto p){
    printf("\n  x = %4.3f y = %4.3f\n", p.x, p.y);
}

int main(int argc, const char * argv[]) {
    punto p = { 1.2, 3.43};
    //tralasciamo input
    stampaPunto(p);
    return 0;
}

