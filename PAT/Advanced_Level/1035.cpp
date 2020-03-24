/*
   问题描述：
   解题思路： 
   一个测试样例没过!!
   原因是：只有一个account的时候，没有修改，输出的是There is xxx account,而不是There are xxx accounts
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<string> print;
    string acc, pass;
    bool modify;
    int index = 0;
    for (int i = 0; i < n; i++) {
        cin >> acc >> pass;
        modify = false;
        for (int j = 0; j < pass.size(); j++) {
            if (pass[j] == '1') {
                pass[j] = '@';
                modify = true;
            }
            if (pass[j] == '0') {
                pass[j] = '%';
                modify = true;
            }
            if (pass[j] == 'l') {
                pass[j] = 'L';
                modify = true;
            }
            if (pass[j] == 'O') {
                pass[j] = 'o';
                modify = true;
            }
        }
        if (modify) {
            print.push_back(acc + " " + pass);
        }
    }
    if (n == 1 && print.size() == 0)
        cout << "There is " << n << " account and no account is modified" << endl;
    else if (print.size() == 0)
        cout << "There are " << n << " accounts and no account is modified" << endl;
    else {
        cout << print.size() << endl;
        for (int i = 0; i < print.size(); i++) 
            cout << print[i] << endl;
    }
    return 0;
}

// /*
//    问题描述：
//    解题思路： 
//  */
// #include <bits/stdc++.h>

// using namespace std;
// int main(int argc, char const *argv[]) {
//     int n;
//     cin >> n;
//     vector<string > v;
//     for (int i = 0; i < n; i++) {
//         string name, s;
//         cin >> name >> s;
//         int len = s.length(), flag = 0;
//         for (int j = 0; j < len; j++) {
//             switch (s[j])
//             {
//             case '1':s[j]= '@'; flag = 1;      break;
//             case '0':s[j]= '%'; flag = 1;      break;
//             case 'l':s[j]= 'L'; flag = 1;      break;
//             case 'O':s[j]= 'o'; flag = 1;      break;
//             default:
//                 break;
//             }
//         }
//         if (flag) {
//             string temp = name + " " + s;
//             v.push_back(temp);
//         }
//     }
//     int cnt = v.size();
//     if(cnt != 0) {
//         printf("%d\n", cnt);
//         for(int i = 0; i < cnt; i++)
//             cout << v[i] << endl;
//     } else if(n == 1) {
//         printf("There is 1 account and no account is modified");
//     } else {
//         printf("There are %d accounts and no account is modified", n);
//     }
//     return 0;
// }