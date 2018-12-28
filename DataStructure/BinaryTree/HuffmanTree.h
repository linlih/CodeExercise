#ifndef __HUFFMANTREE_H__
#define __HUFFMANTREE_H__

#include "minheap.h"
#include <iostream>

using namespace std;

template <class T> class HuffmanTree;
template <class T>
class HuffmanTreeNode {
    friend class HuffmanTree<T>;
private:
    T info;
    HuffmanTreeNode<T>* parent;
    HuffmanTreeNode<T>* left;
    HuffmanTreeNode<T>* right;
public:
    HuffmanTreeNode() {};
    HuffmanTreeNode<T>* leftchild() {return left;};
    HuffmanTreeNode<T>* rightchild() {return right;};
    bool operator > (HuffmanTreeNode<T> &HN) {return info > HN.info;};
    bool operator < (HuffmanTreeNode<T> &HN) {return info < HN.info;};
    bool operator == (HuffmanTreeNode<T> &HN) {return info == HN.info;};
};


template <class T>
class HuffmanTree {
private:
    HuffmanTreeNode<T>* root;

    void MergeTree(HuffmanTreeNode<T> &ht1, HuffmanTreeNode<T> &ht2, HuffmanTreeNode<T>* parent);
    void DeleteTree(HuffmanTreeNode<T>* root);
public:
    HuffmanTree(T weight[], int n);
    virtual ~HuffmanTree() {DeleteTree(root);};
    void InOrder(HuffmanTreeNode<T> *root);
    HuffmanTreeNode<T>* GetRoot() {return root;};
};

template <class T>
HuffmanTree<T>::HuffmanTree(T weight[], int n) {
    MinHeap<HuffmanTreeNode<T> > heap(n);
    HuffmanTreeNode<T>* parent, firstchild, secondchild;
    HuffmanTreeNode<T>* Nodelist = new HuffmanTreeNode<T>[n];
    int i;
    for (i = 0; i < n; i++) {
        Nodelist[i].info = weight[i];
        Nodelist[i].parent =  Nodelist[i].left = Nodelist[i].right = NULL;
        heap.Insert(Nodelist[i]);
    }
    for (i = 0; i < n-1; i++) {
        parent = new HuffmanTreeNode<T>;
        firstchild = heap.RemoveMin();
        secondchild = heap.RemoveMin();
        MergeTree(firstchild, secondchild, parent);
        heap.Insert(*parent);
        root = parent;
    }
    delete []Nodelist;
}

template <class T>
void HuffmanTree<T>::DeleteTree(HuffmanTreeNode<T>* root) {
    if (root) {
        DeleteTree(root->left);
        DeleteTree(root->right);
        delete root;
    }
}

template <class T>
void HuffmanTree<T>::InOrder(HuffmanTreeNode<T> *root) {
    if (root) {
        InOrder(root->left);
        cout << root->info << " ";
        InOrder(root->right);
    }
}

template <class T>
void HuffmanTree<T>::MergeTree(HuffmanTreeNode<T> &ht1, HuffmanTreeNode<T> &ht2, HuffmanTreeNode<T> *parent) {
    HuffmanTreeNode<T>* l = new HuffmanTreeNode<T>();
    HuffmanTreeNode<T>* r = new HuffmanTreeNode<T>();

    *l = ht1;
    *r = ht2;

    parent->parent = NULL;
    parent->left = l;
    parent->right = r;
    parent->info = ht1.info + ht2.info;
    ht1.parent = ht2.parent = parent;
} 

#endif
