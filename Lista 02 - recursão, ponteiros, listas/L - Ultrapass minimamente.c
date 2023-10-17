#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

typedef struct head {
    int soma;
    int limite;
    struct celula *prox;
} head;

//cria a cabeca da minha lista
head *criaHead(int soma, int limite)
{
    head *newcelula;
    newcelula = malloc(sizeof(celula));
    newcelula->prox = NULL;
    newcelula->soma = soma;
    newcelula->limite = limite;

    return newcelula;
}

//funcao que cria e insere um node com o dado x no inicio da lista
void insere_inicio(head *le, int x)
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

void imprime_rec(celula *le)
{
    if (le == NULL)
    {
        //printf("NULL\n");
        return;
    }
    else
    {
        printf("%d\n", le->dado);
        return imprime_rec(le->prox);
    }
}

int acha_excedem_soma(int vet[], head *le, int i)
{
    //o ultimo elemento do meu vetor sempre sera 0, quando chegamos nele, a funcao acaba
    if (vet[i] == 0)
    {
        return 0;
    }

    //realiza a soma dos elementos
    le->soma = le->soma + vet[i];
    
    //se o elemento atual fez a soma ultrapassar o limite, insere ele na lista encabecada por le
    if (le->soma > le->limite)
    {
        le->soma = 0;
        insere_inicio(le, vet[i]);
    }
    
    //chamada recursiva para o proximo elemento 
    return acha_excedem_soma(vet, le, i + 1);
}

int main()
{
    int vet[1000] = {};
    int input = -1;
    int limiteSoma;

    scanf("%d", &input);

    for(int i = 0; input != 0; i++)
    {
        vet[i] = input;
        scanf("%d", &input);
    }

    scanf("%d", &limiteSoma);
    
    //lista em que a cabeca guarda metadados uteis para o programa
    head *le = criaHead(0, limiteSoma);

    acha_excedem_soma(vet, le, 0);

    imprime_rec(le->prox);

    return 0;
}