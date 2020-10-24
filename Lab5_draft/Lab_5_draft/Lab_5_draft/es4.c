//
//  es4.c
//  Lab_5_draft
//
//  Created by ing.conti on 23/10/20.
//

#include <stdio.h>

/*
 ES 4
 
 Dato un un array (notazione con le []) di punti gia definito e caricato nel main:
 
 punto punti[MAX] = { {1,2}, {3,4}, {5,6}}; // si definisca MAX.
 
 a)    si scriva una funzione  “stampaPunti” che riceva in ingresso l’ array  e lo stampi
 b)    si scriva una funzione  “stampaPuntiNested” che stampi i punti dell’ array chiamando a sua volta (“annidata”) la f. stampaPunto del’ es 1.
 
 */



#define MAX 3

typedef struct {
    float x;
    float y;
} punto;


void stampaPunto(punto p){
    printf("\n  x = %4.3f y = %4.3f\n", p.x, p.y);
}

// a
void stampaPunti(punto arrayPunti[] ){
    int i;
    for (i=0; i<MAX; i++) {
        printf("\n  x = %4.3f y = %4.3f\n", arrayPunti[i].x, arrayPunti[i].y);
    }
}

// b
void stampaPuntiNested(punto arrayPunti[] ){
    int i;
    printf("nested\n");
    for (i=0; i<MAX; i++) {
        stampaPunto(arrayPunti[i]);
    }
}


int main(int argc, const char * argv[]) {
    
    punto punti[MAX] = { {1,2}, {3,4}, {5,6}}; // si definisca MAX.
    stampaPunti(punti);
    stampaPuntiNested(punti);
    return 0;
}

