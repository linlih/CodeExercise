/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

void downAdjust(vector<int> &b, int low, int high) {
    int i = 1, j = i * 2;
    while(j <= high) {
        // 注意这里是大顶堆，并且下标是从1开始的
        if (j + 1 <= high && b[j] < b[j+1]) j = j + 1; // 找到结点孩子中最大的值
        if (b[i] >= b[j]) break; // 已满足大顶堆的条件
        swap(b[i], b[j]);
        i = j; j = i * 2;
    }
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n, p = 2;
    scanf("%d", &n);
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
    while (p <= n && b[p - 1] <= b[p]) p++;
    int index = p;
    while (p <= n && a[p] == b[p]) p++;
    if (p == n + 1) {
        printf("Insertion Sort\n");
        sort(b.begin()+1, b.begin() + index + 1);
    }
    else {
        printf("Heap Sort\n");
        /**
         * 堆排序例子：可以看到这是一个大顶堆
         * 3 1 2 8 7 5 9 4 6 0
         * 6 4 5 1 0 3 2 7 8 9
         */
        p = n;
        while(p > 2&& b[p] >= b[1]) p--;
        swap(b[1], b[p]);
        downAdjust(b, 1, p - 1);
    }
    printf("%d", b[1]);
    for (int i = 2; i <= n; ++i) {
        printf(" %d", b[i]);
    }
    return 0;
}