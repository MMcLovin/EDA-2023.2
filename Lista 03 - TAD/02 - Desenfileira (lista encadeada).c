#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;    
} celula;

//considerando que estamos implementando uma fila com listas simplesmente encadeadas, onde as inserções são sempre realizadas ao final da lista (elementos mais novos) e as remocões no inicio da lista (elementos mais velhos)
int desenfileira(celula *fila, int *y)
{
    if (fila->prox == NULL)
    {
        return 0;
    }
    
    *y = fila->prox->dado;
    fila->prox = fila->prox->prox;

    return 1;
}