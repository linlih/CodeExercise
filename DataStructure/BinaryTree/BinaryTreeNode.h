#ifndef __BINARYTREENODE_H__
#define __BINARYTREENODE_H__

template <class T> class BinaryTree;
template <class T> class BinarySearchTree;

template <class T>
class BinaryTreeNode {
friend class BinaryTree<T>;
friend class BinarySearchTree<T>;
private:
    T info;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

public:
    BinaryTreeNode();
    BinaryTreeNode(const T& inf);
    BinaryTreeNode(const T& inf, BinaryTreeNode<T>* l, BinaryTreeNode<T>* r);

    T value() const;
    BinaryTreeNode<T>* leftchild() const;
    BinaryTreeNode<T>* rightchild() const;
    void setLeftChild(BinaryTreeNode<T>*);
    void setRightChild(BinaryTreeNode<T>*);
    void setValue(const T& val);
    bool isLeaf() const;
    BinaryTreeNode<T>& operator = (const BinaryTreeNode<T>& Node){this = Node;};
};

template<class T>
BinaryTreeNode<T>::BinaryTreeNode() {
    left = right = NULL;
}

template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& inf) {
    info = inf;
    left = right = NULL;
}

template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& inf, BinaryTreeNode* l, BinaryTreeNode* r) {
    info = inf;
    left = l;
    right = r;
}

template<class T>
T BinaryTreeNode<T>::value() const {
    return info;
}

template<class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::leftchild() const {
    return left;
}

template<class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::rightchild() const {
    return right;
}

template<class T>
void BinaryTreeNode<T>::setLeftChild(BinaryTreeNode<T>* subroot) {
    left = subroot;
}

template<class T>
void BinaryTreeNode<T>::setRightChild(BinaryTreeNode<T>* subroot) {
    right = subroot;
}

template<class T>
void BinaryTreeNode<T>::setValue(const T& val) {
    info = val;
}

template<class T>
bool BinaryTreeNode<T>::isLeaf() const {
    return (left == NULL) && (right == NULL);
}


#endif