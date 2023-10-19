#include <stdio.h>
#include <stdlib.h>

typedef struct pilhaEstatica {
    int *dados;
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
    //pilha cheia = redimensionar dados para 2*N
    else if (p->topo == p->N)
    {
        //alocamos um espaço 2x maior q a pilha atual
        p->N = p->N * 2;
        int *novoDados = malloc(sizeof(int) * p->N);

        //copia os dados pilha da antiga para a nova
        for (int i = 0; i < p->topo; i++)
        {
            novoDados[i] = p->dados[i];
        }

        p->dados = novoDados;
    }

    p->dados[p->topo] = x;
    p->topo++;

    return 1;
}

/*
int imprimePilha(pilha *p)
{
    printf("topo = %d\n", p->topo);
    printf("capacidade = %d\n", p->N);
    for (int i = 0; i < p->topo; i++)
    {
        printf("%d ", p->dados[i]);
    }

    printf("\n");

    return 0;
}

int empilhaN(pilha *p, int n)
{
    int x = p->dados[p->topo - 1] + 1;
    for (int i = 0; i < n; i++)
    {
        if(!empilha(p, x))
        {
                return 1;
        }
        else
        {
            x = p->dados[p->topo - 1] + 1;
            printf("elemento empilhado = %d\n", x);
            imprimePilha(p);
        }
    }

    return 0;
}

pilha *criaPilha(int vet[], int top, int capacity)
{
    pilha *p = malloc(sizeof(pilha));
    p->dados = vet;
    p->N = capacity;
    p->topo = top;

    return p;
}

int main()
{

    int nElementos = 6;

    int v1[6] = {0, 1, 2, 3, 4};
    int v2[6] = {};
    int v3[6] = {0,1};

    int size = 6;
    pilha *p1 = criaPilha(v1, 5, size);
    printf("pilha original\n");
    imprimePilha(p1);
    empilhaN(p1, nElementos);

    /*
    pilha *p2 = criaPilha(v2, 5, size);
    printf("pilha original\n");
    imprimePilha(p2);
    empilhaN(p2, nElementos);

    pilha *p3 = criaPilha(v3, 5, size);
    printf("pilha original\n");
    imprimePilha(p3);
    empilhaN(p3, nElementos);
    //

    return 0;
}
//*/