#include <stdio.h>
int main(){
    int n, i, crediti, c, v;
    float media;
    printf("Inserisci il numero di voti: ");
    scanf("%d",&n);
    for(i=0, crediti=0, media=0; i<n; i++){
        printf("Inserisci il numero di crediti associato all'esame e poi separato da uno spazio il voto: ");
        scanf("%d", &c);
        scanf("%d", &v);
        crediti+=c;
        media+=v*c;
    }
    printf("Media Ponderata: %f\n",media/crediti);
    printf("Crediti: %d\n", crediti);
    return 0;
}
