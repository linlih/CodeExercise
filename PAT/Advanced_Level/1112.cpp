// /*
//    问题描述：
//    解题思路： 思路错误
//  */
// #include <bits/stdc++.h>

// using namespace std;
// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     int k;
//     cin >> k;
//     string str;
//     cin >> str;
//     map<char, int> m;
//     stack<char> st;
//     string out;
//     unordered_set<char> brokenkey;
//     for (int i = 0; i < str.size(); ++i) {
//         if (st.empty()) st.push(str[i]);
//         else if (st.top() != str[i]) {
//             if  (st.size() == k) {
//                 if (m.find(st.top()) == m.end()) {
//                     m[st.top()] = 1;
//                     brokenkey.insert(st.top());
//                 }
//                 else {
//                     m[st.top()] = 2;
//                 }
//             }
//             while(!st.empty()) st.pop();
//             st.push(str[i]);
//         }
//         else if (st.top() == str[i]) {
//             if  (st.size() == k) {
//                 if (m.find(st.top()) == m.end()) {
//                     m[st.top()] = 1;
//                     brokenkey.insert(st.top());
//                 }
//                 else {
//                     m[st.top()] = 2;
//                 }
//             }
//             st.push(str[i]);
//         }
//     }
//     for (auto it = brokenkey.begin(); it != brokenkey.end(); ++it) {
//         if (m[*it] == 2)
//             out.insert(out.begin(), *it);
//     }
//     cout << out <<  endl;
//     for (int i = 0; i < str.size(); ++i) {
//         if (m.find(str[i]) != m.end()) 
//             if (m[str[i]] == 2)
//                 i += (k-1);   
//         cout << str[i];
//     }
//     cout << endl;
//     return 0;
// }

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
bool sureNoBroken[256];
int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int k, cnt = 1;
    scanf("%d", &k);
    string s;
    cin >> s;
    map<char, bool> m;
    set<char> printed;
    char pre = '#';
    s = s + '#';
    for (int i = 0; i < s.length(); ++i) {
        if(s[i] == pre)
            cnt++;
        else {
            if (cnt % k != 0) {
                sureNoBroken[pre] = true;
            }
            cnt = 1;
        }
        if (i != s.length() - 1) m[s[i]] = (cnt % k == 0);
        pre = s[i];
    } 
    for (int i = 0; i < s.length() - 1; i++) {
        if (sureNoBroken[s[i]] == true)
            m[s[i]] = false;
    }
    for (int i = 0; i < s.length() - 1; ++i) {
        if (m[s[i]] && printed.find(s[i]) == printed.end()) {
            printf("%c", s[i]);
            printed.insert(s[i]);
        }
    }
    printf("\n");
    for (int i = 0; i < s.length() - 1; ++i) {
        printf("%c", s[i]);
        if (m[s[i]])
            i = i + k - 1;
    }
    return 0;
}