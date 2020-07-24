// /*
//    问题描述：
//    解题思路： 这个思路比较繁琐，无法通过测试点
//  */
// #include <bits/stdc++.h>

// using namespace std;

// struct node {
//     int val;
//     node *left, *right;
// };

// vector<int> pre;
// vector<int> in;

// // node *insert(node* &root, int val) {
// //     if (root==NULL) {
// //         root = new node;
// //         root->val = val;
// //         root->left = root->right = NULL;
// //         return root; 
// //     }
// //     if (val > root->val) {
// //         root->right = insert(root->right, val);
// //     }
// //     else {
// //         root->left = insert(root->left, val);
// //     }
// //     return root;
// // }

// node* build(int preL, int preR, int inL, int inR) {
//     if (preL > preR) return NULL;
//     node*root = new node;
//     root->val = pre[preL];
//     int k = inL;
//     while(in[k] != pre[preL]) k++;
//     int numLeft = k - inL;
//     root->left = build(preL + 1, preL + numLeft, inL, k -1);
//     root->right = build(preL + numLeft + 1, preR, k + 1, inR);
//     return root;
// }

// void inorder(node *root) {
//     if (root == NULL) return;
//     inorder(root->left);
//     cout << root->val << " ";
//     inorder(root->right);
// }

// void postorder(node *root) {
//     if (root==NULL) return;
//     postorder(root->left);
//     postorder(root->right);
//     cout << root->val << " ";
// }

// bool flag = false;
// void preorder(node *root, int val, vector<int> &path, vector<int>& ans) {
//     if (root == NULL || flag == true) return;
//     path.push_back(root->val);
//     if (root->val == val) {
//         flag = true;
//         ans = path;
//     }
//     preorder(root->left, val, path, ans);
//     preorder(root->right, val, path, ans);
//     path.pop_back();
// }


// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     int m, n;
//     cin >>m >>n;
//     node *root = NULL;
//     for (int i = 0; i < n; ++i) {
//         int a;
//         scanf("%d", &a);
//         pre.push_back(a);
//         in.push_back(a);
//         //root = insert(root, a);
//     }
//     sort(in.begin(), in.end());
//     root = build(0, pre.size() - 1, 0, in.size() - 1);
//     //inorder(root);
//     //postorder(root);
//     for (int i = 0; i < m; ++i) {
//         int a, b;
//         cin >> a >> b;
//         flag = false;
//         vector<int> path, patha, pathb;
//         preorder(root, a, path, patha);
//         path.clear();
//         flag = false;
//         preorder(root, b, path, pathb);
//         if (patha.size() == 0 && pathb.size() == 0) 
//             cout << "ERROR: " << a << " and " << b << " are not found." << endl;
//         else if (patha.size() == 0)
//             cout << "ERROR: " << a << " is not found." << endl;
//         else if (pathb.size() == 0)
//             cout << "ERROR: " << b << " is not found." << endl;
//         else {
//             bool flag = false;
//             for (int i = patha.size() - 2; i >= 0; --i) {
//                 if (patha[i] == b) {
//                     cout << b << " is an ancestor of " << a << "." << endl;
//                     flag = true;
//                     break;
//                 }
//             }
//             for (int i = pathb.size() - 2; i >= 0; --i) {
//                 if (pathb[i] == a) {
//                     cout << a << " is an ancestor of " << b << "." << endl;
//                     flag = true;
//                     break;
//                 }
//             }
//             if (flag )
//                 continue;
//             // if (patha[patha.size() - 2] == b) {
//             //     cout << b << " is an ancestor of " << a << "." << endl;
//             // }
//             // else if (pathb[pathb.size() - 2] == a) {
//             //     cout << a << " is an ancestor of " << b << "." << endl;
//             // }
//             //else {
//                 int i = 0;
//                 int j = 0;
//                 while(patha[i] == pathb[j]) {
//                     i++; j++;
//                 }
//                 cout << "LCA of " << a <<" and " << b << " is " << patha[i-1] << "." << endl;
//             //}
//         }
//     }
//     return 0;
// }

/*
   问题描述：
   解题思路： https://blog.csdn.net/liuchuo/article/details/79618849
 */
#include <bits/stdc++.h>

using namespace std;

map<int, bool> mp; // 标记树中出现的结点

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int m, n, u, v, a;
    scanf("%d %d", &m, &n);
    vector<int> pre(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pre[i]);
        mp[pre[i]] = true;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        for (int j = 0;  j < n; ++j) {
            a = pre[j];
            if ((a >= u && a <= v) || (a >= v && a <= u)) break;
        }
        if (mp[u] == false && mp[v] == false)
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if (mp[u] == false || mp[v] == false)
            printf("ERROR: %d is not found.\n", mp[u] == false ? u : v);
        else if (a == u || a == v)
            printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
        else
            printf("LCA of %d and %d is %d.\n", u, v, a);
    }
    return 0;
}