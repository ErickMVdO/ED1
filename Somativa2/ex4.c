#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define parenteses 0
#define operando 1

typedef struct celula {
   char dado;
   struct celula *prox;
} celula;

int empilha(celula *p, char x){
    if(p!=NULL){
        celula *novo = malloc(sizeof(celula));
        if(novo==NULL) return 0;
        novo->dado = x;
        novo->prox = p->prox;
        p->prox = novo;
        return 1;
    }
    return 0;
}

int desempilha(celula *p, char *y){
    if(p!=NULL){
        if(p->prox==NULL) return 0;
        else{
            *y=p->prox->dado;
            p->prox=p->prox->prox;
            return 1;
        }
    }
    return 0;
} 

int main(){

    char str[501];
    char y;
    int resposta=1;
    celula **p = malloc(2*sizeof(celula *));
    p[parenteses] = malloc(sizeof(celula));
    p[parenteses]->prox=NULL;
    p[operando] = malloc(sizeof(celula));
    p[operando]->prox=NULL;

    scanf("%s", str);
    
    for(int i=0; i<strlen(str); i++){
        if(str[i]=='(' || str[i]=='[' || str[i]=='{') empilha(p[parenteses], str[i]);
        else if(str[i]==')' || str[i]==']' || str[i]=='}') {
            resposta = desempilha(p[parenteses], &y);
            if(resposta==0 || ((str[i]==')' && y!='(') || (str[i]==']' && y!='[') || (str[i]=='}' && y!='{'))){
                printf("nao\n");
                return 0;
            }
        }
        else empilha(p[operando], str[i]);
    }
    if(p[parenteses]->prox==NULL && p[operando]->prox!=NULL)
        printf("sim\n");
    else
        printf("nao\n");

    return 0;
}