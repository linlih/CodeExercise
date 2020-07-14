/*
   问题描述：
   解题思路： 这道题涉及到的问题是说什么叫做Vertex cover的问题了
             用vector v[n]保存某结点属于的某条边的编号，比如a b两个结点构成的这条边的编号为0，则v[a].push_back(0)，v[b].push_back(0)——表示a属于0号边，b也属于0号边。对于每一个集合做判断，遍历集合中的每一个元素，将当前元素能够属于的边的编号i对应的hash[i]标记为1，表示这条边是满足有一个结点出自集合S中的。最后判断hash数组中的每一个值是否都是1，如果有不是1的，说明这条边的两端结点没有一个出自集合S中，则输出No。否则输出Yes～

            原文链接：https://blog.csdn.net/liuchuo/article/details/78037329
        
            另外一个相关的概念是set cover，具体参考：
            https://www.bbsmax.com/A/gGdXM6Wz4m/
 */
#include <bits/stdc++.h>

using namespace std;
 
int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n, m, k, nv, a, b, num;
    scanf("%d%d", &n, &m);
    vector<int> v[n];
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        v[a].push_back(i); // 保存的是定点的编号0~m-1
        v[b].push_back(i);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &nv);
        int flag = 0;
        vector<int> hash(m, 0); // m条边，对应编号为0~m-1条边
        for (int j = 0; j < nv; ++j) {
            scanf("%d", &num);
            for (int t = 0; t < v[num].size(); ++t) 
                hash[v[num][t]] = 1; // 如果顶点是这条边的，则hash值置为1
        }
        for (int j = 0; j < m; ++j) {
            if (hash[j] == 0) {
                printf("No\n");
                flag = 1;
                break;
            }
        }
        if (flag == 0) printf("Yes\n");
    }
    return 0;
}