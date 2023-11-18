#include <stdio.h>
#include <stdlib.h>
#define N 1000

//left = first element index
//right = last element index
int bubbleSort(int *v, int left, int right)
{
    int flag = 1;

    for (; right > left && flag; right--)
    {
        for (int i = left; i < right; i++)
        {
            if (v[i] > v[i + 1])
            {
                int aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
            }
        }
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

    bubbleSort(vet, 0, i - 1);

    for (int j = 0; j < i; j++)
    {
        if (j + 1 == i) printf("%d\n", vet[j]);
        else printf("%d ", vet[j]);
    }
}