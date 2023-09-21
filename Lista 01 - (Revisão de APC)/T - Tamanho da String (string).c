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
    
    printf("%d", i - 1);

    return 0;
}