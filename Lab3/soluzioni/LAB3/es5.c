//
//  es1.c
//  LAB3
//
//  Created by ing.conti on 13/10/20.
//


/*

 Problema 5
 Due parole p e q si definiscono Hertzianamente compatibili se entrambe sono leggibili anche “oscillando” e leggendo alternativamente i caratteri dell’una e dell’altra. La figura mostra tigre con fiera e fiera con fresa. In figura parole uguali sono tracciate da linee di ugual stile.
 Si noti anche che la relazione sussiste in due modi (diretto o inverso). In figura: fiera e tigre si leggono iniziando dalla stessa lettera (modo diretto), per fiera e fresa occorre iniziare dall’iniziale dell’ “altra” parola nella coppia (modo inverso). Se la relazione fosse definita solo in modo diretto o solo in modo inverso varrebbe anche la proprietà transitiva (esempio: aria, prua, erba, orma sono tutte direttamente compatibili tra loro), ma consideriamo due parole compatibili indipendentemente dal modo in cui la proprietà si manifesta. Si scriva un programma che verifica la compatibilità Hertziana di due stringhe.
  


 */
#include <stdio.h>

#define STRING_SIZE 128


int main(int argc, const char * argv[]) {
    // lasciamo all' utente l' inserimento della due stringa.
    
    // pre-carichiamo il vettore per avere casi noti:
    
    // caso "tigre/fiera"
    char s1[STRING_SIZE]    = "TIGRE";
    char s2[STRING_SIZE]    = "FIERA";
    // scommentare e provare...
    //char s1[STRING_SIZE]    = "FIERA";
    //char s2[STRING_SIZE]    = "FRESA";

    // scommentare e provare...
    //char s1[STRING_SIZE]    = "__ERA";
    //char s2[STRING_SIZE]    = "FRESA";

    int i, len1, len2;
    for (len1=0; s1[len1] != '\0'; len1++) {
        // empty loop, aspettiamo '\0'
    }

    for (len2=0; s2[len2] != '\0'; len2++) {
        // empty loop, aspettiamo '\0'
    }
    
    // TODO: gestire errore x stringhe di diversa lunghezza... while...etc..
    
    // se qui len1 === len2...
    int hertziane_diretto = 1; // per default tutto ok
    //1 ' caso:
    for (i=0; i<len1 && hertziane_diretto; i++) {
        if (i%2 == 1){
            if (s1[i] != s2[i])
                hertziane_diretto = 0;
        }
    }
    
    // caso inverso..
    int hertziane_inverso = 1; // per default tutto ok
    for (i=0; i<len1 && hertziane_inverso; i++) {
        if (i%2 == 0){
            if (s1[i] != s2[i])
                hertziane_inverso = 0;
        }
    }
    
    if (hertziane_diretto)
        printf(" herziane diretto !\n");
    else if (hertziane_inverso)
        printf("herziane inverse!\n");
        else
        printf("NON somo herziane!\n");

    return 0;
}
