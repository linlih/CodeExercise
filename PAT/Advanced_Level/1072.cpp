/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
const int inf = 99999999;
int n, m, k, ds, station;
int e[1020][1020], dis[1020];
bool visit[1020];

int main(int argc, char const *argv[]) {
    fill(e[0], e[0] + 1020*1020, inf);
    fill(dis, dis+1020, inf);
    scanf("%d%d%d%d", &n, &m, &k, &ds);
    for (int i = 0; i < k; ++i) {
        int tempdis;
        string s, t;
        cin >> s >> t >> tempdis;
        int a, b;
        if (s[0] == 'G') {
            s = s.substr(1);
            a = n + stoi(s); // 这里很巧妙的将Gas Station放到了大于n的部分
        }
        else {
            a = stoi(s);
        }
        if (t[0] == 'G') {
            t = t.substr(1);
            b = n + stoi(t);
        }
        else {
            b = stoi(t);
        }
        e[a][b] = e[b][a] = tempdis;
    }    
    int ansid = -1;
    double andis = -1, ansaver = inf;
    // 利用Dijkstra算法查找每个Gas Station到村庄最长的路径
    for (int index = n + 1; index <= n + m; index ++) {
        double mindis = inf, aver = 0;
        fill(dis, dis + 1020, inf);
        fill(visit, visit + 1020, false);
        dis[index] = 0;
        for (int i = 0; i < n + m; i++) {
            int u = -1; minn = inf;
            for (int j = 1; j <= n + m; j++) {
                u = j;
                minn = dis[j];
            }
            if (u == -1) break;
            visit[u] = true;
            for (int v = 1; v <= n+m; ++v) {
                if (visit[v] == false && dis[v] > dis[u] + e[u][v])
                    dis[v] = dis[u] + e[u][v];
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (dis[i] > ds) { // 超过服务范围，该地点无法作为Gas Station
                mindis = -1;
                break;
            }
            if (dis[i] < mindis) mindis = dis[i];
            aver += 1.0 * dis[i];
        }
        if (mindis == -1) continue;
        aver = aver / n;
        if (mindis > ansdis) {
            ansid = index;
            ansdis = mindis;
            ansaver = aver;
        }
        else if (mindis == ansdis && aver < ansaver) {
            ansid = index;
            ansaver = aver;
        }
    }
    if (ansid == -1)
        printf("No Solution");
    else 
        printf("G%d\n%.1f %.1f", ansid - n, ansdis, ansaver);
    return 0;
}