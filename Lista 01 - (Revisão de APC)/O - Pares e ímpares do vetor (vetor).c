#include <stdio.h>

int main() {
    
    int vetSize;

    scanf("%d", &vetSize);

    int vet[vetSize];
    int vetPar[vetSize];
    int vetImpar[vetSize];

    for(int i = 0; i < vetSize; i++)
    //le os n elementos do vetor
    {
        int input;
        scanf("%d", &input);
        vet[i] = input;
    }

    int j = 0, k = 0;
    
    for (int i = 0; i < vetSize; i++)
    //varre vetor
    {
        if (vet[i] % 2 == 0)
        {
            //eh par
            vetPar[j] = vet[i];
            j++;
        }
        else
        {
            //eh impar
            vetImpar[k] = vet[i];
            k++;
        }
        
    }

    //imprime par
    for (int i = 0; i < j; i++)
    {
        printf("%d ", vetPar[i]);
    }
    
    printf("\n");
    
    //imprime impar
    for (int i = 0; i < k; i++)
    {
        printf("%d ", vetImpar[i]);
    }
      
    return 0;
}