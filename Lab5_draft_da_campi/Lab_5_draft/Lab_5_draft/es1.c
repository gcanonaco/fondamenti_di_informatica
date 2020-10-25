//
//  es1.c
//  Lab_5_draft
//
//  Created by ing.conti on 23/10/20.
/*
  LAB 5 Draft funzioni e parametri
  
  Si scriva un frammento di codice legga da input le coord x e y di una struct “punto” cosi definita:
  typedef struct { float x; float y; } punto;
  
  si scriva una funzione “stampaPunto” che effettui la stessa STAMPA di un punto passato come parametro. La funzione avrà prototipo:
  void stampaPunto(punto p)

  Si scriva poi una funzione “acquisisciPunto” che crea un punto dopo aver chiesto le coordinate all’utente. La funzione avrà prototipo:
  void acquisisciPunto(punto * p)
  oppure
  Punto acquisisciPunto()

  Si scriva infine una funzione “stampaLunghezza” che riceve un vettore di punti e restituisce la lunghezza della linea spezzata composta dai punti nel vettore (nelol’ordine in cui sono nel vettore). La funzione avrà prototipo:
  float lunghezza(punto linea[])

  */

 #include <stdio.h>
 #include <math.h>

 #define MAX 3

 typedef struct {
     float x;
     float y;
 } punto;

 void stampaPunto(punto p){
     printf("\n  x = %4.3f y = %4.3f\n", p.x, p.y);
 }


 punto acquisisciPunto(){
     punto p;
     printf("\ndammi x:");
     scanf("%f", &p.x);
     printf("\ndammi y:");
     scanf("%f", &p.y);
     return p;
 }

 // dobbiamo cambiare nome, "acquisisciPunto" usato sopra.
 void acquisisciPunto_(punto *p){

     scanf("%f", &p->x);
     scanf("%f", &p->y);
 }


 double stampaLunghezza(punto * arrPunti)
 {
     double somma = 0,segmento, dx, dy;
     int i;
     for (i=0; i<MAX-1; i++) {
         dx = (arrPunti+1)->x - (arrPunti)->x;
         dy = (arrPunti+1)->y - (arrPunti)->y;
         segmento = sqrt(dx*dx + dy*dy);
         somma+=segmento;
     }
     
     return somma;
 }


 int main(int argc, const char * argv[]) {
     
     punto punti1[MAX] = { {0,0}, {3,4}, {8,0}};
     // altro caso..
     punto punti2[MAX] = { {1,1}, {4,5}, {9,1}};
     double lung;
     punto P = acquisisciPunto();
     stampaPunto(P);
     
     lung = stampaLunghezza(punti1);
     printf("\n lunghezza: %lf\n", lung);

     lung = stampaLunghezza(punti2);
     printf("\n lunghezza: %lf\n", lung);

     return 0;
 }

