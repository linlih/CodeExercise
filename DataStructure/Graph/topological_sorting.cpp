#include <iostream>
#include <queue>

using namespace std;
#define N 9
#include "graph.h"
#include "graphm.h"

void Visit(Graph &G, int v) {
    cout << "C" << v << " ";
}

void Visit(int v) {
    cout << "C" << v << " ";
}


void ToposortbyQueue(Graph &G) {
    int i;
    for (i = 0; i < G.VerticesNum(); i++)
        G.Mark[i] = UNVISITED;
    using std::queue;
    queue<int> Q;
    for (i = 0; i < G.VerticesNum(); i++) 
        if (G.Indegree[i] == 0) 
            Q.push(i);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        Visit(G, v);
        G.Mark[v] = VISITED;
        for (Edge e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e)) {
            G.Indegree[G.ToVertex(e)] --;
            if (G.Indegree[G.ToVertex(e)] == 0)
                Q.push(G.ToVertex(e));
        }
    }
    for (i = 0; i < G.VerticesNum(); i++) 
        if (G.Mark[i] == UNVISITED) {
            cout << "the graph contains circle!" << endl;
            break;
        }
}
 
int A[N][N] = {  // 张铭老师课本《数据结构与算法》P178, 图 7.17
// C0  C1  C2  C3  C4  C5  C6  C7  C8
    0,  0,  1,  0,  0,  0,  0,  1,  0,
    0,  0,  1,  1,  1,  0,  0,  0,  0,
    0,  0,  0,  1,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  1,  1,  0,  0,
    0,  0,  0,  0,  0,  1,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  1,
    0,  0,  0,  0,  0,  0,  1,  0,  0,
};

int main(int argc, char const *argv[])
{
    Graphm aGraphm(N);
    aGraphm.InitGraphm(&aGraphm, A);

    cout << "Top sort by Queue is :" ;
    ToposortbyQueue(aGraphm);
    cout << "\n OK!" << endl;
    return 0;
}

