#include <stdio.h>

int main() {
    
    int vetSize;

    scanf("%d", &vetSize);

    int vet[vetSize];

    for(int i = 0; i < vetSize; i++)
    {
        int input;
        scanf("%d", &input);
        vet[i] = input;
    }

    int indexMenor = 0;

    for (int i = 0; i < vetSize; i++)
    {
        if (vet[indexMenor] > vet[i])
        {
            indexMenor = i;
        }
    }

    printf("%d\n", indexMenor);
    
    return 0;
}