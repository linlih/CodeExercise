/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n, m, cnt, k, a[210][210] = {0};
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int t1, t2;
        cin >> t1 >> t2;
        a[t1][t2] = a[t2][t1] = 1;
    }
    cin >> cnt;
    while(cnt--) {
        cin >> k;
        vector<int> v(k);
        set<int> s;
        int flag1 = 1, flag2 = 1;
        for (int i = 0; i < k; ++i) {
            scanf("%d", &v[i]);
            s.insert(v[i]);
        }
        // 要包含图中所有的结点，所以结点数量不是n的一定不是Hamiltonian Circle
        if (s.size() != n || k - 1 != n || v[0] != v[k - 1]) flag1 = 0;
        for (int i = 0; i < k - 1; i++) {
            if (a[v[i]][v[i+1]] == 0) flag2 = 0;
        }
        printf("%s", flag1 && flag2?"YES\n":"NO\n");
    }

    return 0;
}