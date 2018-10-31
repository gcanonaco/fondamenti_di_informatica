#include <math.h>
#include <stdio.h>
#define N 4
typedef struct { float x; float y; } punto;
float dist ( punto p1, punto p2 ) {
   return sqrt( pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2) );
}
float perimetro ( punto poligono[], int dim ) {
   int i; float per = 0.0;
   for (i=1; i<dim; i++)
      per = per + dist(poligono[i-1], poligono[i]);
   return per + dist(poligono[0], poligono[dim-1]);
}
int main() {
   int i;
   punto pol[N];
   for(i=0; i<N; i++){
      scanf("%f", &pol[i].x);
      scanf("%f", &pol[i].y);
   }
   printf("%d lati di lunghezza totale %f", N, perimetro(pol, N));
   return 0;
}
