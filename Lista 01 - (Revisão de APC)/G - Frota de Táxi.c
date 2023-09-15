#include <stdio.h>

int main() {

    float A, G;//preco de cada combustivel
    float Ra, Rg;//rendimento de cada combustivel
    float ajuste;//ajusta para a mesma quantidade de km
    float custoA;

    scanf("%f %f %f %f", &A, &G, &Ra, &Rg);
    
    ajuste = Rg / Ra;
    custoA = A * ajuste;
    
    //preco x rendimento = custo por km
    if (custoA > G) {
        printf("G\n");
    }
    else if (custoA < G) {
        printf("A\n");
    }
    else if (custoA == G) {
        printf("G\n");
    }

    return 0;
}