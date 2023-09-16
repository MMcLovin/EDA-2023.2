#include <stdio.h>

int main() {

    int testeN = 1;
    int nOperandos;

    while ((scanf("%d", &nOperandos) == 1) && nOperandos != 0)
    {
        int resultado = 0;
        int operando;
        int operador = 'a';//declar o operador fora do for nos permite acessar o valor previamente lido para a prox operação 

        for (int i = 0; i < (nOperandos + nOperandos - 1); i++)
        {
            //simbolos de operação ficam entre 2 operadores, ou seja,
            //um operador para cada par de operandos
            //quantidade de operadores = operandos - 1

            if (i % 2 == 0)
            //operandos ficam em posições pares
            {
                scanf("%d",&operando);
                if (i == 0)
                {
                    resultado += operando;
                }

            }
            if (i % 2 != 0)
            //operadores ficam em posições impares
            {
                scanf("%c",&operador);
            }
            if ((operador == '+'))
            {
                resultado += operando;
            }
            else if (operador == '-')
            {
                resultado -= operando;
            }
            //limpando o valor guardado no operando para que na 
            //execução em que o operador eh lido, o resultado n seja alterado
            operando = 0;
        }
        printf("Teste %d\n",testeN);
        printf("%d\n",resultado);
        testeN++;
    }


    return 0;
}
