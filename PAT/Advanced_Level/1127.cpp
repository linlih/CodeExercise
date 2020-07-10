/*
   问题描述：
   解题思路： 有一个测试用例段错误，找不到原因
              原因定位到了，
 */
#include <bits/stdc++.h>

using namespace std;

vector<int> in(40);
vector<int> post(40);
struct node{
    int val;
    node *left, *right;
    int level;
};

node *build(int inL, int inR, int postL, int postR, int level) {
    if(postL > postR) return NULL;
    node *root = new node;
    root->level = level;
    root->val = post[postR];
    //root->left = root->right = NULL;
    int k;
    for (k = inL; k <= inR; ++k)
        if (in[k] == post[postR])
            break;
    int numLeft = k - inL;
    root->left = build(inL, k -1, postL, postL + numLeft - 1, level + 1);
    root->right = build(k + 1, inR, postL + numLeft, postR - 1, level + 1);
    return root;
}

vector<node*> level;
void levelOrder(node *root) {
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node *u = q.front();
        q.pop();
        level.push_back(u);
        if (u->left != NULL) q.push(u->left);
        if (u->right != NULL) q.push(u->right);
    }
}

void inorder(node* root,int index) {
    if (root == NULL)return;
    //level[root->val] = index;
    inorder(root->left, index++);
    //cout << root->val << endl;
    inorder(root->right, index++);
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> in[i];
    for (int i = 0; i < n; ++i) 
        cin >> post[i];
    
    node *root = build(0, n - 1, 0, n - 1, 0);
    levelOrder(root);
    //inorder(root, 1);
    int layer = 0;
    for (int i = 0; i < n; ++i) {
        int j = i;
        // 这样写会段错误
        // 原因是这样的，假如这个时候j = n - 1,传入的话j++变成j=n，这个时候不满足j==n-1，再去访问level[j]就会出错
        // while(level[j]->level == layer) {
        //     j++; if (j == n-1) { j++; break;}
        // }

        // 这样写可以通过，为什么。。。。
        while(level[j]->level == layer) {
            j++; if (j == n) break;
        }
        if (layer % 2 != 0) {
             for (int k = i; k < j; ++k) {
                cout << " " << level[k]->val;
            }
        }
        else {
            for (int k = j-1; k >=i; --k) {
                if (layer == 0)
                    cout << level[k]->val ;
                else 
                    cout << " " << level[k]->val;
            }
        }
        i = j - 1;
        layer++;
    }
    return 0;
}