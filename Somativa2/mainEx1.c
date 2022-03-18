#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
  char matricula[10];
  double mediaAtividades;
  double mediaProvas;
  struct celula *prox;
} celula;

void imprime(celula *le){
    for(celula *elem = le->prox; elem!=NULL; elem=elem->prox){
        printf("{%.1f, %.1f} -> ", elem->mediaAtividades, elem->mediaProvas);
    }
    printf("NULL\n");
}

void relatorioMediaAtividades (celula *le, celula *l1, celula *l2, double media){

  celula *p = le->prox;

  while (p != NULL){
    celula *newLista = malloc(sizeof(celula));

    newLista->mediaAtividades = p->mediaAtividades;
    newLista->mediaProvas = p->mediaProvas;
    strcpy(newLista->matricula , p->matricula);

    double result = (p->mediaProvas + p->mediaAtividades) / 2;

    if(result <= media) {
      newLista->prox = l1->prox;
      l1->prox = newLista;
    } else{
      newLista->prox = l2->prox;
      l2->prox = newLista;
    }

    p = p->prox;
  }
}

int main(){

    int dado, op;
    celula *le = malloc(sizeof(celula));
    celula *l1 = malloc(sizeof(celula));
    celula *l2 = malloc(sizeof(celula));
    celula *elem1 = malloc(sizeof(celula));
    celula *elem2 = malloc(sizeof(celula));
    celula *elem3 = malloc(sizeof(celula));
    celula *elem4 = malloc(sizeof(celula));
    celula *elem5 = malloc(sizeof(celula));
    l1->prox = NULL;
    l2->prox = NULL;

    le->prox = elem1;
    elem1->matricula[0]=1;
    elem1->matricula[1]=4;
    elem1->matricula[2]=0;
    elem1->matricula[3]=1;
    elem1->matricula[4]=6;
    elem1->matricula[5]=4;
    elem1->matricula[6]=0;
    elem1->matricula[7]=0;
    elem1->matricula[8]=6;
    elem1->matricula[9]='\0';
    elem1->mediaAtividades=10.0;
    elem1->mediaProvas=8.0;
    elem1->prox=elem2;

    elem2->matricula[0]=1;
    elem2->matricula[1]=6;
    elem2->matricula[2]=0;
    elem2->matricula[3]=0;
    elem2->matricula[4]=1;
    elem2->matricula[5]=6;
    elem2->matricula[6]=1;
    elem2->matricula[7]=6;
    elem2->matricula[8]=9;
    elem2->matricula[9]='\0';
    elem2->mediaAtividades=4.0;
    elem2->mediaProvas=2.0;
    elem2->prox=elem3;

    elem3->matricula[0]=1;
    elem3->matricula[1]=7;
    elem3->matricula[2]=0;
    elem3->matricula[3]=0;
    elem3->matricula[4]=6;
    elem3->matricula[5]=2;
    elem3->matricula[6]=4;
    elem3->matricula[7]=6;
    elem3->matricula[8]=5;
    elem3->matricula[9]='\0';
    elem3->mediaAtividades=9.5;
    elem3->mediaProvas=8.5;
    elem3->prox=elem4;

    elem4->matricula[0]=1;
    elem4->matricula[1]=9;
    elem4->matricula[2]=0;
    elem4->matricula[3]=2;
    elem4->matricula[4]=6;
    elem4->matricula[5]=2;
    elem4->matricula[6]=6;
    elem4->matricula[7]=6;
    elem4->matricula[8]=1;
    elem4->matricula[9]='\0';
    elem4->mediaAtividades=5.0;
    elem4->mediaProvas=7.0;
    elem4->prox=elem5;

    elem5->matricula[0]=1;
    elem5->matricula[1]=9;
    elem5->matricula[2]=0;
    elem5->matricula[3]=2;
    elem5->matricula[4]=6;
    elem5->matricula[5]=2;
    elem5->matricula[6]=6;
    elem5->matricula[7]=6;
    elem5->matricula[8]=1;
    elem5->matricula[9]='\0';
    elem5->mediaAtividades=7.0;
    elem5->mediaProvas=7.0;
    elem5->prox=NULL;

    relatorioMediaAtividades(le, l1, l2, 6.0);
    printf("le -> ");
    imprime(le);
    printf("l1 -> ");
    imprime(l1);
    printf("l2 -> ");
    imprime(l2);
    

    return 0;
}