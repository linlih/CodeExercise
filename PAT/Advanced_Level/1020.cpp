/*
 * 运行数据： ms  KB
 */
#include <bits/stdc++.h>

using namespace std;

struct node {
    int index, value;
};

bool cmp(node a, node b) {
    return a.index < b.index;
}

vector<int> post, in;
vector<node> ans;

// 后续遍历为：左右根
void pre(int root, int start, int end, int index) {
    if (start > end) return;
    int i = start;
    while (i < end && in[i] != post[root]) i++;
    ans.push_back({index, post[root]});
    pre(root - 1 - end + i, start, i - 1, 2 * index + 1); // index为奇数
    pre(root - 1, i + 1, end, 2 * index + 2); // index为偶数
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    post.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    pre(n - 1, 0, n - 1, 0);
    sort(ans.begin(), ans.end(), cmp); // 为什要加一个排序呢？
    for (int i  = 0; i < ans.size(); i++) {
        if (i != 0) cout << " ";
        cout << ans[i].value;
    }

    return 0;
}


