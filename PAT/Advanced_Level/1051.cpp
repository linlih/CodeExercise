/*
   问题描述：考察的是栈的序列满足什么样的关系
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    int m, n, k;
    cin >> m >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < k; i++) {
        bool flag = false;
        stack<int> s;
        vector<int> v(n+1);
        for (int j = 1; j <= n; j++) 
            scanf("%d", &v[j]);
        int current = 1;
        // 判断方式，按照顺序压栈，然后根据判定序列出列
        for (int j = 1; j <= n; j++) {
            s.push(j);
            if (s.size() > m) break;
            while(!s.empty() && s.top() == v[current]) {
                s.pop();
                current ++;
            }
        }
        if (current == (n + 1)) flag = true;
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}