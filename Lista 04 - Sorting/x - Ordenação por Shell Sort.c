#include <stdio.h>
#include <stdlib.h>
#define N 1000

void shell_sort(int v[], int left, int right)
{
    int h = 1;
    while (h < ((right - left + 1) / 3)) h = (h * 3) + 1;
    
    while (h >= 1)
    {
        for (int i = left + h; i <= right; i++)
        {
            for (int j = i; (j >= left + h) && (v[j] < v[j - h]); j = j - h)
            {
                int temp = v[j];
                v[j] = v[j - h];
                v[j - h] = temp;
            }
        }  
        h = h / 3;
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
    int *vet = malloc(sizeof(int) * N);
    int elemento;
    int i = 0;

    while (scanf("%d", &elemento) != EOF)
    {
        vet[i++] = elemento;
    }

    int left = 0;
    int right = i - 1;

    shell_sort(vet, left, right);
    imprimeVetor(vet, i);
}