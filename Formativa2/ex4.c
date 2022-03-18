#include <stdio.h>

int tamanho(char str[501], int i){
    if(str[i]=='\0'){
        return i-1;
    }
    else return tamanho(str, i+1);
}

void inverte(char str[501], char inv[501], int tam, int i){

    inv[i]=str[tam];
    if(tam==0){
        inv[i+1]='\0';
    }
    else{
        inverte(str, inv, tam-1, i+1);
    }

}

int main(){

    char str[501], inv[501];
    int tam;

    scanf("%s", str);
    tam = tamanho(str, 0);
    inverte(str, inv, tam, 0);
    printf("%s\n", inv);

    return 0;
}