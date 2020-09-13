/*
   问题描述：
   解题思路： 虽然全对了，但是思路非常乱，需要重新写下
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    #ifdef DEBUG
    freopen("input.txt","r",stdin);
    #endif
    long a, b, c;
    cin >> a >> b;
    c = a + b;
    string str = to_string(c);
    int cnt = 0;
    //cout << str << endl;
    string out;
    int j = 0;
    if (str[0] == '-') {
        j = 1;
    }
    for (int i = str.length() - 1; i >= j; --i) {
        cnt++;
        out += str[i];
        if (cnt == 3) {
            cnt = 0;
            if (i != j)
                out += ',';
        }
    }
    if (j == 1) out += '-';
    reverse(out.begin(), out.end());
    cout << out << endl;
    return 0;
}   