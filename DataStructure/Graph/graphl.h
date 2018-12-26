// 图的邻接表实现
#ifndef __GRAPHL_H__
#define __GRAPHL_H__

#include "graph.h"
#include <queue>

#define UNVISITED 0
#define VISITED   1
#define INFINITE 0xffffffff
#define N  5 // 定义图的顶点数目

using namespace std;

struct listUnit { // 邻接表表目中数据结构部分的结构定义
    int vertex; // 边的终点
    int weight; // 边的权
};

template<class Elem>
class Link {
public:
    Elem element;
    Link *next;
    Link(const Elem& elemval, Link *nextval = NULL) {
        element = elemval;
        next = nextval;
    }
    Link(Link *nextval = NULL) {
        next = nextval;
    }
};

template<class Elem>
class LList {
    Link<Elem>* head;
    LList() {
        head = new Link<Elem>();
    }

    void removeall() {
        Link<Elem> *fence;
        while(head != NULL){
            fence = head;
            head = head->next;
            delete fence;
        }
    }
    ~LList() {
        removeall();
    }
};

class Graphl: public Graph {
private:
    LList<listUnit> *graList; // 保存所有边表的数组
public:
    Graphl(int numVert):Graph(numVert) {
        graList = new LList<listUnit>[numVert];
    }

    ~Graphl() {
        delete [] graList;
    }

    Edge FirstEdge(int oneVertex) {
        Edge myEdge;
        myEdge.from = oneVertex;
        Link<listUnit> *temp = graList[oneVertex].head;
        if(temp->next != NULL) {
            myEdge.to = temp->next->element.vertex;
            myEdge.weight = temp->next->element.weight;
        }

        // 如果找到了顶点oneVertex的第一条边，则返回的myEdge确实是一条边;如果么有找到顶点的oneVertex的第一条边，那么myEdge的成员变量to为-1，根据IsEgde函数可以判断myEdge不是一条边
        return myEdge;
    }

    Edge NextEdge(Edge preEdge) {
        Edge myEdge;
        myEdge.from = preEdge.from;
        Link<listUnit> *temp = graList[preEdge.from].head;
        while (temp->next != NULL && temp->next->element.vertex <= preEdge.to)
            temp = temp->next;
        if (temp->next != NULL) {
            myEdge.to = temp->next->element.vertex;
            myEdge.weight = temp->next->element.weight;
        }
        return myEdge;
    }

    void setEdge(int from, int to, int weight) {
        Link<listUnit> *temp = graList[from].head;

        while (temp->next != NULL && temp->next->element.vertex < to)
            temp = temp->next;
        
        // 表中不存在这条边，则添加一条边
        if (temp->next == NULL) {
            temp->next = new Link<listUnit>;
            temp->next->element.vertex = to;
            temp->next->element.weight = weight;
            numEdge ++;
            Indegree[to] ++;
            return;
        }

        // 如果表中已经存在了这条边的话，直接修改对应的权值即可
        if (temp->next->element.vertex == to){
            temp->next->element.weight = weight;
            return;
        }

        // 边(from, to)或<from, to>在边表中不存在，但在边表中其后存在其他边，则在边表中插入这条边
        if (temp->next->element.vertex > to)
        {
            Link<listUnit> *other = temp->next;
            temp->next = new Link<listUnit>;
            temp->next->element.vertex = to;
            temp->next->element.weight = weight;
            temp->next->next = other;
            numEdge ++;
            Indegree[to] ++;
            return;
        }
    }

    void delEdge(int from, int to) {
        Link<listUnit> *temp = graList[from].head;
        
        while(temp->next != NULL && temp->next->element.vertex < to)
            temp = temp->next;
        
        if ((temp->next == NULL) || (temp->next->element.vertex > to))
            return;

        if (temp->next->element.vertex == to) {
            Link<listUnit> *other = temp->next->next;
            delete temp->next;
            temp->next = other;
            numEdge --;
            Indegree[to] --;
            return;
        }  
    }

    void InitGraphl(Graphl *graphl, int A[N][N]);
    void DFS(Graph& G, int v);
    void BFS(Graph& G, int v);
    void Visit(Graph& G, int v);
};

void Graphl::InitGraphl(Graphl *graphl, int A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] > 0) {
                graphl->setEdge(i, j, A[i][j]);
            }
        }
    }
}

void Graphl::DFS(Graph& G, int v) {
    G.Mark[v] = VISITED;
    Visit(G, v);

    for(Edge = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e)){
        if (G.Mark[G.ToVertex(e)] == UNVISITED)
            DFS(G, G.ToVertex(e));
    }
}

void Graphl::BFS(Graph& G, int v) {
    using std::queue;
    queue<int> Q;
    Visit(G, v);
    G.Mark[v] = VISITED;
    Q.push(v);
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (Edge e = G.FirstEdge(u); G.IsEdge(e); e = G.NextEdge(e)) {
            Visit(G, G.ToVertex(e));
            G.Mark[G.ToVertex(e)] = VISITED;
            Q.push(G.ToVertex(e));
        }
    }
}

void graphl::Visit(Graph& G, int v) {
    cout << 'V' << v << " ";
}


#endif
