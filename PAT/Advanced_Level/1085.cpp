// /*
//    问题描述：
//    解题思路： 部分正确，三个测试样例错误
//  */
// #include <bits/stdc++.h>

// using namespace std;
// int main(int argc, char const *argv[]) {
//     int n; long long  p;
//     cin >> n >> p;
//     int tmp;
//     vector<int> num;
//     for (int i = 0; i < n; ++i) {
//         scanf("%d", &tmp);
//         num.push_back(tmp);
//     } 
//     sort(num.begin(), num.end());
//     int min_n = num[0];
//     int max_n = num[num.size() - 1];
//     int cnt = 0;
//     for (auto it = num.begin(); it != num.end(); ++it) {
//         if ((*it) <= min_n * p)
//             cnt++;
//     }
//     cout << cnt << endl;
//     return 0;
// }


/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    int n; long long p;
    scanf("%d%lld", &n, &p);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int result = 0, temp = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + result; j < n; ++j) {
            if (v[j] <= v[i] * p) { // 将v[i]作为最小值
                temp = j - i + 1;
                if (temp > result) {
                    result = temp;
                    cout << result << endl;
                }
            }
            else {
                break;
            }
        } 
    }
    cout << result << endl;
    return 0;
}