#include <stdio.h>
#include <stdlib.h>
#define N 1000000
#define exch(a, b) { int temp = *(a); *(a) = *(b); *(b) = temp; }

int sort(int *v, int left, int right)
{
    int pivot = v[right];
    
    int j = left;

    for (int k = left; k < right; k++)
    {
        if (v[k] <= pivot) 
        {
            exch(&v[k], &v[j]);
            j++;
        }
    }
    
    exch(&v[right], &v[j]);

    return j;
}

void quickSort(int *v, int left, int right)
{
    if (left >= right) return;
    int middle = (right + left) / 2;
    
    //mediana de 3
    if(v[middle] > v[right]) exch(&v[middle], &v[right]);
    if(v[left] > v[middle]) exch(&v[left], &v[middle]);
    if(v[middle] > v[right]) exch(&v[middle], &v[right]);

    int pivot_index = sort(v, left, right);
    
    quickSort(v, left, pivot_index - 1);
    quickSort(v, pivot_index + 1, right);
    
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
    int *vet = malloc(sizeof(int) * N);
    int elemento, elementos;

    scanf("%d", &elementos);

    for (int i = 0; i < elementos; i++)
    {
        scanf("%d", &elemento);
        vet[i] = elemento;
    }

    int left = 0;
    int right = elementos - 1;

    quickSort(vet, left, right);
    imprimeVetor(vet, elementos);
    free(vet);

    return 0;
}