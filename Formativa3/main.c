#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

void menu(int *op){
    printf("\nSelecione uma operação\n");
    printf("1 - Criar lista\n");
    printf("2 - Inserir elemento no inicio\n");
    printf("3 - Remover primeiro elemento\n");
    printf("4 - Imprimir lista\n");
    printf("5 - Destruir lista\n");
    printf("6 - Buscar elemento\n");
    printf("0 - Sair\n");
    printf("Digite sua opção: ");
    scanf("%d", op);
    printf("\n");
}

int main(){

    int dado, op;
    celula *le = malloc(sizeof(celula));
    celula *elem1 = malloc(sizeof(celula));
    celula *elem2 = malloc(sizeof(celula));
    celula *elem3 = malloc(sizeof(celula));
    celula *elem4 = malloc(sizeof(celula));

    le->prox = elem1;
    elem1->dado=1;
    elem1->prox=elem2;
    elem2->dado=2;
    elem2->prox=elem3;
    elem3->dado=3;
    elem3->prox=elem4;
    elem4->dado=1;
    elem4->prox=NULL;

    insere_antes(le, 4, 4);
    imprime(le);
    printf("\n");
    /*celula *ptr = malloc(sizeof(celula));
    ptr->prox = NULL;
    menu(&op);
    while(op!=0){
        switch (op)
        {
        case 1:
        le = criar_lista();
            break;
        case 2:
        printf("Digite um novo dado: ");
        scanf("%d", &dado);
        if(inserir(le,dado))
            printf("Elemento inserido com sucesso.\n");
        else{
            printf("Problema na hora de inserir.\n");
            return 1;
        }
            break;
        case 3:
        if(remover(le,&dado))
            printf("Elemento removido: %d.\n", dado);
        else{
            printf("Lista vazia.\n");
            return 1;
        }
            break;
        case 4:
        imprime(le);
            break;
        case 5:
        le=destruir_lista(le);
            break;
        case 6:
        printf("Escolha um dado para buscar: ");
        scanf("%d", &x);
        ptr=busca(le, x);
        printf("usando busca: ");
        imprime(ptr);
        ptr=busca_rec(le, x);
        printf("usando busca_rec: ");
        imprime(ptr);
            break;
        }
        
        menu(&op);
    }*/

    return 0;
}