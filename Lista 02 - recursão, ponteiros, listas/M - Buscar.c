#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *busca(celula *le, int x)
{
    for (; le->prox != NULL;)
    {
        if (le->dado == x)
        {
            return le;
        }
        le = le->prox;
    }

    if (le->dado == x)
    {
        return le;
    }
    
    return NULL;
}

celula *busca_rec(celula *le, int x)
{
    if (le->dado == x)
    {
        return le;
    }
    else if (le->prox == NULL)
    {
        return NULL;
    }
    return busca_rec(le->prox, x);
}

//testando as funções
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

    int x;
    while (1)
    {
        scanf("%d", &x);
        if (x != -1)
        {
            //busca por um valor arbitrário
            if (busca(head, x) != NULL)
            {
                printf("achou :) \n");
            }
            else
            {
                printf("nao achou :( \n");
            }
        }
        else
        {
            break;
        }
    }
    
    return 0;
}
 