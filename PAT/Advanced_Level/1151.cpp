// /*
//    问题描述：
//    解题思路： 
//  */
// #include <bits/stdc++.h>

// using namespace std;

// struct node {
//     int val;
//     node *left, *right;
// };

// vector<int> pre, in;

// node *build(int preL, int preR, int inL, int inR) {
//     if(preL > preR) return NULL;
//     //cout << preL << " " << preR << " " << inL << " " << inR << endl;
//     node *root = new node;
//     root->val = pre[preL];
//     int k;
//     for (k = inL; k <= inR; ++k) {
//         if (in[k] == pre[preL]) break;
//     }
//     int numLeft = k - inL;
//     root->left = build(preL + 1, preL + numLeft, inL, k - 1);
//     root->right = build(preL + numLeft + 1, preR , k + 1, inR);
//     return root;
// }

// bool flag = false;
// void preorder(node *root, int x, vector<int> &path, vector<int> &ans) {
//     if (root == NULL||flag == true) return ;
//     path.push_back(root->val);
//     if (root->val == x) {
//         ans = path;
//         flag = true;
//     }
//     //cout << root->val << endl;
//     preorder(root->left, x, path, ans);
//     preorder(root->right, x, path, ans);
//     path.pop_back();
// }

// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     int m, n;
//     scanf("%d %d", &m, &n);
//     for (int i = 0; i < n; ++i) {
//         int a;
//         scanf("%d", &a);
//         in.push_back(a);
//     }
//     for (int i = 0; i < n; ++i) {
//         int a;
//         scanf("%d", &a);
//         pre.push_back(a);
//     }
//     node *root = build(0, n-1, 0, n-1);

//     for (int i = 0; i < m; ++i) {
//         int a, b;
//         scanf("%d %d", &a, &b);



//         vector<int> path, patha, pathb;
//         flag = false;
//         preorder(root, a, path, patha);
//         path.clear();
//         flag = false;
//         preorder(root, b, path, pathb);
//         if (patha.size() == 0 && pathb.size() == 0)
//             printf("ERROR: %d and %d are not found.\n", a, b);
//         else if (patha.size() == 0)
//             printf("ERROR: %d is not found.\n", a);
//         else if (pathb.size() == 0)
//             printf("ERROR: %d is not found.\n", b);
//         // else if (patha[patha.size() - 2] == b)
//         //     printf("%d is an ancestor of %d.\n", b, a);
//         // else if (pathb[pathb.size() - 2] == a)
//         //     printf("%d is an ancestor of %d.\n", a, b);
//         else {
//             bool flag = false;
            
//             if (a==b) { // 这一个判断是测试点三，没有加这个测试点3过不了
//                 printf("%d is an ancestor of %d.\n", a, b);
//                 continue;
//             }
//             // 下面这两个很重要，根据题目给的条件
//             //  if A is one of U and V, print X is an ancestor of Y. where X is A and Y is the other node.
//             for (int j = patha.size() - 2; j >= 0; --j)
//                 if (patha[j] == b) {
//                     printf("%d is an ancestor of %d.\n", b, a);
//                     flag = true; break;
//                 }
//             if (flag) continue;
//             for (int j = pathb.size() - 2; j >= 0; --j)
//                 if (pathb[j] == a) {
//                     printf("%d is an ancestor of %d.\n", a, b);
//                     flag = true;
//                     break;
//                 }
//             if (flag)  continue;
//             for (int j = 0; j < patha.size(); ++j) {
//                 if (patha[j] != pathb[j]) {
//                     printf("LCA of %d and %d is %d.\n", a, b, patha[j-1]);
//                     break;
//                 }
//                 //cout << patha[i] << " " << pathb[i] << endl;
//             }
//         }
//     }
//     return 0;
// }

/*
   问题描述：
   解题思路： ref: https://blog.csdn.net/liuchuo/article/details/82560863
 */
#include <bits/stdc++.h>

using namespace std;
map<int, int> pos;
vector<int> in, pre;
void lca(int inl, int inr, int preRoot, int a, int b) {
    if (inl > inr) return;
    int inRoot = pos[pre[preRoot]], aIn = pos[a], bIn = pos[b]; // 获得位置信息
    if (aIn < inRoot && bIn < inRoot)  // 如果a和b都是在根节点的左边，那么在左子树寻找lca
        lca (inl, inRoot - 1, preRoot + 1, a, b);
    else if ((aIn < inRoot && bIn > inRoot) || (aIn > inRoot && bIn < inRoot)) // 如果落在根节点的两边，那么当前根节点就是a和b的lca
        printf("LCA of %d and %d is %d.\n", a, b, in[inRoot]);
    else if (aIn > inRoot && bIn > inRoot) // 如果a和b都落在根节点的右边，那么在右子树中寻找
        lca(inRoot + 1, inr, preRoot + 1 + (inRoot - inl), a, b);
    else if (aIn == inRoot)
        printf("%d is an ancestor of %d.\n", a, b);
    else if (bIn == inRoot)
        printf("%d is an ancestor of %d.\n", b, a);
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int m, n, a, b;
    scanf("%d %d", &m, &n);
    in.resize(n + 1), pre.resize(n + 1);
    for (int i= 1; i<=n; ++i) {
        scanf("%d", &in[i]);
        pos[in[i]] = i;
    }
    for (int i = 1; i <= n; ++i) scanf("%d", &pre[i]);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a,&b);
        if (pos[a] == 0 && pos[b] == 0)
            printf("ERROR: %d and %d are not found.\n", a, b);
        else if (pos[a] == 0 || pos[b] == 0)
            printf("ERROR: %d is not found.\n", pos[a] == 0?a : b );
        else 
            lca(1, n, 1, a, b);
    }
    return 0;
}
