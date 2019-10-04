#include <stdio.h>
int main(){
    int n, a, b, c, i;
    printf("Inserisci un numero intero naturale:\n");
    scanf("%d", &n);
    for (a=0,b=1,i=0; i<n; i++){
        c = b;
        b = a + b;
        a = c;
        printf("%d ", b);
    }
    return 0;
}
