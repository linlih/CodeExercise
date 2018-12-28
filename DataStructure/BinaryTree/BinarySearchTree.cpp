#include <iostream>

using namespace std;

#include "BinarySearchTree.h"

#define N 11

int main(int argc, char const *argv[])
{
    // 图示位于张铭老师《数据结构与算法》P116，图 5.11
    int K[N] = {50, 19, 35, 55, 20, 5, 100, 52, 88, 53, 92};
    BinarySearchTree<int> aBST;
    BinaryTreeNode<int > *newpointer, *node1, *node2;

    for (int i = 0; i < N; i++) {
        newpointer = new BinaryTreeNode<int>();
        newpointer->setValue(K[i]);
        aBST.InsertNode(aBST.Root(), newpointer);

        if (K[i] == 52) {
            node1 = newpointer;
        }

        if (K[i] == 55) {
            node2 = newpointer;
        }
    }

    cout << "LevelOrder sequence of BST : " << endl;
    aBST.LevelOrder(aBST.Root());
    cout << endl;


    cout << "delete Node 52, 55 : " << endl;
    aBST.DeleteNodeEx(node1);
    aBST.DeleteNodeEx(node2);

    cout << "After delete LevelOrder sequence of BST : " << endl;
    aBST.LevelOrder(aBST.Root());
    cout << endl;
    
    return 0;
}
