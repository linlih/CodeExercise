/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

struct NODE {
    string data;
    int left, right;
}node[30];

int cnt = 0;
int n;
void inorder(int root) {
    if (root == -1) return;
    inorder(node[root].left);
    cnt++;
    inorder(node[root].right);
}

int getRoot() {
    for (int i = 1; i <= n; ++i) {
        cnt = 0;
        inorder(i);
        if (cnt == n)
            return i;
    }
}

void print_inorder(int root) {
    if (root == -1) return;
    if (node[root].left == -1 &&node[root].right == -1)
        cout <<"(";
    print_inorder(node[root].left);
    cout << node[root].data;
    print_inorder(node[root].right);
    if (node[root].left == -1 &&node[root].right == -1)
        cout << ")";
}

string dfs(int root) {
    if(node[root].left == -1 && node[root].right == -1) return node[root].data;
    if(node[root].left == -1 && node[root].right != -1)  return "(" +  node[root].data + dfs(node[root].right) + ")";
    if(node[root].left != -1 && node[root].right != -1) return "(" +  dfs(node[root].left) + node[root].data + dfs(node[root].right) + ")";
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> node[i].data >> node[i].left >> node[i].right;
    }
    int root = getRoot();
     string ans = dfs(root);
    if(ans[0] == '(') ans = ans.substr(1,ans.size()-2);
    cout << ans;
    return 0;
}