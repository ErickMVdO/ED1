#include <stdio.h>
#include <stdlib.h>

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

    long int n, m, i, num, r;
    //n=potencia(10,9);
    scanf("%li %li", &n, &m);
    long int *v = malloc(n*sizeof(long int));
    long int *s = malloc(n*sizeof(long int));
    

    for(i=0; i<n; i++){
        scanf("%li", &v[i]);
        s[i]=v[i];
    }
    /*for(long int i=0; i<n-1; i++){
      v[i]=i;
      s[i]=i;
    }*/
    qsort(v, n, sizeof(long int), cmp);
    /*for(long int i=0; i<n; i++){
      if(i!=n-1)
        printf("%ld ", v[i]);
      else
        printf("%ld", v[i]);
    }
    printf("\n");*/
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
    //free(*v);
    //free(*s);
    return 0;
}