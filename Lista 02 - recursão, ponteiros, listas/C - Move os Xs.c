#include <stdio.h>
#include <string.h>

int tiraX(char texto[], int tamanho, int i, char novoTexto[], int j)
{
    if (i == tamanho)
    {
        //condicao de parada, retorna o valor de numX
        return 0;
    }
    else
    {
        //pega o char != x, bota em novoTexto e chama a funcao novamente
        if (texto[i] != 'x')
        {
            novoTexto[j] = texto[i];
            j++;
            return tiraX(texto, tamanho, i + 1, novoTexto, j);
        }
        else
        {
            //elemento texto[i] eh um x, ent incrementamos o valor de retorno
            return 1 + tiraX(texto, tamanho, i + 1, novoTexto, j);
        }
    }
}

int botaX(char novoTexto[], int numX, int tamanho)
{
    //o texto original só contém x
    if (numX != 0 && tamanho == 0)
    {
        novoTexto[numX - 1] = 'x';
        botaX(novoTexto, numX - 1, tamanho);
    }
    //adiciona x's necessarios apos o final do novo texto
    else if (numX != 0)
    {
        novoTexto[tamanho] = 'x';
        botaX(novoTexto, numX - 1, tamanho + 1);
    }
    //condicao de parada da recursao eh numX == 0
    else
    {
        return 0;
    }
}

int main()
{
    char texto[102] = " ";
    char novoTexto[102] = "";

    fgets(texto, sizeof(texto), stdin);
    
    //contabilizando o \n e o q eh adicionado ao final da string
    int tamanho = strlen(texto) - 1;

    int numX = tiraX(texto, tamanho, 0, novoTexto, 0);
    
    botaX(novoTexto, numX, strlen(novoTexto));

    printf("%s\n", novoTexto);
    //printf("tamanho = %d\n", tamanho);
    //printf("strlen texto = %d\n", strlen(texto));
    //printf("strlen novoTexto = %d\n", strlen(novoTexto));
    //printf("numX texto = %d\n", numX);

    return 0;
}
