#include <iostream>
#include <stack>

using namespace std;

#define N 10

template <class T> class Tree;

template <class T>
class DualTagTreeNode {
public:
    T info;
    int ltag;
    int rtag;

    DualTagTreeNode() {};
    virtual ~DualTagTreeNode() {}
};

template <class T>
class TreeNode {
friend class Tree<T>;
private:
    T m_Value;
    TreeNode<T>* pChild;
    TreeNode<T>* pSibling;
public:
    TreeNode() {};
    TreeNode(const T& value) {m_Value = value; pChild = NULL; pSibling = NULL;};
    T Value() {return m_Value;};
    TreeNode<T>* LeftMostChild() {return pChild;};
    TreeNode<T>* RightSibling() {return pSibling;};
    void setValue(T& value) {m_Value = value;};
    void setChild(TreeNode<T>* pointer) {pChild = pointer;};
    void setSibling(TreeNode<T>* pointer) {pSibling = pointer;};
};

template <class T>
class Tree {
private:
    TreeNode<T>* root;
    TreeNode<T>* getParent(TreeNode<T>* root, TreeNode<T>* current);
public:
    Tree() {root = NULL;};
    Tree(DualTagTreeNode<T>* nodeArray, int count);
    TreeNode<T>* getRoot() {return root;};
    void Visit(T value) {cout << value << " ";};
    void RootFirstTraverse(TreeNode<T>* root); 
};

template <class T>
Tree<T>::Tree(DualTagTreeNode<T>* nodeArray, int count) {
    using std::stack;
    stack<TreeNode<T>* > aStack;
    TreeNode<T>* pointer = new TreeNode<T>;
    root = pointer;
    for (int i = 0; i < count - 1; i++) {
        pointer->setValue(nodeArray[i].info);
        if (nodeArray[i].rtag == 0)
            aStack.push(pointer);
        else 
            pointer->setSibling(NULL);
        TreeNode<T>* temppointer = new TreeNode<T>;
        if (nodeArray[i].ltag == 0)
            pointer->setChild(temppointer);
        else {
            pointer->setChild(NULL);
            pointer = aStack.top();
            aStack.pop();
            pointer->setSibling(temppointer);
        }
        pointer = temppointer;
    }
    pointer->setValue(nodeArray[count - 1].info);
    pointer->setChild(NULL);
    pointer->setSibling(NULL);
}

template <class T>
void Tree<T>::RootFirstTraverse(TreeNode<T>* root) {
    while (root != NULL) {
        Visit(root->Value());
        RootFirstTraverse(root->LeftMostChild());
        root = root->RightSibling();
    }
}

void DisplayTree() {
    cout << "    A            G   \n";
    cout << "  / | \\         / \\ \n";
    cout << " B  C  D       H   I \n";
    cout << "   / \\         |    \n";
    cout << "  E   F        J     \n";
    
    cout << "rtag = 0, there is    a right sibling" << endl;
    cout << "rtag = 1, there isn't a right sibling" << endl;
    cout << "ltag = 0, there is    a left child"    << endl;
    cout << "ltag = 1, there isn't a left child"    << endl;
}

void DisplayNode(char *Info, int *nRtag, int *nLtag) {
    if (Info != NULL) {
        cout << "info: ";
        for (int i = 0; i < N; i++)
            cout << Info[i] << " " ;
        cout << endl;
    }

    if (nRtag != NULL) {
        cout << "rtag: ";
        for (int i = 0; i < N; i++) 
            cout << nRtag[i] << " ";
        cout << endl;
    }

    if (nLtag != NULL) {
        cout << "ltag: ";
        for (int i = 0; i < N; i++) 
            cout << nLtag[i] << " ";
        cout << endl;
    }
}

void Traverse(Tree<char>* tree) {
    cout << "FirstRoot Traverse: ";
    tree->RootFirstTraverse(tree->getRoot());
    cout << endl;
}

int main(int argc, char const *argv[])
{
    DisplayTree();

    char strInfo[N] = {'A', 'B', 'C', 'E', 'F', 'D', 'G', 'H', 'J', 'I'};
    int nRtag[N] = {0, 0, 0, 0, 1, 1, 1, 0, 1, 1};
    int nLtag[N] = {0, 1, 0, 1, 1, 1, 0, 0, 1, 1};

    cout << "DualTrgFirstRoot create tree: " << endl;
    DisplayNode(strInfo, nRtag, nLtag);

    DualTagTreeNode<char> *nodeArray = new DualTagTreeNode<char>[N];

    for (int i = 0; i < N; i++) {
        nodeArray[i].info = strInfo[i];
        nodeArray[i].rtag = nRtag[i];
        nodeArray[i].ltag = nLtag[i];
    }

    Tree<char> aTree(nodeArray, N);
    Traverse(&aTree);

    return 0;
}