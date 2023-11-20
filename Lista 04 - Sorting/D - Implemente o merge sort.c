#include <stdio.h>
#include <stdlib.h>
#define N 1000000

void imprimeVetor(int v[], int tam)
{
    for (int j = 0; j < tam; j++)
    {
        if (j + 1 == tam) printf("%d\n", v[j]);
        else printf("%d ", v[j]);
    }
}

void merge(int *v, int left, int middle, int right)
{
    int tamanho = (right - left) + 1;
    int *v_aux = malloc(sizeof(int) * tamanho);
    int i = left;
    int j = middle + 1;
    int k = 0;

    for (; (i <= middle) && (j <= right); k++)
    {
        if (v[i] < v[j])
        {
            v_aux[k] = v[i++];
        }

        else v_aux[k] = v[j++];
    }

    //um dos vetores acabou e precisamos continuar a partir do outro
    if (j > right && i <= middle)
    {
        for (; i <= middle;i++)
        {
            v_aux[k++] = v[i];
        }
    }
    else if (i > middle && j <= right)
    {
        for (; j <= right ; j++)
        {
            v_aux[k++] = v[j];
        }
    }

    //copia a parte ordenada, que é o v_aux, para o vetor original
    for (int n = left, m = 0; n <= right; n++)
    {
        v[n] = v_aux[m++];
    }

    free(v_aux);
}

void merge_sort(int *v, int left, int right)
{
    if (left >= right) return;

    int middle = (right + left) / 2;

    merge_sort(v, left, middle);
    merge_sort(v, middle + 1, right);
    merge(v, left, middle, right);
}

int main()
{
    int *v = malloc(sizeof(int) * N);
    int i = 0;
    int elemento, linhas;

    scanf("%d", &linhas);

    for (; i < linhas; i++)
    {
        scanf("%d", &elemento);
        v[i] = elemento;
    }

    int left = 0;
    int right = i - 1;

    merge_sort(v, left, right);
    imprimeVetor(v, i);
    free(v);
}