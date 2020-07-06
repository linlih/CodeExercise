/*
   问题描述：
   解题思路： 有三个测试用例段错误，找不到原因
 */
#include <bits/stdc++.h>

using namespace std;

struct NODE{
    int left, right;
}node[22];

int cnt = 0;
int n;
int last;

void inorder(int i) {
    if (i == -1) return;
    inorder(node[i].left); 
    cnt ++;
    inorder(node[i].right);
}

int findRoot() {
    for (int i = 0; i < n; ++i) {
        cnt = 0;
        inorder(i);
        if (cnt == n)
            return i;
    }
}
// ref : https://zhuanlan.zhihu.com/p/149526194?from_voters_page=true
bool judge(int i) {
    if (i == -1) return true;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        if (tmp != -1) {
            q.push(node[tmp].left);
            q.push(node[tmp].right);
            if (node[tmp].left == -1 && node[tmp].right == -1)
                last = tmp;
        }
        else {
            while (!q.empty()) {
                tmp = q.front();
                q.pop();
                if (tmp != -1)
                    return false;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        //char a, b;
        string a, b;
        cin >> a >> b;

        if (a == "-")
            node[i].left = -1;
        else 
            // 段错误的原因在这里，不能直接使用a-'0'，这样只是读入一个数值，如果是两位数则会出错
            //node[i].left = (a - '0');
            node[i].left = stoi(a);
        if (b == "-")
            node[i].right = -1;
        else 
            //node[i].right = (b - '0');
            node[i].right = stoi(b);
    }
    int root = findRoot();
    if (!judge(root))
        cout << "NO" << " " << root << endl;
    else 
        cout << "YES" << " " << last << endl;
    return 0;
}

////////////////////////柳神的解法////////////////////////////
/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
struct node {
    int l, r;
}a[100];
int maxn = -1, ans;
void dfs(int root, int index) {
    if (index > maxn) {
        maxn = index;
        ans = root;
    }
    if (a[root].l != -1) dfs(a[root].l, index * 2);
    if (a[root].r != -1) dfs(a[root].r, index * 2 + 1);
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n, root = 0, have[100] = {0};
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string l, r;
        cin >> l >> r;
        if (l == "-")
            a[i].l = -1;
        else {
            a[i].l = stoi(l);
            have[stoi(l)] = 1;
        }
        if (r == "-")
            a[i].r = -1;
        else {
            a[i].r = stoi(r);
            have[stoi(r)] = 1;
        }
    } 
    while(have[root] != 0) root++;
    dfs(root, 1);
    if (maxn == n)
        cout << "YES " << ans;
    else
        cout << "NO " << root;
    return 0;
}