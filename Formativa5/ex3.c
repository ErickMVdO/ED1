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