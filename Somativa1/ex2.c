#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmp (const void *x, const void *y) {
   return (*(int *)x - *(int *)y); 
}

long int busca(long int *v, long int num, long int n){
    long int e=-1, d;
    d=n;
    while(e<d-1){
        long int m=(e+d)/2;
        if(v[m]<num) e=m;
        else d=m;
    }
    return d;
}

int main(){
    
    clock_t t;
    long int n, m, i, num, r;
    scanf("%li %li", &n, &m);
    long int *v = malloc(n*sizeof(long int));
    long int *s = malloc(n*sizeof(long int));
    

    for(i=0; i<n; i++){
        scanf("%li", &v[i]);
        s[i]=v[i];
    }
    qsort(v, n, sizeof(long int), cmp);
    for(long int j=0; j<m; j++){
        scanf("%li", &num);
        r = busca(v, num, n);
        if(num==v[r]){
            for(long int k=0; k<n; k++){
                if(num==s[k]){
                    printf("%li\n", k);
                    k=n;
                }
            }
        }
        else{
            printf("-1\n");
        }
    }
    free(v);
    free(s);
    t = clock();
    printf("tempo: %lf s", ((double)t)/((CLOCKS_PER_SEC/1000)));
    return 0;
}