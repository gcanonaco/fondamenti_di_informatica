#include <stdio.h>
#include <string.h>
#define N 100
int main() {
    char str1[N+1],str2[N+1];
    int i,k,dim1,dim2,cont=0;
    printf("Inserire la prima sequenza: ");
    scanf("%s",str1);
    printf("Inserire la seconda sequenza: ");
    scanf("%s",str2);
    dim1=strlen(str1);
    dim2=strlen(str2);

    if (dim1<dim2)
        printf("Str2 non contenuta in str1");
    else{
        for(i=0;i<dim1-dim2+1;i++){
            k=0;
            while(str1[i+k]==str2[k] && k<dim2){
                printf("%c ", str1[k]);
                k++;

            }
            if (k==dim2)
                cont++;
        }
        printf("str2 contenura %d volte in str1",cont);
    }
    return 0;
}
