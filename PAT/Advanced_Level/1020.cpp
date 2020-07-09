// /*
//  * 运行数据： ms  KB
//  */
// #include <bits/stdc++.h>

// using namespace std;

// struct node {
//     int index, value;
// };

// bool cmp(node a, node b) {
//     return a.index < b.index;
// }

// vector<int> post, in;
// vector<node> ans;

// // 后续遍历为：左右根
// void pre(int root, int start, int end, int index) {
//     if (start > end) return;
//     int i = start;
//     while (i < end && in[i] != post[root]) i++;
//     ans.push_back({index, post[root]});
//     pre(root - 1 - end + i, start, i - 1, 2 * index + 1); // index为奇数
//     pre(root - 1, i + 1, end, 2 * index + 2); // index为偶数
// }

// int main(int argc, char const *argv[])
// {
//     int n;
//     scanf("%d", &n);
//     post.resize(n);
//     in.resize(n);
//     for (int i = 0; i < n; i++) scanf("%d", &post[i]);
//     for (int i = 0; i < n; i++) scanf("%d", &in[i]);
//     pre(n - 1, 0, n - 1, 0);
//     sort(ans.begin(), ans.end(), cmp); // 为什要加一个排序呢？
//     for (int i  = 0; i < ans.size(); i++) {
//         if (i != 0) cout << " ";
//         cout << ans[i].value;
//     }

//     return 0;
// }


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

vector<int> in, post;
// 左根右  左右根
node* create(int inL, int inR, int postL, int postR) {
    if (postL > postR) return NULL;
    //cout << "call: " << inL << " " << inR << " " << postL << " " << postR << endl;
    node *root = new node;
    root->val = post[postR];
    int k;
    for (k = inL; k <= inR; ++k) {
        if (in[k] == post[postR]) break;
    }
    int numLeft = k - inL; // 左子结点的个数
    root->left = create(inL, k - 1, postL, postL + numLeft - 1);
    root->right = create(k + 1, inR, postL + numLeft, postR - 1);
    return root;
}

int i = 0;
void levelOrder(node *root) {
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node *u = q.front();
        q.pop();
        if (i == 0) { cout << u->val; i++;}
        else cout << " " << u->val;
        if (u->left != NULL) q.push(u->left);
        if (u->right != NULL) q.push(u->right);
    }
}

void inorder(node *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout<<root->val;
    inorder(root->right);
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    int temp;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        post.push_back(temp);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        in.push_back(temp);
    }
    node *root = create(0, n-1, 0, n-1);
    levelOrder(root);
    return 0;
}

