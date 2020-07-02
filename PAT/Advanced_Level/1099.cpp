/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
struct NODE{
    int left, right;
    int val;
}node[110];

int node_val[110];
int in = 0;
void inorder(int n, int arr[]) {
    if (n == -1) return;
    inorder(node[n].left, arr);
    node[n].val = arr[in++];
    inorder(node[n].right, arr);
}

void inorder_print(int n) {
    if (n == -1) return;
    inorder_print(node[n].left);
    cout << node[n].val << " ";
    inorder_print(node[n].right);
}

void level_print(int n) {
    queue<int> q;
    q.push(n);
    int out = 0;
    while(!q.empty()) {
        int i = q.front();
        q.pop();
        if (out == 0) {
            cout << node[i].val ;
            out++;
        }
        else 
            cout << " " << node[i].val;
        if (node[i].left != -1)
            q.push(node[i].left);
        if (node[i].right != -1)
            q.push(node[i].right);
    }
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    int l, r;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        node[i].left = l;
        node[i].right = r;
        node[i].val = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> node_val[i];
    }
    sort(node_val, node_val + n);
    inorder(0, node_val);
    level_print(0);
    return 0;
}