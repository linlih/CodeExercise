/*
   问题描述：
   解题思路： 没看懂。。。。,那个图根本就是误导。。。。
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    int result = v[0];
    for (int i = 1; i < n; ++i) {
        result = (result + v[i]) / 2;
    }
    printf("%d", result);
    return 0;
}