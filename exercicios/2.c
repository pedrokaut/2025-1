#include<stdio.h>
#include<locale.h>
int potencia(int base, int expoente){
    int resultado = 1;
    for (int i = 0; i < expoente; i++){
        resultado *= base;
    }
    return resultado;
}
int main(){
    setlocale(LC_ALL, "portuguese");
    int base, expoente;
    printf("digite a base: ");
    scanf("%d", &base);
    printf("digite o expoente: ");
    scanf("%d", &expoente);
    resultado = potencia(base, expoente);
    printf("resultado: %d\n", resultado);
    return 0;
}