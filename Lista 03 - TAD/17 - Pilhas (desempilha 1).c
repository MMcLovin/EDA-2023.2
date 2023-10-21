#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

//KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK
//eh so isso msm
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