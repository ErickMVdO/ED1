#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

int desenfileira (celula *f, int *y){
    celula *lixo = f->prox;
    if(lixo!=NULL){
        f->prox = lixo->prox;
        *y=lixo->dado;
        lixo=NULL;
        free(lixo);
        return 1;
    }
    return 0;
}

celula *enfileira (celula *f, int x){
    if(f!=NULL){
    celula *novo = malloc(sizeof(celula));
    novo->prox = f->prox;
    f->prox=novo;
    f->dado=x;
    return novo;
    }
    return NULL;
}

void imprime(celula *le){
    for(celula *elem = le->prox; elem!=le; elem=elem->prox){
        printf("%d -> ", elem->dado);
    }
    printf("NULL\n");
}

void menu(int *op){
    
    printf("\n1 - Adicionar elemento\n");
    printf("2 - Remover elemento\n");
    printf("3 - Imprimir fila\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", op);
    printf("\n");
}

int main(){

    int x, y, tam, op;
    celula *f = malloc(sizeof(celula));
    f->prox = f;

    menu(&op);
    while(op!=0){
    if(op == 1){
        scanf("%d", &x);
        f = enfileira(f, x);
    }
    else if(op == 2){
        desenfileira(f, &y);
        printf("Elemento removido: %d", y);
    }
    else{
        imprime(f);
    }
    menu(&op);
    }

    return 0;
}