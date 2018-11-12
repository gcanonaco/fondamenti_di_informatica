//
//  main.c
//  es_4_matrici_di_binari
//
//  Created by ing.conti on 12/11/2018.
//  Copyright © 2018 ing.conti. All rights reserved.
//

/*
 
 Problema 4
 Si scriva una funzione che riceve in ingresso una matrice di caratteri NxN (con N costante predefinita). Ogni elemento della matrice contiene solo i caratteri ‘0’, ‘1’ o ‘\0’. Ogni riga della matrice (letta da sinistra a destra) rappresenta una stringa che è la codifica binaria di un intero. Si calcoli la media degli interi codificati dalle righe della matrice.
*/

#include <stdio.h>

#define N 12

int conversioneBinaria(char riga[]){
    if (riga[0] == 0)   // fine stringa
        return 0;
    
    int digit = riga[0] - 48;
    return digit + 2 * conversioneBinaria(riga+1);
}



int sommaRicorsiva(char matrice[][N], int num_righe){
    if (num_righe == 0 )
        return 0;
    
    int valoreRiga0 = conversioneBinaria(matrice[0]);
    printf("%d %d \n", valoreRiga0, num_righe);
    int s = valoreRiga0 + sommaRicorsiva(matrice+1, num_righe-1);
    return s;
}

float mediaRicorsiva(char matrice[][N], int num_righe){
    if (num_righe == 0 )
        return 0;   // prevent division by ZERO
    
    float m = sommaRicorsiva(matrice, num_righe);
    m = m / num_righe;
    return m;
}

int main(int argc, const char * argv[]) {

    char matrice[N][N] = {
        {'1','1','1',0},
        {'1','1',0},
        {'0','0','1',0},
        {'0','0','1','1', 0},
    };

    // spacchiamo in piu funzioni:
    //a) conversione (ricorsiva) "conversioneBinaria" su ogni riga
    //b) media (ricorsiva)      "mediaRicorsiva"
    
    //test:
    int n = conversioneBinaria("101");  // dovrebe dare 5..
    printf("%d\n", n);
    
    // ora media:
    float m = mediaRicorsiva(matrice, 4);
    
    printf("%f\n", m);

    return 0;
}
