#include <stdio.h>

int contaEspaco(char *string)
{
    //o numero total de palavras eh igual a quantidade de espacos + 1
    int espacos = 0;
    char letra = ' ';

    for (int i = 0; string[i] != '\n'; i++)
    {
        if (string[i] == ' ')
        {
            espacos++;
        }
    }    
    //printf("espacos = %d\npalavras = espacos + 1\n", espacos);

    return espacos;
}

int contaPalavras(char *string, char letra)
{
    int palavras = 0;
    int achou = 0;

    for (int i = 0; string[i] != '\n'; i++)
    //vai percorrer a string, se achar um espaço, para e zera o contador "achou"
    //ex: vou ao predio
    {
        if (string[i] == ' ')
        {
            achou = 0;
        }
        else if (string[i] == letra && achou == 0)
        {
            achou = 1;
            palavras++;
        }
    }
    //printf("palavras com a letra = %d\n", palavras);
    return palavras;
}

int main() {

    char letra = ' ';
    char texto[1000] = " ";
    char letraBusca = ' ';
    int size = 0;
    float palavrasTotal = 0;
    float palavrasBusca = 0;
    float proporcao = 0;

    scanf("%c", &letraBusca);
    getchar();

    for (int i = 0; letra != '\n'; i++)
    {
        scanf("%c", &letra);
        texto[i] = letra;
    }

    palavrasTotal = contaEspaco(texto) + 1;
    palavrasBusca = contaPalavras(texto, letraBusca);
    proporcao = (palavrasBusca / palavrasTotal) * 100;

    printf("%.1f",proporcao);

    return 0;
}