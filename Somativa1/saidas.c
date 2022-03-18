#include <stdio.h>

int fun1 (int x, int y){
    int tmp = x;
    x = y;
    y = tmp;
}
int fun2 (int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
int fun3 (int *x, int *y){
    int *tmp = x;
    x = y;
    y = tmp;
}
int main(){
    int a=10;
    int b=5;
    int end;

    printf("%d\n",fun1(a,b));
    end = &b;
    printf("SAIDA 1: a = %d, b = %d, %d\n", a, b, end);
    printf("%d\n",fun2(&a,&b));
    printf("SAIDA 2: a = %d, b = %d\n", a, b);
    printf("%d\n",fun3(&a,&b));
    printf("SAIDA 3: a = %d, b = %d\n", a, b);

    return 0;
}