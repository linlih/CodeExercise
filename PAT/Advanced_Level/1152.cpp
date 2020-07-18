/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

long tonum(string s) {
    long res = 0;
    int idx = 1;
    for (int i = s.size() - 1; i >= 0; --i) {
        res += (s[i] - '0')*idx;
        idx *= 10;
    }
    return res;
}

int l, k;
string str;

bool isPrime(long a) {
    for (int i = 2; i <= (int)sqrt(a); ++i) {
        if (a % i == 0) return false;
    }
    return true;
}
bool flag = false;
/*void dfs(int s, int e) {
    if (s - e < k ||e == str.size() || flag == true) return;
    if (s - e == k) {
        long num = tonum(str.substr(s, s-e));
        if (isPrime(num)) {
            cout << str.substr(s, s-e) << endl;
            flag = true;
            return;
        }
    }
    for (int i = e + 1; i < str.size(); i++) {
        dfs(s, i);
    }
    dfs(s + 1, s + 2);
}*/

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    scanf("%d %d", &l, &k);
    //string str;
    cin >> str;

    //dfs(0, 1);
    for (int i = 0; i < l; ++i) {
        if (i == 0 && i + k < l) {
            long num = tonum(str.substr(i, str.size()));
            if (isPrime(num)) {
                cout << str.substr(i, str.size()) << endl;
                flag = true;
                break;
            }
        }

        if (i + k < l) {
            long num = tonum(str.substr(i, k));
            if (isPrime(num)) {
                cout << str.substr(i, k) << endl;
                flag = true;
                break;
            }
        }
    }
    if (!flag) cout <<"404" << endl;

    return 0;
}