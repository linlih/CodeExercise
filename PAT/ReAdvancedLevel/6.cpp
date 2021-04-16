/*******************************************************************
  > File Name    : 6.cpp
  > Author       : linlh
  > Created  Time: 2021.03.31 14:26
  > Modified Time: 2021.03.31 15:05
 *******************************************************************/

#include "bits/stdc++.h"
using namespace std;

// bool cmp1(pair<string, int>& v1, pair<string, int>& v2) {
//     return v1.second < v2.second;
// }
// bool cmp2(pair<string, int>& v1, pair<string, int>& v2) {
//     return v1.second > v2.second;
// }
// int main()
// {
//     vector<pair<string, int>> in;
//     vector<pair<string, int>> out;
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; ++i) {
//         char id[20];
//         int h1, m1, s1, h2, m2, s2;
//         scanf("%s %d:%d:%d %d:%d:%d", id, &h1, &m1, &s1, &h2, &m2, &s2);
//         in.push_back(make_pair(string(id), h1*3600 + m1*60 + s1));
//         out.push_back(make_pair(string(id), h2*3600 + m2*60 + s2));
//     }
//     sort(in.begin(), in.end(), cmp1);
//     sort(out.begin(), out.end(), cmp2);
//     cout << in[0].first << " " << out[0].first << endl;
//     return 0;
// }
//

int main() {
    int n, minn = INT_MAX, maxn = INT_MIN;
    scanf("%d", &n);
    string unlocked, locked;
    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        int h1, m1, s1, h2, m2, s2;
        scanf("%d:%d:%d %d:%d:%d", &h1, &m2, &s1, &h2, &m2, &s2);
        int tempIn = h1*3600 + m1*60 + s1;
        int tempOut = h2*3600 + m2*60 + s2;
        if (tempIn < minn){
            minn = tempIn;
            unlocked = t;
        }
        if (tempOut > maxn) {
            maxn = tempOut;
            locked = t;
        }

    }
    cout << unlocked << " " << locked << endl;
    return 0;
}
