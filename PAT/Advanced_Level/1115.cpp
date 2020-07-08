/*
   问题描述：
   解题思路： 思路很明确，构建二叉搜索树，求出每个节点的所在的level，找到最大的level和第二大的level，相加即可
 */
#include <bits/stdc++.h>

using namespace std;
struct NODE {
    NODE *left, *right;
    int val;
};

void insert(NODE *&root, int val) {
    if (root == NULL) {
        root = new NODE;
        root->left = NULL;
        root->right = NULL;
        root->val = val;
        return;
    }
    else if (val > root->val) 
        insert(root->right, val);
    else 
        insert(root->left, val);
}

multimap<int, int> m;

void inorder(NODE *root, int level) {
    if (root == NULL) return;
    inorder(root->left, level + 1);
    m.insert({root->val, level});
    //cout << root->val << endl;
    inorder(root->right, level + 1);
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    NODE *root = NULL;
    int n;
    cin >> n;
    int temp;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        insert(root, temp);
    }
    inorder(root, 1);
    int max = -1;
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (max < it->second)
            max = it->second;
        //cout <<it->first << " : "<<it->second << endl;
    }
    int cnt_lowest = 0;
    int cnt_lowest_2 = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second == max)
            cnt_lowest++;
        if (it->second == (max - 1))
            cnt_lowest_2++;
    }
    cout << cnt_lowest << " + " << cnt_lowest_2 << " = " << cnt_lowest_2 + cnt_lowest << endl;
    return 0;
}

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

struct node {
    int v;
    node *left, *right;
};

node* build(node *root, int v) {
    if (root == NULL) {
        root = new node();
        root->v = v;
        root->left = root->right = NULL;
    }
    else if (v <= root->v)
        root->left = build(root->left, v);
    else 
        root->right = build(root->right, v);
    return root;
}
vector<int> num(1000);
int maxdepth = -1;
void dfs(node *root, int depth) {
    if (root == NULL) {
        maxdepth = max(depth, maxdepth);
        return;
    }
    num[depth]++;
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n, t;
    scanf("%d", &n);
    node *root = NULL;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        root = build(root, t);
    } 
    dfs(root, 0);
    printf("%d + %d = %d", num[maxdepth-1], num[maxdepth - 2], num[maxdepth-1] + num[maxdepth - 2]);
    return 0;
}