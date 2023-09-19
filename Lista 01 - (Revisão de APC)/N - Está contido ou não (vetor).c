#include <stdio.h>

int main() {
    
    int vetSize;

    scanf("%d", &vetSize);

    int vet[vetSize];

    for(int i = 0; i < vetSize; i++)
    //le os n elementos do vetor
    {
        int input;
        scanf("%d", &input);
        vet[i] = input;
    }

    int toFind;
    int result = 0;//0 = not in the vet. 1 = inside the vet

    //le o elemento a ser procurado no vetor
    scanf("%d", &toFind);

    for (int i = 0; i < vetSize; i++)
    {
        if (vet[i] == toFind)
        {
            result = 1;
        }
    }

    if (result == 1)
    {
        printf("pertence\n");
    }
    else
    {
        printf("nao pertence\n");
    }
    
    return 0;
}