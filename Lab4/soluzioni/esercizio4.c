#include <math.h>
#include <stdio.h>
#define N 4
typedef struct { float x; float y; } punto;
float dist ( punto p1, punto p2 ) {
   return sqrt( pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2) );
}
float erone( punto p1, punto p2, punto p3 ) {
   float p, a, b, c;
   a = dist(p1, p2);  b = dist(p2, p3);  c = dist(p1, p3);
   p = (a+b+c) / 2;
   return sqrt(p*(p-a)*(p-b)*(p-c));
}
float areapol( punto polig[], int dim ) {
   int i; float area = 0.0;
   for ( i=2; i<dim; i++ )
      area = area + erone( polig[0], polig[i-1], polig[i] );
   return area;
}
int main() {
   int i;
   punto pol[N];
   for(i=0; i<N; i++){
      scanf("%f", &pol[i].x);
      scanf("%f", &pol[i].y);
   }
   printf("%d lati di area totale %f", N, areapol(pol, N));
   return 0;
}
