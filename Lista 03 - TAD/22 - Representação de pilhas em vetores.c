#include <stdio.h>
#include <stdlib.h>

typedef struct pilhaEstatica {
    int *v;
    int N;
    int topo;
} pilha;

int empilha(pilha *p, int x)
{
    //topo invalido
    if (p->topo > p->N || p->topo < 0)
    {
        return 0;
    }
    //pilha cheia = redimensionar v para 2*N de v
    else if (p->topo == p->N)
    {
        //alocamos um espaço 2x maior q a pilha atual
        p->N = p->N * 2;
        int *novoV = malloc(sizeof(int) * p->N);

        //copia os da pilha da antiga para a nova
        for (int i = 0; i < p->topo; i++)
        {
            novoV[i] = p->v[i];
        }

        p->v = novoV;
    }

    p->v[p->topo] = x;
    p->topo++;

    return 1;
}

int desempilha(pilha *p, int *y)
{
    //pilha vazia ou topo invalido
    if (p->topo == 0 || p->topo > p->N || p->topo < 0)
    {
        //printf("Nao foi possivel desempilhar pois a pilha esta vazia :(\n");
        return 0;
    }
    
    *y = p->v[p->topo - 1];
    p->topo--;

    return 1;
}