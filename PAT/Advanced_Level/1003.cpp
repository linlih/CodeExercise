/*
    说明：这个问题实质就是寻找最短路径问题，差别在于加了一个需要计算最短路径上节点所拥有的rescue teams数目
*/
#include <bits/stdc++.h>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    int num_cities, num_roads, pos_c1, pos_c2;
    cin >> num_cities >> num_roads >> pos_c1 >> pos_c2;
    int rescue_teams[510] = {0};
    int inf = 99999999;
    int graph[510][510] = {inf};
    bool visit[510] = {false};
    int dis[510] = {0};
    int num[510] = {0};
    int w[510] = {0};

    for (int i = 0; i < num_cities; ++i) {
        cin >> rescue_teams[i];
        cin >> skipws;
        cout   << rescue_teams[i] << endl;

    }
    int c1, c2, length; 
    for (int i = 0; i < num_roads; ++i) {
        scanf("%d%d%d", &c1, &c2, &length);
        //cout << "--->>" << c1 << c2 << length << endl;
        graph[c1][c2] = graph[c2][c1] = length; // 无向图
        //cout << "graph" << graph[c1][c2] << endl;
    }
    dis[pos_c1] = 0;
    w[pos_c1] = rescue_teams[pos_c1];
    num[pos_c1] = 1;
    for (int i = 0; i < num_cities; ++i) {
        int u = -1; 
        int minn = inf;
        //cout << minn << endl;
        for (int j = 0; j < num_cities; ++j) {
            if (visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for (int v = 0; v < num_cities; ++v) {
            if (visit[v] == false && graph[u][v] != inf) {
                if (dis[u] + graph[u][v] < dis[v]) {
                    dis[v] = dis[u] + graph[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + rescue_teams[v];
                    cout << "1" << num[v] << endl;
                }
                else if (dis[u] + graph[u][v] == dis[v]) {
                    num[v] = num[v] + num[u];
                    if (w[u] + rescue_teams[v] > w[v])
                        w[v] = w[u] + rescue_teams[v];
                    cout << "2" <<num[v] << endl;

                }
            }
        }
    }
    printf("%d %d", num[pos_c2], w[pos_c2]);
    return 0;
}