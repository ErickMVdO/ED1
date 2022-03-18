#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, c=1, i=1;
    scanf("%d", &n);
    int *v = malloc((2*n-1)*sizeof(int));
    v[0]=0;

    printf("Cartas descartadas: ");
    for(i=1; i<=2*n-2; i++){
        if(i<=n) v[i] = i;
        if(i==1) printf("%d", v[i]);
        else printf(", %d", v[i]);
        i++;
        if(i<=n) v[i] = i;
        v[n+c] = v[i];
        c++;
    }
    printf("\n");
    printf("Carta restante: %d\n", v[i-1]);

    return 0;
}