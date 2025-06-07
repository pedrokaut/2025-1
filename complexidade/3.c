#include <stdio.h>
#include <time.h>
#include<locale.h>
//essa e a quetão 4
//a)na minha maquina a partir do 40 esse algoritmo se torna proibitivo
//b)o algoritmo esta com uma complexidade esperada em 41 da aproximadamente 1.6 segundos em 44 12.8 segundos e em 46 51 segundos tornando a complexidade desse algortimo o(2), esses resultados foram tirados da minha maquina
int x(int n) {
    if (n <= 1) return 1;
    return x(n - 1) + x(n - 2);
}

int main() {
    int n = 40;          
    int NMax = 10;       
    double tempototal = 0;

    for (int i = 0; i < NMax; i++) {
        clock_t start = clock();
        x(n);  
        clock_t end = clock();

        tempototal += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("Tempo médio para x(%d): %.8f segundos\n", n, tempototal / NMax);
    return 0;
}
