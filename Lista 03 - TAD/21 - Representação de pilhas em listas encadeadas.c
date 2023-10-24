#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int desempilha(celula *p, int *y)
{
    if(p->prox == NULL)
    {
        return 0;
    }
    
    *y = p->prox->dado;
    p->prox = p->prox->prox;

    return 1;
}

int empilha(celula *p, int x)
{
    celula *node = malloc(sizeof(celula));
    node->prox = p->prox;
    p->prox = node;
    node->dado = x;

    return 1;
}