// /*
//    问题描述：
//    解题思路： 
//  */
// #include <bits/stdc++.h>

// using namespace std;
// bool human[110] = {false};
// bool wolf[110] = {false};
// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     fill(human, human + 110, false);
//     fill(wolf, wolf + 110, false);
//     int n;
//     scanf("%d", &n);
//     int cnt_wolf = 0;
//     for (int i = 0; i < n; ++i) {
//         int a;
//         scanf("%d", &a);
//         if (a < 0) {
//             wolf[-a] = true;
//             cnt_wolf++;
//         }
//         else 
//             human[a] = true;
//     }
//     if (cnt_wolf > 3)
//         printf("No Solution\n");
//     else 
//         printf("1 2\n");
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
    vector<int> v(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            vector<int> lie, a(n + 1, 1); // a数组表示的是这个人是好人还是狼人，默认都是好人，-1表示为狼人
            a[i] = a[j] = -1;// 假设i和j是狼人
            for (int k = 1; k <= n; ++k) 
                // 如果当前的假设和实际说的不符合，则说明这个人说谎
                if (v[k] * a[abs(v[k])] < 0) lie.push_back(k);
            if (lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0) { // a[lie[0] ]+ a[lie[1]] == 0，表示撒谎的人其中一个是好人，一个是狼人，这个是题目的要求
                cout << i << " " << j; // 因为i是从小到大遍历，如果找到了一个解，一定是最小的那个解，所以多个Solution的情况下满足输出最小解的条件
                return 0;
            }
        }
    }
    cout << "No Solution";
    return 0;
}