/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int j = 0;
    int i = 0;
    unordered_set<char> worn;
    for (; i < s1.size(); ++i) {
        if (s1[i] == s2[j])
            j++;
        else 
            worn.insert(toupper(s1[i]));
    }

    stack<char> s;
    for (auto it = worn.begin(); it != worn.end(); ++it) 
        s.push(*it);
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
    return 0;
}


/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    string s1, s2, ans;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); ++i) {
        if (s2.find(s1[i]) == string::npos && ans.find(toupper(s1[i])) == string::npos)
            ans += toupper(s1[i]);
    }
    cout << ans;
    return 0;
}