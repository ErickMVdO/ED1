#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
  int *dados;
  int N, p, u;
} fila;

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