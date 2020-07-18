/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

vector<int> e[10010];
bool visit[10010];
bool flag = false;
void dfs(int idx, vector<int> &color) {
    if (flag) return;
    visit[idx] = true;
    for (int i = 0; i < e[idx].size(); ++i) {
        //cout << "compare: " << idx << ":" << e[idx][i] << endl;
        //cout << "color  : " << color[idx] << ":" << color[e[idx][i]] << endl;
        if (color[e[idx][i]] == color[idx]) {
            //cout << "No" << endl;
            flag = true;
            return;
        }
        //cout << i << ":" << visit[i] << endl;
        if (visit[e[idx][i]] == false)
            dfs(e[idx][i], color);
    }
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    //fill(e[0],e[0] + 1010*1010, -1);
    fill(visit, visit+10010, false);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        vector<int> v(n);
        fill(visit, visit+10010, false);
        flag = false;
        set<int> s;
        for(int j = 0; j < n; ++j) {
            scanf("%d", &v[j]);
            s.insert(v[j]);
        }
        dfs(0, v);
        if (!flag)
            printf("%d-coloring\n", s.size());
        else 
            printf("No\n");
    }
    return 0;
}