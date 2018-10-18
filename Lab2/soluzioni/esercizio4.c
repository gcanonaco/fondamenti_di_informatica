#include<stdio.h>
#include<stdlib.h>

#define N 31
int main(){
    char s[N];
    int i;
    printf("Inserisci la stringa:\n");
    scanf("%s", s);
    for(i=0; s[i]!='\0' && i<N; i++)
        if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u' && s[i]!='A' && s[i]!='E' && s[i]!='I' && s[i]!='O' && s[i]!='U')
            printf("%c", s[i]);
    return 0;
}
