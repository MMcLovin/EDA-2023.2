#include <stdio.h>
#include <string.h>

int imprimeAoContrario(char texto[], int len)
{
    if (len < 0)
    {
        printf("\n");
        return 0;
    }
    else
    {
        printf("%c", texto[len]);
        return imprimeAoContrario(texto, len - 1);
    }
    
}

int main()
{
    char texto[502] = "";
    
    fgets(texto, sizeof(texto), stdin);
    
    int size = strlen(texto) - 2;

    imprimeAoContrario(texto, size);

    return 0;
}