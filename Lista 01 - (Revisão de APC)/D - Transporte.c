#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int X, Y, Z;//dimensoes do navio
    int A, B, C;//dimensoes do container
    int XY_containers,Z_containers;//quanto cada dimensao do container cabe no navio
    int total_cointainers = 0;//soma da area dos andares de containers

    scanf("%d %d %d", &A, &B, &C);
    scanf("%d %d %d", &X, &Y, &Z);

    if (A>X || B>Y || C>Z) {
        
        printf("%d\n",0);
    
    }
    else {
        
        XY_containers = (X / A) * (Y / B);//quantos containers cabem no plano xy = "area²"
        Z_containers = Z / C;//quantos containers cabem em z = andar de container
        total_cointainers = XY_containers * Z_containers;
        
        printf("%d\n", total_cointainers);
    }
    return 0;
}