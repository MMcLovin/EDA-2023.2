#include <stdio.h>

int main() {
    
    char texto[1000] = "";
    char caractere = 'a';
    int i = 0;

    for (; caractere != '\n'; i++)
    {
        scanf("%c", &caractere);
        texto[i] = caractere;
    }
    
    for (int j = i - 2; j >= 0; j--)
    //i - 1 (tamanho da str, ultimo elemento = i - 1) - 1 pq o ultimo elemento de toda string é um \n (+ um /0?)
    {
        printf("%c", texto[j]);
    }
    

    return 0;
}