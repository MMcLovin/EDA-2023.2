#include <stdio.h>

void imprimeString(char *string)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        printf("%c", string[i]);
    }
}

int contaNumeros(char texto[1000], int size)
{
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        //numeros tabela ascii: 48 <-> 57
        if (texto[i] >= 48 && texto[i] <= 57)
        {
            n++;
        }
        
    }
    return n;
}

int contaMaiusculas(char texto[1000], int size)
{
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        //maiusculas tabela ascii: 65 <-> 90
        if (texto[i] >= 65 && texto[i] <= 90)
        {
            n++;
        }
    }
    return n;
}

int contaMinusculas(char texto[1000], int size)
{
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        //minusculas tabela ascii: 97 <-> 122
        if (texto[i] >= 97 && texto[i] <= 122)
        {
            n++;
        }
    }
    return n;
}

void testaSenha(char *senha, int *requisitos, int size)
{
    char falhou[] = "Ufa :)\n";
    char passou[] = "Ok =/\n";

    int atendeRequisitos = 0;

    if ((size - 2) >= requisitos[0])
    {

        atendeRequisitos += 1;
    }
    if (contaMinusculas(senha, size) >= requisitos[1])
    {
        atendeRequisitos += 1;
    }
    if (contaMaiusculas(senha, size) >= requisitos[2])
    {
        atendeRequisitos += 1;
    }
    if (contaNumeros(senha, size) >= requisitos[3])
    {
        atendeRequisitos += 1;
    }
/*     if (size <= (requisitos[1] + requisitos[2] + requisitos[3]))
    {
        atendeRequisitos += 1;
    } */

    if (atendeRequisitos == 4)
    {
        imprimeString(passou);
    }
    else
    {
        imprimeString(falhou);
    }
}

int main() {
    
    int requisitos[4];//N,M,A,K,

    for (int i = 0; i < 4; i++)
    {
        int e;
        scanf("%d", &e);
        requisitos[i] = e;
    }
    
    int i = 0;
    char senha[1000] = " ";
    char entrada = 'a';

    getchar();
    for (; entrada != '\n'; i++)
    {
        scanf("%c", &entrada);
        senha[i] = entrada;
    }
    
    testaSenha(senha, requisitos, i);
    
    return 0;
}