#include <stdio.h>

int achaMaior(int vet[], int size)
{
    int maior = 0;

    for (int i = 0; i < size; i++)
    {
         if (vet[i] > maior)
        {
            maior = vet[i];
        }    
        //printf("aeroporto %d teve %d voos\n", i + 1 ,vet[i]);
    }
    return maior;
}

int main() {

    int numAeroportos = 1, numVoos = 0;
    int testeN = 1;

    while (1)
    //condição de parada -> A = V = 0
    {
        scanf("%d %d", &numAeroportos, &numVoos);

        if ((numAeroportos == numVoos) && numAeroportos == 0)
        {
            break;
        }
        else
        {
            int saindoX[numVoos];
            int chegandoY[numVoos];
            int voosTotais[numAeroportos];//maior prob de congestionamento = num de saidas + chegadas (X+Y) para um aeroporto em especifico

            
            for (int i = 0; i < numVoos; i++)//le n voos
            {
                int X,Y;//X Y = do aeroporto x para o y
                
                scanf("%d %d", &X, &Y);
            
                saindoX[i] = X;
                chegandoY[i] = Y;
            }

            for (int id = 1; id <= numAeroportos; id++)
            //identificação dos aeroportos -> 1  - numAeroportos
            //problema tá aqui
            {
                voosTotais[id - 1] = 0;//substitui lixo de memoria por um numero neutro
                for (int j = 0; j < numVoos; j++)
                //varre o vetor de cada de voo
                {
                    if (saindoX[j] == id)
                    {
                        voosTotais[id - 1] += 1;//id - 1 = index correto do vetor de numero id 
                    }
                    if (chegandoY[j] == id)
                    {
                        voosTotais[id - 1] += 1;
                    }
                }
            }
            
            printf("Teste %d\n", testeN);
            
            int maior = achaMaior(voosTotais, numAeroportos);

            for (int i = 0; i < numAeroportos; i++)
            //imprime todos os aeroportos com o maior probabilidade de congestionamento
            {
                if (voosTotais[i] == maior)
                {
                    printf("%d ", (i + 1));
                }
                
            }
            printf("\n");            
            testeN++;
        }
    }
    
    return 0;
}