// /*
//    问题描述：
//    解题思路： 
//  */
// #include <bits/stdc++.h>

// using namespace std;
// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     int n;
//     cin >> n;
//     vector<int> dis;
//     int temp;
//     for (int i = 0; i < n; ++i) {
//         scanf("%d", &temp);
//         dis.push_back(temp);
//     }
//     sort(dis.begin(), dis.end());
//     int num = -1;
//     for (int i = 0; i < n; ++i) {
//         //cout << dis[n - i - 1] << endl;
//         if (i < dis[n - i - 1]) {
//             num = i;
//             //cout << i << endl;
//         }
//     }
//     cout << num + 1 << endl;
//     return 0;
// }

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