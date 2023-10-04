#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/* int main()
{
    int a = 3, b = 4;
    
    printf("Antes da troca\na = %d\nb = %d\n", a, b);
    
    swap(&a, &b);
    
    printf("Depois da troca\na = %d\nb = %d\n", a, b);
    
    return 0;
} */