/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, total;
    cin >> n >> total;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] <= total) {
            cnt++;
            total-=v[i];
        }
        else break;
    }
    cout << cnt << endl;
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    int t, i=1;
    cin >> t;
    while(t--) {
        cout << "Case #" << i << ": ";
        solve();
        ++i;
    }
    return 0;
}