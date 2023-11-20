#include <stdio.h>
#include <stdlib.h>
#define N 50000

//versão mais otimizada do insertion sort
void insertion_sort(int v[], int left, int right)
{
    int j;

    //coloca o menor item na primeira posição
    for (int i = right; i > left; i--)
    {
        if (v[i] < v[i - 1])
        {
            int aux = v[i - 1];
            v[i - 1] = v[i];
            v[i] = aux;
            //imprimeVetor(v, right + 1);   
        }
    }
    
    for (int i = left + 2; i <= right; i++)
    {
        int temp = v[i];

        //se o item atual for menor que o seu antecessor
        //a gnt empurra o antecessor pra frente
        for (j = i; temp < v[j - 1]; j--)
        {
            v[j] = v[j - 1];
            //imprimeVetor(v, right + 1);
        }

        //a instrução j = i sempre é executada, ent caso o for n tenha sido executada, o elemento é igual a ele mesmo
        //se for tiver sido executado, j é primeira posição depois do elemento menor que temp
        v[j] = temp;
        //imprimeVetor(v, right + 1);
    }
}

/*
Versão mais básica do insertion sort
void insertion_sort(int v[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        for (int j = i; j > left && v[j] < v[j - 1]; j--)
        {
            int aux = v[j];
            v[j] = v[j - 1];
            v[j - 1] = aux;
        }
    }
}
//*/
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

    insertion_sort(vet, 0, i - 1);
    imprimeVetor(vet, i);
}