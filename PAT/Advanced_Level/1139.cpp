/*
   问题描述：
   解题思路： 同时这道题最多就是通过这样的形式：A -->> C -->> D -->> B
              最多就是四个人构成一个通信流
              A 和C，D和B是同性朋友
              那么，显然如果A和B是异性，C和D是异性朋友
              这道题的目的是为了求A -->> B之间的[C, D]共有多少对
 */
#include <bits/stdc++.h>

using namespace std;

// ref : https://blog.csdn.net/liuchuo/article/details/79065004

unordered_map<int, bool> arr; // 邻接临界矩阵标记两人是否是朋友
struct node {
    int a, b;
};

bool cmp(node x, node y) {
    return x.a != y.a ? x.a < y.a : x.b < y.b;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n, m, k;
    scanf("%d%d", &n, &m);
    vector<int> v[10000]; // 标记所有人的同性朋友
    for (int i = 0; i < m; ++i) {
        string a, b;
        cin >> a >> b;
        if (a.length() == b.length()) {
            v[abs(stoi(a))].push_back(abs(stoi(b)));
            v[abs(stoi(b))].push_back(abs(stoi(a)));
        }
        arr[abs(stoi(a)) * 10000 + abs(stoi(b))] = arr[abs(stoi(b)) * 10000 + abs(stoi(a))] = true;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        int c, d;
        cin >> c >> d;
        vector<node> ans;
        // 遍历c和d的同性朋友
        for (int j = 0; j < v[abs(c)].size(); ++j) {
            for (int k = 0; k < v[abs(d)].size(); ++k) {
                if (v[abs(c)][j] == abs(d) || abs(c) == v[abs(d)][k]) continue;
                if (arr[v[abs(c)][j]* 10000 + v[abs(d)][k]] == true)
                    ans.push_back(node{v[abs(c)][j], v[abs(d)][k]});
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", int(ans.size()));
        for (int j = 0; j < ans.size(); ++j) {
            printf("%04d %04d\n", ans[j].a, ans[j].b);
        }
    }
    return 0;
}