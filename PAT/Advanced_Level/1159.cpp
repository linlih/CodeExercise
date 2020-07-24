
#include <bits/stdc++.h>

using namespace std;
vector<int> post, in;

struct Node {
    int data;
    Node *left, *right;
    Node *parent;
}node[10010];
bool full = true;

vector<int> level(10000, 0);
Node* build(Node *root, int inL, int inR, int postL, int postR, int depth) {
    if (inL > inR) return NULL;
    if (root == NULL) {
        root = new Node;
        root->data = post[postR];
        root->left = root->right = NULL;
        level[root->data] = depth;
        root->parent = NULL;
    }
    int k;
    for (k = inL; k <= inR; ++k) {
        if (in[k] == post[postR]) break;
    }
    int numLeft = k - inL;
    root->left = build(root->left, inL, k -1, postL, postL + numLeft - 1, depth+1);
    root->right = build(root->right, k + 1, inR, postL + numLeft, postR - 1, depth+1);
    if (root->left != NULL)
        root->left->parent = root;
    if (root->right != NULL)
        root->right->parent = root;

    //node[root->data] = *root;

    if ((root->left != NULL && root->right == NULL)||(root->left == NULL && root->right != NULL)) full = false;
    return root;
}

void preorder(Node *root) {
    if (root==NULL)return;
    node[root->data]  = *root;
    preorder(root->left);
    preorder(root->right);
}

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    post.resize(n);
    in.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
    }
    Node *root = NULL;
    root = build(root, 0, n -1, 0, n - 1, 0);
    int k;
    scanf("%d", &k);
    getchar();
    preorder(root);
    for (int i = 0; i < k; ++i) {
        string str;
        getline(cin, str);
        //cout << "zdf " <<str << endl;
        if (str.find("root") != str.npos) {
            int tmp;
            sscanf(str.c_str(), "%d is the root", &tmp);
            if (tmp == root->data)printf("Yes\n");
            else printf("No\n");
        }
        else if (str.find("siblings") != str.npos) {
            int t1, t2;
            sscanf(str.c_str(), "%d and %d are siblings", &t1, &t2);
            if (node[t1].parent == node[t2].parent)
                printf("Yes\n");
            else
                printf("No\n");
        }
        else if (str.find("parent") != str.npos) {
            int t1, t2;
            sscanf(str.c_str(), "%d is the parent of %d", &t1, &t2);
            //if ((node[t1].left != NULL && node[t1].left->data == t2)||(node[t1].right != NULL && node[t1].right->data == t2))
            if (node[t2].parent->data == t1)
                printf("Yes\n");
            else
                printf("No\n");
        }
        else if (str.find("left child") != str.npos) {
            int t1, t2;
            sscanf(str.c_str(), "%d is the left child of %d", &t1, &t2);
            if (node[t2].left != NULL && node[t2].left->data == t1)
                printf("Yes\n");
            else
                printf("No\n");
        }
        else if (str.find("right child") != str.npos) {
            int t1, t2;
            sscanf(str.c_str(), "%d is the right child of %d", &t1, &t2);
            if (node[t2].right != NULL && node[t2].right->data == t1)
                printf("Yes\n");
            else
                printf("No\n");
        }
        else if (str.find("same level") != str.npos) {
            int t1, t2;
            sscanf(str.c_str(), "%d and %d are on the same level", &t1, &t2);
            if (level[t1] == level[t2])
                printf("Yes\n");
            else
                printf("No\n");
        }
        else if (str.find("full") != str.npos) {
            if (full) printf("Yes\n");
            else printf("No\n");
        }
    }

    return 0;
}