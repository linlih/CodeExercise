// /*
//    问题描述：
//    解题思路： 只对了一个用例
//  */
// #include <bits/stdc++.h>

// using namespace std;
// int main(int argc, char const *argv[]) {
//     int n;
//     cin >> n;
//     cin.clear();
//     fflush(stdin);
//     vector<string> seq;
//     string tmp;
//     for (int i = 0; i < n; ++i) {
//         getline(cin, tmp);
//         reverse(tmp.begin(), tmp.end());
//         seq.push_back(tmp);
//     }
//     int min_size = seq[0].size();
//     for (int i = 1; i < seq.size(); ++i) {
//         if (min_size > seq[i].size()) min_size = seq[i].size();
//     }
//     string com;
//     for (int i = 0; i < min_size; i++) {
//         char tmp_c = seq[0][i];
//         int flag = true;
//         for (int j = 1; j < seq.size(); ++j) {
//             if (tmp_c != seq[j][i] ) {
//                 flag = false;
//                 break;
//             }
//         }
//         if (flag)
//             com.push_back(tmp_c);
//         else break;
//     }
//     reverse(com.begin(), com.end());
//     if (com.size() != 0)
//         cout << com << endl;
//     else 
//         cout << "nai" << endl;
//     return 0;
// }

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    int n;
    scanf("%d\n", &n);
    string ans;
    for (int i = 0; i < n; ++i) {
        string s;
        geline(cin, s);
        int lens = s.length();
        reverse(s.begin(), s.end());
        if (i == 0) {
            ans = s;
            continue;
        }
        else {
            int lenans = ans.length();
            if (lens < lenans) swap(ans, s);
            int minlen = min(lens, lenans);
            for (int j = 0; j < minlen; ++j) {
                if (ans[j] != s[j]) {
                    ans = ans.substr(0, j);
                    break;
                }
            }
        }
    }
    reverse(ans.begin(), ans.end());
    if (ans.length() == 0) ans = "nai";
    cout << ans << endl;
    return 0;
}

