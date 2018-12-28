#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

#include "BinaryTree.h"

template <class T>
class BinarySearchTree:public BinaryTree<T> {
public:
    BinarySearchTree() {this->root = NULL;};
    virtual ~BinarySearchTree(){};
    void Initialize(BinaryTreeNode<T> *newpointer);
    BinaryTreeNode<T>* Root() {return this->root;};
    
    void InsertNode(BinaryTreeNode<T>* root, BinaryTreeNode<T>* newpointer);
    void DeleteNode(BinaryTreeNode<T>* pointer);
    void DeleteNodeEx(BinaryTreeNode<T>* pointer);
};

template <class T>
void BinarySearchTree<T>::Initialize(BinaryTreeNode<T>* newpointer) {
    this->root = newpointer;
}

template <class T>
void BinarySearchTree<T>::InsertNode(BinaryTreeNode<T>* root, BinaryTreeNode<T>* newpointer) {
    BinaryTreeNode<T>* pointer = NULL;
    if (root == NULL) {
        Initialize(newpointer);
        return;
    }
    else pointer = root;
    while (1) {
        if (newpointer->value() == pointer->value())
            return;
        else if (newpointer->value() < pointer->value()) {
            if (pointer->leftchild() == NULL) {
                pointer->left = newpointer;
                return;
            }
            else 
                pointer =  pointer->leftchild();
        }
        else {
            if (pointer->rightchild() == NULL) {
                pointer->right = newpointer;
                return;
            }
            else
                pointer = pointer->rightchild();
        }
    }
}
/*
template <class T>
void BinarySearchTree<T>::DeleteNode(BinaryTreeNode<T>* pointer) {
    BinaryTreeNode<T>* temppointer = NULL;
    if (!pointer)
        return;
    BinaryTreeNode<T>* parent = Parent(pointer);
    if (pointer->leftchild() == NULL) {
        if (parent == NULL)
            root = pointer->rightchild();
        else if (parent->leftchild() == pointer)
            parent->left = pointer->rightchild();
        else
            parent->right = pointer->rightchild();
        delete pointer;
        pointer = NULL;
        return;
    }
    else 
        temppointer = pointer->leftchild();
    while(temppointer->rightchild() != NULL) 
        temppointer = temppointer->rightchild();
    temppointer->right = pointer->rightchild();
    if (NULL == parent)
        root = pointer->leftchild();
    else if (parent->leftchild() == pointer)
        parent->left = pointer->leftchild();
    else
        parent->right = pointer->leftchild();
    delete pointer;
    pointer = NULL;
    return;
}*/

template <class T>
void BinarySearchTree<T>::DeleteNodeEx(BinaryTreeNode<T>* pointer) {
    if (pointer == NULL)
        return;
    BinaryTreeNode<T>* temppointer = NULL;
    BinaryTreeNode<T>* tempparent = NULL;
    BinaryTreeNode<T>* parent = this->Parent(pointer);
    if (pointer->leftchild() == NULL) {
        temppointer = pointer->rightchild();
    }
    else {
        temppointer = pointer->leftchild();
        while(temppointer->rightchild() != NULL) {
            tempparent = temppointer;
            temppointer = temppointer->rightchild();
        }
        if (tempparent == NULL)
            pointer->left = temppointer->leftchild();
        else
            temppointer->right = temppointer->leftchild();
        temppointer->left = pointer->leftchild();
        temppointer->right = pointer->rightchild();
    }
    if (parent == NULL)
        this->root = temppointer;
    else if (parent->leftchild() == pointer)
        parent->left = temppointer;
    else
        parent->right = temppointer;
    delete pointer; 
    pointer = NULL;
    return;
}

#endif