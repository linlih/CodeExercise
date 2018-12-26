#include <iostream>

#define N 3
using namespace std;
#include "graph.h"
#include "graphm.h"

//*****************************************************
//这里要注意 图类中的边为无穷大的时候也应该看成是一条边
//所以要修改一下graph.h中IsEdge函数的定义
//******************************************************

void Floyd(Graph &G, Dist **&D) {
    int i, j, v;
    D = new Dist*[G.VerticesNum()];
    for (i = 0; i < G.VerticesNum(); i++) 
        D[i] = new Dist[G.VerticesNum()];
    for (i = 0; i < G.VerticesNum(); i++) {
        for (j = 0; j < G.VerticesNum(); j++) {
            if (i == j) {
                D[i][j].length = 0;
                D[i][j].pre = i;
            }
            else {
                D[i][j].length = INFINITE;
                D[i][j].pre = -1; 
            }
        }
    }
    for ( v = 0; v < G.VerticesNum(); v++)
        for (Edge e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e)) {
            D[v][G.ToVertex(e)].length = G.Weight(e);
            D[v][G.ToVertex(e)].pre = v;
        }
    
    for (v = 0; v < G.VerticesNum(); v++) 
        for (i = 0; i < G.VerticesNum(); i++)
            for (j = 0; j < G.VerticesNum(); j++)
                if (D[i][j].length > D[i][v].length + D[v][j].length) {
                    D[i][j].length = D[i][v].length + D[v][j].length;
                    D[i][j].pre = D[v][j].pre;
                }


}

// 对应张铭老师《数据结构与算法》P183, 图 7.20
int A[N][N] = {
//  v0 v1 v2
    0,  INFINITE,  2,
    5,  0,   8,
    INFINITE,  3, 0,
};

int main(int argc, char const *argv[])
{
    Graphm aGraphm(N);
    aGraphm.InitGraphm(&aGraphm, A);

    Dist **D;
    Floyd(aGraphm, D);

    for (int i = 0; i < N; i ++)  {
		for (int j = 0; j < N; j ++)
			cout << D[i][j].length << " ";
		cout << endl;
	}
    return 0;
}

