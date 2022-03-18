#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
  int *dados;
  int N, p, u;
} fila;
// p = inicio
// u = final
/*
int enfileira (fila *f, int x){
    if((f->p==0 && f->u == f->N-1) || f->u == f->p-1){
        f->dados=realloc(f->dados, 2*f->N*sizeof(int));
        if(f->p==0 && f->u == f->N-1){
            f->N*=2;
            if(f->dados==NULL) return 0; 
        }
        else if(f->u<=(f->N - f->p)){
            int i;
            for(i=0; i<=f->u; i++){
                f->dados[f->N+i]=f->dados[i];
            }
            f->u += f->N;
            f->N*=2;
            if(f->dados==NULL) return 0;
        }
        else{
            int i = 2*f->N-1;
            for(int j = f->N-1; j>=f->u; j--){
                f->dados[i]=f->dados[j];
                i--;
            }
            f->p += f->N;
            f->N*=2;
            if(f->dados==NULL) return 0;
        }
    }
    f->dados[f->u] = x;
    f->u = (f->u+1)%f->N;
    return 1;
}

int desenfileira(fila *f, int *y){
    if(f->p==f->u) return 0;
    *y=f->dados[f->p];
    f->dados[f->p] = 0;
    f->p=(f->p+1)%f->N;
    return 1;
}*/

int desenfileira (fila *f, int *y){
    if(f->p==f->u) return 0;
    *y = f->dados[f->p];
    f->dados[f->p] = 0;
    f->p = (f->p+1)%f->N;
    return 1;
}


int enfileira (fila *f, int x){
    if(f!=NULL){
    if((f->p==0 && f->u == f->N-1) || f->u == f->p-1){
        f->dados=realloc(f->dados, 2*f->N*sizeof(int));
        if(f->p==0 && f->u == f->N-1){
            f->N*=2;
            if(f->dados==NULL) return 0; 
        }
        else if(f->u<=(f->N - f->p)){
            int i;
            for(i=0; i<=f->u; i++){
                f->dados[f->N+i]=f->dados[i];
            }
            f->u += f->N;
            f->N*=2;
            if(f->dados==NULL) return 0;
        }
        else{
            int i = 2*f->N-1;
            for(int j = f->N-1; j>=f->u; j--){
                f->dados[i]=f->dados[j];
                i--;
            }
            f->p += f->N;
            f->N*=2;
            if(f->dados==NULL) return 0;
        }
    }
    f->dados[f->u] = x;
    f->u = (f->u+1)%f->N;
    return 1;
    }
    return 0;
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
    fila *f = malloc(sizeof(fila));
    f->N = 5;
    f->p = 0;
    f->u = 0;
    f->dados = malloc(f->N*sizeof(int));

    menu(&op);
    while(op!=0){
    if(op == 1){
        scanf("%d", &x);
        enfileira(f, x);
    }
    else if(op == 2){
        desenfileira(f, &y);
        printf("Elemento removido: %d\n", y);
    }
    else{
        for(int i=0; i<f->N; i++){
            printf("%d ", f->dados[i]);
        }
        printf("\n");
    }
    menu(&op);
    }

    return 0;
}