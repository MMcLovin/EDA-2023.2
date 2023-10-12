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
/* void imprime_rec(celula *le)
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
    
    int input = 1;
    while (input != 0)
    {
        int i = 0;
        int n = 5;
        
        celula *head = criacelula(-1);

        //cria uma lista com n celulas, incluindo a cabeça
        for (; i < n; i++)
        {
            //scanf("%d", dado);
            int dado = i;
            celula *node = criacelula(dado);
            node->prox = head->prox;
            head->prox = node;
        }

        printf("lista original\n");
        imprime_rec(head);

        int x,y;

        printf("valor 'x' a ser inserido: \n");
        scanf("%d", &x);

        printf("Valor de 'y' (x sera inserido antes de y, y<0 = insere no inicio): \n");
        scanf("%d", &y);
        
        if (y >= 0)
        {
            printf("\ninsercao antes de y\n");
            insere_antes(head, x, y);
        }
        else
        {
            printf("\ninsercao no inicio da lista\n");
            insere_inicio(head, x);
        }
        
        printf("lista apos a insercao\n");
        imprime_rec(head);
        printf("\nDeseja continuar? 0 = nao, 1 = sim\n");
        scanf("%d", &input);
        printf("\n");
    }
    return 0;
}  */