#include <stdio.h>

int main() {
    
    int rodadas = 1;//inicializando soh para o caso do lixo de memoria ser 0
    int i = 1;//contador de testes

    while (scanf("%d", &rodadas) == 1 && rodadas != 0)
    {
        int cartasA = 0, cartasB = 0;//quantas cartas cada um virou ao final dos testes

        for (int i = 0; i < rodadas; i++)
        {
            int rodadaA, rodadaB;//quantas cartas cada um virou em cada rodada
            
            scanf("%d %d", &rodadaA, &rodadaB);
            
            cartasA += rodadaA;
            cartasB += rodadaB;
        }

        if (cartasA > cartasB)
        {
            printf("Teste %d\nAldo\n", i);
        }
        if (cartasA < cartasB)
        {
            printf("Teste %d\nBeto\n", i);
        }
        i++;
    }
    
    return 0;
}