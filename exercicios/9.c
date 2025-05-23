#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 100

typedef struct {
    char nome[50];
    char telefone[20];
    char email[50];
} Contato;

void adicionarContato(Contato contatos[], int *total) {
    if (*total >= MAX_CONTATOS) {
        printf("Agenda cheia! Não é possível adicionar mais contatos.\n");
        return;
    }

    printf("\n--- Adicionar Contato ---\n");

    printf("Nome: ");
    getchar(); 
    fgets(contatos[*total].nome, sizeof(contatos[*total].nome), stdin);
    contatos[*total].nome[strcspn(contatos[*total].nome, "\n")] = '\0';

    printf("Telefone: ");
    fgets(contatos[*total].telefone, sizeof(contatos[*total].telefone), stdin);
    contatos[*total].telefone[strcspn(contatos[*total].telefone, "\n")] = '\0';

    printf("Email: ");
    fgets(contatos[*total].email, sizeof(contatos[*total].email), stdin);
    contatos[*total].email[strcspn(contatos[*total].email, "\n")] = '\0';

    (*total)++;
    printf("Contato adicionado com sucesso!\n");
}

void buscarContato(Contato contatos[], int total) {
    char nomeBusca[50];
    printf("\nDigite o nome do contato a buscar: ");
    getchar(); 
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    int encontrado = 0;
    for (int i = 0; i < total; i++) {
        if (strcmp(contatos[i].nome, nomeBusca) == 0) {
            printf("\n--- Contato Encontrado ---\n");
            printf("Nome: %s\n", contatos[i].nome);
            printf("Telefone: %s\n", contatos[i].telefone);
            printf("Email: %s\n", contatos[i].email);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Contato não encontrado.\n");
    }
}

void listarContatos(Contato contatos[], int total) {
    if (total == 0) {
        printf("\nNenhum contato cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Contatos ---\n");
    for (int i = 0; i < total; i++) {
        printf("Contato %d:\n", i + 1);
        printf("  Nome: %s\n", contatos[i].nome);
        printf("  Telefone: %s\n", contatos[i].telefone);
        printf("  Email: %s\n\n", contatos[i].email);
    }
}


int main() {
    Contato contatos[MAX_CONTATOS];
    int totalContatos = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1 - Adicionar Contato\n");
        printf("2 - Buscar Contato por Nome\n");
        printf("3 - Exibir Todos os Contatos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato(contatos, &totalContatos);
                break;
            case 2:
                buscarContato(contatos, totalContatos);
                break;
            case 3:
                listarContatos(contatos, totalContatos);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}
