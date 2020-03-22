/*
   问题描述：
   解题思路： 
   这种实现方法会段错误
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    int n;
    int m;
    scanf("%d", &n);
    //long int *arr1 = new long int[n];
    int arr1[20005] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    scanf("%d", &m);
    //long int *arr2 = new long int[n];
    int arr2[20005] = {0};
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }
    
    // long int *arr = new long int[m+n];
    // for (int i = 0; i < n; i++) {
    //     arr[i] = arr1[i];
    // }
    // for (int i = n; i < m + n; i++) {
    //     arr[i] = arr2[i-n];
    // }
    // sort(arr, arr + m + n - 1);
    // cout << arr[(m + n - 1)/2] << endl;

    int i = 0, j = 0;
    int cnt = 0;
    long int ans = 0;
    int target = 0;
    target = (m + n -1)/2;
    while(i < n && j < m) {
        ans = arr1[i] <= arr2[j] ? arr1[i++] : arr2[j++];
        if (cnt == target) break; 
        cnt++;
    }
    //cout << cnt << target << endl;
    // if (i < n && cnt < target)
    //     ans = arr1[i + target - cnt ];
    // else if (j < m && cnt < target)
    //     ans = arr2[j + target - cnt ];
    printf("%d", ans);


    return 0;
}


// /*
//    问题描述：
//    解题思路： 
//  */
// #include <bits/stdc++.h>

// using namespace std;

// const int maxn = 200005;
// int n, m, a1[maxn], a2[maxn], cnt = 0, i, j, ans;

// int main(int argc, char const *argv[]) {
//     scanf("%d", &n);
//     for (int i = 1; i <= n; i++) scanf("%d", &a1[i]);
//     scanf("%d", &m);
//     for (int i = 1; i <= m; i++) scanf("%d", &a2[i]);
//     int target = (m + n + 1)/2;
//     i = 1, j = 1;
//     while(i <= n && j <= m) {
//         ans = a1[i] <= a2[j] ? a1[i++] : a2[j++];
//         if (++cnt == target) break;
//     }
//     if (i <= n && cnt < target)
//         ans = a1[i + target - cnt - 1];
//     else if (j <= m && cnt < target)
//         ans = a2[j + target - cnt - 1];
//     printf("%d", ans);
    
//     return 0;
// }






