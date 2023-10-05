#include <stdio.h>

int f91(int N)
{
    if (N >= 101)
    {
        return (N - 10);
    }
    else
    {
        return f91(f91(N + 11));
    }
}

int main()
{
    while(1)
    {
        int N;

        scanf("%d",&N);

        if (N > 0 && N <= 1000000)
        {
            printf("f91(%d) = %d\n", N,f91(N));
        }
        else if(N == 0)
        {
            break;
        }
    }

    return 0;
}