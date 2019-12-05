#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define N 3

typedef char griglia[N][N];
typedef struct mo { int r,c;
    struct mo * next; } Mossa;
typedef Mossa * Partita;

char ennuplaVert(griglia);
char ennuplaOriz(griglia);
char ennuplaDiag(griglia);
int esito(griglia);
Partita crea();
void gioca(Partita);



int main() {
    Partita p=crea();
    gioca(p);
    return 0;
}

char ennuplaVert(griglia g){
    int i,j, flag;
    for(i=0; i<N; i++) {
        for (j = 0, flag = 1; flag && j < N; j++)
            if (g[j][i] != g[i][i]) {
                flag = 0;
            }
        if(flag)
            return g[i][i];
    }
    return '\0';
}

char ennuplaOriz(griglia g){
    int i,j, flag;
    for(i=0; i<N; i++) {
        for (j = 0, flag = 1; flag && j < N; j++)
            if (g[i][j] != g[i][i]) {
                flag = 0;
            }
        if(flag)
            return g[i][i];
    }
    return '\0';
}

char ennuplaDiag(griglia g){
    int i, flag;
    for(i=0, flag=1; flag && i<N; i++)
        if(g[i][i]!=g[0][0])
            flag=0;

     if(flag)
        return g[0][0];

    for(i=0, flag=1; flag && i<N; i++)
        if(g[N-i-1][i]!=g[N-1][0])
            flag=0;

    if(flag)
        return g[N-1][0];

    return '\0';

}

int esito(griglia g){
    char e;
    int i,j;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            if(g[i][j]=='\0')
                return 0;

    e = ennuplaOriz(g);

    if(e=='X')
        return 1;
    else if (e=='O')
        return 2;

    e = ennuplaVert(g);

    if(e=='X')
        return 1;
    else if (e=='O')
        return 2;

    e = ennuplaDiag(g);

    if(e=='X')
        return 1;
    else if (e=='O')
        return 2;

    return 3;

}
Partita inserisci_in_coda(Partita l, int r, int c){
    Partita punt, tmp;
    punt = (Partita) malloc(sizeof(Mossa));
    punt->r = r;
    punt->c = c;
    punt->next = NULL;
    if(l==NULL)
        return punt;
    tmp=l;
    while(tmp->next!=NULL)
        tmp=tmp->next;
    tmp->next=punt;
    return  l;
}

Partita crea() {
    Partita lis=NULL;
    lis=inserisci_in_coda( lis, 1, 2 );
    lis=inserisci_in_coda( lis, 2, 2 );
    lis=inserisci_in_coda( lis, 0, 2 );

    lis=inserisci_in_coda( lis, 1, 1 );
    lis=inserisci_in_coda( lis, 0, 1 );
    lis=inserisci_in_coda( lis, 0, 0 );

    lis=inserisci_in_coda( lis, 2, 1 );
    lis=inserisci_in_coda( lis, 2, 0 );
    lis=inserisci_in_coda( lis, 1, 0 );
    return lis;
}

void gioca(Partita p){
    griglia g;
    int i, j;

    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            g[i][j]='\0';
    i=0;
    while(p!=NULL){
        if(i%2==0)
            g[p->r][p->c] = 'X';
        else
            g[p->r][p->c] = 'O';
        p=p->next;
        i++;
    }
    for(i=0; i<N; i++) {
        for (j = 0; j < N; j++)
            printf("%c ", g[i][j]);
        printf("\n");
    }
    j=esito(g);
    if(j==0)
        printf("Partita in corso...\n");
    else if(j==1)
        printf("Ha vinto X\n");
    else if(j==2)
        printf("Ha vinto O\n");
    else
        printf("Pareggio\n");
    return;
}

