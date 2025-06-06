#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;
//utilizei uma função diferente aqui, ela insere e cria.

No* inserirecriar(No* raiz, int num) {
    if (raiz == NULL) {
        No* aux = malloc(sizeof(No));
        aux->dado = num;
        aux->esquerdo = NULL;
        aux->direito = NULL;
        return aux;
    } else {
        if (num < raiz->dado) {
            raiz->esquerdo = inserirecriar(raiz->esquerdo, num);
        } else {
            raiz->direito = inserirecriar(raiz->direito, num);
        }
        return raiz;
    }
}

No* buscar(No* raiz, int dado) {
    if (raiz == NULL || raiz->dado == dado)
        return raiz;
    if (dado < raiz->dado)
        return buscar(raiz->esquerdo, dado);
    else
        return buscar(raiz->direito, dado);
}

No* encontrarMinimo(No* raiz) {
    while (raiz->esquerdo != NULL)
        raiz = raiz->esquerdo;
    return raiz;
}

No* removerNo(No* raiz, int dado) {
    if (raiz == NULL) return NULL;

    if (dado < raiz->dado)
        raiz->esquerdo = removerNo(raiz->esquerdo, dado);
    else if (dado > raiz->dado)
        raiz->direito = removerNo(raiz->direito, dado);
    else {
        
        if (raiz->esquerdo == NULL && raiz->direito == NULL) {
            free(raiz);
            return NULL;
        }
        
        else if (raiz->esquerdo == NULL || raiz->direito == NULL) {
            No* temp = (raiz->esquerdo != NULL) ? raiz->esquerdo : raiz->direito;
            free(raiz);
            return temp;
        }
        
        else {
            No* sucessor = encontrarMinimo(raiz->direito);
            raiz->dado = sucessor->dado;
            raiz->direito = removerNo(raiz->direito, sucessor->dado);
        }
    }

    return raiz;
}

void inOrdem(No* raiz) {
    if (raiz != NULL) {
        inOrdem(raiz->esquerdo);
        printf("%d ", raiz->dado);
        inOrdem(raiz->direito);
    }
}

void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        preOrdem(raiz->esquerdo);
        preOrdem(raiz->direito);
    }
}

void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerdo);
        posOrdem(raiz->direito);
        printf("%d ", raiz->dado);
    }
}

int altura(No* raiz) {
    if (raiz == NULL) return -1;
    int altEsq = altura(raiz->esquerdo);
    int altDir = altura(raiz->direito);
    return (altEsq > altDir ? altEsq : altDir) + 1;
}

int profundidade(No* raiz, int valor, int nivel) {
    if (raiz == NULL) return -1;
    if (raiz->dado == valor) return nivel;
    if (valor < raiz->dado)
        return profundidade(raiz->esquerdo, valor, nivel + 1);
    else
        return profundidade(raiz->direito, valor, nivel + 1);
}

int somaValores(No* raiz) {
    if (raiz == NULL) return 0;
    return raiz->dado + somaValores(raiz->esquerdo) + somaValores(raiz->direito);
}

int nivel(No* raiz, int valor) {
    return profundidade(raiz, valor, 0);
}

int numeronos(No* raiz) {
    if (raiz == NULL) return 0;
    return 1 + numeronos(raiz->esquerdo) + numeronos(raiz->direito);
}

int folha(No* raiz) {
    if (raiz == NULL) return 0;
    if (raiz->esquerdo == NULL && raiz->direito == NULL) return 1;
    return folha(raiz->esquerdo) + folha(raiz->direito);
}

void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerdo);
        liberarArvore(raiz->direito);
        free(raiz);
    }
}

int main() {
    No* raiz = NULL;

    raiz = inserirecriar(raiz, 50);
    raiz = inserirecriar(raiz, 30);
    raiz = inserirecriar(raiz, 70);
    raiz = inserirecriar(raiz, 20);
    raiz = inserirecriar(raiz, 40);
    raiz = inserirecriar(raiz, 60);
    raiz = inserirecriar(raiz, 80);

    printf("PreOrdem: "); preOrdem(raiz); printf("\n");
    printf("inOrdem: "); inOrdem(raiz); printf("\n");
    printf("PosOrdem: "); posOrdem(raiz); printf("\n");

    printf("Altura: %d\n", altura(raiz));
    printf("Soma dos valores: %d\n", somaValores(raiz));
    printf("Numero de nos: %d\n", numeronos(raiz));
    printf("Numero de folhas: %d\n", folha(raiz));

    int num;
    printf("\nDigite o valor para ver a profundidade e o nivel: ");
    scanf("%d", &num);

    int prof = profundidade(raiz, num, 0);
    if (prof == -1) {
        printf("Valor %d nao encontrado na arvore.\n", num);
    } else {
        printf("Profundidade do %d: %d\n", num, prof);
        printf("Nivel do %d: %d\n", num, nivel(raiz, num));
    }

    int valorRemover;
    printf("\nDigite o valor que deseja remover: ");
    scanf("%d", &valorRemover);
    raiz = removerNo(raiz, valorRemover);
    printf("inOrdem apos remocao: ");
    inOrdem(raiz); printf("\n");

    liberarArvore(raiz);
    return 0;
}
