//
//  main.c
//  es_2_fibonacci_div3
//
//  Created by ing.conti on 12/11/2018.
//  Copyright © 2018 ing.conti. All rights reserved.
//

#include <stdio.h>


// per prima cosa fibonacci:

int Fibonacci(int N){
    if (N < 0) return -1; // non definita x N negativo
    
    // scatiamo casi "vicini" all' 1 che NON hanno precedenti:
    if (N == 0)
        return 0;
    if (N == 1)
        return 1;
    
    return Fibonacci(N-1) + Fibonacci(N-2);
    
}
int main(int argc, const char * argv[]) {
   
    
    // per comodita mettiano n fisso:
    int n = 3;
    
    int i = 2;// parto dal 2, potre partire anche con il primo numero che so divisibile x 3 ...
    int cont_divisibili = 0;
    while (cont_divisibili<n){
        int fib = Fibonacci(i);
        if ( fib % 3 == 0){
            cont_divisibili+=1;
            printf("%d divisibile x 3\n", fib);
        }
        i++;
    }
    return 0;
}
