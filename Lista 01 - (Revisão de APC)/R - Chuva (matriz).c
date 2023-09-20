#include <stdio.h>


void imprimeMatriz(int *vet, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", *(vet + (i*colunas) + j));
        }
        printf("\n");
    }
}

void somaMatriz(int *resultado, int *M1, int *M2, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            *(resultado + i*colunas + j) = *(M1 + i*colunas + j) + *(M2 + i*colunas + j);
        }
    }
}

int main() 
{
    int dimensao;
    
    scanf("%d", &dimensao);

    int linhasEntrada = dimensao * 2;
    int mapaP1[dimensao][dimensao];
    int mapaP2[dimensao][dimensao];
    //numero de regioes = NxN
    //as dimensao*2 são dois mapas, cada um de um periodo distinto
    //é so uma soma de matrizes pqp, passei 3h pra entender isso
    //a cada dimensao * 2 linhas, nos temos um mapa

    for (int i = 0; i < dimensao; i++)
    //for que vai percorrer as 2*dimensão para o mapa do primeiro periodo, onde temos que ler as duas matrizes que devem ser somadas
    {
        for (int j = 0; j < dimensao; j++)
        {
            scanf("%d", &mapaP1[i][j]);
        }
    }
    for (int i = 0; i < dimensao; i++)
    //mapa do segundo periodo
    {
        for (int j = 0; j < dimensao; j++)
        {
            scanf("%d", &mapaP2[i][j]);
        }
    }
        
    int resultado[dimensao][dimensao];
    
    somaMatriz((int *)resultado, (int *)mapaP1, (int *)mapaP2, dimensao, dimensao);
    imprimeMatriz((int *)resultado, dimensao, dimensao);

    return 0;
}