//
//  es1.c
//  Lab_5_draft
//
//  Created by ing.conti on 23/10/20.
/*

Es1 warm up

Si scriva un frammento di codice legga da input le coord x e y di una struct punto cosi definita:
typedef struct { float x; float y; } punto;
si stampi a video le coord x e y con 2 decimali.
*/


#include <stdio.h>

typedef struct {
    float x;
    float y;
} punto;


int main(int argc, const char * argv[]) {
    punto p;
    scanf("%f", &p.x);
    scanf("%f", &p.y);
    
    
    printf("\n  x = %4.2f y = %4.2f\n", p.x, p.y);
    
    return 0;
}

