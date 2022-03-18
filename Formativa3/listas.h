typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

celula *criar_lista();
int insere_inicio(celula *le, int x);
void insere_antes(celula *le, int x, int y);
void remove_depois(celula *p);
void remove_elemento (celula *le, int x);
void remove_todos_elementos(celula *le, int x);
void imprime(celula *le);
void imprime_rec(celula *le);
celula *destruir_lista(celula *le);
celula *busca (celula *le, int x);
celula *busca_rec (celula *le, int x);