#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int c, n;
    struct no *prox;
}no;

void insere_inicio(no *le, int c, int x){
    no *novo = malloc(sizeof(no));
    if(novo==NULL) return;
    novo->c=c;
    novo->n = x;
    novo->prox = le->prox;
    le->prox = novo;
}

void soma(no *le, int *v){
    int soma = 0;
    for(no *elem = le->prox; elem!=NULL; elem=elem->prox){
        soma+=(elem->n * v[elem->c]);
    }
    printf("%d\n", soma);
}

int main(){

    int m, n;
    int l, c, num;
    scanf("%d %d", &m, &n);
    if(m==0 || n==0) return 0;
    no **le = malloc(m*sizeof(no *));
    int *v = malloc(n*sizeof(int));
    for(int i=0; i<m ; i++){
        le[i] = malloc(sizeof(m));
        le[i]->prox = NULL;
    }
    scanf("%d %d %d", &l, &c, &num);
    
    while (l!=-1 && c!=-1 && num!=-1){
        if(l<0 || l>=m || c<0 ||c>=n) return 0;
        insere_inicio(le[l], c, num);
        scanf("%d %d %d", &l, &c, &num);
    }
    for(int i=0; i<n ; i++){
        scanf("%d", &v[i]);
    }
    for(int i=0; i<m ; i++){
        soma(le[i], v);
    }
    
    return 0;
}