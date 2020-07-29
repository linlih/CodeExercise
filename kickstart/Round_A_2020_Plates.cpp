/*
   问题描述：
   解题思路： 
 */
// #include <bits/stdc++.h>
// using namespace std;

// // 这道题和0-1背包问题类似

// int n, k, p;
// int a[50][30], dp[51][1510];
// void solve() {
//     cin >> n >> k >> p; // n堆盘子，每堆k个盘子，选择p个，要求漂亮值最大
//     memset(dp, 0, sizeof(dp));
//     dp[0][0] = 0;
//     for (int i = 0; i < n; ++i) {
//         memcpy(dp[i+1], dp[i], sizeof(dp[0])); 
//         for (int j = 0, s= 0; j < k; ++j) {
//             cin >> a[i][j];
//             s += a[i][j]; // s记录的是从第i堆的stack中取出(j+1)个盘子的总的漂亮值
//             for (int l = 0; l + j + 1<=p; ++l) 
//                 // 第(i+1)堆中选j个，第(1~i)堆选择l个可以获得的最大值
//                 // 最大值来源有两个，一个是选择当下i+1堆的(j+1)个盘子，另外一个就是不选
//                 dp[i+1][l+j+1]=max(dp[i][l]+s, dp[i+1][l+j+1]);
//         }
//     }
//     cout << dp[n][p] << endl;
// }

// int main(int argc, char const *argv[]) {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     freopen("input.txt","r",stdin);
//     int t, i=1;
//     cin >> t;
//     while(t--) {
//         cout << "Case #" << i << ": ";
//         solve();
//         ++i;
//     }
//     return 0;
// }


// 0-1背包问题

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>
using namespace std;

int dp[60][1510];
int sum[60][1510];

void solve() {
    int n, k, p;
    cin >> n >> k >> p;
    fill(dp[0], dp[0] + 60*1510, 0);
    fill(sum[0], sum[0] + 60*1510, 0);
    for (int i = 1; i <= n; ++i) {
        int s = 0;
        int tmp;
        for (int j = 1; j <= k; ++j) {
            cin >> tmp;
            s+=tmp;
            sum[i][j] = s;    
        }
    }
    for (int i = 1;i <= n; ++i) {
        for (int j = 1; j <= p; ++j) {
            dp[i][j] = 0;
            for (int x = 0; x <= min(j, k); x++) {
                dp[i][j] = max(dp[i][j], sum[i][x] + dp[i-1][j-x]);
            }
        }
    }
    cout << dp[n][p] << endl;
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
