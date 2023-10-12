#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

//funcao que insere um node com o dado x no inicio da lista
void insere_inicio(celula *le, int x)
{
    //aloca espaço suficiente para o ponteiro
    celula *newNode = malloc(sizeof(celula));

    //atribui o valor de x
    newNode->dado = x;

    //novo node aponto para o proximo node à head da lista
    newNode->prox = le->prox;

    //head agora aponta para o novo node
    le->prox = newNode;
}

/*função que insere um elemento x imediatamente antes da primeira ocorrência de um elemento y na lista
encadeada. Se y não estiver na lista encadeada, x deve ser inserido ao final*/
void insere_antes(celula *le, int x, int y)
{
    //printf("%u\n", le->dado);
    //fim da lista ou lista vazia
    if (le->prox == NULL)
    {
        celula *newNode = malloc(sizeof(celula));
        newNode->dado = x;
        le->prox = newNode;
        newNode->prox = NULL;

        return;
    }
    //achamos o dado e inserimos o novo dado antes dele
    else if (le->prox->dado == y)
    {
        celula *newNode = malloc(sizeof(celula));
        newNode->dado = x;
        newNode->prox = le->prox;
        le->prox = newNode;
        
        return;
    }
    insere_antes(le->prox, x, y);
}