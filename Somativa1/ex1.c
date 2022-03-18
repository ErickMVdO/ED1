#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ordena(int *v, int n){
    
    int aux, aux1;

    for(int j=0; j<10; j++){
      int z=0,u=0,d=0,t=0,q=0,c=0,s=0,st=0,o=0,nv=0;

    int *zero = malloc(n*sizeof(int));
    int *um = malloc(n*sizeof(int));
    int *dois = malloc(n*sizeof(int));
    int *tres = malloc(n*sizeof(int));
    int *quatro = malloc(n*sizeof(int));
    int *cinco = malloc(n*sizeof(int));
    int *seis = malloc(n*sizeof(int));
    int *sete = malloc(n*sizeof(int));
    int *oito = malloc(n*sizeof(int));
    int *nove = malloc(n*sizeof(int));

        int k=0, l=0, zeroso=0;
        aux1 = pow(10,j);
        aux = pow(10,j+1);
    for(int i=0; i<n; i++){

        if(v[i]==0){
          zeroso++;
          k++;
        }  
        else if(((v[i]%aux)/aux1)==0){
            zero[z]=v[i];
            z++;
            k++;
        }
        else if(((v[i]%aux)/aux1)==1){
            um[u]=v[i];
            u++;
            k++;
        }
        else if(((v[i]%aux)/aux1)==2){
            dois[d]=v[i];
            d++;
            k++;
        }
        else if(((v[i]%aux)/aux1)==3){
            tres[t]=v[i];
            t++;
            k++;
        }
        else if(((v[i]%aux)/aux1)==4){
            quatro[q]=v[i];
            q++;
            k++;
        }
        else if(((v[i]%aux)/aux1)==5){
            cinco[c]=v[i];
            c++;
            k++;
        }
        else if(((v[i]%aux)/aux1)==6){
            seis[s]=v[i];
            s++;
            k++;
        }
        else if(((v[i]%aux)/aux1)==7){
            sete[st]=v[i];
            st++;
            k++;
        }
        else if(((v[i]%aux)/aux1)==8){
            oito[o]=v[i];
            o++;
            k++;
        }
        else if(((v[i]%aux)/aux1)==9){
            nove[nv]=v[i];
            nv++;
            k++;
        }
    }
    for(int i=0; i<zeroso && zeroso!=0; i++){
      v[l]=0;
      l++;
    }
    for(int i=0; zero[i]!='\0'; i++){
      v[l]=zero[i];
      l++;
    }
    for(int i=0; um[i]!='\0'; i++){
      v[l]=um[i];
      l++;
    }
    for(int i=0; dois[i]!='\0'; i++){
      v[l]=dois[i];
      l++;
    }
    for(int i=0; tres[i]!='\0'; i++){
      v[l]=tres[i];
      l++;
    }
    for(int i=0; quatro[i]!='\0'; i++){
      v[l]=quatro[i];
      l++;
    }
    for(int i=0; cinco[i]!='\0'; i++){
      v[l]=cinco[i];
      l++;
    }
    for(int i=0; seis[i]!='\0'; i++){
      v[l]=seis[i];
      l++;
    }
    for(int i=0; sete[i]!='\0'; i++){
      v[l]=sete[i];
      l++;
    }
    for(int i=0; oito[i]!='\0'; i++){
      v[l]=oito[i];
      l++;
    }
    for(int i=0; nove[i]!='\0'; i++){
      v[l]=nove[i];
      l++;
    }
    if(k==0){
        j=10;
    }
    }

}

int main(){

    int n;
    scanf("%d", &n);
    int *v = malloc(n*sizeof(int));

    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    ordena(v, n);
    for(int i=0; i<n; i++){
      if(i!=n-1)
        printf("%d ", v[i]);
      else
        printf("%d", v[i]);
    }
    printf("\n");
    

    return 0;
}