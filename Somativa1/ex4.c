#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


void apaga(char *n_str, char *str, int m, int i){
    
    if(n_str[i]=='\0'){
        str[i]='\0';
    }
    else{
        str[i]=n_str[i];
        return apaga(n_str, str, m, i+1);
    }

}

void inverte(char *str, char *inv, int tam, int i){

    inv[i]=str[tam];
    if(tam==0){
        inv[i+1]='\0';
    }
    else{
        inverte(str, inv, tam-1, i+1);
    }

}

int existe(char *str, char *sub, int tam, int tam_sub, int i, int aux){

    if(str[i]==sub[aux]){
        aux++;
    }
    else{
        aux=0;
    }
    if(i==tam){
        return 0;
    }
    else if(tam_sub==aux){
        return 1;
    }
    else{
        existe(str, sub, tam, tam_sub, i+1, aux);
    }

}

int main(){

    char str[102], sub[101], inv[102], inv_sub[101];
    int n,m, soma=0;

    scanf("%[^\n]", str);
    
    scanf("%s", sub);
    m=strlen(sub);
    n=strlen(str);
    
    
    if(n==m){
        if(existe(str, sub, n, m, 0, 0)==1){
            soma+=m;
        }
    }
    else if(n>m){
        if(existe(str, sub, n, m, 0, 0)==1){
            apaga(strstr(str, sub), str, m, 0);
            n=strlen(str);
            inverte(str, inv, n-1, 0);
            inverte(sub, inv_sub, m-1, 0);
            apaga(strstr(inv, inv_sub), inv, m, 0);
            soma=strlen(inv);
        }
    }
    
    printf("%d\n", soma);

    return 0;
}