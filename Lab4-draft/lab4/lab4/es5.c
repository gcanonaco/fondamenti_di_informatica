//
//  es5.c
//  lab4
//
//  Created by ing.conti on 17/10/20.
//

#include <stdio.h>


typedef struct t_Complex{
    double Re;
    double Im;
} Complex;


int main(){
    Complex C1, C2, SC, PC;
    
    // tralasciamo input...
    // eventualmente sarebbe::
    //scanf("%f", C1.Re);
    //scanf("%f", C1.Im);

    C1.Re = 1; C1.Im = 1;
    C2.Re = 1; C2.Im = 3;
    
    SC.Re = C1.Re + C2.Re;
    SC.Im = C1.Im + C2.Im;
    
    printf("somma %f, i %f\n", SC.Re, SC.Im);
    
    PC.Re = C1.Re * C2.Re - C1.Im * C2.Im; // (a*c -b*d)
    PC.Im = C1.Re * C2.Im + C1.Im * C2.Re; // (a*d+b*c)

    printf("somma %f, i %f\n", PC.Re, PC.Im);

}
