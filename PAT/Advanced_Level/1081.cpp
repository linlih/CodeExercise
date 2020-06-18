/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
// gcd最大公约数
// ref:https://www.cnblogs.com/fusiwei/p/11301436.html
// 下面这个函数的实现方式是辗转相除法
long long gcd (long long a, long long b) {
    return (b == 0)? abs(a) : gcd(b, a % b);
}

int main(int argc, char const *argv[]) {
    long long n, a, b, suma = 0, sumb = 1, gcdvalue;
    scanf("%lld", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld/%lld", &a, &b);
        gcdvalue = gcd(a, b); // 找到最大公约数
        // very clever
        a = a / gcdvalue;
        b = b / gcdvalue;
        suma = a * sumb + suma * b;
        sumb = b * sumb;
        gcdvalue = gcd(suma, sumb);
        sumb = sumb / gcdvalue;
        suma = suma / gcdvalue;
    }
    long long integer = suma / sumb;
    suma = suma - (sumb * integer);
    if (integer != 0) {
        printf("%lld", integer);
        if (suma != 0) printf(" ");
    }
    if (suma != 0)
        printf("%lld/%lld", suma, sumb);
    if (integer == 0 && suma == 0)
        printf("0");
    return 0;
}