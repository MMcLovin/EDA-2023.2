#include <stdio.h>

int bubbleSort(int v[], int i)
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
        if (flag != 0)
        {
            flag = 1;
        }
        
    }

    return 0;
}

int main()
{
    int vet[] = {1,10,0,4,7,3,6,5,2,8,9};

    printf("Vetor Desordenado\n");
    for (int i = 0; i < 11; i++)
    {
        printf("%d ", vet[i]);
    }

    bubbleSort(vet, 11);

    printf("\nVetor Ordenado\n");
    for (int i = 0; i < 11; i++)
    {
        printf("%d ", vet[i]);
    }

}