/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int a[100000];
int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n, e = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
        scanf("%d", &a[i]);
    sort(a, a + n, greater<int>());
    while (e < n && a[e] > e + 1) e++;
    printf("%d", e);
    return 0;
}