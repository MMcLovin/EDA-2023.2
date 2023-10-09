#include <stdio.h>

//os valores de f(0) e f(1) nunca vão ser armazenados em storedFib[0] e storedFib[1]
//storedFib[0] = fib(1) = 1 por meio de return 1
//storedFib[1] = fib(2) = 1 por meio de return 1
//storedFib[2] = fib(3) = 2 por meio de storedFib(n-1) + storedFib(n-2) 
//storedFib[3] = fib(4) = 3 por meio de storedFib(n-1) + storedFib(n-2)
long int storedFib[80] = {};

//f(0) retorna 0 e f(1) retorna 1
long int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    //o valor de f(n) já foi previamente calculado e só acessamo-os a partir do vetor
    else if(storedFib[n] != 0)
    {
        return storedFib[n];
    }

    //Calcula f(n)
    storedFib[n] = fibonacci(n - 1) + fibonacci(n - 2);
    
    return storedFib[n];
    
}

int main()
{
    int n;
    scanf("%d", &n);
    //imprime(n);
    printf("%ld\n",fibonacci(n));
} 