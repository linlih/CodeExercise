/*******************************************************************
  > File Name    : 3.cpp
  > Author       : linlh
  > Created  Time: 2021.03.29 21:58
  > Modified Time: 2021.03.29 22:53
 *******************************************************************/

#include "bits/stdc++.h"
using namespace std;
const int inf = INT_MAX;
// int main()
// {
//     int n, m, c1, c2;
//     cin >> n >> m >> c1 >> c2;
//     int rescure_teams[510]; // 记录每个节点的救援队伍数量
//     int max_teams[510];     // 记录每条路径最多的队伍数量
//     int graph[510][510];    // 无向图
//     int dis[510];           // 每个节点的最短距离
//     bool visit[510];        // 节点是否访问
//     int num[510];           // 共有几条路径可以到达
//
//     // 初始化所有变量，很重要！没有初始化有可能出现异常的bug
//     fill(num, num+510, 0);
//     fill(dis, dis+510, inf);
//     fill(visit, visit+510, false);
//     fill(max_teams, max_teams+510, 0);
//     fill(rescure_teams, rescure_teams+510, 0);
//     fill(graph[0], graph[0] + 510*510, inf);
//
//     for (int i = 0; i < n; ++i)
//         cin >> rescure_teams[i];
//     for (int i = 0; i < m; ++i) {
//         int a, b, c;
//         cin >> a >> b >> c;
//         graph[a][b] = c;
//         graph[b][a] = c;
//     }
//     dis[c1] = 0;
//     num[c1] = 1;
//     max_teams[c1] = rescure_teams[c1];
//     for (int i = 0; i < n; ++i) {
//         int minn = inf;
//         int v = -1;
//         for (int j = 0; j < n; ++j) {
//             if (minn > dis[j] && visit[j] == false) {
//                 v = j;
//                 minn = dis[j];
//             }
//         }
//         if (v == -1) break;
//         visit[v] = true;
//         for (int j = 0; j < n; ++j) {
//             if (visit[j] == false && graph[v][j] != inf) {
//                 // 如果当前节点的最短路径dis[j]比节点v加上v到j路径长度要长，则更新最短路径
//                 if (dis[j] > (dis[v] + graph[v][j])) {
//                     dis[j] = dis[v] + graph[v][j];
//                     num[j] = num[i];
//                     max_teams[j] = max_teams[v] + rescure_teams[j];
//                 }
//                 // 如果当前节点的最短路径dis[j]比节点v加上v到j路径长度相同，那么要判断更新救援队伍数量和路径条数
//                 else if (dis[j] == (dis[v] + graph[v][j])) {
//                     if (max_teams[v] < (max_teams[j] + rescure_teams[v]))
//                         max_teams[j] = max_teams[v] + rescure_teams[j];
//                     num[j] = num[v] + num[j];
//                 }
//             }
//         }
//     }
//     cout << num[c2] << " " << max_teams[c2] <<endl;
//     return 0;
// }
//
//
int main(int argc, char* argv[]) {
    int n, m, c1, c2;
    cin >> n >> m >> c1 >> c2;
    
    int rescure_teams[510];
    int max_teams[510];
    int dis[510];
    bool visit[510];
    int graph[510][510];
    int num[510];

    fill(rescure_teams, rescure_teams+510, 0);
    fill(max_teams, max_teams+510, 0);
    fill(dis, dis+510, inf);
    fill(visit, visit+510, false);
    fill(graph[0], graph[0]+510*510, inf);
    fill(num, num+510, 0);

    for (int i = 0; i < n; ++i) {
        cin >> rescure_teams[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }

    num[c1] = 1;
    dis[c1] = 0;
    max_teams[c1] = rescure_teams[c1];
    
    for (int i = 0; i < n; ++i) {
        int minn = inf,v = -1;
        for (int j = 0; j < n; ++j) {
            if (minn > dis[j] && visit[j] == false) {
                minn = dis[j];
                v = j;
            }
        }
        if (v == -1) break;
        visit[v] = true;
        for (int j = 0; j < n; ++j) {
            if (visit[j] == false && graph[v][j] != inf) {
                if (dis[j] > (dis[v] + graph[v][j])) {
                    dis[j] = dis[v] + graph[v][j];
                    max_teams[j] = max_teams[v] + rescure_teams[j];
                    num[j] = num[v];
                }
                else if (dis[j] ==(dis[v] + graph[v][j])) {
                    if (max_teams[j] < max_teams[v] + rescure_teams[j])
                        max_teams[j] = max_teams[v] + rescure_teams[j];
                    num[j] += num[v];
                }
            }
        }
    }

    cout << num[c2] << " " << max_teams[c2] << endl; 
    return 0;
}
// 这道题思路比较明确，和柳姐的思路一样，不再写一遍了
