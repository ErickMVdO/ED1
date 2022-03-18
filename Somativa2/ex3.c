#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
   char str[501];
   struct celula *prox;
} celula;

void imprime(celula *le){
    for(celula *elem = le->prox; elem!=NULL; elem=elem->prox){
        printf("%s -> ", elem->str);
    }
    printf("NULL\n");
}

int empilha(celula *p, char *str){
    if(p!=NULL){
        celula *novo = malloc(sizeof(celula));
        if(novo==NULL) return 0;
        strcpy(novo->str, str);
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
            strcpy(y, p->prox->str);
            p->prox=p->prox->prox;
            return 1;
        }
    }
    return 0;
} 

int main (){

    char comando[9], str[501], y[101];
    celula *p = malloc(sizeof(celula));
    p->prox=NULL;
    
    while(scanf("%s", comando)==1){
        if(strcmp(comando, "inserir")==0){
        scanf(" %[^\n]", str);
        empilha(p, str);
        }
        else{
            if(desempilha(p, y)==1) printf("%s\n", y);
            else printf("NULL\n");
        }
    }
    

    return 0;
}