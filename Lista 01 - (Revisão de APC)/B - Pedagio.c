#include <stdio.h>

int main() {
    
    int L;//comprimento da estrada
    int D;//distancia entre pedagios
    int K;//custo por km
    int P;//preco de cada pedagio 
    int total = 0;//custo total

    scanf("%d %d", &L, &D);
    scanf("%d %d", &K, &P);


    total = (L * K) + ((L / D) * P);
    
    printf("%d\n", total);
    
    return 0;
}