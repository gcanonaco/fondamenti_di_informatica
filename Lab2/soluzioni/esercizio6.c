#include<stdio.h>
#define N 5
int main(){
    char s[N];
    int i, ordinata;
    printf("Inserisci stringa:\n");
    scanf("%s", s);
    for(i=1, ordinata=1; ordinata && i<N; i++)
        if(s[i]<s[i-1])
            ordinata=0;
    if(ordinata)
        printf("La stringa è in ordine alfabetico\n");
    else
        printf("La stringa non è in ordine alfabetico\n");
    return 0;
}
