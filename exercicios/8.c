#include <stdio.h>
#include <string.h>
#include <locale.h>

struct produto {
    char nome[50];
    int codigo;
    float preco;
};

void cadastrarproduto(struct produto *p) {
    printf("Digite o nome do produto: ");
    getchar();
    fgets(p->nome, sizeof(p->nome), stdin);
    p->nome[strcspn(p->nome, "\n")] = '\0';

    printf("Digite o código do produto: ");
    scanf("%d", &p->codigo);

    printf("Digite o preço do produto: ");
    scanf("%f", &p->preco);
}

void listarprodutos(struct produto *p, int n) {
    printf("\nProdutos cadastrados:\n");
    for (int i = 0; i < n; i++) {
        printf("Nome: %s\n", p[i].nome);
        printf("Código: %d\n", p[i].codigo);
        printf("Preço: %.2f\n", p[i].preco);
        printf("\n");
    }
}

void buscarproduto(struct produto *p, int n) {
    int codigo;
    printf("Digite o código do produto que deseja buscar: ");
    scanf("%d", &codigo);

    for (int i = 0; i < n; i++) {
        if (p[i].codigo == codigo) {
            printf("Nome: %s\n", p[i].nome);
            printf("Código: %d\n", p[i].codigo);
            printf("Preço: %.2f\n", p[i].preco);
            printf("\n");
            return;
        }
    }
    printf("Produto com código %d não encontrado.\n", codigo);
}

int main() {
    setlocale(LC_ALL, "portuguese");
    struct produto produtos[10];
    int n = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Buscar produto\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (n < 10) {
                    cadastrarproduto(&produtos[n]);
                    n++;
                } else {
                    printf("Limite de produtos atingido.\n");
                }
                break;
            case 2:
                listarprodutos(produtos, n);
                break;
            case 3:
                buscarproduto(produtos, n);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
