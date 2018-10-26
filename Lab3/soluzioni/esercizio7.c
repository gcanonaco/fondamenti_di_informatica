#include<stdio.h>
#define N 31
int main(){
    char s[N],c;
    int i;
    printf("Inserisci stringa:\n");
    scanf("%s", s);
    for(i=0; i<N && s[i]!='\0'; i++){
        if(s[i]<123 && s[i]>96)
            s[i]=s[i]-32;
        printf("%c", s[i]);
    }
    return 0;

}
