#include <stdio.h>

int main() {
    
    int L;//comprimento da estrada
    int D;//distancia entre pedagios
    int K;//custo por km
    int P;//preco de cada pedagio 
    int total = 0;//custo total

    scanf("%d %d", &L, &D);
    scanf("%d %d", &K, &P);

    for(int i = D; i <= L; i = i + D) {
        total = total + P;
        //printf("km = %d\n", i);
    }
    total += L;
    
    printf("%d\n", total);
    
    return 0;
}