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

node* rotateLeft(node* root) {
    node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

node* rotateRight(node *root) {
    node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

node* rotateLeftRight(node *root) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}

node* rotateRightLeft(node *root) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}

int getHeight(node *root) {
    if (root == NULL) return 0;
    else return max(getHeight(root->left), getHeight(root->right))  + 1;
}

node* insert(node *root, int val){
    if (root == NULL) {
        root = new node;
        root->left = root->right = NULL;
        root->val = val;
    }
    else if (val > root->val) {
        root->right = insert(root->right, val);
        if (getHeight(root->left) - getHeight(root->right) == -2) {
            root = val > root->right->val?rotateLeft(root):rotateRightLeft(root);
        }
    }
    else {
        root->left = insert(root->left, val);
        if (getHeight(root->left) - getHeight(root->right) == 2) {
            root = val < root->left->val?rotateRight(root):rotateLeftRight(root);
        }
    }
    return root;
}

int j = 0;
void levelOrder(node *root) {
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node *u = q.front();
        q.pop();
        if (j == 0) {cout << u->val;j++;}
        else cout << " " << u->val;
        if (u->left != NULL) q.push(u->left);
        if (u->right != NULL) q.push(u->right);
    }
}

bool judge(node *root) {
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node *u = q.front();
        q.pop();
        if (u != NULL) {
            q.push(u->left);
            q.push(u->right);
        }
        else {
            while(!q.empty()) {
                u = q.front();
                q.pop();
                if (u != NULL)
                    return false;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    int temp;
    node *root = NULL;
    for (int i =  0; i < n; ++i) {
        scanf("%d", &temp);
        root = insert(root, temp);
    }
    levelOrder(root);
    cout << endl;
    cout << (judge(root)==true?"YES":"NO") << endl;
    return 0;
}