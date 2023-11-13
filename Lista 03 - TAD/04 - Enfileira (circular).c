#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int enfileira(fila *f, int x)
{
    //a fila esta cheia e u vem antes de p
    if (f->u + 1 == f->p)
    {
        f->dados = realloc(f->dados, sizeof(int) * (f->N * 2));

        int j = 0;

        //jogamos os dados de dados[0] a dados[u - 1] para o fim da fila
        for (; j + 1 != f->p; j++)
        {
            f->dados[f->N + j] = f->dados[j];
        }

        //não precisa incrementar +1 pois o for já realiza uma soma além do necessário
        f->u = j + f->N;
        f->N = f->N * 2;
    }
    //a fila esta cheia, mas inicio (p) esta em 0 e o final (u) esta 1 unidade alem da ultima posicao do vetor = N
    else if (f->u - f->p == f->N)
    {
        f->N = f->N * 2;
        f->dados = realloc(f->dados, sizeof(int) * f->N);
    }

    if(f->u == f->N) f->u = 0;

    f->dados[f->u] = x;

    f->u++;

    return 1;
}