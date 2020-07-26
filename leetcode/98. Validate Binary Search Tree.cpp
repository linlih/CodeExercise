/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 参考自Solution评论区：fudonglai
// 方法特别巧妙，因为要保证的是BST的性质，记录了左右子树的最大值，最小值
class Solution {
public:
    bool isValidBST(TreeNode* root, TreeNode* min=NULL, TreeNode* max=NULL) {
        if (root == NULL) return true;
        if (min != NULL && root->val <= min->val) return false;
        if (max != NULL && root->val >= max->val) return false;
        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }
};

// 自己的思路，利用BST数的性质：中序遍历得到的是一个有序序列
class Solution {
public:
    //vector<int> seq;
    void inorder(TreeNode* root, vector<int> &seq) {
        if (root == NULL) return;
        inorder(root->left, seq);
        seq.push_back(root->val);
        inorder(root->right, seq);
    }
    bool isValidBST(TreeNode* root) {
        // 利用BST树中序是有序的来实现
        vector<int> seq;
        inorder(root, seq);
        bool res = true;
        if (seq.size() > 1) // 这里要注意判断，处理输入为空或者1个节点的情况
            for (int i = 0; i < seq.size() - 1; ++i) {
                if (seq[i] >= seq[i+1]) {
                    res = false; break;
                }
            }
        return res;
    }
};