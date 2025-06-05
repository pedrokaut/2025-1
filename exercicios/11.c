#include <stdio.h>

int busca(int v[], int n, int alvo) {
    int i = 0, f = n - 1, m;

    while (i <= f) {
        m = (i + f) / 2;
        if (v[m] == alvo) return m;
        if (v[m] < alvo) i = m + 1;
        else f = m - 1;
    }

    return -1;
}

int main() {
    int v[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(v) / sizeof(v[0]);
    int alvo = 7;

    int pos = busca(v, n, alvo);

    printf("%s\n", pos != -1 ? "Encontrado" : "Não encontrado");

    return 0;
}
