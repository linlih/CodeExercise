// 没看懂题目

#include <stdio.h>
#include <math.h>

int main()
{
    int M, N, X;
    int raise = 0;

    scanf("%d %d %d", &M, &N, &X);
    while (X >= ((M - 1) / N + 1))
    {
        X -= M / N + 1;
        raise = M / N;
        N += raise;
    }
    printf("%d", N);
}