#include<stdio.h>
#include<locale.h>
int main(){
    setlocale(LC_ALL, "portuguese");
    int v1[10],v2[10],i,j;
    printf("preencha o primeiro vetor:\n");
    for ( i = 0; i < 10; i++)
    {
        printf("digite 0 %d: ",i+1);
        scanf("%d",&v1[i]);

    }
    printf("preecha o segunda vetor:\n");
    for ( i = 0; i < 10; i++)
    {
        printf("digite o %d: ",i+1);
        scanf("%d",&v2[i]);

    }
    printf("elementos em comum:\n");
    
    
}