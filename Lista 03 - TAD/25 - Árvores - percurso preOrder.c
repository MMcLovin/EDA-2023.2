#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

typedef struct celula {
    struct no *noh;
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

    no *noh = p->prox->noh;
    p->prox = p->prox->prox;

    return noh;
}

int empilha(celula *p, no *x)
{   
    celula *new = malloc(sizeof(celula));
    new->noh = x;
    new->prox = p->prox;
    p->prox = new;

    return 1;
}

void pre_ordem (no *raiz)
{
    if (raiz == NULL) return;

    celula *pilha = malloc(sizeof(celula));
    pilha->prox = NULL;
    no *x = raiz;

    empilha(pilha, raiz);

    while (!isPilhaVazia(pilha))
    {
        raiz = desempilha(pilha);

        printf("%d ", raiz->dado);

        if (raiz->dir != NULL)
        {
            empilha(pilha, raiz->dir);
        }

        if (raiz->esq != NULL)
        {
            empilha(pilha, raiz->esq);
        }
    }
    printf("\n");
}