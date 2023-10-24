#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int lado;
    struct celula *prox;
} celula;

celula *criaCelula(char L)
{
    celula *node = malloc(sizeof(celula));
    node->lado = L;
    node->prox = NULL;

    return node;
}

int empilha(celula *p, char L)
{
    celula *node = criaCelula(L);

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

    int x = p->prox->lado;
    p->prox = p->prox->prox;

    return x;
}

int isVazia(celula *p)
{
    if (p->prox == NULL)
    {
        return 1;
    }

    return 0;
}

void criaPilhas(celula *p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = malloc(sizeof(celula));
        p[i]->prox = NULL;
    }
}

int main()
{
    int M;
    int pares = 0;
    int pe;
    char L; //lado do pe da bota. 'D' = pé direito & 'E' = pé esquerdo

    //vetor de pilhas, 1 pilha para cada numeração
    celula *botas[32];
    criaPilhas(botas, 32);

    while (scanf("%d %c", &M, &L) != EOF)
    {
        //ainda nao tinha nenhum par daquela numeração
        if (isVazia(botas[M - 30]))
        {
            empilha(botas[M - 30], L);
        }
        //tem uma bota salva na pilha da numeração correspondente
        else
        {
            //pega o lado da bota no topo
            pe = desempilha(botas[M - 30]);

            //se os lados forem diferentes, temos um par
            if (pe != L)
            {
                pares++;
            }
            //Se forem iguais, empilha devolta o desempilhado mais o atual que foi lido
            else
            {
                empilha(botas[M - 30], pe);
                empilha(botas[M - 30], L);
            }
        }
    }

    printf("%d\n", pares);

    return 0;
}