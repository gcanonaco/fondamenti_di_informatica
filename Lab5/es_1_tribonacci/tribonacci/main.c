//
//  main.c
//  tribonacci
//
//  Created by ing.conti on 12/11/2018.
//  Copyright © 2018 ing.conti. All rights reserved.
//

#include <stdio.h>

int tribo (int n){
    if (n==0) return 0;
    if (n==1 || n==2) return 1;
    return tribo (n-1)+tribo(n-2)+tribo (n-3);}


int  tribovis_inversa(int n){
    if (n==0) return 0;
    printf ("%d \n",tribo(n));
    return tribovis_inversa(n-1);
}



int  tribovis_DRITTA(int n){
    if (n==0) return 0;
    
    int temp = tribovis_DRITTA(n-1);
    printf ("%d \n",tribo(n));
    return temp;
}



int main(){
    tribovis_inversa(6);
    printf("\n----\n");
    tribovis_DRITTA(6);
    return 0;
}
