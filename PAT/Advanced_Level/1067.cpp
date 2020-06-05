// /*
//    问题描述：
//    解题思路： 完全没想到思路
//  */
// #include <bits/stdc++.h>

// using namespace std;
// int main(int argc, char const *argv[]) {
//     int n;
//     cin >> n;
//     int *arr = new int[n];
//     for (int i = 0; i < n; ++i) {
//         scanf("%d", &arr[i]);
//     }
//     int cnt = 0;
//     int pos_0 = 0;
//     for (int i = 0; i < n; ++i) {
//         if (arr[i] == 0) {
//             pos_0 = i;
//             break;
//         }
//     }
//     // 错误解法
//     for (int i = 1; i < n; ++i) {
//         if (arr[i] == i) continue;
//         else {
//             for (int j = i + 1; j < n; j++) {
//                 if (arr[j] == i) {
//                     swap(arr[j], arr[pos_0]);
//                     cout << "swap: " << arr[pos_0] << ":" << arr[j] << endl;
//                     cout << "pos: " << pos_0 << ":" << j << endl;  
//                     pos_0 = j;
//                     cnt++;
//                     break;
//                 }
//             }
//         }
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
    int n, t, cnt = 0, a[100010];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        a[t] = i;
    }
    // 这个实现方法和题目给的例子是不太一样的
    // 例子：4 0 2 1 3
    // 题目过程：4 0 2 1 3 --> swap(0, 1): 4 1 2 0 3 --> swap(0, 3): 4 1 2 3 0 --> swap(0, 4): 0 1 2 3 4
    // 代码过程：4 0 2 1 3 --> swap(3, 4): 3 0 2 1 4 --> swap(3, 1): 1 0 2 3 4 --> swap(1, 0): 0 1 2 3 4
    // 所以题目给的例子有一定的误导性，不一定是最优的实现方法
    for (int i = 1; i < n; ++i) {
        if (i != a[i]) {
            while (a[0] != 0) {
                swap(a[0], a[a[0]]);
                cnt++;
            }
            if (i != a[i]) {
                swap(a[0], a[i]);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}