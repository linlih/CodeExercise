#include <iostream>
#include "BinaryTree.h"


int main(int argc, char const *argv[])
{
    // 图示如张铭老师《数据结构与算法》P107, 图 5.5
    BinaryTree<char> a, b, c, d, e, f, g, h, i, nulltree;
    d.CreateTree('D', nulltree, nulltree);
    g.CreateTree('G', nulltree, nulltree);
    h.CreateTree('H', nulltree, nulltree);
    i.CreateTree('I', nulltree, nulltree);
    f.CreateTree('F', h, i);
    e.CreateTree('E', g, nulltree);
    b.CreateTree('B', d, e);
    c.CreateTree('C', nulltree, f);
    a.CreateTree('A', b, c);

    cout << "PreOrder sequence is : " << endl;
    a.PreOrder(a.Root());
    cout << endl;
    cout << "PreOrder sequence Withou Recursion is : " << endl;
    a.PreOrderWithoutRecursion(a.Root());
    cout << endl;

    cout << "InOrder sequence is : " << endl;
    a.InOrder(a.Root());
    cout << endl;
    cout << "InOrder sequence Withou Recursion is : " << endl;
    a.InOrderWithoutRecursion(a.Root());
    cout << endl;

    cout << "PostOrder sequence is : " << endl;
    a.PostOrder(a.Root());
    cout << endl;
    cout << "PostOrder sequence Withou Recursion is : " << endl;
    a.PostOrderWithoutRecursion(a.Root());
    cout << endl;

    cout << "LeverOrder sequenc is : " << endl;
    a.LevelOrder(a.Root());
    cout << endl;

    cout << "Tree Root is : " << a.Root()->value() << endl;

    return 0;
}
