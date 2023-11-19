#include <stdio.h>
#include <stdlib.h>
#define N 1000

void selection_sort(int v[], int left, int right)
{
    for (int i = left; i < right; i++)
    {
        int min = i;

        for (int j = i + 1; j <= right; j++)
        {
            if (v[j] < v[min]) min = j;
        }

        if (v[i] != v[min])
        {
            int temp = v[i];
            v[i] = v[min];
            v[min] = temp;
        }
    }
}

void imprimeVetor(int v[], int tam)
{
    for (int j = 0; j < tam; j++)
    {
        if (j + 1 == tam) printf("%d\n", v[j]);
        else printf("%d ", v[j]);
    }
}

int main()
{
    int *v = malloc(sizeof(int) * N);
    int elemento;
    int i = 0;

    
    while (scanf("%d", &elemento) != EOF)
    {
        v[i++] = elemento;
    }

    int left = 0;
    int right = i - 1;

    selection_sort(v, left, right);
    imprimeVetor(v, i);
}