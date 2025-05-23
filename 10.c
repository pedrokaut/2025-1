#include<stdio.h>
int fibonacci(int n);
int main(){
    int n;
    int valor;
    n = fibonacci(valor);
    printf("%d\n", n);
    return 0;

}
int fibonacci(int n){
    if(n <=1){
        return 1;
    }else{
        return fibonacci(n-1)+ fibonacci(n-2);
    }
}