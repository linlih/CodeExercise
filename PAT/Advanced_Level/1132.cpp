/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

long long toint(string str) {
    long index = 1;
    long long sum = 0;
    for (int i = str.size() - 1; i >= 0; --i) {
        sum += index*(int)(str[i] - '0');
        index *= 10;
    }
    return sum;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    string str;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        long long fr = toint(str.substr(0, str.size()/2));
        long long ba = toint(str.substr(str.size()/2));
        //cout << fr << " " << ba << endl;
        long long s = toint(str);
        // fr*ba可能为0，所以要多加一个判断
        if ((fr * ba != 0) && (s % (fr * ba) == 0))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    } 
    return 0;
}