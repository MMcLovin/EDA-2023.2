#include <stdio.h>
#include <string.h>

//função que realiza a soma dos numeros, de tras pra frente, e rotorna a quantidade de vezes que a soma dos digitos foi realizada até chegar em um numero de 1 digito
int somaDigitos(char N[], long long int *soma, int i)
{
    //variavel só pra ajudar na hr de debuggar
    //int tamanho = strlen(N);

    //chegou ao final da soma dos digitos
    if (i < 0)
    {
        //printf("\nsoma dos digitos = %d\n\n", *soma);

        //se a soma dos digitos eh um numero com mais de dois digitos, repete o processo
        if (*soma >= 10)
        {
            //string que recebe o resultado da ultima soma
            char novoN[1001] = "";
            
            //transfere o resultado da soma para a string
            sprintf(novoN, "%d", *soma);
            
            //reseta o valor da soma
            *soma = 0;

            //pega o ultimo indice da string
            i = strlen(novoN) - 1;
            return 1 + somaDigitos(novoN, soma, i);
        }
        //ponto de parada da recursao
        else
        {
            return 1;
        }
    }
    //checa se char[i] eh um numero
    else if(N[i] >= '0' && N[i] <= '9')
    {
        //pega o inteiro equivalente do char
        int num = N[i] - '0';
        
        //soma os digitos
        *soma = *soma + num;
        
        //variavel só pra ajudar na hr de debuggar
        //int x = *soma;

        //parte para o prox digito
        somaDigitos(N, soma, i - 1);
    }
}

int main()
{
    while (1)
    {
        char N[1002] = "";

        fgets(N, sizeof(N), stdin);

        //condição de parada do programa
        if (N[0] == '0')
        {
            break;
        }
        else
        {
            long long int soma = 0;
            
            //remove o \n pq tava atrapalhando na hr de imprimir
            N[strlen(N) - 1] = '\0';

            //chamadas = grau-9 do numero, se houver
            //printf("******************************************************\n");
            int chamadas = somaDigitos(N, &soma, strlen(N) - 1);
            //printf("******************************************************\n");
            
            //se a ultima soma dos digitos eh igual a nove, o numero tambem eh multiplo de nove
            if(soma == 9)
            {
                printf("%s is a multiple of 9 and has 9-degree %d.\n", N, chamadas);
            }
            else
            {
                printf("%s is not a multiple of 9.\n",N);
            }
        }
    }
    return 0;
}