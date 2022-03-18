#include <stdio.h>

long int qtd(long int n, int i){

    if(n%10 == n){
        if(n==7)
            return i+1;
        else
            return i;
    }   
    else{
        if(n%10==7){
            return qtd((n-n%10)/10, i+1);
        }
        else
            return qtd((n-n%10)/10, i);
    }

}

int main (){

    long int n;
    scanf("%li", &n);
    printf("%li\n", qtd(n, 0));

    return 0;
}