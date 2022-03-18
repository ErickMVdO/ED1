#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  char matricula[10];
  double mediaAtividades;
  double mediaProvas;
  struct celula *prox;
} celula;

void relatorioMediaAtividades (celula *le, celula *l1, celula *l2, double media){
    
    for(celula *elem=le->prox; elem!=NULL; elem=elem->prox){
        if(elem->mediaAtividades>media){
            l2->prox = elem;
            l2 = elem;
        }
        else{
            l1->prox = elem;
            l1 = elem;
        }
    }
    l1->prox = NULL;
    l2->prox =NULL;
}

typedef struct celula
{
    char matricula[10];
    double mediaAtividades;
    double mediaProvas;
    struct celula *prox;
} celula;


void relatorioMediaAtividades (celula *le, celula *l1, celula *l2, double media){
    
    for(celula *elem=le->prox; elem!=NULL; elem=elem->prox){
        if (elem -> mediaAtividades <= media){
            l1 -> prox = elem;
            l1 = elem;
        }
        else{
            l2 -> prox = elem;
            l2 = elem;
        }
    }
    l1 -> prox = NULL;
    l2 -> prox = NULL;
}