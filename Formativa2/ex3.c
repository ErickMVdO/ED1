#include <stdio.h>

long int soma(long int n){

    if(n%10 == n)
        return n;
    else{
        return (n%10)+soma((n-n%10)/10);
    }

}

int main (){

    long int n;
    scanf("%li", &n);
    printf("%li\n", soma(n));

    return 0;
}