/*
 * 运行数据： ms  KB
 */
#include <bits/stdc++.h>

using namespace std;

const int inf = 99999999;
int cmax, n, sp, m;
int minNeed = inf, minBack = inf;
int e[510][510], dis[510], weight[510];
bool visit[510];
vector<int> pre[510], path, temppath;

void dfs(int v) {
    temppath.push_back(v);
    if (v == 0) {
        int need = 0, back = 0;
        for (int i = temppath.size() - 1; i>= 0; i--) {
            int id = temppath[i];
            // weight[id] > 0表明该节点的车辆数目大于cmax/2
            if (weight[id] > 0) {
                back += weight[id];
            }
            else {
                // back的数目够补充当前节点达到cmax/2的状态，则直接给
                if (back > (0 - weight[id])) {
                    back += weight[id]; // 虽然写的是加上，但是weight[id] < 0的
                }
                // back的数目不够了，就需要补充发放的自行数量
                else {
                    need += ((0 - weight[id]) - back);
                    back = 0;
                }
            }
        }
        if (need < minNeed) {
            minNeed = need;
            minBack = back;
            path = temppath;
        }
        else if (need == minNeed && back < minBack) {
            minBack = back;
            path = temppath;
        }
        temppath.pop_back();
        return;
    }
    for (int i = 0; i < pre[v].size(); i++) 
        dfs(pre[v][i]);
    temppath.pop_back();
}

int main(int argc, char const *argv[])
{
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
        weight[i] = weight[i] - cmax / 2;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        scanf("%d", &e[a][b]);
        e[b][a] = e[a][b];
    }
    dis[0] = 0;
    for (int i = 0; i <= n; i++) {
        int u = -1, minn = inf;
        for (int j = 0; j <= n; j++) {
            if (visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        // 获取每个节点最短路径的上一个节点
        for (int v = 0; v <= n; v++) {
            if (visit[v] == false && e[u][v] != inf) {
                if (dis[v] > dis[u] + e[u][v]) {
                    dis[v] =  dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        } 
    }
    dfs(sp);
    printf("%d 0", minNeed);
    for (int i = path.size() - 2; i>= 0; i--) {
        printf("->%d",path[i]);
    }
    printf(" %d", minBack);

    return 0;
}