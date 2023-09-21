#include <stdio.h>

int melhorColuna(int *matriz, int linhas, int colunas)
{
    int soma;
    int maior = 0;

    for (int j = 0; j < colunas; j++) //for que percorre as colunas a serem somadas
    {
        soma = 0;

        for (int i = 0; i < linhas; i++) //for que soma todos os valorCelulas de uma coluna, pegando apenas o primeiro valorCelula de uma linha
        {
            int valorCelula = *(matriz + i*colunas + j);
            soma += *(matriz + i*colunas + j);
        }

        //printf("soma da coluna %d = %d\n", j, soma);

        if (soma >= maior)
        {
            maior = soma;
        }
    }
    //printf("\n");
    
    return maior;
}

int melhorLinha(int *matriz, int linhas, int colunas)
{    
    int maior = 0;
    int soma;

    for (int i = 0; i < linhas; i++) //for que percorre as linhas a serem somadas
    {
        soma = 0;

        for (int j = 0; j < colunas; j++)
        {
            int valorCelula = *(matriz + i*colunas + j);
            soma += *(matriz + i*colunas + j);
        }

        //printf("soma da linha %d = %d\n", i, soma);

        if (soma > maior)
        {
            maior = soma;
        }
    }
    //printf("\n");

    return maior;
}

int main() {
    
    int linhas, colunas;
    
    scanf("%d %d", &linhas, &colunas);

    int campo[linhas][colunas];

    for (int i = 0; i < linhas; i++)
    //for para ler o dado das celulas da matriz
    {
        for (int j = 0; j < colunas; j++)
        {
            int celula;
            
            scanf("%d",&celula);
            
            campo[i][j] = celula;
        }
    }
    
    int maiorLinha = melhorLinha(*campo, linhas, colunas);
    int maiorColuna = melhorColuna(*campo, linhas, colunas);

    if (maiorColuna > maiorLinha)
    {
/*         printf("maior coluna = %d\n", maiorColuna);
        printf("maior linha = %d\n", maiorLinha); */
        printf("%d\n", maiorColuna);
    }
    else
    {
/*         printf("maior linha = %d\n", maiorLinha);
        printf("maior coluna = %d\n", maiorColuna); */
        printf("%d\n", maiorLinha);
    }
    

    return 0;
}