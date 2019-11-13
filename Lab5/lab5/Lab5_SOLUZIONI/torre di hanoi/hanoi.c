#include <stdio.h> 
  

void hanoi(int n, char dal_piolo, char al_piolo, char piolo_ausiliario) 
{ 
    if (n == 1) 
    { 
        printf("\n Sposta il disco 1 dal piolo %c al piolo %c", dal_piolo, al_piolo); 
        return; 
    } 
    hanoi(n-1, dal_piolo, piolo_ausiliario, al_piolo); 
    printf("\n Sposta il disco %d dal piolo %c al piolo %c", n, dal_piolo, al_piolo); 
    hanoi(n-1, piolo_ausiliario, al_piolo, dal_piolo); 
} 
  
int main() 
{ 
    int n = 4; // numero di dischi
    hanoi(n, 'A', 'C', 'B');  // A, B and C sono i nomi dei pioli
    return 0; 
} 
