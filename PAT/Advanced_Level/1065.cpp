/*
   问题描述：
   解题思路： 一开始的思路是大数的加减
 */
// #include <bits/stdc++.h>

// using namespace std;

// bool add(string a, string b, string c) {
    
// }

// int main(int argc, char const *argv[]) {
//     string a, b, c;
//     int n;
//     cin >> n;
//     for(int i = 0; i < n; ++i) {
//         cin >> a >> b >> c;
//         cout << "Case #" << i + 1 << ": " << add(a, b, c) << endl;
//     }
//     return 0;
// }

/*
   问题描述：
   解题思路： 这道题的关键点在于数据范围，2^63次方刚好是long long 的取值范围
 */

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        long long sum = a + b;
        if (a > 0 && b > 0 && sum < 0) { // 两个数的和超出longlong的表示范围，所以一定大于c
            printf("Case #%d: true\n", i + 1);
        } else if (a < 0 && b < 0 && sum >= 0) { // 两个负数的和大于0，一定小于c
            printf("Case #%d: false\n", i + 1);
        } else if (sum > c) { // 正常表示范围内的判断
            printf("Case #%d: true\n", i + 1);
        } else {
            printf("Case #%d: false\n", i + 1);
        }
    }
    return 0;
}