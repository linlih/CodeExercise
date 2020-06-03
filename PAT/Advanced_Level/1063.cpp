/*
   问题描述：
   解题思路： 方法可以，但是最后一个运行超时
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<set<int> > arr;
    arr.resize(n);
    int num, m;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &num);
            arr[i].insert(num);
        }
    }
    int k;
    cin >> k;
    int s, e;
    set<int> tmp;
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        cin >> s >> e;
        s = s - 1;
        e = e - 1;
        cnt = 0;
        for (auto it = arr[s].begin(); it != arr[s].end(); it++) {
            tmp.insert(*it);
        }
        for (auto it = arr[e].begin(); it != arr[e].end(); it++) {
            pair<set<int>::iterator, bool> ret = tmp.insert(*it);
            if (ret.second == false) cnt++;
        }
        printf("%.1f%\n",(cnt * 1.0)/tmp.size()*100);
        tmp.clear();
    }
    return 0;
}