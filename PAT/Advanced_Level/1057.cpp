// /*
//    问题描述：
//    解题思路： 
//  */
// #include <bits/stdc++.h>

// using namespace std;

// int arr[100010];

// int main(int argc, char const *argv[]) {
//     int n;
//     string in;
//     stack<int> s;
//     int index = -1;
//     scanf("%d", &n);
//     cin.sync();
//     for (int i = 0; i < n; i++) {
//         // cout << "-------------------- "  << i << endl;
//         getline(cin, in, '\n');
//         if (in == "Pop") {
//             if (s.size() > 0) {
//                 cout << s.top() << endl;
//                 s.pop();
//                 index --;
//             }
//             else cout << "Invalid" << endl;
//         }
//         else if (in == "PeekMedian") {
//             if (index < 0)
//                 cout << "Invalid" << endl;            
//             else 
//                 cout << arr[(index + 1)/2] << endl;
//         }
//         else {
//             s.push(in[5] - '0');
//             index++;
//             arr[index] = (in[5] - '0');
//         }
//     }
//     return 0;
// }

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

#define lowbit(i) ((i) & (-i))
const int maxn = 100010;

using namespace std;

int c[maxn];
stack<int> s;
void update (int x, int v) {
    for (int i = x; i < maxn; i += lowbit(i))
        c[i] += v;
}

int getsum(int x) {
    int sum = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
        sum += c[i];
    return sum;
}

void PeekMedian() {
    int left = 1, right = maxn, mid, k = (s.size() + 1) /2;
    while (left < right) {
        mid = (left + right) / 2;
        if (getsum(mid) >= k)
            right = mid;
        else 
            left = mid + 1;
    }
    printf("%d\n", left);
}

int main(int argc, char const *argv[]) {
    int n, temp;
    scanf("%d", &n);
    char str[15];
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        if (str[1] == 'u') {
            scanf("%d", &temp);
            s.push(temp);
            update(temp, 1);
        }
        else if (str[1] == 'o') {
            if (!s.empty()) {
                update(s.top(), -1);
                printf("%d\n", s.top());
                s.pop();
            }
            else 
                printf("Invalid\n");
        }
        else {
            if (!s.empty())
                PeekMedian();
            else
                printf("Invalid\n");
        }
    }    
    return 0;
}