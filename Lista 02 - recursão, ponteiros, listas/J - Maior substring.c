#include <stdio.h>
#include <string.h>

int euNaoAguentoMaisPeloAmorDeDeus(char texto[], char sub[], int vetPos[])
{
    //guarda o ponteiro que aponta para o primeiro pedaco de texto[] que contem sub[]
    char *temp = (strstr(texto, sub));

    //strstr retorna NULL e podemos parar a execucao
    if (temp == NULL)
    {
        vetPos[2] = vetPos[1] + strlen(sub);
        return 0;
    }
    else
    {
        //indice de onde comeca a minha ocorrencia no meu novoTexto/texto
        int indice = temp - texto;

        //guarda a posicao de inicio da ocorrencia e tmb determina se eh ou nao a primeira vez que a funcao eh executada
        if (vetPos[0] == -1)
        {
            vetPos[0] = indice;
        }

        //posicao onde a ocorrencia termina
        vetPos[1] = vetPos[1] + indice + 1;


        //array que recebe parte da string original
        char novoTexto[82] = "";

        //copia tudo depois da primeira ocorrencia de sub
        strcpy(novoTexto, &temp[1]);

        euNaoAguentoMaisPeloAmorDeDeus(novoTexto, sub, vetPos);
    }
}
int main()
{
    char str[102] = "";
    char sub[102] = "";

    fgets(str, sizeof(str), stdin);
    fgets(sub, sizeof(sub), stdin);

    int strLen = strlen(str);
    int subLen = strlen(sub);

    //remove o \n pq se nao ele contabilizaria apenas recorrencias seguidas pelo \n
    sub[strlen(sub) - 1] = '\0';

    //v[0] = inicio da ocorrencia
    //v[1] = valor temporario
    //v[2] = fim da ocorrencia
    int vetPos[3] = {-1, 0, 0};

    if (strLen >= subLen && (subLen + strLen > 1))
    {
        euNaoAguentoMaisPeloAmorDeDeus(str, sub, vetPos);
    }

    int maiorSub = 0;

    //vetPos[0] nao foi alterado ou sub nao esta contida em str
    if (vetPos[0] == vetPos[1])
    {
        maiorSub = subLen - 1;
    }
    else if (vetPos[0] != -1)
    {
        maiorSub = vetPos[2] - vetPos[0] - 1;
    }

    printf("%d\n", maiorSub);

    return 0;
}
