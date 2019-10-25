#include <stdio.h>
#include <stdlib.h>
#define N 31
int main(){
    char s1[N], s2[N];
    int count, i, l1, l2, j, flag;
    printf("Inserisci la prima stringa senza spazi:\n");
    scanf("%s", s1);
    printf("Inserisci la seconda stringa senza spazi:\n");
    scanf("%s", s2);
    l1=strlen(s1);
    l2=strlen(s2);
    for(i=0, count=0; i<l1; i++){
        if(i+l2<=l1)
            for(j=0, flag=1; flag && j<l2; j++)
                if(s1[i+j]!=s2[j])
                    flag=0;
        if(flag==1)
            count++;
            flag=0;
    }
    printf("%d", count);
    return 0;
}
