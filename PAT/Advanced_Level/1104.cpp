// /*
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
//         // for (int j = 0; j < i; j++)
//         //     cnt[i] += (num.size() - i + 1);
//         // cnt[i] += (num.size() - i);
//         cnt[i] = i * (n - i + 1);
//         cout << cnt[i] << endl;
//     }
//     long long  sum = 0;
//     for (int i = 0; i < n; ++i)
//         sum += (num[i]*cnt[i]);
//     printf("%.2f\n", sum);
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
    int n;
    cin >> n;
    long long sum = 0;
    double temp;
    for (int i = 1; i <= n; ++i) {
        cin >> temp;
        /**
         * ref: https://blog.csdn.net/S_999999/article/details/98248683
         * 将数列中的每个数字读取到temp中，假设我们选取的片段中包括temp，且这个片段的首尾指针分别为p和q，那么对于p，有i种选择，即12…i，对于q，有n-i+1种选择，即i, i+1, … n，所以p和q组合形成的首尾片段有i * (n-i+1)种，因为每个里面都会出现temp，所以temp引起的总和为temp * i * (n – i + 1)；遍历完所有数字，将每个temp引起的总和都累加到sum中，最后输出sum的值
         */
        cout << i * (n - i + 1) << endl;
        sum += (long long)(temp * 1000) * i * (n - i + 1);
    }
    printf("%.2f", sum/1000.0);
    return 0;
}