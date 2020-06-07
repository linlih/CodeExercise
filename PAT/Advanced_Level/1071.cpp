/*
   问题描述：
   解题思路：这道题的描述有点莫名其妙，输入的句子是以“”开头结束，还是直接就是一个句子也没有说清楚。。。 
   参考了github，输入就是直接一个句子，不是用“”代表一个句子的
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    string s, t;
    getline(cin ,s);
    map<string, int> m;
    for (int i = 0; i < s.length(); ++i) {
        if (isalnum(s[i])) { // 该函数用于判断一个字符是否是字母数字，相关的函数有isdigit，isalpha
            s[i] = tolower(s[i]);
            t += s[i];
        }
        if (!isalnum(s[i]) || i == s.length() - 1) {
            if (t.length() != 0) m[t]++;
            t = "";
        }
    }
    int maxn = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second > maxn) {
            t = it->first;
            maxn = it->second;
        }
    }
    cout << t << " " << maxn << endl;
    return 0;
}