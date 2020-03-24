
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