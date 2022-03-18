#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void imprime(celula *p){
    for(celula *elem = p->prox; elem!=NULL; elem=elem->prox){
        printf("%d -> ", elem->dado);
    }
    printf("NULL\n");
}

int empilha(celula *p, int x){
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

int desempilha(celula *p, int *y){
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

int main (){

    int dado, op, y=0;
    celula *p = malloc(sizeof(celula));
    celula *elem1 = malloc(sizeof(celula));
    celula *elem2 = malloc(sizeof(celula));
    celula *elem3 = malloc(sizeof(celula));
    celula *elem4 = malloc(sizeof(celula));

    p->prox = elem1;
    elem1->dado=1;
    elem1->prox=elem2;
    elem2->dado=2;
    elem2->prox=elem3;
    elem3->dado=3;
    elem3->prox=elem4;
    elem4->dado=1;
    elem4->prox=NULL;

    imprime(p);
    printf("%d\n", empilha(p, 5));
    empilha(p, 6);
    imprime(p);

    return 0;
}



/*void insere_inicio(celula *le, int x){
    celula *novo = malloc(sizeof(celula));
    if(novo==NULL) return;
    novo->dado = x;
    novo->prox = le->prox;
    le->prox = novo;
}*/