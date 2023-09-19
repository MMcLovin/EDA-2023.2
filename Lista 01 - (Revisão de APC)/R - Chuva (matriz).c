#include <stdio.h>

void inicializaVetor(int *vet, int linhas, int colunas)
{
    int *vetP = vet;

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            vetP[i][j] = 0;
        }
    }
}

void imprimeMatriz(int *vet, int linhas, int colunas)
{
    int *vetP = vet;

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", vetP[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int dimensao;
    
    scanf("%d", &dimensao);

    int linhas = dimensao * 2;
    int mapa[linhas][dimensao];//cada elemento do mapa é uma 
    //região

    printf("vetor com lixo de memoria\n");
    imprimeMatriz(mapa, linhas, dimensao);

/*     for (int i = 0; i < linhas; i++)
    //for que vai percorrer as 2*dimensão
    //só q cada linha precisa de um outro for para 
    //ler n mapas
    {
        for (int i = 0; i < dimensao; i++)
        {
            scanf("%d", &mapa);
        }
    } */

    printf("vetor inicializado por uma função\n");
    imprimeMatriz(mapa, linhas, dimensao);

    return 0;
}