#include<stdio.h>
int main(){
    int a[3][3],b[3][3],c[3][3],i,j;
    printf("preencha a primeira matriz:\n");
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("digite o elemento [%d][%d]: ",i,j);
            scanf("%d",&a[i][j]);

        }
        
    }
    
}