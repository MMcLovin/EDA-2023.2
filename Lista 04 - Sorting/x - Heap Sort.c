#include<stdio.h>
#include <conio.h>  
#include <stdlib.h>

void imprimeVetor(int *v, int left, int right, char message[][50])
{
    printf("%s\n", message);

    for (int i = left; i <= right; i++) printf("%d ", v[i]);
    printf("\n");
}

void fixDown(int *v, int k, int N)
{
    int j;

    //enquanto houveram nós internos
    while (2*k <= N)
    {
        //j = filho esquerdo de k
        j = 2*k;

        //decidindo qual filho escolher
        //j n é o último elemento da heap & o filho da direita for maior, escolhemos ele
        if (j < N  && (v[j] < v[j + 1]) ) j++;
        
        //k é menor que o filho? vida que segue. É maior? cai fora
        if( !(v[k] < v[j]) ) break;

        //swap
        int temp = v[k];
        v[k] = v[j];
        v[j] = temp;

        //char message[][50] = {"vetor apos swap em MAX HEAPIFY"};
        //imprimeVetor(v, 1, N, message);

        //continua a SINKAR
        k = j;
    }
    
}

void heapsort(int *v, int left, int right, int N)
{
    v = v;

    //chama fixDown até chegar no primeiro item da heap -> MAX HEAPIFY
    for (int k = N/2 ; k >= 1; k--)
    {
        fixDown(v, k, N);
    }
    
    //aqui q a mágica acontece -> Heap Sort
    while (N > 2)
    {
        //swap
        //já temos a garantia da prioridade decrescente, ent funciona 
        int temp = v[1];
        v[1] = v[N];
        v[N] = temp;

        //sinka o elemento que acabamos de dar swap
        //--N, como o ultimo elemento SEMPRE será o maior, vamos diminuindo a variável que representa o tamanho da minha heap
        fixDown(v, 1, --N);
    }
    
}

int main()
{
    int left = 1;
    int right = 150;
    int N = right;
    int v[N];

    printf("tamanho = %d\n", right);
    for (int i = 1; i <= N; i++)
    {
        v[i] = rand() % (5) + 1;
    }
    

    char message[][50] = {"Vetor nao ordenado"};
    imprimeVetor(v, left, right, message);

    char message2[][50] = {"Vetor ordenado"};
    heapsort(v, left, right, N);
    imprimeVetor(v, left, right, message2);

    return 0;
}