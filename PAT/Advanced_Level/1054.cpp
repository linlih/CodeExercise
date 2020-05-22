/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    int m, n;
    cin >> m >> n;
    map<int, int> color;
    int tmp;
    int half = (m * n)/2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &tmp);
            color[tmp]++;
            if (color[tmp] > half) {
                cout << tmp << endl;
                return 0;
            }
        }
    }
    return 0;
}