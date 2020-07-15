/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i <= (int)sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int tsize, n, m, a;
    cin >> tsize >> n >> m;
    while(!isPrime(tsize)) tsize++;
    vector<int> v(tsize);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        int flag = 0;
        for (int j = 0; j < tsize; j++) {// 这里j的取值范围只要[0, tsize)
            int pos = (a + j * j ) % tsize;
            if (v[pos] == 0) {
                v[pos] = a;
                flag = 1;
                break;
            }
        }
        if (!flag) printf("%d cannot be inserted.\n", a);
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &a);
        for (int j = 0; j <= tsize; j++) {
            ans ++;
            int pos = (a + j * j) % tsize;
            if (v[pos] == a || v[pos] == 0) break; 
        }
    }
    printf("%.1f\n", ans * 1.0 / m);
    return 0;
}