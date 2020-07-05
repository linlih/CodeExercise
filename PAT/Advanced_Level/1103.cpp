/*
   问题描述：
   解题思路： https://blog.csdn.net/liuchuo/article/details/52493390
 */
#include <bits/stdc++.h>

using namespace std;
int n, k, p, maxFacSum = -1;
vector<int> v, ans, tempAns;
// 存储从0开始的p次方值
void init() {
    int temp = 0, index = 1;
    while(temp <= n) {
        v.push_back(temp);
        temp = pow(index, p);
        index++;
    }
}
// index为从0开始的p次方值的个数，tempSum为当前的p次方和，tempK为当前p次方值的个数，index也是
void dfs(int index, int tempSum, int tempK, int facSum) {
    // tempK当前总的个数
    if (tempK == k) {
        // facSum则控制多个满足条件的序列为递增
        if (tempSum == n && facSum > maxFacSum) {
            ans = tempAns;
            maxFacSum = facSum;
        }
        return;
    }
    while(index >= 1) {
        if (tempSum + v[index] <= n) {
            tempAns[tempK] = index;
            dfs(index, tempSum + v[index], tempK + 1, facSum + index);
        }
        if (index == 1) return;
        index--;
    }
}
int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    scanf("%d%d%d", &n, &k, &p);
    init();
    tempAns.resize(k);
    dfs(v.size() - 1, 0, 0, 0);
    if (maxFacSum == -1) {
        printf("Impossible");
        return 0;
    }
    printf("%d=", n);
    for (int i =0; i < ans.size(); ++i) {
        if (i != 0) printf(" + ");
        printf("%d^%d", ans[i], p);
    }
    return 0;
}