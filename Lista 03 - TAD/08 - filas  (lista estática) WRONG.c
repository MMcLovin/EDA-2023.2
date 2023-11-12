#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *v;       //vetor que representa a fila
    int N;        //tamanho do vetor
    int inicio;   //inicio da fila
    int fim;      //fim da fila
} fila;

int imprimeFilaEstatica(fila *f)
{
    if (f->inicio == f->fim)
    {
        for (int i = 0; i < f->N; i++)
        {
            if (i + 1 == f->N)
            {
                printf("vazio\n");
            }
            else if (i == f->fim)
            {
                printf("fim -> ");
            }
            else {
                printf("vazio -> ");
            }
        }
    }

    //lista com elementos
    else if (f->inicio < f->fim)
    {
        //de 0 ate p
        for (int i = 0; i < f->inicio; i++)
        {
            printf("vazio -> ");
        }

        //de p ate u
        for (int i = f->inicio; i < f->fim; i++)
        {
            if (i + 1 == f->N)
            {
                printf("%d", f->v[i]);
            }
            else
            {
                printf("%d -> ", f->v[i]);
            }
        }

        //de u ate N
        for (int i = f->fim; i < f->N; i++)
        {
            if (i + 1 == f->N)
            {
                printf("vazio");
            }
            else if(i == f->fim)
            {
                printf("fim -> ");
            }
            else
            {
                printf("vazio -> ");
            }
        }
    }

    else if (f->inicio > f->fim)
    {
        //de 0 ate u
        for (int i = 0; i < f->fim; i++)
        {
            printf("%d -> ", f->v[i]);
        }

        //de u ate p
        for (int i = f->fim; i != f->inicio; i++)
        {
            if(i == f->fim)
            {
                printf("fim -> ");
            }
            else
            {
                printf("vazio -> ");
            }
        }

        //de p ate N
        for (int i = f->inicio; i < f->N; i++)
        {
            if (i + 1 == f->N)
            {
                printf("%d", f->v[i]);
            }
            else
            {
                printf("%d -> ", f->v[i]);
            }
        }
    }

    printf("\n");
    return 0;
}

int enfileira(fila *fila, int x)
{
    //fila cheia
    if ((fila->fim + 1 == fila->inicio)) return 0;
    
    //se ja ha um elemento na ultima posicao, vai pro inicio
    if (fila->fim == fila->N) fila->fim = 0;
    
    fila->v[fila->fim++] = x;

    return 1; 
}

int desenfileira(fila *fila, int *y)
{
    if (fila->inicio == fila->fim) return 0;
    
    *y = fila->v[fila->inicio++];
    if (fila->inicio == fila->N) fila->inicio = 0;

    return 1;
}

fila *criaFila_vetor(int p, int u, int N)
{
    fila *f = malloc(sizeof(fila));
    f->N = N;
    f->inicio = p;
    f->fim = u;
    f->v = malloc(sizeof(int) * N);

    if (f->inicio < f->fim)
    {
        for (int i = f->inicio, j = 0; i < f->fim; i++, j++)
        {
            f->v[i] = j;
        }
    }
    if (f->inicio > u)
    {
        int j = 0;
        for (int i = f->inicio; i < f->N; i++, j++)
        {
            f->v[i] = j;
        }
        for (int i = 0; i < f->fim; i++, j++)
        {
            f->v[i] = j;
        }
    }

    return f;
}

void enfileiraVarios_vetor(fila *f, int n)
{
    int j;

    if (f->inicio == f->fim)
    {
        j = 0;
    }
    else
    {
        j = f->v[f->fim - 1] + 1;
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
        printf("\nelemento x enfileirado = %d\n\n", j);
        imprimeFilaEstatica(f);
    }
    return;
}

void desenfileiraVarios_vetor(fila *f, int n)
{
    for (int i = 0; i < n; i++)
    {
        int *y = malloc(sizeof(int));
        int result = desenfileira(f, y);
        //int result = enfileira2(f, j);

        if(result == 0)
        {
            printf("********* INTERVALO DE p OU u INVALIDOS *********\n\n");
            break;;
        }
        printf("\nelemento x desenfileirado = %d\n\n", *y);
        free(y);
        imprimeFilaEstatica(f);
    }
    return;
}


int z = 0;

int testaFilaEstatica(int p, int u, int N, int n, char teste[], int operation)
{
    printf("-------------------------------- START --------------------------------\n");
    printf("TESTE: %s\n", teste);
    printf("p = %d e u = %d\n", p, u);
    fila *f = criaFila_vetor(p, u, N);
    printf("\nFila f%d Original\n", z);
    imprimeFilaEstatica(f);
    if (operation == 1)
    {
        enfileiraVarios_vetor(f, n);
    }
    else
    {
        desenfileiraVarios_vetor(f, n);
    }
    printf("--------------------------------- END ---------------------------------\n");
    z++;

    return 1;
}

int main()
{
    int N = 7;
    int n = 2;

    char teste[] = "fila cheia e tenta enfileirar\n";
    testaFilaEstatica(6, 5, N, 13, teste, 1);

    char teste1[] = "fila com 1 espaco livre\n";
    testaFilaEstatica(6, 4, N, 13, teste1, 1);

    char teste2[] = "Fila vazia e enfileira\n";
    testaFilaEstatica(6, 6, N, 13, teste2, 1);

    char teste3[] = "Fila vazia e desenfileira\n";
    testaFilaEstatica(6, 6, N, 13, teste3, 0);

    char teste4[] = "Fila com 1 elemento e desenfileira\n";
    testaFilaEstatica(6, 0, N, 13, teste4, 0);

    char teste5[] = "Fila com 3 elemento e desenfileira\n";
    testaFilaEstatica(6, 3, N, 13, teste5, 0);

    return 0;
}
//*/