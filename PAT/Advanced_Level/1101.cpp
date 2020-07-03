// /*
//    问题描述：
//    解题思路： 这个方法有两个测试样例超时
//  */
// #include <bits/stdc++.h>

// using namespace std;

// bool judge(vector<int> v) {
    
// }
// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     int n;
//     cin >> n;
//     vector<int> v;
//     int temp;
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &temp);
//         v.push_back(temp);
//     }
//     vector<int> pivot;
//     for (int i = 0; i < n; i++) {
//         int j = i + 1;
//         bool flag = true;
//         for (int k = i+1; k < n; ++k) {
//             if (v[k] < v[i]) {
//                 flag = false;
//                 break;
//             } 
//         }
//         if (!flag) continue;
//         for (int k = 0; k < i; ++k) {
//             if (v[k] > v[i])  {
//                 flag = false;
//                 break;
//             }
//         }
//         if (flag)
//             pivot.push_back(v[i]);
//     }
//     cout << pivot.size() << endl;
//     sort(pivot.begin(), pivot.end());
//     for (int i = 0; i < pivot.size(); ++i)
//         if (i == 0) cout << pivot[0];
//         else cout << " " << pivot[i];
//     cout << endl;
//     return 0;
// }   

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

int v[100000];

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n, max = 0, cnt = 0;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        // 需要大于max的原因在于有这样一种情况5 2 3 4 1，排序后为1 2 3 4 5，虽然3的位置没有发生变化，但是它不能作为pivot，所以需要排除这种情况。pivot满足一定是比左边的最大值大，那么就可以解决这个问题。
        // 这里的max代表的就是左边序列最大的值
        if (a[i] == b[i] && b[i] > max)
            v[cnt++] = b[i];
        if (b[i] > max)
            max = b[i];
    }
    printf("%d", cnt);
    for (int i = 0; i < cnt; ++i) {
        if (i != 0) cout << " ";
        cout << v[i]; 
    }
    cout << endl;
    return 0;
}