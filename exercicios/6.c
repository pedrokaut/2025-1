#include <stdio.h>

int main() {
    int a[3][3], b[3][3], c[3][3], i, j;

    
    printf("Preencha a primeira matriz:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Digite o elemento [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }


    printf("Preencha a segunda matriz:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Digite o elemento [%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    
    printf("Soma das matrizes:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            c[i][j] = a[i][j] + b[i][j];
            printf("%4d", c[i][j]);  
        }
        printf("\n");  
    }

    return 0;
}
