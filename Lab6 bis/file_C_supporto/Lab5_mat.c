#include <stdio.h>
#define N 100 // fino a 100 maialini in un allevamento

typedef struct { int giorno, mese, anno; } Data;
typedef struct { char nome[20]; Data datanascita; 
                 float peso; int popolarita; } Maialino;
typedef struct { int numero_maialini; Maialino pigs[N];} Allevamento;
int confronta( Data, Data );
int main () {

 Allevamento a = { 7,  "Porky Pig", {12,7,1936}, 33.50, 85 ,
                        "Miss Piggy", {17,12,1974}, 23.95, 170 ,
                        "Babe", {23,1,1996}, 18.80, 250 ,
                        "Pumbaa", {14,11,1994}, 79.99, 1690 ,
                        "Peppa", {31,5,2004}, 12.15, 8500 ,
                        "Hamm", {12,7,1968}, 19.05, 290 ,
                        "Piglet", {22,4,1926}, 9.30, 1260  };

 Maialino  * ord_alfabetico[N] = { NULL },   // inizialmente, per "sicurezza", tutti a NULL
           * ord_data[N] = { NULL },
           * ord_peso[N] = { NULL },
           * ord_pop[N] = { NULL };

  /* codice! */

  return 0;
}
