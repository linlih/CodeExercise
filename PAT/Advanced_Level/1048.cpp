// /*
//    问题描述：
//    解题思路： 
//  */
// #include <bits/stdc++.h>

// using namespace std;
// int main(int argc, char const *argv[]) {
//     int n, amount;
//     cin >> n >> amount;
//     int *arr = new int[n];
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }
//     sort(arr, arr + n);
//     int i = n/2;
//     int j = i + 1;
//     int res_i = n, res_j = -1;
//     while(i != 0 && j != (n-1)) {
//         if (arr[i] + arr[j] > amount)
//             i -= 1;
//         else if (arr[i] + arr[j] < amount)
//             j += 1;
//         else {
//             //if (res_i > i)  {
//                 res_i = i;
//                 res_j = j;
//             //}
//             i -= 1;
//             j += 1;
//         }
//         // cout << i << " " << j << endl;
//     }
//     if (res_j == -1 || res_i == n)
//         cout << "No Solution" << endl;
//     else
//         cout << arr[res_i] << " " << arr[res_j] << endl;
//     return 0;
// }

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    int n, amount;
    cin >> n >> amount;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    int i = 0;
    int j = n - 1;
    while(i != n-1 && j != 0) {
        if (arr[i] + arr[j] > amount)
            j -= 1;
        else if (arr[i] + arr[j] < amount)
            i += 1;
        else {
            break;
        }
        // cout << i << " " << j << endl;
    }
    if (i == n-1 || j == 0 || (i == j))
        cout << "No Solution" << endl;
    else
        cout << arr[i] << " " << arr[j] << endl;
    return 0;
}