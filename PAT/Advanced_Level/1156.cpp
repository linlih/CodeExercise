/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i*i <=n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n;
    scanf("%d", &n);
    if (isPrime(n)) {
        printf("Yes\n");
        if (isPrime(n - 6))
            printf("%d", n - 6);
        else if (isPrime(n + 6))
            printf("%d", n - 6);
    }
    else {
        printf("No\n");
        while(!isPrime(n))n++;
        printf("%d", n);
    }
    return 0;
}