#include <stdio.h>
#define N 10
int main() {
    int i,j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("%d ", (i+1)*(j+1));
        }
        printf("\n");
    }

    return 0;
}
