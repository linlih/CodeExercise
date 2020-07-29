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
// 我的思路，根据结点是否为空作为递归返回，加上判断结点的值是否相等
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        else if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) return false;
        bool flag = false;
        if (p->val == q->val) flag =  true;
        return flag && isSameTree(p->left , q->left) && isSameTree(p->right , q->right);
    } 
};

// 也可以考虑使用层序遍历的方式进行判断
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        else if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) return false;
        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()) {
            TreeNode *n1 = q1.front();
            q1.front();
            TreeNode *n2 = q2.front();
            q2.front();
            if (n1 == NULL || n2 == NULL) return false;
            else if(n1->val != n2->val) return false;
            q1.push(n1->left);q1.push(n1->right);
            q2.push(n2->left);q2.push(n2->right);
        }
        return true;
    } 
};