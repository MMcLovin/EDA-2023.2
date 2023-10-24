#include <stdio.h>
#include <stdlib.h>

//obs: fila circular
typedef struct fila {
    int *dados;
    int N;
    int p;
    int u;//fim da fila
} fila;

int desenfileira(fila *f, int *y)
{
    if (f->p == f->u)
    {
        return 0;
    }

    *y = f->dados[f->p];
    f->p++;
    //o elemento na posicao n - 1 foi retirado e p deve voltar para o incio do vetor
    if (f->p == f->N) f->p = 0;

    return 1;
}