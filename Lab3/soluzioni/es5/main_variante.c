//
//  main_variante.c
//  lab03_es5_boracchi
//
//  Created by ing.conti on 26/10/2019.
//  Copyright © 2019 ing.conti. All rights reserved.
//

/*
 Problema 5: Matrici di caratteri
 Scrivere un programma che chieda all'utente di inserire una matrice quadrata 5x5 contenente solo caratteri. Il programma dica all'utente se la parola che si trova sulla diagonale principale può essere ritrovata in un qualsiasi altro punto della matrice (in una riga o in una colonna). Venga indicato a video anche la posizione della parola. Esempio:
 
 a  i  o  a  q
 h  n  t  n  a
 a  v  s  s  p
 u  s  p  i  o
 a  i  s  n  a     <--- cambiata, ansia inverita DX / SX
 
 
 Sì consideri anche di poterla trovare leggendo da destra verso sinistra.
 
 */


// SOLUZIONE:
#include <stdio.h>



#define MAX 5

// per semplicita si consideri l' array gia caricato come da esempio:
char matrice[MAX][MAX] =
{
    {'a'  ,'i'  ,'o'  ,'a'  ,'q' },
    {'a'  ,'n'  ,'s'  ,'i'  ,'a' },  // cambiatia x verifica...
    {'a'  ,'v'  ,'s'  ,'s'  ,'p' },
    {'u'  ,'s'  ,'p'  ,'i'  ,'o' },
    {'a'  ,'i'  ,'s'  ,'n'  ,'a' }, // <--- cambiata, ansia inverita DX / SX
    
};
// cerchiamo: "ansia"

int main(int argc, const char * argv[]) {
    
    int r,c;
    // scandiamo le righe, ed all' interno le colonne:
    for (r=0; r<MAX; r++) {
        // mi serve un contatore x i caratteri uguali, ma va azzerato ad OGNI riga:
        int uguali = 0;
        int uguali_invertiti = 0;

        for (c=0; c<MAX; c++) {
            //mi sposto sulla riga r, ed uso lo stesso indice c x scandire la diagonale:
            char sullaDiag = matrice[c][c];
           
            char ch = matrice[r][c];
            char ch_inverso = matrice[r][MAX-c-1];

            if (ch == sullaDiag)
                uguali++;
            if (ch_inverso == sullaDiag)
                uguali_invertiti++;

        }
        if (uguali == MAX || uguali_invertiti == MAX){
            printf("found on row %d\n", r);
        }
    }
    // ---------------------
    
    // ripetiamo a logica invertita: (attenzione agli indici!)
    for (c=0; c<MAX; c++) {
        int uguali = 0;
        int uguali_invetiti = 0;
        int uguali_invertiti = 0;

        for (r=0; r<MAX; r++) {
            //mi sposto sulla colonna c, ed uso lo stesso indice r x scandire la diagonale:
            char sullaDiag = matrice[r][r];

            char ch = matrice[r][c];
            char ch_inverso = matrice[r][MAX-c-1];

          if (ch == sullaDiag)
              uguali++;
          if (ch_inverso == sullaDiag)
              uguali_invertiti++;

        }
        if (uguali == MAX || uguali_invertiti == MAX){
            printf("found on col %d\n", c);
        }
    }
    
    
    

    return 0;
}
