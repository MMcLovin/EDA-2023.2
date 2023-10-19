#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int *dados;        //duh
    int N;             //capacidade maxima da pilha
    int topo;          //aqui o topo eh sempre a primeira posição livre da pilha, logo, topo = 0 é uma pilha vazia
} pilha;

int desempilha(pilha *p, int *y)
{
    //pilha vazia ou topo invalido
    if (p->topo == 0 || p->topo > p->N || p->topo < 0)
    {
        //printf("Nao foi possivel desempilhar pois a pilha esta vazia :(\n");
        return 0;
    }
    
    *y = p->dados[p->topo - 1];
    p->topo--;

    return 1;
}

/*
int imprimePilha(pilha *p)
{
    for (int i = 0; i < p->topo; i++)
    {
        printf("%d ", p->dados[i]);
    }
    
    printf("\n");

    return 0;
}

int desempilhaTudo(pilha *p)
{
    for (int i = p->topo; i >= 0; i--)
    {
        int *y = malloc(sizeof(int));
        desempilha(p, y);
        printf("elemento desempilhado = %d\n", *y);
        imprimePilha(p);
        free(y);
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

    int v1[] = {0, 1, 2, 3, 4};
    int v2[] = {0};
    int v3[] = {0,1};

    pilha *p1 = criaPilha(v1, 5, 5);
    printf("pilha original\n");
    imprimePilha(p1);
    desempilhaTudo(p1);

    pilha *p2 = criaPilha(v1, 5, 5);
    imprimePilha(p2);
    desempilhaTudo(p2);

    pilha *p3 = criaPilha(v1, 5, 5);
    imprimePilha(p3);
    desempilhaTudo(p3);
    //
    return 0;
}
//*/