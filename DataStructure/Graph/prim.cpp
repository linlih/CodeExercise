#include <iostream>
#include <queue>

#define UNVISITED 0
#define VISITED   1
#define INFINITE  9999
#define N 7

using namespace std;

#include "graph.h"
#include "graphm.h"

int minVertex(Graph &G, Dist* &D) { // 找到Dist数组中的最小值
    int i, v;
    for (i = 0; i < G.VerticesNum(); i++) 
        if (G.Mark[i] == UNVISITED) {
            v = i;
            break;
        }
    for (i = 0; i < G.VerticesNum(); i++) 
        if ((G.Mark[i] == UNVISITED) && (D[i] < D[v]))
            v = i;
    return v;
}

void AddEdgetoMST(Edge e, Edge *&MST, int n) {
    MST[n] = e;
}

void Prim(Graph &G, int s, Edge* &MST) {
    int MSTtag = 0;
    MST = new Edge[G.VerticesNum() - 1];
    Dist *D;
    D = new Dist[G.VerticesNum()];
    for (int i = 0; i < G.VerticesNum(); i++) {
        G.Mark[i] = UNVISITED;
        D[i].index = i;
        D[i].length = INFINITE;
        D[i].pre = s;
    }

    D[s].length = 0;

    int v = s;
    int i;
    for (i = 0; i < G.VerticesNum(); i++) {
        if (D[v].length == INFINITE) return;

        for (Edge e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e))
            if (G.Mark[G.ToVertex(e)] != VISITED && (D[G.ToVertex(e)].length > e.weight)) {
                D[G.ToVertex(e)].length = e.weight;
                D[G.ToVertex(e)].pre = v;
            }
        
        v = minVertex(G, D);

        G.Mark[v] = VISITED;
        Edge edge(D[v].pre, D[v].index, D[v].length);
        AddEdgetoMST(edge, MST, MSTtag++);
    }
}


// 图对应于张铭老师《数据结构与算法》P185, 图 7.23
int A[N][N] = {
// V0  V1  V2  V3  V4  V5  V6
    0, 20,  0,  0,  1,  0,  0,
   20,  0,  6,  4,  0,  0,  0,
    0,  6,  0,  0,  0,  0,  2,
    0,  4,  0,  0,  0, 12,  8,
    1,  0,  0,  0,  0, 15,  0,
    0,  0,  0, 12, 15,  0, 10,
    0,  0,  2,  8,  0, 10,  0, 
};

int main(int argc, char const *argv[])
{
    Graphm aGraphm(N);
    aGraphm.InitGraphm(&aGraphm, A);

    Edge *D;
    Prim(aGraphm, 0, D);
    for (int i = 0; i < N ; i++) 
        cout << "V" << D[i].from << "->V" << D[i].to << " Weight is : " << D[i].weight << endl;

    return 0;
}



