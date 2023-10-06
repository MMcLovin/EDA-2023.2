#include <stdio.h>
#include <string.h>

int contaPares(char texto[], int size, char c)
{
    if (size < 2)
    {
        return 0;
    }
    if(texto[size] == texto[size - 2])
    {
        size--;
        return 1 + contaPares(texto, size, texto[size]);
    }
    else
    {
        size--;
        return contaPares(texto, size, texto[size]);
    }
}

int main()
{
    char texto[202] = "";

    fgets(texto, sizeof(texto), stdin);

    //contabilizando o \n e a contagem a partir de 0 para indices
    int size = strlen(texto) - 2;

    printf("%d\n", contaPares(texto, size, texto[size]));

    return 0;
}
