/*
   问题描述：计算树中每层没有孩子的结点数目，并按照树的层顺序输出
   解题思路：使用深度优先搜索的方式从根节点开始往下查找，如果遇到对应的结点的大小为0
            则将该层没有孩子的结点数目加一
 */
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[100];
int book[100], maxdepth = -1;

void dfs(int index, int depth) {
    if (v[index].size() == 0) {
        book[depth] ++;
        maxdepth = max(depth, maxdepth);
        return;
    }
    for (int i = 0; i < v[index].size(); ++i) {
        dfs(v[index][i], depth + 1);
    }
}

int main(int argc, char const *argv[])
{
    int n, m, node, c, k;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &node, &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &c);
            v[node].push_back(c);
        }
    }    

    dfs(1, 0);
    printf("%d", book[0]);
    for (int i = 1; i <= maxdepth; ++i) {
        printf(" %d", book[i]);
    }
    return 0;
}