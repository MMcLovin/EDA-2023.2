#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

//usando listas n é possivel ter uma lista cheia
//implementar uma pilha usando listas encadeadas, é nada mais nada menos do que usar listas simplesmente encadeadas, sempre realizando tanto as inserções quanto remoções na cabeça da lista 
int empilha(celula *p, int x)
{
    celula *node = malloc(sizeof(celula));
    node->prox = p->prox;
    p->prox = node;
    node->dado = x;

    return 1;
}