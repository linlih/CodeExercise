/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int k;
    cin >> k;
    string str;
    cin >> str;
    map<char, int> m;
    stack<char> st;
    string out;
    unordered_set<char> brokenkey;
    for (int i = 0; i < str.size(); ++i) {
        if (st.empty()) st.push(str[i]);
        else if (st.top() != str[i]) {
            if  (st.size() >= k) {
                if (m.find(st.top()) == m.end()) {
                    m[st.top()] = 1;
                    brokenkey.insert(st.top());
                }
                else {
                    m[st.top()] = 2;
                }
            }
            while(!st.empty()) st.pop();
            st.push(str[i]);
            out.push_back(str[i]);
        }
        else if (st.top() == str[i]) {
            st.push(str[i]);
        }
    }
    for (auto it = brokenkey.begin(); it != brokenkey.end(); ++it) {
        if (m[*it] == 2)
            cout << *it;
    }
    cout << endl;
    for (int i = 0; i < str.size(); ++i) {
        if (m.find(str[i]) != m.end()) 
            if (m[str[i]] == 2)
                i += (k-1);   
        cout << str[i];
    }
    cout << endl;
    return 0;
}