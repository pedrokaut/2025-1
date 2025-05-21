#include<stdio.h>
struct produto{
    char nome[50];
    int codigo;
    float preco;

};
int main(){

}
void cadastrarproduto(struct produto *p){

    printf("digite o nome do produto: !");
    getchar();
    fgets(p->nome, sizeof(p->nome), stdin);
    printf("digite o codigo do produto: ");
    scanf("%d", &p->codigo);
    printf("digite o preco do produto: ");
    scanf("%f", &p->preco);

}
void listarprodutos(struct produto *p, int n){
    printf("produtos cadastrados: \n");
    for(int i=0; i<n; i++){
        printf("nome: %s\n", p[i].nome);
        printf("codigo: %d\n", p[i].codigo);
        printf("preco: %.2f\n", p[i].preco);
        printf("\n");
        
    }


}

