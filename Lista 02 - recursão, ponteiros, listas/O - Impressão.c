#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le)
{
    celula *node = le->prox;

    for (; node != NULL;)
    {
        printf("%d -> ", node->dado);
        node = node->prox;
    }

    printf("NULL\n");
}

void imprime_rec(celula *le)
{
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

/* //testando as funções
celula *criacelula(int x)
{
    celula *newcelula;
    newcelula = malloc(sizeof(celula));
    newcelula->prox = NULL;
    newcelula->dado = x;

    return newcelula;
}

int main()
{
    int i = 0;
    int n = 4;
    celula *head = criacelula(-1);

    //cria uma lista com n celulas, incluindo a cabeça
    for (; i < n; i++)
    {
        //scanf("%d", dado);
        int dado = i*14;
        celula *node = criacelula(dado);
        node->prox = head->prox;
        head->prox = node;
    }

    imprime(head);
    imprime_rec(head);
    
    return 0;
}
  */