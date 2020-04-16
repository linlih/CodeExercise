/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s;
        stack<char> t;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] != '#') s.push(S[i]);
            if (S[i] == '#' && s.size() != 0) {
                s.pop();
            }
        }

        for (int i = 0; i < T.length(); i++) {
            if (T[i] != '#') t.push(T[i]);
            if (T[i] == '#' && t.size() != 0) {
                t.pop();
            }
        }

        if (s.size() != t.size()) return false;

        while (s.size() != 0 && t.size() != 0) {
            if (s.top() != t.top()) return false;
            s.pop(); t.pop();
        }
        return true;
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;
    string S("bxj##tw");
    string T("bxj###tw");

    cout << sol.backspaceCompare(S, T) << endl;
    return 0;
}