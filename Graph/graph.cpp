#include <iostream>
#include <queue>

#define UNVISITED 0
#define VISITED   1
#define N 5
using namespace std;
#include "graphm.h"
#include "minheap.h"

using namespace std;

class Dist {
public:
    int index;
    int length;
    int pre;
    Dist() {};
    ~Dist() {};

    bool operator < (const Dist &arg) {
        return (length < arg.length);
    }
    bool operator == (const Dist &arg) {
        return (length == arg.length);
    }
    bool operator > (const Dist &arg) {
        return (length > arg.length);
    }
    bool operator <= (const Dist &arg) {
        return (length <= arg.length);
    }
    bool operator >= (const Dist &arg) {
        return (length >= arg.length);
    }
};

void Dijkstra(Graph &G, int s, Dist* &D) {
    D = new Dist[G.VerticesNum()];
    for (int i = 0; i < G.VerticesNum(); i++) {
        G.Mark[i] = UNVISITED;
        D[i].index = i;
        D[i].length = INFINITE;
        D[i].pre = s;
    } 
    D[s].length = 0;
    MinHeap<Dist> H(G.EdgesNum());
    H.Insert(D[s]);
    for (int i = 0; i < G.VerticesNum(); i++) {
        bool FOUND = false;
        Dist d;
        while (!H.isEmpty()) {
            d = H.RemoveMin();
            //  if (G.Mark[d.index] == UNVISITED) {
            //      cout << "vertex index :" << d.index << "  ";
            //      cout << "vertex pre :" << d.pre   << "  ";
            //      cout << "V0 --> V" << d.index << " length :" << d.length << endl;
            //  }

            if (G.Mark[d.index] == UNVISITED)
            {
                FOUND = true;
                break;
            }
        }

        if (!FOUND)
            break;
        int v = d.index;
        G.Mark[v] = VISITED;

        
        for (Edge e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e))
        {
            if (D[G.ToVertex(e)].length > (D[v].length + G.Weight(e))) {
                D[G.ToVertex(e)].length = D[v].length + G.Weight(e);
                D[G.ToVertex(e)].pre = v;
                H.Insert(D[G.ToVertex(e)]);
            } 
        }
        
    } 

}

int A[N][N] = {
    0, 10,  0, 30, 100,
    0,  0, 50,  0,   0,
    0,  0,  0,  0,  10,
    0, 10, 20,  0,  60,
    0,  0,  0,  0,   0,
};


int main(int argc, char const *argv[])
{
    Graphm aGraphm(N);
    aGraphm.InitGraphm(&aGraphm, A);
    Dist *D;
    Dijkstra(aGraphm, 0, D);

    cout << "output the distance array : ";
    for (int i = 0; i < aGraphm.VerticesNum(); i++) {
        cout <<  D[i].length << " ";
    }
    cout << endl;

    return 0;
}
