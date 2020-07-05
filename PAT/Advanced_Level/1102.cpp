/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
struct NODE{
    int left;
    int right;
    int val;
}node[12];
int n;
int cnt;

void inorder(int i) {
    if (i == -1) return;
    //cout << i <<endl;
    inorder(node[i].left);
    cnt++;
    inorder(node[i].right);
}

int find_root() {
    for (int i = 0; i < n; ++i) {
        cnt = 0;
        inorder(i);
        if (cnt == n)
            return i;
    }
}

void invert(int i) {
    if (i == -1) return;
    int temp = node[i].left;
    node[i].left = node[i].right;
    node[i].right = temp;
    invert(node[i].left);
    invert(node[i].right);
}

void print_inorder(int i) {
    if (i == -1) return;    
    print_inorder(node[i].left);
    if (cnt == 0) {cout << node[i].val; cnt++;}
    else cout << " " << node[i].val;
    print_inorder(node[i].right);
} 

void print_level(int i) {
    queue<int> q;
    q.push(i);
    while(!q.empty()) {
        int tmp = q.front();
        q.pop();
        if (cnt == 0) {cout << node[tmp].val; cnt++;}
        else cout << " " << node[tmp].val;
        if (node[tmp].left != -1) q.push(node[tmp].left);
        if (node[tmp].right != -1) q.push(node[tmp].right);
    }
}


int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    scanf("%d", &n);
    char a, b;
    for (int i = 0; i < n; ++i) {
        scanf(" %c %c", &a, &b); // https://blog.csdn.net/weixin_46368810/article/details/105867661
        node[i].val = i;
        if (a == '-')
            node[i].left = -1;
        else
            node[i].left = (a - '0');
        if (b == '-')
            node[i].right = -1;
        else
            node[i].right = (b - '0');
    }
    int root = find_root();
    invert(root);
    cnt = 0;
    print_level(root);
    cout << endl;
    cnt = 0;
    print_inorder(root);
    
    return 0;
}