#include <stdio.h>

int main() {
    int N, C;// numero de leituras e capacidade max do elevador
    int S,E;//numero de pessoas que entraram e sairam do elevador em um andar
    int pessoas = 0;
    char excedeu = 'N';
    
    scanf("%d %d", &N, &C);

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &S, &E);
        pessoas += E - S;
        
        if (pessoas > C)
        {
            excedeu = 'S';
        }
    }

    printf("%c", excedeu);
    
    return 0;
}