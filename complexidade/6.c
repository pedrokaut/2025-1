#include <stdio.h>
#include <time.h>
#include <locale.h>
//modificado para usar uma abordagem interativa
long long x(int n) {
    if (n <= 1) return 1;
    long long a = 1, b = 1, temp;

    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }

    return b;
}

int main() {
    setlocale(LC_ALL, "portuguese");
    int n = 300;
    int NMax = 10;
    double tempototal = 0;

    for (int i = 0; i < NMax; i++) {
        clock_t start = clock();
        x(n);  
        clock_t end = clock();

        tempototal += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("Tempo médio de x(%d) [Iterativo]: %.8f segundos\n", n, tempototal / NMax);
    return 0;
}
