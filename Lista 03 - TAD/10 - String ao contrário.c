#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilhaEstatica {
    char *data;
    int top;
} pilha;

pilha *criaPilha(char texto[])
{
    pilha *p = malloc(sizeof(pilha));
    p->data = texto;
    if (texto != NULL)
    {
        p->top = strlen(texto) - 2;
    }
    else
    {
        p->top = -1;
    }
    return p;
}

int imprimeAoContrario(pilha *p) {

    if(p->top == -1)
    {
        printf("\n");
        return 0;
    }

    printf("%c",p->data[p->top]);
    p->top--;

    return imprimeAoContrario(p);
}

int main()
{
    char text[502]  = "";
    char text1[502] = "ola\n";
    char text2[502] = "oio\n";
    char text3[502] = "xx\n";

    fgets(text, sizeof(text), stdin);

    pilha *p = criaPilha(text);
    imprimeAoContrario(p);

    /*testes

    pilha *p1 = criaPilha(text1);
    imprimeAoContrario(p1);

    pilha *p2 = criaPilha(text2);
    imprimeAoContrario(p2);

    pilha *p3 = criaPilha(text3);
    imprimeAoContrario(p3);
    //*/
    return 0;
}