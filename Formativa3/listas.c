#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;
/*
celula *criar_lista(){
    celula *le = malloc(sizeof(celula));
    le->prox = NULL;
    return le;
}*/

void insere_inicio(celula *le, int x){
    celula *novo = malloc(sizeof(celula));
    if(novo==NULL) return;
    novo->dado = x;
    novo->prox = le->prox;
    le->prox = novo;
}
void insere_antes(celula *le, int x, int y){
    celula *elem = malloc(sizeof(celula));
    for(elem=le; elem->prox!=NULL; elem=elem->prox)
        if(elem->prox->dado==y){
            insere_inicio(elem, x);
            return;
        }
    insere_inicio(elem,x);
}
/*
void remove_depois(celula *p){
    celula *lixo = p->prox;
    if(lixo!=NULL){
        p->prox = lixo->prox;
        lixo=NULL;
        free(lixo);
    }
}
void remove_elemento (celula *le, int x){
    for(celula *elem=le; elem->prox!=NULL; elem=elem->prox)
        if(elem->prox->dado==x){
            remove_depois(elem);
            return;
        }
}
void remove_todos_elementos(celula *le, int x){
    for(celula *elem=le; elem->prox;)
        if(elem->prox->dado==x)
            remove_depois(elem);
        else
            elem=elem->prox;
}

void imprime(celula *le){
    for(celula *elem = le->prox; elem!=NULL; elem=elem->prox){
        printf("%d -> ", elem->dado);
    }
    printf("NULL\n");
}
void imprime_rec(celula *le){
    celula *elem = le->prox;
    if(elem==NULL)
        printf("NULL\n");
    else{
        printf("%d -> ", elem->dado);
        imprime_rec(elem);
    }
}


celula *destruir_lista(celula *le){
    int dado;
    while(remove_depois(le));
    le=NULL;
    free(le);
    return le;
}

celula *busca (celula *le, int x){
    for(celula *elem = le->prox; elem!=NULL; elem=elem->prox){
        if(elem->dado==x){
            return elem;
        }
    }
    return 0;
}
celula *busca_rec (celula *le, int x){
    celula *elem = le->prox;
    if(elem!=NULL){
        if(elem->dado==x)
            return elem;
        return busca_rec(elem, x);
    } 
    return 0;
}*/
