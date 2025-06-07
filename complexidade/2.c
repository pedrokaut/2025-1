#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<locale.h>
//a depuração desse cordigo esta no codigo depuração2.c
float f(float n)
{
    if (n == 1)
    {
        return 1;
    }

    return ((1 / 2) * f(n - 1) + 2 / (f(n - 1)));
};
int main()
{
    setlocale(LC_ALL, "portuguese");
    
    float n = 3;
    float resultado = f(n);
    printf("%lf\n", resultado);
    // printf("%f\n", f(n));
    return 0;
}