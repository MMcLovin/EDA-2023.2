#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int X_maria;
    int Y_maria;
    int X_reuniao;
    int Y_reuniao;
    int cruzamentos;

    scanf("%d %d %d %d",&X_maria, &Y_maria, &X_reuniao, &Y_reuniao);
    
    cruzamentos = abs(X_reuniao - X_maria) + abs(Y_reuniao - Y_maria);
    
    printf("%d\n", cruzamentos);
    
    return 0;
}