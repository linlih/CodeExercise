/*
   问题描述： 
   解题思路： 关键点在于理解题意，最关键的一句话在开头：
              It is vitally important to have all the cities connected by highways in a war. 
              也就是说我们要保证的是，图的所有的结点都是连接的
              在给定的被敌人暂居的结点，设置为true，利用其它结点访问全图，则可以转换为对联通分支的求解
 */
#include <bits/stdc++.h>

using namespace std;

int v[1010][1010];
bool visit[1010];
int n;

void dfs(int node) {
    visit[node] = true;
    for (int i = 1; i <= n; i++) {
        if (visit[i] == false && v[node][i] == 1)
            dfs(i);
    }  
}

int main(int argc, char const *argv[])
{
    int m, k, a, b;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a][b] = v[b][a] = 1;
    }
    for (int i = 0; i < k; i++) {
        fill(visit, visit + 1010, false);
        scanf("%d", &a);
        int cnt = 0;
        visit[a] = true;
        for (int j = 1; j <= n;  j++) {
            if (visit[j] == false) {
                dfs(j);
                cnt ++;
            }
        }
        printf("%d\n", cnt - 1);
    }
    return 0;
}