/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

// ref: https://www.cnblogs.com/grandyang/p/4280120.html
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* node, int& res) {
        if (!node) return 0;
        int left = max(helper(node->left, res), 0);
        int right = max(helper(node->right, res), 0);
        res = max(res, left + right + node->val);
        return max(left, right) + node->val;
    }
};

int main(int argc, char const *argv[]) {
    
    return 0;
}