#include <stdio.h>

int checkHeapOrder(int *heap, int size)
{
    int N = size / 2;
    int correctNodes = 0;

    for (int i = 1; i <= N; i++)
    {
        //noh raiz eh maior que seus dois filhos
        //a quantidade de noh internos eh igual a floor(N)/2
        if (heap[i] >= heap[2*i] && heap[i] >= heap[(2*i) + 1])
        {
            correctNodes++;       
        }
    }

    if (correctNodes == N) return 1;
    else return 0;
}

int testeN = 1;

void testaHeapOrder(int *heap, int size)
{
    int result = checkHeapOrder(heap, size);
    if (result) printf("\n%d - Em ordem decrescente :)\n", testeN++);
    else printf("\n%d - Nao esta em ordem decrescente :)\n", testeN++);
}

int main()
{
    int size = 4;
    int heap1[] = {-1, 1, 2, 3, 4};
    int heap2[] = {-1, 5, 4, 3, 2};
    int heap3[] = {-1, 5, 3, 4, 2};
    int heap4[] = {-1, 5, 5, 5, 5};
    int heap5[] = {-1, 5, 1, 2, 3};
    int heap6[] = {-1, 5, 2, 1, 4};

    testaHeapOrder(heap1, size);
    testaHeapOrder(heap2, size);
    testaHeapOrder(heap3, size);
    testaHeapOrder(heap4, size);
    testaHeapOrder(heap5, size);
    testaHeapOrder(heap6, size);

    return 0;
}