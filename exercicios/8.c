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

