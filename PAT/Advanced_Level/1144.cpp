// /*
//    问题描述：
//    解题思路： 
//  */
// #include <bits/stdc++.h>

// using namespace std;

// int hash1[700000] = {0}; // hash的空间不够大，最后一个测试用例会段错误

// int main(int argc, char const *argv[]) {
//     //freopen("input.txt","r",stdin);
//     int n;
//     cin >> n;
//     int a;
//     int cnt = 0;
//     for (int i = 0; i < n; ++i) {
//         scanf("%d", &a);
//         if (a >= 0 && a < 700000) { // 由于hash表不够大，这里取了个巧，将a限制在这个范围内，侥幸通过
//         // 不属于完全正确的解法
//             hash1[a] = 1;
//             cnt ++;
//         }
//     } 
//     if (cnt == 0) {
//         cout << 1 << endl;
//         return 0;
//     }
//     int i = 0;
//     while(hash1[i] == 0) {i++;}
//     while(hash1[i] != 0) {i++;}
//     cout << i << endl;
//     return 0;
// }

/*
   问题描述：
   解题思路： 柳神的正确做法
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n, a, num = 0;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        m[a] ++;
    }

    while(++num)
        if (m[num] == 0) break; // 这里有一个神奇的magic！就是map可以直接访问未插入的元素
    cout << num << endl;
    return 0;
}
