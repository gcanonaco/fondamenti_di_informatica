//
//  main.c
//  es5_ninfee
//
//  Created by ing.conti on 12/11/2018.
//  Copyright © 2018 ing.conti. All rights reserved.
//

/*
 Problema 5
 Uno stagno è pieno di ninfee:
 • ogni ninfea in un giorno si riproduce generando un’altra ninfea
 • dopo 30 giorni lo stagno è pieno
 Quanti giorni hanno impiegato le ninfee a riempire metà dello stagno?
 */

#include <stdio.h>

// partiamo da 1 ninfea...

int popolazioneNinfee(int giorni){
    if (giorni == 0)
        return  1; // 1 ninfea all' inzio. giorno ZERO, al gg 1 si e' gia riprodotta...
    return  2 * popolazioneNinfee(giorni-1);
}


int ggNinfeeLimitati(int gg, int giorniMax, int MaxNinfee){

    if (gg == giorniMax)
        return  giorniMax;// to be safe.. never here..
    
    int popolazione =  popolazioneNinfee(gg);
    if (popolazione >= MaxNinfee)
        return gg;
    
    return ggNinfeeLimitati(gg+1, giorniMax, MaxNinfee);

}


int main() {
   
    // prova, dopo 2 gg:
    int dopo2 = popolazioneNinfee(2);
    printf("%d\n", dopo2);
    
    int GG = 8;
    int dopGG = popolazioneNinfee(GG);
    printf("%d\n", dopGG);
    
    int perMetaPieno = ggNinfeeLimitati(1, GG, dopGG/2);
    return 0;
}
