#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;     //vetor que representa a fila
    int N;          //tamanho do vetor
    int p;          //inicio da fila
    int u;          //fim da fila
} fila;

//considerendo a implementação de uma fila com listas estáticas (vetores), cara, não é possivel que isso daqui ta certo vtnc KKKKKKK
int desenfileira(fila *fila, int *y)
{
    //lista vazia
    if (fila->p == fila->u)
    {
        return 0;
    }
    else
    {
        *y = fila->dados[fila->p];
        fila->p++;

        return 1;
    }
}
