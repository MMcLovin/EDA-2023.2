#include <stdio.h>
#include <stdlib.h>
#define N 1000

int bubbleSort(int *v, int i)
{
    int flag = 1;

    while (flag)
    {
        flag = 0;

        for (int j = 0; j + 1 < i; j++)
        {
            if (v[j] > v[j + 1])
            {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                flag++;
            }
        }
        if (flag != 0) flag = 1;
    }

    return 0;
}

int main()
{
    int *vet = malloc(sizeof(int) * N);
    int elemento;
    int i = 0;

    while (scanf("%d", &elemento) != EOF)
    {
        vet[i++] = elemento;
    }

    bubbleSort(vet, i);

    for (int j = 0; j < i; j++)
    {
        if (j + 1 == i) printf("%d\n", vet[j]);
        else printf("%d ", vet[j]);
    }
}