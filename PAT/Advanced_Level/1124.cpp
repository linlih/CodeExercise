/*
   问题描述：
   解题思路：一个用例过不了 
             这道题的题意没有说的很清楚，如果这个人获奖过，那么下一次从下一个人开始计数
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int m, n, s;
    cin >> m >> n >> s;
    int cnt = 0;
    set<string> win;
    vector<string> follwer;
    follwer.resize(m + 1);
    for (int i = 1; i <= m; ++i) {
        string str;
        cin >> str;
        follwer[i] = str;
    }

    for (int i = 1; i <= m; ++i) {
        // if (i == (s + cnt*n))  {
        //     if (win.find(follwer[i]) == win.end()) {
        //         win.insert(follwer[i]);
        //         cnt++;
        //         cout << follwer[i] << endl;
        //     }
        //     else {
        //         // if (i + 1 != (m + 1)) {
        //         //     win.insert(follwer[i+1]);
        //         //     cnt++;
        //         //     cout << follwer[i+1] << endl; 
        //         //     i = i + 1;
        //         // }
        //         for (int j = i + 1; j <= m; j++) {
        //             if (follwer[j] != follwer[i]) {
        //                 win.insert(follwer[j]);
        //                 cnt++;
        //                 cout << follwer[j] << endl; 
        //             }
        //         }
        //     }
        // }
        if (win.find(follwer[i]) != win.end()) s = s + 1;
        else if (i == s && win.find(follwer[i]) == win.end()) {
            cout<< follwer[i] << endl;
            cnt++;
            win.insert(follwer[i]);
            s = s + n;
        }
    }
    if (cnt == 0) cout << "Keep going..." << endl;
    return 0;
}

// /*
//    问题描述：
//    解题思路： 
//  */
// #include <bits/stdc++.h>

// using namespace std;
// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     int m, n, s;
//     cin >> m >> n >> s;
//     string str;
//     map<string, int> mapp;
//     bool flag = false;
//     for (int i = 1; i <= m; ++i) {
//         cin >> str;
//         if (mapp[str] == 1) s = s + 1;
//         if (i == s && mapp[str] == 0) {
//             mapp[str] = 1;
//             cout << str << endl;
//             flag = true;
//             s = s + n;
//         }
//     }
//     if (flag == false) cout << "Keep going...";
//     return 0;
// }