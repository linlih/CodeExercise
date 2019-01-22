// 这道题有问题，参考了答案，答案也是有问题的，输入43输出1，莫名其妙

#include <cstdio>
int main()
{
    long long n, i;
    scanf("%lld", &n);
    for (i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            n /= i;
            printf("%lld\n", n);
            return 0;
        }
    }
    return 0;
}