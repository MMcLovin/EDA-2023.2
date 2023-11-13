#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int N, p, u;
} fila;

int imprimeFilaEstatica(fila *f)
{
    if (f->p == f->u)
    {
        for (int i = 0; i < f->N; i++)
        {
            if (i + 1 == f->N)
            {
                printf("vazio\n");
            }
            else if (i == f->u)
            {
                printf("fim -> ");
            }
            else {
                printf("vazio -> ");
            }
        }
    }

    //lista com elementos
    else if (f->p < f->u)
    {
        //de 0 ate p
        for (int i = 0; i < f->p; i++)
        {
            printf("vazio -> ");
        }

        //de p ate u
        for (int i = f->p; i < f->u; i++)
        {
            if (i + 1 == f->N)
            {
                printf("%d", f->dados[i]);
            }
            else
            {
                printf("%d -> ", f->dados[i]);
            }
        }

        //de u ate N
        for (int i = f->u; i < f->N; i++)
        {
            if (i + 1 == f->N)
            {
                printf("vazio");
            }
            else if(i == f->u)
            {
                printf("fim -> ");
            }
            else
            {
                printf("vazio -> ");
            }
        }
    }

    else if (f->p > f->u)
    {
        //de 0 ate u
        for (int i = 0; i < f->u; i++)
        {
            printf("%d -> ", f->dados[i]);
        }

        //de u ate p
        for (int i = f->u; i != f->p; i++)
        {
            if(i == f->u)
            {
                printf("fim -> ");
            }
            else
            {
                printf("vazio -> ");
            }
        }

        //de p ate N
        for (int i = f->p; i < f->N; i++)
        {
            if (i + 1 == f->N)
            {
                printf("%d", f->dados[i]);
            }
            else
            {
                printf("%d -> ", f->dados[i]);
            }
        }
    }

    printf("\n");
    return 0;
}

int enfileira(fila *f, int x)
{
    //a fila esta cheia e u vem antes de p
    if (f->u + 1 == f->p)
    {
        f->dados = realloc(f->dados, sizeof(int) * (f->N * 2));

        int j = 0;

        //pega os dados do comeco do vetor ate o inicio (f->p) da fila
        for (; j + 1 != f->p; j++)
        {
            f->dados[f->N + j] = f->dados[j];
        }

        //não precisa incrementar +1 pois o for sempre realiza uma soma além do necessário
        f->u = j + f->N;
        f->N = f->N * 2;
        printf("\n****** REDIMENSIONAMENTO DE f->dados ******\n\n");
        imprimeFilaEstatica(f);
    }
    //a fila esta cheia, mas inicio (p) esta em 0 e o final (u) esta 1 unidade alem da ultima posicao do vetor = N
    else if (f->u - f->p == f->N)
    {
        f->N = f->N * 2;
        f->dados = realloc(f->dados, sizeof(int) * f->N); 

        printf("\n****** REDIMENSIONAMENTO DE f->dados ******\n\n");
    }

    if(f->u == f->N) f->u = 0;

    f->dados[f->u] = x;

    f->u++;

    return 1;
}

fila *criaFila_vetor(int p, int u, int N)
{
    fila *f = malloc(sizeof(fila));
    f->N = N;
    f->p = p;
    f->u = u;
    f->dados = malloc(sizeof(int) * N);

    if (f->p < f->u)
    {
        for (int i = f->p, j = 0; i < f->u; i++, j++)
        {
            f->dados[i] = j;
        }
    }
    if (f->p > u)
    {
        int j = 0;
        for (int i = f->p; i < f->N; i++, j++)
        {
            f->dados[i] = j;
        }
        for (int i = 0; i < f->u; i++, j++)
        {
            f->dados[i] = j;
        }
    }

    return f;
}

//enfileira varios.versao mais atualizada
void enfileiraVarios_vetor(fila *f, int n)
{
    int j;

    if (f->p == f->u)
    {
        j = 0;
    }
    else
    {
        j = f->dados[f->u - 1] + 1;
    }

    for (int i = 0; i < n; i++, j++)
    {
        int result = enfileira(f, j);
        //int result = enfileira2(f, j);

        if(result == 0)
        {
            printf("********* INTERVALO DE p OU u INVALIDOS *********\n\n");
            break;;
        }
        printf("elemento x enfileirado = %d\n", j);
        imprimeFilaEstatica(f);
    }
    return;
}

int z = 0;

int testaFilaEstatica(int p, int u, int N, int n, char teste[])
{
    printf("-------------------------------- START --------------------------------\n");
    printf("TESTE: %s\n", teste);
    printf("p = %d e u = %d\n", p, u);
    fila *f = criaFila_vetor(p, u, N);
    printf("\nFila f %d Original\n", z);
    imprimeFilaEstatica(f);
    enfileiraVarios_vetor(f, n);
    printf("--------------------------------- END ---------------------------------\n");
    z++;

    return 1;
}

int main()
{
    int N = 7;
    int n = 2;
    
    char teste[] = "So vai porra\n";
    testaFilaEstatica(6, 6, N, 13, teste);

    
    char teste1[] = "fila ja comeca cheia e inicio (u) > fim (p)\n";
    testaFilaEstatica(3, 2, N, n, teste1);
    

    return 0;
}

//*/