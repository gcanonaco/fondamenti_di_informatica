//
//  es2.c
/***********************************************************************************************
* Si definisca una struttura che possa contenere i dati di una semplice rubrica telefonica:
* cognome, nome, cellulare. Si limiti a un massimo di 10 il numero di recapiti memorizzabili.
* Si scriva quindi un programma che, tramite un apposito men˘, consenta l'inserimento di un
* recapito telefonico, la visualizzazione dei recapiti inseriti e l'eliminazione
* (con compattamento) di uno specifico recapito.
**********************************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAXSTRLEN 100 + 1    // 20 caratteri max + terminatore '\0'
#define MAXREC    10
#define NZ        '\0'

// definire qui tipi di dati e strutture ------------------------------------------------------

typedef struct {
                char cognome[MAXSTRLEN];
                char nome[MAXSTRLEN];
                char cellulare[MAXSTRLEN];
} RECAPITO;

void main(){
  int i, j, r, next; // le variabili i e r sono indici di servizio, next Ë l'indice costantemente
                     // aggiornato del prossimo elemento recapito da riempire
  char c;

  RECAPITO rubrica[MAXREC];

  next = 0; // primo elemento libero dell'array
  do{
    printf("\n\n--- MENU DELLE OPERAZIONI ---\n");
    printf("\nA - Inserimento nuovo recapito");
    printf("\nB - Stampa elenco recapiti");
    printf("\nC - Elimina recapito");
    printf("\nX - Uscita dal programma.");
    printf("\n\nSelezionare un'operazione: ");
    scanf("%c%*c", &c);
    
    if (c == 'a' || c == 'A'){
     if (next < MAXREC){
      printf("\n\nInserimento dati recapito N. %d", next + 1);

      printf("\nInserire il cognome (max %d caratteri)..: ", MAXSTRLEN - 1);
      scanf("%s", rubrica[next].cognome);

      printf("\nInserire il nome (max %d caratteri).....: ", MAXSTRLEN - 1);
      scanf("%s", rubrica[next].nome);

      printf("\nInserire il cellulare (max %d caratteri): ", MAXSTRLEN - 1);
      scanf("%s%*c", rubrica[next].cellulare);

      printf("\nFine inserimento ----------------");
      next++;
     }
     else
      printf("\n*** ATTENZIONE *** Rubrica piena! ***");
    }
    else if (c == 'b' || c == 'B'){
      printf("\n\n--------------- ELENCO RECAPITI ------------------");
      if (next > 0){
       for (i = 0;i < next;i++)
        printf("\nRECAPITO N. %d: %s %s\t\t%s", i + 1, rubrica[i].cognome, rubrica[i].nome, rubrica[i].cellulare);
      } else printf("\nNessun recapito in rubrica!");
      printf("\n------------- FINE ELENCO RECAPITI ---------------");
    }
    else if (c == 'c' || c == 'C') {
      printf("\n\n--------------- ELENCO RECAPITI ------------------");
      if (next > 0){
       for (i = 0;i < next;i++)
        printf("\nRECAPITO N. %d: %s %s\t\t%s", i + 1, rubrica[i].cognome, rubrica[i].nome, rubrica[i].cellulare);

       printf("\n\nEliminare il recapito N.: ");
       scanf("%d%*c", &r);
       
       // ciclo di eliminazione e compattamento
       for (j = r - 1; j < next; j++) // sposto a sinistra di una posizione tutti gli elementi pieni a destra dell'elemento da eliminare
       {                              // se r Ë il numero dell'elemento da eliminare, r - 1 Ë il relativo indice nell'array
        strcpy(rubrica[j].cognome, rubrica[j+1].cognome);
        strcpy(rubrica[j].nome, rubrica[j+1].nome);
        strcpy(rubrica[j].cellulare, rubrica[j+1].cellulare);
       }
       next--; // riposiziono il puntatore al prossimo elemento libero e, per sicurezza, lo azzero
       rubrica[next].cognome[0] = NZ;
       rubrica[next].nome[0] = NZ;
       rubrica[next].cellulare[0] = NZ;

       printf("\nRECAPITO N. %d ELIMINATO -------------------------", r);
      } else {
       printf("\nNessun recapito in rubrica!");
       printf("\n------------- FINE ELENCO RECAPITI ---------------");
      }
    }
  } while (c != 'x' && c != 'X');

  printf("\n\nFINE ELABORAZIONE ***\n\n");
}
