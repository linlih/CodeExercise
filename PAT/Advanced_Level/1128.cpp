/*
   问题描述：
   解题思路：有一个测试点过不了。找到原因了。要增加一个判断v[i] == v[j]
             这个场景是两个皇后处于同一行的情况
 */
#include <bits/stdc++.h>

using namespace std;

bool judge(vector<int> &v) {
    for (int i = 1; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            if (v[i] == v[j] || (abs(i - j) == abs(v[i] - v[j])))
                return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        vector<int> v(temp+1);
        for (int j = 1; j <=temp; ++j) {
            cin >> v[j];
        }
        printf("%s\n", judge(v)==true?"YES":"NO");
        v.clear();
    }
    return 0;
}