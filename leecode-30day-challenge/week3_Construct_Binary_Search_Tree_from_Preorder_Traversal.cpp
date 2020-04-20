/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// ref: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/discuss/252232/JavaC%2B%2BPython-O(N)-Solution
class Solution {
public:
    int i = 0;
    TreeNode* bstFromPreorder(vector<int>& A, int bound = INT_MAX) {
        if (i == A.size() || A[i] > bound) return NULL;
        TreeNode* root = new TreeNode(A[i++]);
        root->left = bstFromPreorder(A, root->val);
        root->right = bstFromPreorder(A, bound);
        return root;
    }
};

class Solution_Best {
public:
    TreeNode* constructBinTree(TreeNode *root, int &cval) {
        if(root==NULL) {
            root=new TreeNode(cval);
            
        } else if(cval < root->val) {
            root->left = constructBinTree(root->left, cval);
        } else if( cval> root->val) {
            root->right = constructBinTree(root->right, cval);
        }
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = constructBinTree(root,preorder[0]);;
        for(int i = 1; i<preorder.size() ;i++) {
            constructBinTree(root,preorder[i]);
        }
        return root;
    }
    
};

int main(int argc, char const *argv[]) {
    
    return 0;
}