#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct punto_s{
    char name;
    float x,y;
}punto_t;
typedef struct poligono_s{
    punto_t p;
    struct poligono_s * next;
}poligono_t;

float perimetro(poligono_t *);
poligono_t * aggiungi_in_coda(poligono_t *, punto_t);

poligono_t * aggiungi_in_coda(poligono_t * pol, punto_t p){
    poligono_t * a = (poligono_t*)malloc(sizeof(poligono_t)), *h;
    
    a->p = p;
    a->next = NULL;
    if (pol == NULL)
        return a;
    h=pol;
    while(pol->next!=NULL)
        pol=pol->next;
    pol->next=a;
    return h;
}
float perimetro(poligono_t *p){
    float acc =0, dx, dy;
    poligono_t *h;
    h = p;
    if (p == NULL)
        return -1;
    while(p->next!=NULL){
        dx = p->p.x - p->next->p.x;
        dy = p->p.y - p->next->p.y;
        acc += sqrt(dx*dx +dy*dy);
        p = p->next;
    }
    dx = p->p.x - h->p.x;
    dy = p->p.y - h->p.y;
    acc += sqrt(dx*dx +dy*dy);
    if (acc == 0)
        return -1;
    return acc;
}

int main() {
    int n,i;
    punto_t p;
    poligono_t * pol=NULL;
    printf("Inserisci il numero di vertici del poligono:");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("Inserisci il nome del vertice seguito dalle suecoordinate x e y tutto separato da spazi: \n");
        scanf(" %c", &(p.name));
        scanf("%f", &(p.x));
        scanf("%f", &(p.y));
        pol = aggiungi_in_coda(pol, p);
    }
    printf("Il perimetro del poligono è: %f\n", perimetro(pol));

    return 0;
}
