#include <iostream>
#include <queue>
using namespace std;

#define N 10

template <class T> class Tree;

template <class T>
class DualTagWidthTreeNode {
public:
    T info;
    int ltag;
    int rtag;

    DualTagWidthTreeNode() {};
    virtual ~DualTagWidthTreeNode() {};
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
    void setValue(T &value) {m_Value = value;};
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
    Tree(DualTagWidthTreeNode<T>* nodeArray, int count);
    TreeNode<T>* getRoot() {return root;};
    void Visit(T value) {cout << value << " ";};
    void RootFirstTraverse(TreeNode<T>* root);
};

template <class T>
Tree<T>::Tree(DualTagWidthTreeNode<T>* nodeArray, int count) {
    using std::queue;
    queue<TreeNode<T>*> aQueue;
    TreeNode<T>* pointer = new TreeNode<T>;
    root = pointer;
    for (int i = 0; i < count - 1; i++) {
        pointer->setValue(nodeArray[i].info);
        if (nodeArray[i].ltag == 0)
            aQueue.push(pointer);
        else 
            pointer->setChild(NULL);
        TreeNode<T>* temppointer = new TreeNode<T>;
        if (nodeArray[i].rtag == 0)
            pointer->setSibling(temppointer);
        else {
            pointer->setSibling(NULL);
            pointer = aQueue.front();
            aQueue.pop();
            pointer->setChild(temppointer);
        }
        pointer = temppointer;
    }
    pointer->setValue(nodeArray[count - 1].info);
    pointer->setChild(NULL);
    pointer->setSibling(NULL);
}

template <class T>
void Tree<T>::RootFirstTraverse(TreeNode<T>* root) {
    while(root != NULL) {
        Visit(root->Value());
        RootFirstTraverse(root->LeftMostChild());
        root = root->RightSibling();
    }
}

void Traverse(Tree<char>* tree) {
    cout << "FirstRoot Traverse: ";
    tree->RootFirstTraverse(tree->getRoot());
    cout << endl;
}

void DisplayTree()  {
	cout << "      A              G      \n";
	cout << "   /  |  \\         /   \\   \n";
	cout << "  B   C    D      H     I   \n";
	cout << "     / \\          |         \n";
	cout << "    E   F         J         \n";
	cout << "\n";
	cout << "rtag =  0  have right sibling" << endl;
	cout << "rtag =  1  havn't right sibling" << endl;
	cout << "ltag =  0  have left child" << endl;
	cout << "ltag =  1  havn't left child" << endl << endl;
}

void DisplayNode(char *Info, int *nRtag, int *nLtag)  {
	if (Info != NULL)  {
		cout << "info   ";
		for (int i = 0; i < N; i ++)
			cout << Info[i] << " ";
		cout << endl;
	}
	
	if (nRtag != NULL)  {
		cout << "rtag   ";
		for (int i = 0; i < N; i ++)
			cout << nRtag[i] << " ";
		cout << endl;
	}
	
	if (nLtag != NULL)  {
		cout << "ltag   ";
		for (int i = 0; i < N; i ++)
			cout << nLtag[i] << " ";
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
    DisplayTree();

    char strInfo[N] = {'A', 'G', 'B', 'C', 'D', 'H', 'I', 'E', 'F', 'J'};
    int nRtag[N] = {0, 1, 0, 0, 1, 0, 1, 0, 1, 1};
    int nLtag[N] = {0, 0, 1, 0, 1, 0, 1, 1, 1, 1};

    cout << "DualTagWidth create tree : "<< endl;
    DisplayNode(strInfo, nRtag, nLtag);

    DualTagWidthTreeNode<char>* nodeArray = new DualTagWidthTreeNode<char>[N];

    for (int i = 0; i < N; i++) {
        nodeArray[i].info = strInfo[i];
        nodeArray[i].rtag = nRtag[i];
        nodeArray[i].ltag = nLtag[i];
    }

    Tree<char> aTree(nodeArray, N);
    Traverse(&aTree);
    return 0;
}