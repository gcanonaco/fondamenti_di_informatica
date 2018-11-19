//
//  main.c
//  Pigs_lab6
//
//  Created by ing.conti on 19/11/2018.
//  Copyright © 2018 ing.conti. All rights reserved.
//


#include <stdio.h>
#include <string.h>


#define N 100 // fino a 100 maialini in un allevamento
typedef struct { int giorno; int mese; int anno; } Data;
typedef struct { char nome[20]; Data datanascita; float peso; int popolarita; } Maialino;
typedef struct { int num_maialini; Maialino pigs[N]; } Allevamento;

// prototipi:
int confronta( Data, Data );


// per comodita potremmo definire:
typedef Maialino * MaialinoPunt;

// prototipi accessori:
void printPig(Maialino* p);
void printArrayOfPigs(MaialinoPunt pigsArr[], int n);


void swap(MaialinoPunt * pp1, MaialinoPunt * pp2){
    MaialinoPunt temp = *pp1;
    *pp1 = *pp2;
    *pp2 = temp;
}

int main(int argc, const char * argv[]) {
    
    Allevamento all = { 7,  "Porky Pig", {12,7,1936}, 33.50, 85 ,
        "Miss Piggy", {17,12,1974}, 23.95, 170 ,
        "Babe", {23,1,1996}, 18.80, 250 ,
        "Pumbaa", {14,11,1994}, 79.99, 1690 ,
        "Peppa", {31,5,2004}, 12.15, 8500 ,
        "Hamm", {12,7,1968}, 19.05, 290 ,
        "Piglet", {22,4,1926}, 9.30, 1260  };
    
    // inizialmente, per "sicurezza", tutti a NULL:
    Maialino * ord_alfabetico[N] = { NULL };
    Maialino * ord_data[N] = { NULL };
    Maialino * ord_peso[N] = { NULL };
    Maialino * ord_pop[N] = { NULL };

    /* codice! */
    
    Maialino * temp; // ci servira' x scambiare.

    // stampa, solo x verifica...
    printf("\n elenco iniziale: \n");
    for (int i = 0; i<all.num_maialini; i++){
        printPig(&all.pigs[i]);
    }
    printf("\n");

    
    // rempiamo gli array: un solo ciclo x tutti, testando se usciamo da indice:
    for (int i = 0; i < N; i++){
        Maialino * m;
        if (i<all.num_maialini)
            m = &all.pigs[i];
        else
            m = NULL;   // inutile.. era gia messo a NULL... cmq..se sopra non fosse stato fatto.
        
        ord_alfabetico[i] = m;
        ord_data[i] = m;
        ord_peso[i] = m;
        ord_pop[i] = m;
    }
    
    // ordinamento sul NOME:
    // OSS: potremmo gia ordinare tutti gli array nel doppio FOR, ma non lo facciamo x chiarezza.
    for(int n1=0; n1 < all.num_maialini; n1++){
        for(int n2=0; n2<all.num_maialini; n2++){
            
            int ris = strcmp(ord_alfabetico[n1]->nome, ord_alfabetico[n2]->nome);
            if (ris <0)
            {
                //Scambio valori
                temp = ord_alfabetico[n1];
                ord_alfabetico[n1] = ord_alfabetico[n2];
                ord_alfabetico[n2] = temp;
            }
        }
    }

    printf("\n- ordine alfabetico: ------\n");
    printArrayOfPigs(ord_alfabetico, all.num_maialini);

    
    // ordinamento sulla DATA:
    for(int n1=0; n1 < all.num_maialini; n1++){
        for(int n2=0; n2<all.num_maialini; n2++){
            
            int ris = confronta(ord_data[n1]->datanascita, ord_data[n2]->datanascita);
            if (ris <0)
            {
                //Scambio valori
                temp = ord_data[n1];
                ord_data[n1] = ord_data[n2];
                ord_data[n2] = temp;
            }
        }
    }

    printf("\n- ordine di data: ------\n");
    printArrayOfPigs(ord_data, all.num_maialini);

    // ordinamento sul peso:
    // proviamo ad utilizzare una f. x scambiare: (per variare logica..)
    for(int n1=0; n1 < all.num_maialini; n1++){
        for(int n2=0; n2<all.num_maialini; n2++){
            
            int ris = ord_peso[n1]->peso - ord_peso[n2]->peso;
            if (ris < 0)
            {
                swap(&ord_peso[n1], &ord_peso[n2]);
            }
        }
    }
    printf("\n- ordine di peso: ------\n");
    printArrayOfPigs(ord_peso, all.num_maialini);
 

    // ordinamento sulla popolarita:
    for(int n1=0; n1 < all.num_maialini; n1++){
        for(int n2=0; n2<all.num_maialini; n2++){
            
            int ris = ord_pop[n1]->popolarita - ord_pop[n2]->popolarita;
            if (ris <0)
            {
                swap(&ord_pop[n1], &ord_pop[n2]);
            }
        }
    }
    printf("\n- ordine di popolarita: ------\n");
    printArrayOfPigs(ord_pop, all.num_maialini);

    
    return 0;
}


// implementazione funzioni:
// usiamo stessa logica della strcmp x simmetria:
// -1 se d1<d2
//  1 se d1>d2
//  0 se d1 == d2
int confronta( Data d1, Data d2 ){
    // potremmo fare uan serie di if annidati... molto piu veloce fare:
    int gg1 = d1.anno * 366 + d1.mese * 31 + d1.giorno;
    int gg2 = d2.anno * 366 + d2.mese * 31 + d2.giorno;

    if (gg1<gg2) return -1;
    if (gg1>gg2) return 1;
    return 0;
}


void printPig(Maialino* p){
    printf("%-20s %4d %2d %2d %7.2f %4d \n",
           
           p->nome,
           p->datanascita.anno,
           p->datanascita.mese,
           p->datanascita.giorno,
           p->peso,
           p->popolarita
           );
}

//void printArrayOfPigs(MaialinoPunt pigsArr[], int n){
// oppure:
void printArrayOfPigs(Maialino * pigsArr[], int n){

    for (int i = 0; i<n; i++){
        printPig(pigsArr[i]);
    }
}

