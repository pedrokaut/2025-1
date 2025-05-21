#include<stdio.h>
typedef struct{
    char nome[50];
    int matricula;
    float media;
}aluno;

int main(){
    int x;
    printf("digite a quantidade de alunos: ");
    scanf("%d", &x);
     aluno alunos[x];
        for(int i=0; i<x; i++){
            getchar(); 
            printf("digite o  nome do aluno %d: ", i+1);
            fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
            printf("digite a matricula do aluno %d: ", i+1);
            scanf("%d", &alunos[i].matricula);
            printf("digite a media do aluno %d: ", i+1);
            scanf("%f", &alunos[i].media);

        };
        printf("alunos aprovados: \n");
        for(int i=0; i<x; i++){
            if(alunos[i].media >= 7){
            printf("nome: %s\n", alunos[i].nome);
            printf("matricula: %d\n", alunos[i].matricula);
            printf("media: %.2f\n", alunos[i].media);
            };

        };
    
    return 0;

}