/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node *left, *right;
};

vector<int> pre, in;

node *build(int preL, int preR, int inL, int inR) {
    if(preL > preR) return NULL;
    //cout << preL << " " << preR << " " << inL << " " << inR << endl;
    node *root = new node;
    root->val = pre[preL];
    int k;
    for (k = inL; k <= inR; ++k) {
        if (in[k] == pre[preL]) break;
    }
    int numLeft = k - inL;
    root->left = build(preL + 1, preL + numLeft, inL, k - 1);
    root->right = build(preL + numLeft + 1, preR , k + 1, inR);
    return root;
}

bool flag = false;
void preorder(node *root, int x, vector<int> &path, vector<int> &ans) {
    if (root == NULL||flag == true) return ;
    path.push_back(root->val);
    if (root->val == x) {
        ans = path;
        flag = true;
    }
    //cout << root->val << endl;
    preorder(root->left, x, path, ans);
    preorder(root->right, x, path, ans);
    path.pop_back();
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        in.push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        pre.push_back(a);
    }
    node *root = build(0, n-1, 0, n-1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
    


        vector<int> path, patha, pathb;
        flag = false;
        preorder(root, a, path, patha);
        path.clear();
        flag = false;
        preorder(root, b, path, pathb);
        if (patha.size() == 0 && pathb.size() == 0)
            printf("ERROR: %d and %d are not found.\n", a, b);
        else if (patha.size() == 0)
            printf("ERROR: %d is not found.\n", a);
        else if (pathb.size() == 0)
            printf("ERROR: %d is not found.\n", b);
        else if (patha[patha.size() - 2] == b)
            printf("%d is an ancestor of %d.\n", b, a);
        else if (pathb[pathb.size() - 2] == a)
            printf("%d is an ancestor of %d.\n", a, b);
        else 
            for (int j = 0; j < patha.size(); ++j) {
                if (patha[j] != pathb[j]) {
                    printf("LCA of %d and %d is %d.\n", a, b, patha[j-1]);
                    break;
                }
                //cout << patha[i] << " " << pathb[i] << endl;
            }
    }
    return 0;
}