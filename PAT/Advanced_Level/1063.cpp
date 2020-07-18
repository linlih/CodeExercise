// /*
//    问题描述：
//    解题思路： 方法可以，但是最后一个运行超时
//  */
// #include <bits/stdc++.h>

// using namespace std;
// int main(int argc, char const *argv[]) {
//     int n;
//     cin >> n;
//     vector<set<int> > arr;
//     arr.resize(n);
//     int num, m;
//     for (int i = 0; i < n; ++i) {
//         scanf("%d", &m);
//         for (int j = 0; j < m; j++) {
//             scanf("%d", &num);
//             arr[i].insert(num);
//         }
//     }
//     int k;
//     cin >> k;
//     int s, e;
//     set<int> tmp;
//     int cnt = 0;
//     for (int i = 0; i < k; i++) {
//         cin >> s >> e;
//         s = s - 1;
//         e = e - 1;
//         cnt = 0;
//         for (auto it = arr[s].begin(); it != arr[s].end(); it++) {
//             tmp.insert(*it);
//         }
//         for (auto it = arr[e].begin(); it != arr[e].end(); it++) {
//             pair<set<int>::iterator, bool> ret = tmp.insert(*it);
//             if (ret.second == false) cnt++;
//         }
//         printf("%.1f%\n",(cnt * 1.0)/tmp.size()*100);
//         tmp.clear();
//     }
//     return 0;
// }

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n, m, k, temp, a, b;
    scanf("%d", &n);
    vector<set<int> > v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &m);
        set<int> s;
        for (int j = 0; j < m; ++j) {
            scanf("%d", &temp);
            s.insert(temp);
        }
        v[i] = s;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d %d", &a, &b);
        int nc = 0, nt = v[b - 1].size();
        for (auto it = v[a - 1].begin(); it != v[a - 1].end(); it++) {
            if (v[b - 1].find(*it) == v[b - 1].end())
                nt++; // b中也没有这个数值，则nt++
            else 
                nc++; // b中有这个数值，表示二者相同
        }
        double ans = (double)nc / nt  * 100;
        printf("%.1f%%\n", ans);
    }
    return 0;
}
