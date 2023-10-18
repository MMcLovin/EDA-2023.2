#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct {
    int *dados;     //vetor que representa a fila
    int N;          //tamanho do vetor
    int p;          //inicio da fila
    int u;          //fim da fila
} fila;

int desenfileira(fila *fila, int *y)
{
    if (fila->p == fila->u)
    {
        return 0;
    }
    else
    {
        *y = fila->dados[fila->p];
        fila->p = (fila->p + 1) % fila->N;
        return 0;
    }
}
