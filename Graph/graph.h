//*********** Graph.h **************//
// 图的基类

#ifndef __GRAPH_H__
#define __GRAPH_H__

#define UNVISITED 0
#define VISITED   1
#define INFINITE 9999

class Edge {
public:
    int weight; // 边的权值
    int from;   // 边的起点
    int to;     // 边的终点
    
    Edge(){
        from = -1; to = -1; weight = 0;
    }
    Edge(int f, int t, int w){
        from = f; to = t; weight = w;
    }
    bool operator < (const Edge &arg) {return  (this->weight < arg.weight);};
    bool operator == (const Edge &arg) {return  (this->weight == arg.weight);};
    bool operator > (const Edge &arg) {return  (this->weight > arg.weight);};
    bool operator <= (const Edge &arg) {return  (this->weight <= arg.weight);};
    bool operator >= (const Edge &arg) {return  (this->weight >= arg.weight);};
};

class Graph {
public:
    int numVertex; // 图顶点的个数
    int numEdge;   // 图的边的数目
    int *Mark;     // 标记节点是否访问的数组
    int *Indegree; // 保存图顶点的入度数组

    Graph(int numVert) {
        numVertex = numVert;
        numEdge = 0;
        Indegree = new int[numVertex];
        Mark = new int[numVertex];

        for(int i = 0; i < numVertex; i++){
            Mark[i] = UNVISITED;
            Indegree[i] = 0;
        }
    }

    ~Graph() {
        delete [] Mark;
        delete [] Indegree;
    }

    virtual Edge FirstEdge(int oneVertex) {
        Edge myEdge;
        myEdge.from = oneVertex;
        myEdge.to = -1;
        return myEdge;
    }

    virtual Edge NextEdge(Edge preEdge) {
        return preEdge;
    }

    int VerticesNum() {
        return numVertex;
    }

    int EdgesNum() {
        return numEdge;
    }

    int FromVertex(Edge oneEdge) {
        return oneEdge.from;
    }

    int ToVertex(Edge oneEdge){
        return oneEdge.to;
    }

    int Weight(Edge oneEdge) {
        return oneEdge.weight;
    }

    bool IsEdge(Edge oneEdge) {
        // 是边的条件要满足权值大于零小于INFINITE并且有边的终点
        if  (oneEdge.weight > 0 && oneEdge.weight < INFINITE && oneEdge.to >= 0)
            return true;
        else 
            return false;
    }

    virtual void setEdge(int from, int to, int weight) = 0;
    virtual void delEdge(int from, int to) = 0;
};

#endif
