#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int *v;             //vetor que representa a fila
    int N;              //tamanho da fila
    int inicio;
    int fim;    //indices de inicio e fim da fila
} fila;

int enfileira(fila *f, int x)
{
    //fila ta cheia e precisamos redimensionar
    if (f->fim == f->N)
    {
        //alocando memoria para um fila 2x maior
        f->N = f->N*2;
        int *novoV = malloc(sizeof(int)*f->N);

        int j = 0;
        //copiando os valores da fila original para a nova fila
        for (int i = 0; i < f->fim; i++, j++)
        {
            novoV[j] = f->v[i];
        }

        //liberando o espaço reservado para a fila original
        free(f->v);

        //faz a copia dos vetores 
        f->v = novoV;

        //enfila x e incrementa o fim (u)
        f->v[f->fim] = x;
        f->fim++;

        return 0;
    }
    else
    {
        f->v[f->fim] = x;
        f->fim++;
        return 0;
    }
}

/*
fila *criaFila(int p, int u, int size)
{
    fila *f = malloc(sizeof(fila));
    f->inicio = p;
    f->fim = u ;
    f->N = size;
    f->v = malloc(sizeof(int)*f->N);

    int j = 0;
    for(int i = f->inicio; i < f->fim; i++, j++)
    {
        f->v[i] = j;
    }
    return f;
}
void imprimeFilaEstatica(fila *f)
{
    for (int i = 0; i < f->N; i++)
    {
        printf("%d -> ", f->v[i]);
    }
    printf("\n");
}

void enfileiraVarios(fila *f, int n)
{
    for (int i = 0; i < n; i++)
    {
        enfileira(f,4+i);
        printf("fim = %d\n",f->fim);
        imprimeFilaEstatica(f);
    }
}

int main()
{
    fila *f = criaFila(0, 4, 5);
    imprimeFilaEstatica(f);
    enfileiraVarios(f, 2);
    imprimeFilaEstatica(f);
}
*/