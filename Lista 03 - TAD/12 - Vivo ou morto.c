#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    struct celula *prox;
    struct celula *ultimo;
    int vivoMorto;
    int id;
} celula;

celula *criaCelula()
{
    celula *l = malloc(sizeof(celula));
    l->vivoMorto = -1;
    l->id = -1;
    l->prox = NULL;
}

//insere na cauda
celula *enfileira(celula *fila, int x)
{
    celula *newHead = malloc(sizeof(celula));
    
    //se a fila estiver vazia: fila->prox == fila 
    newHead->prox = fila->prox;
    fila->prox = newHead;
    fila->id = x;

    return newHead;
}

//atualiza o atributo de vivo ou morto de acordo a entrada dada 
int atualizalistaParticipantes(celula *l, int comando)
{
    if (l->prox == NULL) return 1;
    
    int vivo_OU_morto;
    
    scanf("%d", &vivo_OU_morto);

    if (vivo_OU_morto != comando)
    {
        l->prox = l->prox->prox;
        return atualizalistaParticipantes(l, comando);
    }
    else 
    {
        atualizalistaParticipantes(l->prox, comando);
    }

    return 1;
}

int main()
{
    int testeN = 1;
    int P, R; //numero de participantes e numero de rodadas

    scanf("%d %d", &P, &R);

    //condicao de parada -> P == R == 0
    while (P + R != 0)
    {
        celula *listaParticipantes = criaCelula();

        for (int i = 0; i < P; i++)
        {
            int pessoaNum;
            scanf("%d", &pessoaNum);
            listaParticipantes = enfileira(listaParticipantes, pessoaNum);
        }

        for (int i = 0; i < R; i++)
        {
            int nParticipantes, comando;

            scanf("%d %d", &nParticipantes, &comando);

            atualizalistaParticipantes(listaParticipantes, comando);
        }

        printf("Teste %d\n", testeN++);

        //todo caso teste tem apenas um vencedor
        printf("%d\n", listaParticipantes->prox->id);

        free(listaParticipantes);

        scanf("%d %d", &P, &R);
    }

    return 0;
}