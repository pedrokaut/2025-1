/* O algoritmo mede o tempo m�dio de execu��o da fun��o recursiva x(n) para um valor fixo n?,
 repetindo sua execu��o at� atingir um n�mero m�ximo de repeti��es (NMax). Isso fornece uma avalia��o emp�rica do desempenho,
  mas n�o determina a complexidade te�rica, que depende da pr�pria defini��o recursiva da fun��o x(n). */
/*
Algorithm 1: Calculo da fun��o ao recursiva x(n)
input: Algoritmo para x(n) avaliado para n = n?
Output: Tempo medio do algoritmo x(n) para n = n?, N_Max
N = 0;
T = 0;
if N ? N_Max then
return T / N_Max
end
else
N = N + 1;
T = T + tempo_execucao(x(n?));
Execute Algoritmo para calcular�x(n?);
end
*/
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