#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado; 
    struct celula *prox;
} celula;


/*void imprime_rec(celula *le)
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
}*/


void mescla_listas(celula *l1, celula *l2, celula *l_destino)
{
    //ja retiramos e ordenamos todos os itens das duas, que eh a nossa condicao de parada da recursao
    if (l1->prox == NULL && l2->prox == NULL)
    {
        l_destino->prox = NULL;

        return;
    }

    //acabaram os nós somente da primeira lista, podemos usar todos os elementos da segunda lista, pois ja estao em ordem crescente
    if (l1->prox == NULL)
    {
        //int debuggingVar3 = l2->prox->dado;
        l_destino->prox = l2->prox;
        l2->prox = l2->prox->prox;

        return mescla_listas(l1,l2,l_destino->prox);

        //esse return eh importante pois depois da chamada acima ter sido executada, quer dizer que a minha lista ja foi ordenanda e meu codigo nao deve executar mais nada, apenas sair da funcao 
        //return;
    }
    //acabaram os nós somente da segunda lista, podemos usar todos os elementos da primeira lista, pois ja estao em ordem crescente
    else if (l2->prox == NULL)
    {
        int debuggingVar1 = l1->prox->dado;
        l_destino->prox = l1->prox;
        l1->prox = l1->prox->prox;

        return mescla_listas(l1,l2,l_destino->prox);
        //return;
    }
    //int debuggingVar1 = l1->prox->dado;
    //int debuggingVar2 = l2->prox->dado;

    //ambas as listas ainda possuem elementos
    if (l1->prox->dado <= l2->prox->dado)
    {
        //elemento atual da minha lista de destino, aponta para o proximo menor elemento entre as duas listas
        l_destino->prox = l1->prox;
        //remove o menor elemento de sua lista original
        l1->prox = l1->prox->prox;
    }
    //o elemento de l2 eh menor e segue a mesma logica do if acima
    else
    {
        l_destino->prox = l2->prox;
        l2->prox = l2->prox->prox;
    }

    //como modificamos l1 ou l2, retirando o menor elemento, podemos passar as listas "inteiras" como parametros. Ja para a lista final, passamos o prox elemento, ja que ele fara o papel de 'cabeca' da proxima chamada
    mescla_listas(l1, l2, l_destino->prox);
}

/*
celula *criacelula(int x)
{
    celula *newcelula;
    newcelula = malloc(sizeof(celula));
    newcelula->prox = NULL;
    newcelula->dado = x;

    return newcelula;
}

void criaLista(celula *head, int i, int n)
{
    for (; i >= n; i--)
    {
        int dado;
        //scanf("%d", dado);
        if (i>6)
        {
            dado = 3;
        }
        else
        {
            dado = i;
        }

        celula *node = criacelula(dado);
        node->prox = head->prox;
        head->prox = node;
    }
}

int main()
{
    celula *l1_Head = criacelula(-1);
    celula *l2_Head = criacelula(-1);
    celula *l3_Head = criacelula(-1);
    criaLista(l1_Head, 1, 0);
    criaLista(l2_Head, 3, 2);

    printf("Lista 01 original \nl1 -> ");
    imprime_rec(l1_Head);
    printf("Lista 02 original \nl2 -> ");
    imprime_rec(l2_Head);

    mescla_listas(l1_Head, l2_Head, l3_Head);

    printf("\nLista de destino totalmente mesclada\n");
    imprime_rec(l3_Head);

    return 0;
}
*/