#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int tamanho;
    char lado;
    int comparada;
    struct celula *prox;
} celula;

celula *criaCelula(int M, char L)
{
    celula *node = malloc(sizeof(celula));
    node->lado = L;
    node->tamanho = M;
    node->prox = NULL;
    node->comparada = 0;

    return node;
}

int empilha(celula *p, int M, char L)
{
    celula *node = criaCelula(M, L);

    node->prox = p->prox;
    p->prox = node;

    return 1;
}

int desempilha(celula *p)
{
    if (p->prox == NULL)
    {
        return 0;
    }

    p->prox = p->prox->prox;

    return 1;
}

int contaPares(celula *cTopo, celula *c)
{
    if (cTopo == NULL || c == NULL)
    {
        return 0;
    }

    if (cTopo->tamanho == c->tamanho && (cTopo->comparada + c->comparada == 0))
    {
        if(cTopo->lado == 'D' && c->lado == 'E')
        {
            cTopo->comparada = 1;
            c->comparada = 1;

            return 1;
        }
        else if (cTopo->lado == 'E' && c->lado == 'D')
        {
            cTopo->comparada = 1;
            c->comparada = 1;

            return 1;
        }
    }

    return contaPares(cTopo, c->prox);
}

int isVazia(celula *p)
{
    if (p->prox == NULL)
    {
        return 1;
    }

    return 0;
}

int main()
{
    int M;
    int pares = 0;
    char L; //lado do pe da bota. 'D' = pé direito & 'E' = pé esquerdo
    celula *botas = criaCelula(-1, '1');

    while (scanf("%d %c", &M, &L) != EOF)
    {
        if (L == 'D' || L == 'E')
        {
            if (M >= 30 && M <=60)
            {
                empilha(botas, M, L);
            }
        }
    }

    while (!isVazia(botas))
    {
        if (contaPares(botas->prox, botas->prox->prox)) pares++;
        desempilha(botas);
    }

    printf("%d\n", pares);

    return 0;
}