// /*
//    问题描述：
//    解题思路： 这道题主要是要理解题意
//               比如说D，D1，其中D1表示的是前面这个数D有1个D，所以是D1
//                     D1, D111，则是说前面这个数D1，有1个D，1个1，所以是D1(1个D) 11(1个1)=D111
//                     D111 D113，则是说前面这个数有1个D，3个1，所以D1(1个D)13(3个1)
//                     同时要注意这个统计的是连续的数值个数！
//             下面这个实现有一个样例过不了。。。。
//  */
// #include <bits/stdc++.h>

// using namespace std;
// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     int d, n;
//     cin >> d >> n;
//     string res;
//     string tmp = to_string(d);
//     vector<int> v(10, 0); 
//     string ans;
//     tmp.push_back('1');
//     if (n == 0) {
//         cout << d << endl;
//         return 0;
//     }
//     for (int i = 1; i < n-1; ++i) {
//         int cnt = 1;
//         int j;
//         for ( j = 1; j < tmp.size() + 1; ++j) {
//             if (tmp[j - 1] == tmp[j])
//                 cnt++;
//             else {
//                 ans.push_back(tmp[j - 1]);
//                 ans.push_back(cnt + '0');
//                 cnt = 1;
//             }
//         }
//         // if (j == tmp.size() ) {
//         //     ans.push_back(tmp[j - 1]);
//         //     ans.push_back(cnt + '0');
//         // }
//         tmp = ans;
//         ans.clear();
//     } 
//     cout << tmp << endl;
//     return 0;
// }

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    string s;
    int n, j;
    cin >> s >> n;
    for (int cnt = 1; cnt < n; ++cnt) {
        string t;
        for (int i = 0; i < s.length(); i = j) {
            for (j = i; j < s.length() && s[j] == s[i]; j++); 
            t += s[i] + to_string(j - i);
        }
        s = t;
    }
    cout << s << endl;
    return 0;
}