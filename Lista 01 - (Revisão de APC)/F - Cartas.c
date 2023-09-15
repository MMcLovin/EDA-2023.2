#include <stdio.h>

//int teste(int C1, int C2, int C3, int C4, int C5) {
int main(){
    
    int C1,C2,C3,C4,C5;//cartas 1 - 5
    int contador = 0;//-4 = decrescente. 4 = crescente. 0 = N

    scanf("%d %d %d %d %d", &C1, &C2, &C3, &C4, &C5);

    int vet[] = {C1,C2,C3,C4,C5};
        
    for (int i = 0, j = 1; j < 5; i++, j++)
    {
        if (vet[i] > vet[j])
        {
            contador--;
        }
        else if (vet[i] < vet[j])
        {
            contador++;
        }
    }
    
    if (contador == 4)
    {
        printf("C\n");
    }
    else if (contador == -4)
    {
        printf("D\n");
    }
    else
    {
        printf("N\n");
    }
    
    return 0;
}
/* int main(){
    teste(6,5,4,3,2);
    teste(1,2,3,4,5);
    teste(12,1,5,6,7);

    return 0;
} */