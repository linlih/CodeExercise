#ifndef __TREE_H__
#define __TREE_H__

#include <iostream>
using namespace std;

template <class T>
class Tree {
private:
    TreeNode<T>* root;
    void DestroyNodes(TreeNode<T>* root);
public:
    Tree();
    virtual ~Tree();
    TreeNode<T>* getRoot();
    void CreateRoot(const T& value);
    bool isEmpty();
    TreeNode<T>* Parent(TreeNode<T>* current);
    TreeNode<T>* PrevSibling(TreeNode<T>* current);
    void DeleteSubTree(TreeNode<T>* subroot);
    void RootFirstTraverse(TreeNode<T>* root);
    void RootLastTraverse(TreeNode<T>* root);
    void WidthTraverse(TreeNode<T>* root);
    void Visit(T value) {
        cout << value << " ";
    };
};





#endif
