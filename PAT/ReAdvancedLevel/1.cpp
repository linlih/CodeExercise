/*******************************************************************
  > File Name    : 1.cpp
  > Author       : linlh
  > Created  Time: 2021.03.29 19:13
  > Modified Time: 2021.03.29 21:17
 *******************************************************************/

// #include "bits/stdc++.h"
// using namespace std;
// int main(){
//
//     // 这道题首先要明确的是数值的表示范围，就是long long类型能不能表示10^6大小
//     // long long 是正负2^63次方，大概是9×10^18次方，完全可以
//     long a, b, c;
//     cin >> a >> b;
//     c = a + b;
//     string str = to_string(c);
//
//     int i = 0;
//     string res;
//     for (auto it = str.rbegin(); it != str.rend(); ++it) {
//         res.push_back(*it);
//         i++;
//         // 这里要做特殊数据的处理，比如-100，100，这两种类型需要特殊处理
//         if (i % 3 == 0 && *(it+1) != '-'&&str.size() != 3) {
//             res.push_back(',');
//             i=0;
//         }
//     }
//     reverse(res.begin(), res.end());
//     cout << res << endl;
//     return 0;
// }
//
#include "bits/stdc++.h"

using namespace std;

int main() {
    // 柳姐的做法
    int a, b;
    cin >> a >> b;
    string s = to_string(a + b);
    int len = s.length();
    for (int i = 0; i < len; i++) {
        cout << s[i];
        if (s[i] == '-') continue;
        // 这里就是就神奇的地方，(i+1)%3==len%3神奇
        // i != len-1 表示的是不能在结尾处输出,
        if ((i + 1) % 3 == len % 3 &&i != len - 1) cout << ',';
    }
    return 0;
}
