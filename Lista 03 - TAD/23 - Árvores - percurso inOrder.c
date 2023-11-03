#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

typedef struct celula {
    struct no *no;
    struct celula *prox;
} celula;

int isPilhaVazia(celula *p)
{
    if (p->prox == NULL)
    {
        return 1;
    }

    return 0;
}

no *desempilha(celula *p)
{
    if (isPilhaVazia(p)) return 0;

    no *noh = p->prox->no;
    p->prox = p->prox->prox;

    return noh;
}

int empilha(celula *p, no *x)
{   
    celula *new = malloc(sizeof(celula));
    new->no = x;
    new->prox = p->prox;
    p->prox = new;

    return 1;
}

void em_ordem (no *raiz)
{
    celula *pilha = malloc(sizeof(celula));
    pilha->prox = NULL;
    no *x = raiz;

    while (1)
    {
        while (x != NULL)
        {
            empilha(pilha, x);
            x = x->esq;
        }
        
        if (isPilhaVazia(pilha)) break;
        
        x = desempilha(pilha);
        printf("%d ", x->dado);
        x = x->dir;
    }

    printf("\n");
}