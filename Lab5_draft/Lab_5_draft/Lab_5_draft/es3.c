//
//  es3.c
//  Lab_5_draft
//
//  Created by ing.conti on 23/10/20.
//

/*
 ES 3
 Si scriva una f. “azzezaPunto” che riceva iin ingresso un parametro di tipo punto e lo azzeri.
 Si stampi poi x verifica tale punto con la f. dell’ 2.
 Hint: si presti attenzione al passaggio per valore e/o riferimento.

 */

#include <stdio.h>

typedef struct {
    float x;
    float y;
} punto;

void stampaPunto(punto p){
    printf("\n  x = %4.3f y = %4.3f\n", p.x, p.y);
}

void azzeraPunto(punto * p){
    p->x = 0;
    p->y = 0;
}

int main(int argc, const char * argv[]) {
    punto p = {1.2, 3.43};

    //tralasciamo input
    stampaPunto(p); // prima..

    azzeraPunto(&p);
    stampaPunto(p); // dopo azzeramento
    return 0;
}

