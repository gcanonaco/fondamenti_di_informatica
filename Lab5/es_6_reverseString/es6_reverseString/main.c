//
//  main.c
//  es6_reverseString
//
//  Created by ing.conti on 12/11/2018.
//  Copyright © 2018 ing.conti. All rights reserved.
//

#include <stdio.h>
/*
 Problema 6
 Scrivere una funzione ricorsiva che data una stringa di al massimo N caratteri la stampi al contrario
 */


void printReverse(char *s){
    if (*s == 0)
        return;
    
    printReverse(s+1);
    printf("%c", *s);
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    char s[] = "Hello";
    printReverse(s);
    return 0;
}
