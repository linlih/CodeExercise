// 没看懂题目

#include <stdio.h>
#include <math.h>

int main()
{
    int M, N, X;
    int raise = 0;

    scanf("%d %d %d", &M, &N, &X);
    while (X >= ((M - 1) / N + 1)) // 判断能量元素是否还可以恢复体力
    {
        X -= M / N + 1;
        raise = M / N; // 计算获得的战斗力
        N += raise;
    }
    printf("%d", N);
}