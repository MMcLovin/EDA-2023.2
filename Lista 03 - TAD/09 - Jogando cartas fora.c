#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

typedef struct pilha {
    int numItens;
    struct celula *topo;
    struct celula *ultimo;
} pilha;

typedef struct fila {
    int *dados;
    int inicio;
    int fim;
} fila;

int imprimePilha(celula *p)
{
    if (p == NULL)
    {
        printf("\n");
        return 1;
    }

    printf("%d ", p->dado);
    imprimePilha(p->prox);

    return 0;
}

celula *criaCelula(int x)
{
    celula *node = malloc(sizeof(celula));
    node->prox = NULL;
    node->dado = x;

    return node;
}

pilha *criaPilha()
{
    pilha *p = malloc(sizeof(pilha));
    p->topo = NULL;
    p->ultimo = NULL;
    p->numItens = 0;

    return p;
}

void empilha(pilha *p, int x)
{
    celula *node = criaCelula(x);

    if (p->ultimo == NULL)
    {
        p->ultimo = node;
    }

    node->prox = p->topo;
    p->topo = node;
    p->numItens++;
}

int desempilha(pilha *p, int *itemRetirado)
{
    if (p->topo == NULL)
    {
        return 1;
    }

    *itemRetirado = p->topo->dado;
    p->topo = p->topo->prox;

    return 1;
}

void movePra_Base(pilha *p)
{
    if(p->topo->prox != NULL)
    {
        int *x = malloc(sizeof(int));
        desempilha(p, x);
        celula *novoUltimo = criaCelula(*x);
        p->ultimo->prox = novoUltimo;
        p->ultimo = novoUltimo;
        free(x);
    }
}

void enfileira(fila *f, int *x)
{
    f->dados[f->fim++] = *x;
}

void desenfileira(fila *f)
{
    printf("Cartas descartadas: ");

    for (; f->inicio < f->fim; f->inicio++)
    {
        if (f->inicio + 1 == f->fim)
        {
            printf("%d\n", f->dados[f->inicio]);
        }
        else
        {
            printf("%d, ", f->dados[f->inicio]);
        }
    }
}

int main()
{
    int nCartas;

    scanf("%d", &nCartas);

    pilha *deck = criaPilha();
    fila *cartasRemovidas = malloc(sizeof(fila));
    cartasRemovidas->inicio = 0;
    cartasRemovidas->fim = 0;
    cartasRemovidas->dados = malloc(sizeof(int)*nCartas);

    for (int i = nCartas; i > 0; i--)
    {
        empilha(deck, i);
    }

    while (deck->numItens >= 2)
    {
        int *carta = malloc(sizeof(int));

        desempilha(deck, carta);
        enfileira(cartasRemovidas, carta);
        movePra_Base(deck);
        deck->numItens--;

        free(carta);
    }

    desenfileira(cartasRemovidas);
    printf("Carta restante: %d", deck->topo->dado);

    return 0;
}