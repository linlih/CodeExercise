/*
//    问题描述：
//    解题思路： 错误的思路，规律找的不对
//  */
// #include <bits/stdc++.h>

// using namespace std;

// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     int n;
//     cin >> n;
//     vector<double> num;
//     double temp;
//     for (int i = 0; i < n; ++i) {
//         cin >> temp;
//         num.push_back(temp);
//     }

//     vector<int> cnt(n);
//     cnt[0] = num.size();
//     for (int i = 1; i < n; ++i) {
//         for (int j = 0; j < i; j++)
//             cnt[i] += (num.size() - i + 1);
//         cnt[i] += (num.size() - i);
//         cout << cnt[i] << endl;
//     }
//     long long  sum = 0;
//     for (int i = 0; i < n; ++i)
//         sum += (num[i]*cnt[i]);
//     printf("%.2f\n", sum);
//     return 0;
// }
