#include <stdio.h>
#include <string.h>

int trocaX(char texto[], int i)
{
    if (i >= strlen(texto))
    {
        return 0;
    }
    else if (texto[i] == 'x')
    {
        texto[i] = 'y';
        return trocaX(texto, i + 1);
    }
    else
    {
        return trocaX(texto, i + 1);
    }
    
}

int main()
{
    char texto[82] = "";
    
    fgets(texto, sizeof(texto), stdin);
    
    trocaX(texto, 0);
    
    fputs(texto, stdout);

    return 0;
}