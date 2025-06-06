#include <stdio.h>
#include <math.h>
#include <time.h>
#include <locale.h>
// aqui foi utilizado uma formula fechada, pra ser mais especifico a de binet para melhorar o tempo
long long x(int n) {
    double sqrt5 = sqrt(5);
    double phi = (1 + sqrt5) / 2;
    double psi = (1 - sqrt5) / 2;

    double resultado = (pow(phi, n) - pow(psi, n)) / sqrt5;
    return (long long)(resultado + 0.5);
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

    printf("Tempo médio de x(%d) [Fórmula Fechada]: %.8f segundos\n", n, tempototal / NMax);
    return 0;
}
