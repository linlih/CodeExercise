/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
// gcd最大公约数
// ref:https://www.cnblogs.com/fusiwei/p/11301436.html
// 下面这个函数的实现方式是辗转相除法
// 例子：求1071 和462的最大公约数 
// 1071 = 2 X 462 + 147   a = 1071, b = 462
// 462 = 3 X 147 + 21     a = 462 , b = 147
// 147 = 7 X 21 + 0       a = 147 , b = 21
//                        a = 21  , b = 0
long long gcd (long long a, long long b) {
    return (b == 0)? abs(a) : gcd(b, a % b);
}

int main(int argc, char const *argv[]) {
    long long n, a, b, suma = 0, sumb = 1, gcdvalue;
    scanf("%lld", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld/%lld", &a, &b);
        gcdvalue = gcd(a, b); // 找到分子分母最大公约数
        // very clever
        a = a / gcdvalue; // 分子化简
        b = b / gcdvalue; // 分母化简
        // 这里的计算方式是依据分数的加法即可：a/b + suma/sumb = (a*sumb + b*suma)/(b * sumb)
        suma = a * sumb + suma * b; 
        sumb = b * sumb;
        gcdvalue = gcd(suma, sumb); // 化简求和的结果
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