#include <stdio.h>

int fibo(int n);

int main()
{
    int test = 6;
    test = fibo(test);
    printf("%d ",test);
}


int fibo(int n)
{
    if( n <= 2)
        return 1;
    else
        return fibo(n - 1) + fibo(n - 2);
}

