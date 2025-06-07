#include <stdio.h>
#include <time.h>
#include <locale.h>
//os codigos 5,6,7 são as versões do algoritimo melhorado, e que foram utilizados para fazer o grafico
#define MAX 1000
long long me[MAX];
//algoritmo modificado para calcular valores maiores que os proibitivos
long long x(int n) {
    if (n <= 1) return 1;
    if (me[n] != -1) return me[n];
    me[n] = x(n - 1) + x(n - 2);
    return me[n];
}

int main() {
    setlocale(LC_ALL, "portuguese");
    int n = 600;
    int NMax = 10;
    double tempototal = 0;

    for (int i = 0; i < NMax; i++) {
        for (int j = 0; j < MAX; j++) me[j] = -1;

        clock_t start = clock();
        x(n);  
        clock_t end = clock();

        tempototal += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("Tempo médio de x(%d) [Recursivo com Memoização]: %.8f segundos\n", n, tempototal / NMax);
    return 0;
}
