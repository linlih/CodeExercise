/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

float num[2000] = {0};


int main(int argc, char const *argv[]) {
    #ifdef DEBUG
    freopen("input.txt","r",stdin);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        float number;
        cin >> tmp >> number;
        num[tmp]+=number;
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        float number;
        cin >> tmp >> number;
        num[tmp]+=number;
    }
    int cnt = 0; 
    for (int i = 0; i < 2000; ++i) {
        if (num[i] != 0) cnt++;
    }
    cout << cnt;
    for (int i = 1999; i >= 0; --i) {
        if (num[i] != 0)
            printf(" %d %.1f", i, num[i]);
    }
    cout << endl;
    return 0;
}