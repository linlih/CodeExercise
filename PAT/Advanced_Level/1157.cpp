/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n, m;
    set<string> s;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        s.insert(str);
    }
    scanf("%d", &m);
    int cnt = 0;
    string date;
    string predate;
    string oldest;
    for (int i = 0; i < m; ++i) {
        string tmp;
        cin >> tmp;
        if (s.find(tmp) != s.end()) {
            predate = tmp.substr(7, 8);
            if (cnt == 0) {
                date = predate;
                oldest = tmp;
            }
            else  {
                if (date > predate) {
                    date = predate;
                    oldest = tmp;
                }
            }
            cnt++;
        } 
    }
    printf("%d\n", cnt);
    printf("%s\n", oldest.c_str());
    return 0;
}