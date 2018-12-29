template <class T> class Tree;

template <class T>
class TreeNode {
friend class Tree<T>;
private:
    T m_Value;
    TreeNode<T>* pChild;
    TreeNode<T>* pSibling;
public:
    TreeNode(const T& value);
    virtual ~TreeNode() {};
    bool isLeaf();
    T Value();
    TreeNode<T>* LeftMostChild();
    TreeNode<T>* RightSibling();
    void setValue(T&);
    void setChild(TreeNode<T>* pointer);
    void setSibling(TreeNode<T>* pointer);
    void InsertFirst(TreeNode<T>* node);
    void InsertNext(TreeNode<T>* node);
};

template <class T>
TreeNode<T>::TreeNode(const T& value) {
    m_Value = value;
    pChild = NULL;
    pSibling = NULL;
}

template <class T>
bool TreeNode<T>::isLeaf() {
    if (pChild == NULL) 
        return true;
    return false;
}

template <class T>
T TreeNode<T>::Value() {
    return m_Value;
}

template <class T>
TreeNode<T>* TreeNode<T>::LeftMostChild() {
    return pChild;
}

template <class T>
TreeNode<T>* TreeNode<T>::RightSibling() {
    return pSibling;
}

template <class T>
void TreeNode<T>::setChild(TreeNode<T>* pointer) {
    pChild = pointer;
}

template <class T>
void TreeNode<T>::setSibling(TreeNode<T>* pointer) {
    pSibling = pointer;
}

template <class T>
void TreeNode<T>::InsertFirst(TreeNode<T>* node) {
    if (pChild)
        node->pSibling = pChild;
    pChild = node;
}

template <class T>
void TreeNode<T>::InsertNext(TreeNode<T>* node) {
    if (pSibling)
        node->pSibling = pSibling;
    pSibling = node;
}


