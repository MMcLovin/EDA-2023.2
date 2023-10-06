#include <stdio.h>
#include <string.h>

//função que realiza a soma dos numeros, de tras pra frente, e rotorna a quantidade de vezes que a soma dos digitos foi realizada até chegar em um numero de 1 digito
int somaDigitos(char N[], int i)
{

    //chegou ao final da soma dos digitos
    if (i < 0)
    {
        return 0;
    }
    //checa se char[i] eh um numero
    else if(N[i] >= '0' && N[i] <= '9')
    {
        //pega o inteiro equivalente do char
        int num = N[i] - '0';

        //parte para o prox digito
        return num + somaDigitos(N, i - 1);
    }
}

int main()
{
    char N[1002] = "";

    fgets(N, sizeof(N), stdin);

    int soma = somaDigitos(N, strlen(N) - 2);

    printf("%d\n", soma);
    
    return 0;
}