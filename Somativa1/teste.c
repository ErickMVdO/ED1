#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

int cmp (const void *x, const void *y) {
   return (*(int *)x - *(int *)y); 
}

typedef struct vetor{
long int numero;
long int posicao;
}vetor;

long int busca(vetor *v, long int num, long int n){
    long int e=-1, d;
    d=n;
    while(e<d-1){
        long int m=(e+d)/2;
        if(v[m].numero<num) e=m;
        else d=m;
    }
    return v[d].posicao;
}

void quick_sort(vetor *v, long int left, long int right) {
    long int i, j, x;
    vetor y;
     
    i = left;
    j = right;
    x = v[(left + right) / 2].numero;
     
    while(i <= j) {
        while(v[i].numero < x && i < right) {
            i++;
        }
        while(v[j].numero > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = v[i];
            v[i] = v[j];
            v[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(v, left, j);
    }
    if(i < right) {
        quick_sort(v, i, right);
    }
}


int main(){

    long int n, m, r, i, num, soma=0, k_ant=0;
    scanf("%li %li", &n, &m);
    vetor *v = malloc(n*sizeof(vetor));
    
    for(i=0; i<n; i++){
        scanf("%li", &v[i].numero);
        v[i].posicao=i;
    }
    /*for(i=0; i<n; i++){
        printf("%li ", v[i].posicao);
    }*/
    quick_sort(v, 0, n-1);
    /*for(i=0; i<n; i++){
        printf("%li ", v[i].numero);
    }
    printf("\n");
    for(i=0; i<n; i++){
        printf("%li ", v[i].posicao);
    }*/
    for(long int j=0; j<m; j++){
        scanf("%li", &num);
        r = busca(v, num, n);
        soma+=abs(r-k_ant);
                    k_ant=r;
        /*if(num==v[r].numero){
            for(long int k=0; k<n; k++){
                if(num==s[k]){
                    soma+=abs(k-k_ant);
                    k_ant=k;
                    k=n;
                }
            }
        }*/
    }
     
    printf("%li\n", soma); 
    free(v);
    //t = clock();
    //printf("tempo: %lfs\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
    return 0;
}