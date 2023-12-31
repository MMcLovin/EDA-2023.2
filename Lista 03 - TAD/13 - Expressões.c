#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha {
    char *expressao;
    int N;
    int topo;
} pilha;

int empilha(pilha *p, int x)
{
    if (p->topo == p->N)
    {
        return 0;
    }

    p->expressao[p->topo] = x;
    p->topo++;

    return 1;
}

int desempilha(pilha *p)
{
    if (p->topo <= 0)
    {
        return 0;
    }

    int y = p->expressao[p->topo - 1];
    p->topo--;

    return y;
}

int isVazia(pilha *p)
{
    if (p->topo == 0)
    {
        return 1;
    }
    
    return 0;
}

int main()
{
    int tamanho = 100002;
    pilha *semiCadeias = malloc(sizeof(pilha));
    semiCadeias->expressao = malloc(sizeof(char) * tamanho);
    semiCadeias->N = tamanho;
    semiCadeias->topo = 0;

    char bemDefinida = 'S';
    int linhas;
    scanf("%d", &linhas);
    getchar();

    if (!(linhas<= 20 && linhas >= 1))
    {
        linhas = 0;
    }

    for (int i = 0; i < linhas; i++)
    {
        char texto[100001] = "";

        fgets(texto, sizeof(texto), stdin);

        for (int i = 0; i < strlen(texto) - 1; i++)
        {
            //empilha apenas os que abrem as expressoes
            if ((texto[i] == '{') || (texto[i] == '[') || (texto[i] == '('))
            {
                empilha(semiCadeias, texto[i]);
            }
            //se for um de fechar, compara com o do topo da pilha
            else
            {
                int desempilhado = desempilha(semiCadeias);

                //se nao fechar uma expressao, nem precisamos continuar
                if (!((desempilhado == '{' && texto[i] == '}')
                    || (desempilhado == '[' && texto[i] == ']')
                    || (desempilhado == '(' && texto[i] == ')')))
                {
                    bemDefinida = 'N';
                    break;
                }
            }
        }

        //se todas as cadeias que foram abertas, também forem fechadas, a pilha estará vazia
        if (!(isVazia(semiCadeias))) bemDefinida = 'N';
        
        printf("%c\n", bemDefinida);

        semiCadeias->topo = 0;
    }

    return 0;
}