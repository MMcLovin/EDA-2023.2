#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void divide_lista(celula *l, celula *lImPar, celula *lPar)
{
    if (l->prox == NULL)
    {
        lPar->prox = NULL;
        lImPar->prox = NULL;
        return;
    }
    else if (l->prox->dado % 2 == 0)
    {
        lPar->prox = l->prox;
        l->prox = l->prox->prox;
        divide_lista(l, lImPar, lPar->prox);
    }
    else
    {
        lImPar->prox = l->prox;
        l->prox = l->prox->prox;
        divide_lista(l, lImPar->prox, lPar);
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

//testando as funções
int main()
{
    int i = 0;
    int n = 7;
    
    celula *head = criacelula(-1);
    criaLista(head, n);

    celula *lPar = criacelula(-1);
    celula *limpar = criacelula(-1);

    printf("lista original\n");
    imprime_rec(head);
    printf("\n");

    divide_lista(head, limpar, lPar);

    printf("\n****** lista Impar Final ******\n");
    imprime_rec(limpar);
    printf("\n****** lista par Final ******\n");
    imprime_rec(lPar);
    
    return 0;
}  

//*/