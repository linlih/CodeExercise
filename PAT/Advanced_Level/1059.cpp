/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
vector<int> prime(50000, 1);

int main(int argc, char const *argv[]) {
    // 构建一个数组，如果index为prime值为1，不是prime值为0
    for (int i = 2; i * i < 50000; i++) {
        for (int j = 2; j * i < 50000; j++)
            prime[j*i] = 0;
    }
    long int a;
    scanf("%ld", &a);
    printf("%ld=", a);
    if (a == 1) printf("1");
    bool state = false;
    // 遍历50000个乘子
    for (int i = 2; i < 50000 && a >= 2; i++) {
        int cnt = 0, flag = 0;
        while(prime[i] == 1 && a % i == 0) {
            cnt ++;
            a = a / i;
            flag = 1;
        }
        if (flag) {
            if (state) printf("*");
            printf("%d", i);
            state = true;
        }
        if (cnt >= 2) printf("^%d", cnt);
    }
    if (a > 1) printf("%s%ld", state ? "*" :"", a);
    return 0;
}