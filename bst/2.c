#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<locale.h>

typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
    struct Aluno* esquerdo;
    struct Aluno* direito;
} Aluno;

//já neste codigo utilizei a versão disponibilizada no pdf
Aluno* criarAluno(char nome[], int matricula, float nota);
Aluno* inserir(Aluno* raiz, char nome[], int matricula, float nota);
Aluno* buscarPorNome(Aluno* raiz, char nome[]);
void imprimirInOrdem(Aluno* raiz);
float somarNotas(Aluno* raiz, int* contador);
void liberarArvore(Aluno* raiz);



int main() {
    setlocale(LC_ALL,"portuguese");
    Aluno* raiz = NULL;
     
    raiz = inserir(raiz, "pedro", 202343081, 8.5);
    raiz = inserir(raiz, "micaely", 20232312, 4.0);
    raiz = inserir(raiz, "nilda", 2023067443, 1.0);
    raiz = inserir(raiz, "jonatha", 202123664, 10.0);
    
    printf("\nAlunos cadastrados (ordem alfabética):\n");
    imprimirInOrdem(raiz);
    
    
    char nomeBusca[50];
    printf("\nDigite o nome do aluno para buscar: ");
    scanf(" %[^\n]", nomeBusca);
    
    Aluno* encontrado = buscarPorNome(raiz, nomeBusca);
    if (encontrado != NULL) {
        printf("Aluno encontrado: %s, Matrícula: %d, Nota: %.2f\n",
            encontrado->nome, encontrado->matricula, encontrado->nota);
    } else {
        printf("Aluno com nome '%s' não encontrado.\n", nomeBusca);
    }
    
    
    int total = 0;
    float soma = somarNotas(raiz, &total);
    if (total > 0) {
        float media = soma / total;
        printf("\nMédia das notas dos alunos: %.2f\n", media);
    } else {
        printf("\nNenhum aluno cadastrado para calcular a média.\n");
    }
    
    liberarArvore(raiz);
    return 0;



}


Aluno* criarAluno(char nome[], int matricula, float nota) {
    Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
    strcpy(novo->nome, nome);
    novo->matricula = matricula;
    novo->nota = nota;
    novo->esquerdo = NULL;
    novo->direito = NULL;
    return novo;
}

Aluno* inserir(Aluno* raiz, char nome[], int matricula, float nota) {
    if (raiz == NULL) return criarAluno(nome, matricula, nota);

    if (strcmp(nome, raiz->nome) < 0)
        raiz->esquerdo = inserir(raiz->esquerdo, nome, matricula, nota);
    else if (strcmp(nome, raiz->nome) > 0)
        raiz->direito = inserir(raiz->direito, nome, matricula, nota);

    return raiz;
}

Aluno* buscarPorNome(Aluno* raiz, char nome[]) {
    if (raiz == NULL) return NULL;
    if (strcmp(nome, raiz->nome) == 0) return raiz;
    if (strcmp(nome, raiz->nome) < 0)
        return buscarPorNome(raiz->esquerdo, nome);
    else
        return buscarPorNome(raiz->direito, nome);
}

void imprimirInOrdem(Aluno* raiz) {
    if (raiz != NULL) {
        imprimirInOrdem(raiz->esquerdo);
        printf("Nome: %s, Matrícula: %d, Nota: %.2f\n", raiz->nome, raiz->matricula, raiz->nota);
        imprimirInOrdem(raiz->direito);
    }
}


float somarNotas(Aluno* raiz, int* contador) {
    if (raiz == NULL) return 0;

    float somaEsquerda = somarNotas(raiz->esquerdo, contador);
    float somaDireita = somarNotas(raiz->direito, contador);

    *contador += 1;
    return somaEsquerda + raiz->nota + somaDireita;
}

void liberarArvore(Aluno* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerdo);
        liberarArvore(raiz->direito);
        free(raiz);
    }
}