/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    string shop;
    string eva;
    cin >> shop;
    cin >> eva;
    map<char, int> s;
    map<char, int> e;
    for (int i = 0; i < shop.size(); ++i) {
        if (s.find(shop[i]) == s.end()) {
            s[shop[i]] = 1;
        }
        else {
            s[shop[i]] ++;
        }
    }
    for (int i = 0; i < eva.size(); ++i) {
        if (e.find(eva[i]) == e.end()) {
            e[eva[i]] = 1;
        }
        else {
            e[eva[i]] ++;
        }
    }
    bool flag = true;
    int cnt = 0;
    for (int i = 0; i < eva.size(); ++i) {
        if (s.find(eva[i]) != s.end() && s[eva[i]] > 0) {
            e[eva[i]] --;
            s[eva[i]] --;
        }
    }
    for (auto it = e.begin(); it != e.end(); it++) {
        cnt += it->second;
    }
    if (cnt == 0) cout << "Yes " << shop.size() - eva.size() << endl;
    else cout << "No " << cnt << endl; 
    return 0;
}