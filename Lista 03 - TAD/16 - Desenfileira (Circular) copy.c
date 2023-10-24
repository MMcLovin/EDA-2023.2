#include <stdio.h>
#include <stdlib.h>

//obs: fila circular
typedef struct fila {
    int *dados;
    int N;
    int p;
    int u;//fim da fila
} fila;

int desenfileira(fila *f, int *y)
{
    if (f->p == f->u)
    {
        return 0;
    }

    *y = f->dados[f->p];
    f->p++;
    //o elemento na posicao n - 1 foi retirado e p deve voltar para o incio do vetor
    if (f->p == f->N) f->p = 0;

    return 1;
}

fila *criaFila(int p, int u, int N)
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

int imprimeFila(fila *f)
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
        for (int i = 0; i < f->p; i++)
        {
            if (i + 1 == f->N)
            {
                printf("%d", f->dados[i]);
            }
            else
            {
                printf("vazio -> ", f->dados[i]);
            }
        }

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
        for (int i = 0; i < f->u; i++)
        {
            printf("%d -> ", f->dados[i]);
        }

        for (int i = f->u; i != f->p; i++)
        {
            if(i == f->u)
            {
                printf("fim -> ");
            }
            else if (f->p == f->N && (i + 1 == f->p))
            {
                printf("vazio");
            }
            else
            {
                printf("vazio -> ");
            }
        }

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

int esvaziaFila(fila *f)
{
    if (f->p != f->u)
    {
        int *y = malloc(sizeof(int));
        desenfileira(f,y);
        printf("\nelemento retirado = %d\n", *y);
        imprimeFila(f);
        free(y);
        return esvaziaFila(f);
    }
    else return 0;
}


int main()
{
    fila *f = criaFila(2, 1, 5);
    printf("lista original\n");
    imprimeFila(f);
    esvaziaFila(f);

    fila *f1 = criaFila(0, 2, 5);
    printf("\nlista original\n");
    imprimeFila(f1);
    esvaziaFila(f1);

    fila *f2 = criaFila(4, 0, 5);
    printf("\nlista original\n");
    imprimeFila(f2);
    esvaziaFila(f2);

    return 0;
}
//*/