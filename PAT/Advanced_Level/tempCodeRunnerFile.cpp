/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

long long tonum(string s) {
    long long res = 0;
    long index = 1;
    for (int i = s.size() - 1; i >= 0; --i) {
        res += (index * (s[i]-'0'));
        index*=10;
    }
    return res;
}

bool judge(string s) {
    for (int i = 0; i < s.size()/2; ++i)
        if (s[i] != s[s.size() - 1 - i])
            return false;
    return true;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    long long n;
    cin >> n;
    for (int i = 0; i < 10; ++i) {
        string num = to_string(n);
        reverse(num.begin(), num.end());
        long long re_n = tonum(num);
        long long res = n + re_n;
        cout << n << " + " << re_n << " = " << res << endl;
        if (judge(to_string(res))) {
            cout << res << " is a palindromic number." << endl;
            return 0;
        }
        n = res;
    }
    cout << "Not found in 10 iterations." << endl;
    return 0;
}