#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
  int *dados;
  int N, topo;
} pilha;

int main (){

    int y, x, tam;
    pilha *p = malloc(sizeof(pilha));
    p->N=5;
    p->dados=malloc(p->N*sizeof(int));
    p->topo=0;

    scanf("%d", &tam);
    for(int i=0; i<tam; i++){
        scanf("%d", &x);
        empilha(p, x);
        for(int i=0; i<p->topo; i++){
            printf("%d ", p->dados[i]);
        }
        printf("\n");
    }
    printf("%d\n", p->topo);

    //printf("%d\n", desempilha(p, &y));
    //desempilha(&p, &y);
    /*for(int i=0; i<p->topo; i++){
        printf("%d ", p->dados[i]);
    }*/
    //printf("\n%d", y);

    return 0;
}

int empilha(pilha *p, int x){
    if(p!=NULL){
        if(p->topo==p->N){
            p->dados=realloc(p->dados, 2*p->N*sizeof(int));
            if(p->dados==NULL) return 0;
            p->N*=2;
        }
        p->dados[p->topo]=x;
        p->topo++;
        return 1;
    }
}

int desempilha(pilha *p, int *y){
    if(p!=NULL){
        if(p->topo==0) return 0;
        else{
            *y=p->dados[p->topo-1];
            p->topo--;
            return 1;
        }
    }
}