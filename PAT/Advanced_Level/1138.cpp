// /*
//    问题描述：
//    解题思路： 按照这个思路实现的话，会有两个测试点超时
//  */
// #include <bits/stdc++.h>

// using namespace std;

// vector<int> pre(50010,  0);
// vector<int> in(50010, 0);

// struct node{
//     int val;
//     node *left, *right;
// };

// node *build(int preL, int preR, int inL, int inR) {
//     if (preL > preR) return NULL;
//     node *root = new node;
//     root->val = pre[preL];
//     int k;
//     for (k = inL; k <= inR; ++k)
//         if (in[k] == pre[preL])
//             break;
//     int numLeft = k - inL;
//     root->left = build(preL + 1, preL + numLeft, inL, k -1);
//     root->right = build(preL+numLeft + 1, preR, k + 1, inR);
//     return root;
// }

// void postOrder(node *root) {
//     if (root == NULL) return;
//     postOrder(root->left);
//     postOrder(root->right);
//     cout << root->val << endl;
//     exit(0);
// }

// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; ++i)
//         cin >> pre[i];
//     for (int i = 1; i <= n; ++i)
//         cin >> in[i];
//     node *root = build(1, n, 1, n);
//     postOrder(root);
//     return 0;
// }

// /*
//    问题描述：
//    解题思路： 按照这个思路实现的话，会有两个测试点超时
//  */
// #include <bits/stdc++.h>

// using namespace std;

// vector<int> pre(50010,  0);
// vector<int> in(50010, 0);

// struct node{
//     int val;
//     node *left, *right;
// };

// void findPost(int preL, int preR, int inL, int inR) {
//     if (preL > preR) {
//         cout << pre[preL] << endl;
//         return;
//     }
//     int k;
//     for (k = inL; k <= inR; ++k)
//         if (in[k] == pre[preL])
//             break;
//     int numLeft = k - inL;
//     findPost(preL + 1, preL + numLeft, inL, k - 1);
// }

// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; ++i)
//         cin >> pre[i];
//     for (int i = 1; i <= n; ++i)
//         cin >> in[i];
//     findPost(1, n, 1, n);
//     return 0;
// }

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

vector<int> pre, in, post;
bool flag = false;

// pre 根左右
// in  左根右
void postOrder(int preL, int inL, int inR) {
    if (inL > inR || flag == true) return;
    int i = inL;
    while(in[i] != pre[preL]) i++;
    postOrder(preL + 1, inL, i - 1); // 相当于遍历左子树
    postOrder(preL + i - inL + 1, i + 1, inR); // 相当于遍历右子树
    
    if (flag == false) {
        printf("%d ", in[i]);
        flag = true;
    } 
}

// 同样的，可以得到给定中序后序输出前序
void preOrder(int postR, int inL, int inR) {
    if (inL > inR) return;
    printf("%d ", post[postR]);
    int i = inL;
    while(in[i] != post[postR]) i++;
    // inR - i
    preOrder(postR - inR + i - 1, inL, i - 1);
    preOrder(postR - 1, i + 1, inR);
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    pre.resize(n);
    in.resize(n);
    //post.resize(n);
    for (int i = 0; i < n; ++i) scanf("%d", &pre[i]);
    //for (int i = 0; i < n; ++i) scanf("%d", &post[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &in[i]);
    postOrder(0, 0, n - 1);
    //preOrder(n - 1, 0, n - 1);
    return 0;
}

