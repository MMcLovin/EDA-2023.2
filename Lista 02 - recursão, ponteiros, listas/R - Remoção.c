#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

//remove o primeiro elemento apos o endereco de le
int remove_depois(celula *le)
{
    //nao e possivel retirar o proximo elemento pois ele nao existe
    if (le->prox == NULL)
    {
        return 1;
    }
    else
    {
        le->prox = le->prox->prox;
        return 0;
    }
}

//remove a primeira instancia com dado igual a x
void remove_elemento(celula *le, int x)
{
    if (le->prox == NULL)
    {
        return;
    }
    else if (le->prox->dado == x)
    {
        le->prox = le->prox->prox;
        return;
    }
    remove_elemento(le->prox, x);
}

//remove todos as celulas com dado igual a x
void remove_todos_elementos(celula *le, int x)
{
    if (le == NULL || le->prox == NULL)
    {
        return;
    }
    else if (le->prox->dado == x)
    {
        le->prox = le->prox->prox;
        remove_todos_elementos(le, x);
    }
    else
    {
        remove_todos_elementos(le->prox, x);
    }
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

void criaLista(celula *head, int n)
{
    //celula *a = criacelula(1);
    //celula *b = criacelula(2);
    //celula *c = criacelula(1);
    //celula *d = criacelula(4);
    //celula *e = criacelula(1);
    //celula *f = criacelula(6);
    //head->prox = a;
    //a->prox = b;
    //b->prox = c;
    //c->prox = d;
    //d->prox = e;
    //e->prox = f;
    //f->prox = NULL;
    for (int i = 0; i < n; i++)
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

int main()
{
    int n = 8;
    
    celula *head = criacelula(-1);

    //cria uma lista, a partir de head, com n celulas
    criaLista(head, n);

    printf("lista original\n");
    imprime_rec(head);
    
    int input;
    scanf("%d",&input);
    //celula *b = head->prox;
    //remove_depois(b);
    //remove_elemento(head, input);
    remove_todos_elementos_rec(head, input);
    
    printf("lista apos remocao\n");
    imprime_rec(head);
    
    return 0;
}
*/