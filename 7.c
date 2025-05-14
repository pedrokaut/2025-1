#include<stdio.h>
struct aluno{
    char nome[50];
    int matricula;
    float media;
};
int main(){
    int x;
    printf("digite a quantidade de alunos: ");
    scanf("%d", &x);
    struct aluno alunos[x];
        for(int i=0; i<x; i++){
            printf("digite o  nome do aluno %d: ", i+1);
            scanf("%s", alunos[i].nome);
            printf("digite a matricula do aluno %d: ", i+1);
            scanf("%d", &alunos[i].matricula);
            printf("digite a media do aluno %d: ", i+1);
            scanf("%f", &alunos[i].media);

        };
        
    
    
    

}