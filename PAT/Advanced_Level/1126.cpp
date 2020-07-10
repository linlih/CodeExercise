/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > v;
vector<bool> visit;
int cnt = 0;
void dfs(int index) {
    visit[index]= true;
    cnt++;
    for (int i = 0; i < v[index].size(); ++i)
        if (visit[v[index][i]] == false)
            dfs(v[index][i]);
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n, m, a, b, even = 0;
    scanf("%d%d", &n, &m);
    v.resize(n + 1);
    visit.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1;i <= n; ++i) {
        if (i != 1) printf(" ");
        printf("%d", v[i].size());
        if (v[i].size() % 2 == 0) even++;
    }
    printf("\n");
    dfs(1);
    if (even == n && cnt == n) 
        cout << "Eulerian" << endl;
    else if (even == n - 2 && cnt == n)
        cout << "Semi-Eulerian" << endl;
    else    
        cout << "Non-Eulerian" << endl;
    return 0;
}