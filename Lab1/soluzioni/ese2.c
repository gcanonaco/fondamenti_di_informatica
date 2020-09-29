#include <stdio.h>

int main() {
    char a, b, min, max;
    printf("Inserisci 2 caratteri minuscoli:\n");
    scanf("%c", &a);
    getchar();
    scanf("%c", &b);
    getchar();
    if(a<b){
        min=a;
        max=b;
    }else{
        min=b;
        max=a;
    }

    while(min!=max) {
        printf("%c, ", min);
        min++;
    }
    printf("%c.", max);

    return 0;
}
