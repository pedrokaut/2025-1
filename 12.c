#include <stdio.h>
#include <string.h>

int palindromo(char str[]) {
    int i, j;
    int n = strlen(str);

    for (i = 0, j = n - 1; i < j; i++, j--) {
        if (str[i] != str[j])
            return 0; 
    }

    return 1; 
}

int main() {
    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    if (palindromo(palavra))
        printf("� pal�ndromo\n");
    else
        printf("N�o � pal�ndromo\n");

    return 0;
}
