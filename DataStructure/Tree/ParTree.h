#ifndef __PARTREE_H_
#define __PARTREE_H_

#include "ParTreeNode.h"

template <class T>
class ParTree {
public:
    ParTreeNode<T>* array;
    int Size;
    ParTree(const int size);
    virtual ~ParTree();
    ParTreeNode<T>* Find(ParTreeNode<T>* node) const;
    ParTreeNode<T>* FindPC(ParTreeNode<T>* node) const;
    void Union(int i, int j);
    void UnionPC(int i, int j);
    bool Different(int i, int j);
};

template <class T>
ParTree<T>::ParTree(const int size) {
    Size = size;
    array = new ParTreeNode<T>[size];
}

template <class T>
ParTree<T>::~ParTree() {
    delete []array;
}

template <class T>
ParTreeNode<T>* ParTree<T>::Find(ParTreeNode<T>* node) const {
    ParTreeNode<T>* pointer = node;
    while(pointer->getParent() != NULL)
        pointer = pointer->getParent();
    return pointer;
}

template <class T>
ParTreeNode<T>* ParTree<T>::FindPC(ParTreeNode<T>* node) const {
    if (node->getParent() == NULL)
        return node;
    
    node->setParent(FindPC(node->getParent()));
    return node->getParent();
}

template <class T>
bool ParTree<T>::Different(int i, int j) {
    ParTreeNode<T>* pointeri = Find(&array[i]);
    ParTreeNode<T>* pointerj = Find(&array[j]);
    return pointeri !=  pointerj;
}

template <class T>
void ParTree<T>::Union(int i, int j) {
    ParTreeNode<T>* pointeri = Find(&array[i]);
    ParTreeNode<T>* pointerj = Find(&array[j]);
    if (pointeri != pointerj) {
        if (pointeri->getCount() >= pointerj->getCount()) {
            pointerj->setParent(pointeri);
            pointeri->setCount(pointeri->getCount() + pointerj->getCount());
        }
        else {
            pointeri->setParent(pointerj);
            pointerj->setCount(pointeri->getCount() + pointerj->getCount());
        }
    }
}

template <class T>
void ParTree<T>::UnionPC(int i, int j) {
    ParTreeNode<T>* pointeri = FindPC(&array[i]);
    ParTreeNode<T>* pointerj = FindPC(&array[j]);

    if (pointeri != pointerj) {
        if (pointeri->getCount() >= pointerj->getCount()) {
            pointerj->setParent(pointeri);
            pointeri->setCount(pointeri->getCount() + pointerj->getCount());
        }
        else {
            pointeri->setParent(pointerj);
            pointerj->setCount(pointeri->getCount() + pointerj->getCount());
        }
    }
}
#endif

