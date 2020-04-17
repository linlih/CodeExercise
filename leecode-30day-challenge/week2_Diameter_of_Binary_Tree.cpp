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

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// reference: https://www.cnblogs.com/grandyang/p/6607318.html
// 思路是求左右子树的最大深度
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        //int left = dia
        int res = 0;
        maxDepth(root, res);
        return res;
    }

    int treeDepth(TreeNode* root) {
        if (!root) return 0;
        int left = treeDepth(root->left);
        int right = treeDepth(root->right);
        return max(left, right) + 1;
    }

    int maxDepth(TreeNode* node, int& res) {
        if (!node) return 0;
        int left = maxDepth(node->left, res);
        int right = maxDepth(node->right, res);
        res = max(res, left+right);
        return max(left, right) + 1;
    }
};

// 和上面的解题思路是一致的
class Solution_Best {
public:
    int globalDiameter = 0;
    
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return globalDiameter;
    }

    int depth(TreeNode* root) {
        if (root == NULL) return 0;
        int lHeight = depth(root->left);
        int rHeight = depth(root->right);

        int currDiameter = lHeight + rHeight;

        globalDiameter = max(currDiameter, globalDiameter);

        return max(lHeight, rHeight) + 1;
    }
}

int main(int argc, char const *argv[]) {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);

    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;

    Solution sol;
    cout << sol.treeDepth(&node1) << endl;
    cout << sol.diameterOfBinaryTree(&node1) << endl;

    return 0;
}