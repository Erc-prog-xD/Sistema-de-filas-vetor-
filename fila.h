typedef struct  fila Fila;

/* Criar fila vazia */
Fila * criaFila();

/*Inserir na fila vazia o primeiro valor*/
void insere(Fila *f, int valor);

/* verificar se a fila esta vazia */
int filaVazia(Fila *f);

/* verifica se a fila esta cheia */
int filaCheia(Fila *f);

/* remover o primeiro da fila */
int remova(Fila *f);

/* liberar */
void libera(Fila *f);

/* imprimir valores da fila */
void imprimirFila(Fila *f);