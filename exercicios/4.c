#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");
    int n[10], i, j, count;

    printf("Digite 10 números:\n");
    for(i = 0; i < 10; i++) {
        scanf("%d", &n[i]);
    }

    printf("Números que se repetem: ");
    for(i = 0; i < 10; i++) {
        count = 0;

        
        for(j = 0; j < 10; j++) {
            if(n[i] == n[j]) {
                count++;
            }
        }

        
        if(count > 1) {
            // Verifica se já foi impresso antes
            int repetido = 0;
            for(j = 0; j < i; j++) {
                if(n[i] == n[j]) {
                    repetido = 1;
                    break;
                }
            }

            if(!repetido) {
                printf("%d ", n[i]);
            }
        }
    }

    printf("\n");
    return 0;
}
