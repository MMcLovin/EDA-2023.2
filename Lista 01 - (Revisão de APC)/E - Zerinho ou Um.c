#include <stdio.h>

int main() {
    
    int A, B, C;//jogadores
    
    scanf("%d %d %d", &A, &B, &C);

    if((A == B) && (B == C)){
        printf("empate\n");
    }
    else{
        if ((A != B) && (A != C))
        {
            printf("A\n");
        }
        if ((B != A) && (B != C))
        {
            printf("B\n");
        }
        if ((C != A) && (C != B))
        {
            printf("C\n");
        }
    }
    return 0;
}