#include <stdlib.h>
#include <stdio.h>
#include "fila.h"
#define N 10

struct fila{
    int n;
    int inicio;
    float vet[N];
};

Fila * criaFila()
{
    Fila *f = (Fila*) malloc(sizeof(Fila)); 
    if(f == NULL)
    {
        printf("Memoria insuficiente");
        exit(1);
    }
    f->n = 0;
    f->inicio = 0;
    return f;
}

void insere(Fila *f, int valor){
    int fim;
    if(f->n == N)
    {
        printf("Fila cheia");
        exit(1);
    }
    fim = (f->inicio + f->n) % N;
    f->vet[fim] = valor;
    f->n++;
}
int filaVazia(Fila *f){
    return (f->n == 0);
}
int filaCheia(Fila *f){
    return (f->n == N);
}
int remova(Fila *f)
{
    int valor;
    if(filaVazia(f))
    {
        printf("Fila vazia\n");
        exit(1);
    }
    valor = f->vet[f->inicio];
    f->inicio = (f->inicio + 1) % N;
    f->n--;
    return valor;
}

void libera(Fila *f){
free(f);
}

void imprimirFila(Fila *f){
    if(filaVazia(f))
    {
        printf("Fila esta vazia");
        return;
    }
    for (int i = 0; i < f->n; i++)
    {
        printf("%.2f <-", f->vet[(f->inicio + i) % N]);
    }
    
}