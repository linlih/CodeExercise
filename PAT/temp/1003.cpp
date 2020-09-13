/*
   问题描述：
   解题思路： 两个测试点没过
 */
#include <bits/stdc++.h>

using namespace std;

const int inf = 99999999;

int main(int argc, char const *argv[]) {
    #ifdef DEBUG
    freopen("input.txt","r",stdin);
    #endif
    int n, m, c1, c2;
    cin >> n >> m >> c1 >> c2;
    int rescure_teams[510];
    int max_teams[510];
    int graph[510][510];
    int dis[510];
    bool visit[510];    
    //int cnt = 1;
    int num[510];
    fill(num, num+510, 0);
    fill(dis, dis+510, inf);
    fill(visit, visit+510, false);
    fill(max_teams, max_teams+510, 0);
    fill(rescure_teams, rescure_teams+510, 0);
    fill(graph[0], graph[0]+510*510, inf);
    for (int i = 0; i < n; ++i) {
        cin >> rescure_teams[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    //c1 as start point
    dis[c1] = 0;
    num[c1] = 1;
    max_teams[c1] = rescure_teams[c1];
    for (int i = 0; i < n; ++i) {
        int minn = inf;
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (minn > dis[j] && visit[j] == false) {
                v = j;
                minn = dis[j];
            }
        }
        if (v == -1) break;
        visit[v] = true;
        for (int j = 0; j < n; ++j) {
            if (visit[j] == false && graph[v][j] != inf) {
                if (dis[j] > (dis[v] + graph[v][j])) {
                    dis[j] = dis[v] + graph[v][j];
                    num[j] = num[v];
                    max_teams[j] = max_teams[v] + rescure_teams[j];
                }
                else if (dis[j] == (dis[v] + graph[v][j])) {
                    if (max_teams[v] < (max_teams[j] + rescure_teams[v]))
                        max_teams[j] = max_teams[v] + rescure_teams[j];
                    //cnt++;
                    num[j] = num[v]+num[j];
                }
            }
        }
    }
    cout << num[c2] << " " <<  max_teams[c2] << endl;
    return 0;
}