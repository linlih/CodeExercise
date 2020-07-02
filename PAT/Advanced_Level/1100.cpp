/*
   问题描述：没看懂题目
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

string a[13] = {"tret",  "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string b[13] = {"####", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

string s;
int len;
void func1(int t) {
    if (t / 13) cout << b[t / 13];
    if ((t / 13)&&(t % 13)) cout << " ";
    if (t % 13 || t == 0) cout << a[t % 13];
}

void func2() {
    int t1 = 0, t2 = 0;
    string s1 = s.substr(0, 3), s2;
    if (len > 4) s2 = s.substr(4, 3);
    for (int j = 1; j <= 12; ++j) {
        if (s1 == a[j] || s2 == a[j]) t2 = j;
        if (s1 == b[j]) t1 = j;
    }
    cout << t1 * 13 + t2;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    getchar(); // 用户输入完年龄后按回车结束输入，把“\n”留在了输入流里，而cin不会主动删除输入流内的换行符，这样换行符就被getline读取到，getline遇到换行符返回，因此程序不会等待用户输入。所以要读入下一个字符
    //cin.ignore();// 也可以使用这个方式
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        len = s.length();
        if (s[0] >= '0' && s[0] <= '9')
            func1(stoi(s));
        else 
            func2();
        cout << endl;
    }
    return 0;
}