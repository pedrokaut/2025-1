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

    printf("Digite o c�digo do produto: ");
    scanf("%d", &p->codigo);

    printf("Digite o pre�o do produto: ");
    scanf("%f", &p->preco);
}

void listarprodutos(struct produto *p, int n) {
    printf("\nProdutos cadastrados:\n");
    for (int i = 0; i < n; i++) {
        printf("Nome: %s\n", p[i].nome);
        printf("C�digo: %d\n", p[i].codigo);
        printf("Pre�o: %.2f\n", p[i].preco);
        printf("\n");
    }
}

void buscarproduto(struct produto *p, int n) {
    int codigo;
    printf("Digite o c�digo do produto que deseja buscar: ");
    scanf("%d", &codigo);

    for (int i = 0; i < n; i++) {
        if (p[i].codigo == codigo) {
            printf("Nome: %s\n", p[i].nome);
            printf("C�digo: %d\n", p[i].codigo);
            printf("Pre�o: %.2f\n", p[i].preco);
            printf("\n");
            return;
        }
    }
    printf("Produto com c�digo %d n�o encontrado.\n", codigo);
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
        printf("Escolha uma op��o: ");
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
                printf("Op��o inv�lida.\n");
        }
    } while (opcao != 0);

    return 0;
}
