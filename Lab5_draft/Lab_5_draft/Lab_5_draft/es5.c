//
//  es5.c
//  Lab_5_draft
//
//  Created by ing.conti on 23/10/20.
//

#include <stdio.h>


/*
 ES 5
 

 Es 5 si scriva una f. leggiPunto che chieda all’ utente le coord. x e y (come es 1) e che restituisca il uscita un risultato di tipo
 Si chiami poi la f. stampaPunto per verifica.

 
 
 */


typedef struct {
    float x;
    float y;
} punto;


punto leggiPunto(){
    punto p;

    scanf("%f", &p.x);
    scanf("%f", &p.y);
    return p;
}
void stampaPunto(punto p){
    printf("\n  x = %4.3f y = %4.3f\n", p.x, p.y);
}



int main(int argc, const char * argv[]) {
    
    punto P = leggiPunto();
    stampaPunto(P);
    return 0;
}

