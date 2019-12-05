#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX 30

typedef char Parola[MAX];
typedef struct {
    Parola word;
    char * messaggio;
    int occorrenze;
} ParolaProibita;
typedef ParolaProibita ListaParole[1000];
typedef struct {
    ListaParole lista;
    int NumParole;
} ElencoParole;


int controlla(ElencoParole,Parola);
void scorri(char *, char);

int main() {
    ElencoParole ep;
    Parola p, end;
    end[0]='#';
    end[1]='\0';
    int i=0, n=0, s;
    do{
        printf("Inserisci parola proibita:\n");
        scanf("%s",ep.lista[i].word);
        scanf("%*c");
        printf("Quanto è lungo il messaggio associato?");
        scanf("%d", &n);
        scanf("%*c");
        ep.lista[i].messaggio=(char*)malloc(sizeof(char)*(n+1));
        printf("Inserisci il testo del messaggio: ");
        gets(ep.lista[i].messaggio);
        printf("Se hai finito premi 0: ");
        scanf("%d", &s);
        i++;
    }while(s);
    ep.NumParole=i;
    printf("Inizia lo stream di messaggi:\n");
    do{
        scanf("%s", p);
        if(!strcmp(p,end))
            break;
        controlla(ep,p);
    }while (1);
    scorri(p,'!');
    printf("%s", p);
    return 0;
}

void scorri(char * p, char c){
    int l=strlen(p),i;
    for(i=1; i<l; i++)
        p[i-1]=p[i];
    p[i-1]=c;
    return;
}

int controlla(ElencoParole ep, Parola p){
    int i, flag=0;
    for(i=0; !flag && i<ep.NumParole; i++)
        if(strcmp(ep.lista[i].word,p) == 0){
            printf("%s", ep.lista[i].messaggio);
            return 1;
        }
     return 0;
}


