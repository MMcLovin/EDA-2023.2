#include <stdio.h>

int main() {
     int N;

    scanf("%d", &N);
    
     for (int i = 1; i <= N; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < 6; j++)
            {
                printf("THUMS ");
            }
        }
        else
        {
            for (int j = 0; j < 3; j++)
            {
                printf("THUMS ");
            }
        }       
        printf("\n");
    } 
    return 0;
}