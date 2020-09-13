/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    long a, b, c;
    cin >> a >> b;
    c = a + b;
    string str = to_string(c);
    int cnt = 0;
    cout << str << endl;
    string out;
    for (int i = str.length() - 1; i >= 0; --i) {
        cnt++;
        out += str[i];
        if (cnt == 3) {
            cnt == 0;
            out +=',';
        }
    }
    reverse(out.begin(), out.end());
    cout << out << endl;
    return 0;
}