/*
   问题描述：刚开始没理解题目，题目要求的是最大的能够从店里获取的数额，所以就是正值最大相乘，负值最小相乘即可，异号的可以不考虑，因为得到的负数
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    int m, n, ans = 0, p = 0, q = 0;
    scanf("%d", &m);
    vector<int> v1(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &v1[i]);
    }
    scanf("%d", &n);
    vector<int> v2(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v2[i]);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    while (p < m && q < n && v1[p] < 0 && v2[q] < 0) {
        ans += v1[p] * v2[p];
        p++; q++;
    }
    p = m - 1, q = n - 1;
    while (p >= 0 && q >= 0 && v1[p] > 0 && v2[q] > 0) {
        ans += v1[p] * v2[q];
        p--; q--;
    }
    printf("%d", ans);
    return 0;
}