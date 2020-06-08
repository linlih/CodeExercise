// /*
//    问题描述：
//    解题思路： 
//  */
// #include <bits/stdc++.h>

// using namespace std;

// struct node {
//     int data;
//     int Next;
// };

// node arr[100010];

// int main(int argc, char const *argv[]) {
//     int start, n, k;
//     cin >> start >> n >> k;
//     int tmp, dat, nex;
//     for (int i = 0; i < n; ++i) {
//         cin >> tmp >> dat >> nex;
//         arr[tmp].data = dat;
//         arr[nex].Next = nex;
//     }
//     stack<int> s;
//     int pre = start;
//     int next = arr[pre].Next;
//     int i = 0;
//     for (int j = 1; j < k; j++) {
//         arr[pre].Next = arr[next].Next;
//         arr[next].Next = pre;
//         pre = next;
//         next = arr[pre].Next;
//     }
//     start = 0;
//     while (start != -1) {
//         cout << arr[start].data << endl;
//         start = arr[start].Next;
//     }
//     return 0;
// }

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    int first, k, n, sum = 0;
    cin >> first >> n >> k;
    int temp, data[100005], next[100005], list[100005], result[100005];
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        cin >> data[temp] >> next[temp];
    }
    while (first != -1) {
        list[sum++] = first;
        first = next[first];
    }
    for (int i = 0; i < sum; ++i) result[i] = list[i];
    for (int i = 0; i < (sum - sum % k); ++i) 
        result[i] = list[i/k*k + k - 1 - i %k];
    for (int i = 0; i < sum - 1; i++) 
        printf("%05d %d %05d\n", result[i], data[result[i]], result[i+1]);
    printf("%05d %d -1", result[sum - 1], data[result[sum -1]]);
    return 0;
}



