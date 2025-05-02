#include<stdio.h>
#include<locale.h>
int inverte(int n){
    int invertido=0;
    while(n>0){
        invertido = invertido*10 + n%10;
        n = n/10;

    }
    return invertido;
}
int main(){
    setlocale(LC_ALL, "portuguese");
    int n, invertido;
    printf("digite um numero: ");
    scanf("%d", &n);
    invertido = inverte(n);
    printf("numero invetdido %d\n", invertido);
    return 0;

}