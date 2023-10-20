#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;    
} celula;

//considerando que estamos implementando uma fila com uma 
//***** TUDO ERRDADO "lista simplesmente encadeada, onde as inserções são sempre realizadas ao final da lista (elementos mais novos sao os mais proximos da head) e as remocões no inicio da lista (elementos mais velhos são os mais distantes da head" TUDO ERRDADO ***** 
//a implementação é feita com uma lista encadead simples e circular, onde a cabeça original é transformada no elemento inserido, criando-se uma nova celula que será a nova cabeça, que sempre aponta para o último elemento 
int desenfileira(celula *fila, int *y)
{
    if (fila->prox == fila || fila->prox == NULL)
    {
        return 0;
    }
    
    *y = fila->prox->dado;
    fila->prox = fila->prox->prox;

    return 1;
}