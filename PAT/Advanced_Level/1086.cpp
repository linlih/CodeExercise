// /*
//    问题描述：
//    解题思路： 这个代码本地运行不会得到结果，提交确实正确的答案
//    ref :https://github.com/liuchuo/PAT/blob/master/AdvancedLevel_C%2B%2B/1086.%20Tree%20Traversals%20Again%20(25)%20.cpp
//  */
// #include <bits/stdc++.h>

// using namespace std;

// vector<int> pre, in, post, value;

// void postorder(int root, int start, int end) {
//     if (start > end) return;
//     int i = start;
//     while (i < end && in[i] != pre[root]) i++;
//     postorder(root + 1, start, i - 1);
//     postorder(root + 1 +i - start, i + 1, end);
//     post.push_back(pre[root]);
// }

// int main(int argc, char const *argv[]) {
//     int n;
//     scanf("%d", &n);
//     char str[5];
//     stack<int> s;
//     int key = 0;
//     while (~scanf("%s", str)) {
//         if (strlen(str) == 4) {
//             int num;
//             scanf("%d", &num);
//             value.push_back(num);
//             pre.push_back(key);
//             s.push(key++);
//         }
//         else {
//             in.push_back(s.top());
//             s.pop();
//         }
//     }
//     postorder(0, 0, n - 1);
//     printf("%d", value[post[0]]);
//     for (int i = 1; i < n; ++i) {
//         printf(" %d", value[post[i]]);
//     }
//     return 0;
// }

/*
   问题描述：
   解题思路：核心要点：push进去是先序，pop出来是中序，依据先序中序构建二叉树
            ref: https://blog.csdn.net/galesaur_wcy/article/details/82021050
 */
#include <bits/stdc++.h>

using namespace std;

vector<int> post, pre, in;
int n, x;

struct node {
    int data;
    node *left, *right;
};

void postOrder(node *root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        post.push_back(root->data);
    }
    return;
}

node *buildTree(vector<int> pre, vector<int> in, int pl, int pr, int il, int ir) {
    if (pl > pr || il > ir)
        return NULL;
    int pos;
    for (int i = il; i <= ir; ++i) {
        if (pre[pl] == in[i]) {
            pos = i;
            break;
        }
    }
    node *root = new node();
    root->data = pre[pl];
    root->left = root->right = NULL;
    root->left = buildTree(pre, in, pl+1, pl+pos-il, il, pos-1);
    root->right = buildTree(pre, in, pl+pos-il+1, pr, pos+1, ir);
    return root;
}

int main(int argc, char const *argv[]) {
    stack<int> st;
    scanf("%d", &n);
    char str[10];
    pre.push_back(-1);
    in.push_back(-1);
    for (int i = 1; i <= n*2; ++i) {
        scanf("%s", str);
        if (strcmp(str, "Push") == 0) {
            scanf("%d", &x);
            st.push(x);
            pre.push_back(x);
        }
        else {
            x = st.top();
            st.pop();
            in.push_back(x);
        }
    }
    node *root;
    root = buildTree(pre, in, 1, n, 1, n);
    postOrder(root);
    for (int i = 0; i < n; ++i) {
        printf("%d%c", post[i], " \n"[i==n-1]);
    } 
    return 0;
}