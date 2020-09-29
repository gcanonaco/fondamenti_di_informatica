#include <stdio.h>

int main() {
    char a, b, c;
    printf("Inserisci 3 caratteri:\n");
    scanf("%c", &a);
    getchar();
    scanf("%c", &b);
    getchar();
    scanf("%c", &c);
    getchar();

    if(a<b){
        if(a<c) {
            printf("%c, ", a);
            if(b<c)
                printf("%c, %c", b, c);
            else
                printf("%c, %c", c, b);
        }else{
            printf("%c, %c, %c", c, a, b);
        }

    } else{
        if(b<c){
            printf("%c, ", b);
            if(a<c)
                printf("%c, %c", a, c);
            else
                printf("%c, %c", c, a);
        }else{
            printf("%c, %c, %c", c, b, a);
        }

    }
    return 0;
}
