/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    int n, left = 0, right = 0, a = 1, now = 1, ans = 0;
    scanf("%d", &n);
    // 调试的例子：
    /*
    123
    12 3 0
    1 2 3
    0 1 23
    */
    while(n / a) {
        left = n /(a * 10); 
        now = n / a % 10;   
        right = n % a;
        //cout << left << " " << now << " " << right << endl;
        if (now == 0) ans += left * a;
        else if (now == 1) ans += left * a + right + 1;
        else ans += (left + 1) * a;
        a = a * 10;
    }
    printf("%d", ans);
    return 0;
}