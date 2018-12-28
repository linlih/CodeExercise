#include <iostream>
using namespace std;
#include "HuffmanTree.h"



int main(int argc, char const *argv[])
{
    int weight[] = {6, 2, 3, 4};

    HuffmanTree<int> a(weight, 4);
    cout << "HuffmanTree is constructed. " << endl;

    cout << "InOrder sequence is : " << endl;
    a.InOrder(a.GetRoot());
    return 0;
}


