#include <stdio.h>

int main() {
    
    int X_maria;
    int Y_maria;
    int X_reuniao;
    int Y_reuniao;
    int cruzamentos;

    scanf("%d %d %d %d",&X_maria, &Y_maria, &X_reuniao, &Y_reuniao);

    cruzamentos = (X_reuniao - X_maria) + (Y_reuniao - Y_maria);
    
    printf("%d\n", cruzamentos);
    
    return 0;
}