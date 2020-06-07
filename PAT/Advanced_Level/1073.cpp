/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    string s;
    cin >> s;
    int i = 0;
    while (s[i] != 'E') ++i;
    string t = s.substr(1, i-1);
    int n = stoi(s.substr(i+1)); // 取指数部分
    if (s[0] == '-') cout << '-';
    if (n < 0) {
        cout << "0.";
        for (int j = 0; j < abs(n) - 1; ++j) cout << '0';
        for (int j = 0; j < t.length(); j++)
            if (t[j] != '.') cout << t[j];
    }
    else { // 这个实现只能转换x.xxxxExx的形式，如果是xx.xxxxExxx则出错
        cout << t[0]; //
        int cnt, j;
        // j从2开始跳过小数点
        for (j = 2, cnt = 0; j < t.length() && cnt < n; j++, cnt++) cout << t[j];
        // +1.23000E01 输出结果为：12.3000
        if (j == t.length()) {
            for (int k = 0; k < n - cnt; k++) cout <<'0';
        }
        else {
            cout << ".";
            for (int k = j; k < t.length(); k++) cout << t[k];
        }
    }
}