#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

bool ehPrimo(int n) {
    if(n<=1){
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int n1, n2;
    printf("Digite dois números: ");
    scanf("%d %d", &n1, &n2);
    
    
    
    printf("Números primos entre %d e %d são:\n", n1, n2);
    for (int num = n1; num <= n2; num++) {
        if (ehPrimo(num)) {
            printf("%d ", num);
        }
    }
    printf("\n");
    
    return 0;
}