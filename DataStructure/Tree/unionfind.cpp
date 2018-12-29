#include <iostream>
#include "ParTree.h"

using namespace std;
#define N 10

char strInfo[N] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

int GetNum(char ch) {
    for (int i = 0; i < N; i++) 
        if (ch == strInfo[i])
            return i;
    return -1;
}

void Display(ParTree<char> &aParTree) {
    for (int i = 0; i < N; i++) {
        if (aParTree.array[i].getParent() == NULL)
            cout << "*" << " ";
        else {
            char ch = aParTree.array[i].getParent()->getValue();
            cout << GetNum(ch) << " ";
        }
    }
    cout << endl;
}

#define PATHCOMPRESSION 1 // 0-不带压缩 1-带压缩

int main(int argc, char const *argv[])
{
    ParTree<char> aParTree(N);
    cout << "* means that the node has no parents!" << endl;

    for (int i = 0; i < N; i++)
        cout << i << " ";
    cout << endl;
    int i;
    for (i = 0; i < N; i++) {
        aParTree.array[i].setValue(strInfo[i]);
        cout << strInfo[i] << " ";
    }
    cout << endl;

    cout << "Union: (A,B) (C,D) (E,F) (G,H) (I,J)" << endl;
    aParTree.Union(GetNum('A'), GetNum('B'));
    aParTree.Union(GetNum('C'), GetNum('D'));
    aParTree.Union(GetNum('E'), GetNum('F'));
    aParTree.Union(GetNum('G'), GetNum('H'));
    aParTree.Union(GetNum('I'), GetNum('J'));
    Display(aParTree);

    cout << "\nUnion: (A,D) (I,H)" << endl;
    aParTree.Union(GetNum('A'), GetNum('D'));
    aParTree.Union(GetNum('I'), GetNum('H'));
    Display(aParTree);

    #if !PATHCOMPRESSION
        cout <<"\nUnion: (F,J)" << endl;
        aParTree.Union(GetNum('F'), GetNum('J'));
        Display(aParTree);
        cout << "\nUnion: (D,J)" << endl;
        aParTree.Union(GetNum('D'), GetNum('J'));
        Display(aParTree);
    #else
        cout <<"\nUnionPC: (F,J)" << endl;
        aParTree.UnionPC(GetNum('F'), GetNum('J'));
        Display(aParTree);
        cout << "\nUnionPC: (D,J)" << endl;
        aParTree.UnionPC(GetNum('D'), GetNum('J'));
        Display(aParTree);
    #endif

    cout << endl;
    if (aParTree.Different(GetNum('D'), GetNum('E')))
        cout << "D and E are in different sets!" << endl;
    else
        cout << "D and E are in a common set!" << endl;

    return 0;
}