#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

//nao tem como ter uma fila cheia na implementação com listas
//considerando que estamos implementando uma fila como uma lista encadeada circular
celula *enfileira(celula *fila, int x)
{
    celula *newHead = malloc(sizeof(celula));
    
    //se a fila estiver vazia: fila->prox == fila 
    newHead->prox = fila->prox;
    fila->prox = newHead;
    fila->dado = x;

    return newHead;
}

/*
celula *criacelula(int x){
    celula *newcelula = malloc(sizeof(celula));
    newcelula->prox = NULL;
    newcelula->dado = x;

    return newcelula;
}

void imprime_rec(celula *le){
    celula *node = le->prox;

    if (node == NULL)
    {
        printf("NULL\n");
        return;
    }
    else
    {
        printf("%d -> ", node->dado);
        imprime_rec(le->prox);
    }
}

int main()
{
    celula *fila = criacelula(-1);
    int n = 4;

    printf("fila original\n");
    imprime_rec(fila);

    for (int i = 0; i < n; i++)
    {
        enfileira(fila, i);
        //enfileira_rec(fila, i);
        //colocanafila(fila, i);
        printf("fila enfileirada com: %d\n", i);
        imprime_rec(fila);
    }

    return 0;
}
//*/
//*/