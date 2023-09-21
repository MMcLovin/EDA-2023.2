#include <stdio.h>

void imprimePar(int *vetor, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (vetor[i] % 2 == 0)
        {
            printf("%d ", i);
        } 
    }
}

void imprimeImpar(int *vetor, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (vetor[i] % 2 != 0)
        {
            printf("%d ", i);
        } 
    }
}

int main() {
    int tamanho;

    scanf("%d", &tamanho);
    
    int vetor[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        int elemento;
        scanf("%d", &elemento);
        vetor[i] = elemento;
    }
    imprimePar(vetor, tamanho);
    printf("\n");
    imprimeImpar(vetor, tamanho);

    return 0;
}