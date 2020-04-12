/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    string s1;
    string s2;
    string res;
    getline(cin, s1);
    getline(cin, s2);
    for (int i = 0; i < s1.size(); i++) {
        if (s2.find(s1[i]) != string::npos) {
            //cout << s2.find(s1[i]) << endl;
            continue;
        }
        res += s1[i];
    }
    cout << res << endl;
    return 0;
}