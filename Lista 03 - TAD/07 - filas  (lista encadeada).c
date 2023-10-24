#include <stdio.h>
#include <stdlib.h>

//lista encadeada circular
typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void enfileira(celula **fila, int x)
{
    celula *newHead = malloc(sizeof(celula));
    
    //se a fila estiver vazia: fila->prox == fila 
    newHead->prox = (*fila)->prox;
    (*fila)->prox = newHead;
    (*fila)->dado = x;

    *fila = newHead;
}

int desenfileira(celula *fila, int *y)
{
    if (fila->prox == fila)
    {
        return 0;
    }
    
    *y = fila->prox->dado;
    fila->prox = fila->prox->prox;

    return 1;
}

/*
int main()
{
    celula **f = malloc(sizeof(celula));
    enfileira(f, 69);
    printf("%d\n", (*f)->prox->dado);

    return 0;
}
*/