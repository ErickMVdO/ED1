#include <stdio.h>

float potencia(int a, int b)
{

    if (b == 0)
        return 1;
    else
        return a * potencia(a, b - 1);
}

void main()
{

    int a, b;
    float resultado;
    scanf("%d %d", &a, &b);
    if ((a==0 && b==0) || (a==0 && b<0)){
        printf("indefinido\n");
    }
    else{
        if (b < 0)
        {
            b = b * (-1);
            resultado = (1 / potencia(a, b));
            printf("%.3f\n", resultado);
        }
        else
        {
            resultado = potencia(a, b);
            printf("%.1f\n", resultado);
        }
    }

    return 0;
}