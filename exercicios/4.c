#include<stdio.h>
int main(){
    int n[10], i,j,cout;
    printf("digite 10 numeros: ");
    for(i=0;i<10;i++){
        scanf("%d", &n[i]);
    }
    printf("numeros que se repetem: ");
    for(i=0;i<10;i++){
        cout=0;
        for(j=0;j<10;j++){
            if(n[i]==n[j]){
                cout++;
            }

        }
        if(cout>1)
    }
}