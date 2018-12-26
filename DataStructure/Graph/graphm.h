#ifndef __GRAPHM_H__
#define __GRAPHM_H__


// 图的相邻矩阵实现

#include "graph.h"

class Graphm:public Graph {
private:
    int **matrix;
public:
    void InitGraphm(Graphm* Graphm, int A[N][N]);
    void DFS(Graph &G, int v);
    void BFS(Graph &G, int v);
    void Visit(Graph &G, int v);

public:
    Graphm(int numVert):Graph(numVert) {
        int i, j;
        matrix = (int **)new int*[numVert];

        for (i = 0; i < numVert; i++) 
            matrix[i] = new int[numVert];
        
        // 这里可以直接使用memset来实现 memset(matrix, 0, sizeof(int) * numVert * numVert)
        for (i = 0; i < numVert; i++)
            for (j = 0; j < numVert; j++)
                matrix[i][j] = 0;
    }
    
    ~Graphm() {
        for (int i = 0; i < numVertex; i++) {
            delete matrix[i];
        delete [] matrix;
        }
    }

    Edge FirstEdge(int oneVertex) {
        Edge myEdge;
        myEdge.from = oneVertex;

        for (int i = 0; i < numVertex; i++) {
            if (matrix[oneVertex][i] != 0) {
                myEdge.to = i;
                myEdge.weight = matrix[oneVertex][i];
                break;
            }
        }
        return myEdge;
    }
    Edge NextEdge(Edge preEdge) {
        Edge myEdge;
        myEdge.from = preEdge.from;

        if (preEdge.to < numVertex) {
            for (int i = preEdge.to + 1; i < numVertex; i ++) {
                if (matrix[preEdge.from][i] != 0) {
                    myEdge.to = i;
                    myEdge.weight = matrix[preEdge.from][i];
                    break;
                }
            }
        }
        return myEdge;
    }
    void setEdge(int from, int to, int weight) {
        if (matrix[from][to] <= 0) {
            numEdge ++;
            Indegree[to] ++;
        }
        matrix[from][to] = weight;
    }
    void delEdge(int from, int to) {
        if (matrix[from][to] > 0) {
            numEdge --;
            Indegree[to] --;
        }
        matrix[from][to] = 0;
    }
};

void Graphm::Visit(Graph &G, int v) {
    cout << 'V' << v << " "; 
}

void Graphm::InitGraphm(Graphm *Graphm, int A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] > 0)
                Graphm->setEdge(i, j, A[i][j]);
        }
    }
}

#endif
