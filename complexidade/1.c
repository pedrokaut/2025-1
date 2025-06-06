#include <stdio.h>
#include <time.h>
#include<locale.h>

int x(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return x(n-1) + x(n-2);
}
int main() {
    setlocale(LC_ALL,"portuguese");
    int n0 = 5;      
    int Nmax = 10;   
    double total = 0;
    
    for (int n = n0; n <= Nmax; n++) {
        clock_t start = clock();
        x(n);
        total += (double)(clock() - start) / CLOCKS_PER_SEC;
    }

    double media = total / (Nmax - n0 + 1);
    printf("Tempo medio: %.6f segundos\n", media);
    
    return 0;
}