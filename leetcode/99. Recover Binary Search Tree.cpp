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
// reference: 
class Solution {
public:
    TreeNode *firstElement = NULL;
    TreeNode *secondElement = NULL;
    TreeNode prevElement = new TreeNode(INT64_MIN);
    void inorder(TreeNode*root) {
        if(root == NULL) return;
        inorder(root->left);
        if (firstElement == NULL && prevElement->val >= root->val) {
            firstElement = prevElement;
        }
        if (firstElement != NULL && prevElement->val >= root->val) {
            secondElement = root;
        }        
        prevElement = root;

        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        int tmp = firstElement->val;
        firstElement->val = secondElement->val;
        secondElement->val = tmp;
    };
};