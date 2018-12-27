#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <stack>
#include <queue>

#include "BinaryTreeNode.h"

enum Tags{Left, Right};

template<class T>
class StackElement {
public:
    BinaryTreeNode<T>* pointer;
    Tags tag;
};

using namespace std;

template<class T>
class BinaryTree {
private:
    BinaryTreeNode<T>* root;
public:
    BinaryTree() {root = NULL;};
    ~BinaryTree() {DeleteBinaryTree(root);};
    bool isEmpty() const;
    BinaryTreeNode<T>* Root() {return root;};
    BinaryTreeNode<T>* Parent(BinaryTreeNode<T>* current);
    BinaryTreeNode<T>* LeftSibling(BinaryTreeNode<T>* current);
    BinaryTreeNode<T>* RightSibling(BinaryTreeNode<T>* current);
    void CreateTree(const T& info, BinaryTree<T>& leftTree, BinaryTree<T>& rightTree);
    void PreOrder(BinaryTreeNode<T>* root);
    void InOrder(BinaryTreeNode<T>* root);
    void PostOrder(BinaryTreeNode<T>* root);
    void PreOrderWithoutRecursion(BinaryTreeNode<T>* root);
    void InOrderWithoutRecursion(BinaryTreeNode<T>* root);
    void PostOrderWithoutRecursion(BinaryTreeNode<T>* root);
    void LevelOrder(BinaryTreeNode<T>* root);
    void DeleteBinaryTree(BinaryTreeNode<T>* root);
    void Visit(T value) {cout << value;};
};

template<class T>
bool BinaryTree<T>::isEmpty() const {
    return (root? false :true);
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::Parent(BinaryTreeNode<T>* current) {
    using std::stack;
    stack<BinaryTreeNode<T>*> aStack;
    BinaryTreeNode<T>* pointer = root;
    if (NULL != root && NULL != current) {
        while (!aStack.empty() || pointer) {
            if (pointer) {
                if (current = pointer->leftchild() || current = pointer->rightchild())
                    return pointer;
                aStack.push(pointer);
                pointer = pointer->leftchild();
            }
            else {
                pointer = aStack.top();
                aStack.pop();
                pointer = pointer->rightchild();
            }
        }
    }
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::LeftSibling(BinaryTreeNode<T>* current) {
    if (current) {
        BinaryTreeNode<T>* temp = Parent(current);
        if (temp == NULL || current == temp->leftchild()) 
            return NULL;
        else
            return temp->leftchild();
    }
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::RightSibling(BinaryTreeNode<T>* current) {
    if (current) {
        BinaryTreeNode<T>* temp = Parent(current);
        if (temp == NULL || current = temp->rightchild())
            return NULL;
        else
            return temp->rightchild();
    }
}

template<class T>
void BinaryTree<T>::CreateTree(const T& info, BinaryTree<T>& leftTree, BinaryTree<T>& rightTree) {
    root = new BinaryTreeNode<T>(info, leftTree.root, rightTree.root);
    leftTree.root = rightTree.root = NULL;
}

template<class T>
void BinaryTree<T>::DeleteBinaryTree(BinaryTreeNode<T>* root) {
    if (root) {
        DeleteBinaryTree(root->left);
        DeleteBinaryTree(root->right);
        delete root;
    }
}

template<class T>
void BinaryTree<T>::PreOrder(BinaryTreeNode<T>* root) {
    if (root != NULL) {
        Visit(root->value());
        PreOrder(root->leftchild());
        PreOrder(root->rightchild());
    }
}

template<class T>
void BinaryTree<T>::InOrder(BinaryTreeNode<T>* root) {
    if (root != NULL) {
        InOrder(root->leftchild());
        Visit(root->value());
        InOrder(root->rightchild());
    }
}

template<class T>
void BinaryTree<T>::PostOrder(BinaryTreeNode<T>* root) {
    if (root != NULL) {
        PostOrder(root->leftchild());
        PostOrder(root->rightchild());
        Visit(root->value());
    }
}

template<class T>
void BinaryTree<T>::PreOrderWithoutRecursion(BinaryTreeNode<T>* root) {
    using std::stack;
    stack<BinaryTreeNode<T>*> aStack;
    BinaryTreeNode<T>* pointer = root;
    while(!aStack.empty() || pointer) {
        if (pointer) {
            Visit(pointer->value());
            aStack.push(pointer);
            pointer = pointer->leftchild();
        }
        else {
            pointer = aStack.top();
            aStack.pop();
            pointer = pointer->rightchild();
        }
    }
}

template<class T>
void BinaryTree<T>::InOrderWithoutRecursion(BinaryTreeNode<T>* root) {
    using std::stack;
    stack<BinaryTreeNode<T>* > aStack;
    BinaryTreeNode<T>* pointer = root;
    while(!aStack.empty() || pointer) {
        if (pointer) {
            aStack.push(pointer);
            pointer = pointer->leftchild();
        }
        else {
            pointer = aStack.top();
            aStack.pop();
            Visit(pointer->value());
            pointer = pointer->rightchild();
        }
    }
}

template<class T>
void BinaryTree<T>::PostOrderWithoutRecursion(BinaryTreeNode<T>* root) {
    using std::stack;
    StackElement<T> element;
    stack<StackElement<T > > aStack;
    BinaryTreeNode<T>* pointer;
    if (root == NULL)
        return;
    else 
        pointer = root;
    
    while (!aStack.empty() || pointer) {
        while (pointer != NULL) {
            element.pointer = pointer;
            element.tag = Left;
            aStack.push(element);
            pointer = pointer->leftchild();
        }

        element = aStack.top();
        aStack.pop();
        pointer = element.pointer;

        if (element.tag == Left) {
            element.tag = Right;
            aStack.push(element);
            pointer = pointer->rightchild();
        }
        else {
            Visit(pointer->value());
            pointer = NULL;
        }
    }
}

template<class T>
void BinaryTree<T>::LevelOrder(BinaryTreeNode<T>* root) {
    using std::queue;
    queue<BinaryTreeNode<T>*> aQueue;
    BinaryTreeNode<T>* pointer = root;
    if (pointer)
        aQueue.push(pointer);
    while (!aQueue.empty()) {
        pointer = aQueue.front();
        aQueue.pop();
        Visit(pointer->value());
        if (pointer->leftchild())
            aQueue.push(pointer->leftchild());
        if (pointer->rightchild())
            aQueue.push(pointer->rightchild());
    }
}



#endif




