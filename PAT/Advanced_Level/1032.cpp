// /*
//    问题描述：
//    解题思路： 
//    一个测试用例没过
//  */
// #include <bits/stdc++.h>

// using namespace std;
// int main(int argc, char const *argv[]) {
//     int arr[100010];
//     int word1, word2;
//     int n;
//     cin >> word1 >> word2 >> n;
//     int addr,  next;
//     char data;
//     for (int i = 0;i < n; i++) {
//         cin >> addr >> data >> next;
//         arr[addr] = next;
//     }
//     int word1_len = 1, word2_len = 1;
//     int word1_start_tmp = word1;
//     int word2_start_tmp = word2;
//     for (int i = 0; i < n; i++) {
//         if (arr[word1_start_tmp] == -1) break;
//         word1_start_tmp = arr[word1_start_tmp];
//         word1_len ++;
//     }
//     for (int i = 0; i < n; i++) {
//         if (arr[word2_start_tmp] == -1) break;
//         word2_start_tmp = arr[word2_start_tmp];
//         word2_len ++;
//     }
//     //cout << word1_len << " " << word2_len<< endl;
//     bool found = false;
//     if (word1_len > word2_len) {
//         int tmp = word1_len - word2_len;
//         while(tmp!=0) {
//             word1 = arr[word1];
//             tmp -= 1;
//         }
//         // cout << word1 << endl;
//         for (int i = 0; i < n; i++) {
//             if (arr[word2] == arr[word1]) {
//                 cout << arr[word1] << endl;
//                 found = true;
//                 break;
//             }
//             word1 = arr[word1];
//             word2 = arr[word2];
//         }
//     }
//     else {
//         int tmp = word2_len - word1_len;
//         while(tmp!=0) {
//             word2 = arr[word2];
//             tmp -= 1;
//         }
//         //cout << word1 << endl;
//         for (int i = 0; i < n; i++) {
//             if (arr[word2] == arr[word1]) {
//                 cout << arr[word1] << endl;
//                 found = true;
//                 break;
//             }
//             word1 = arr[word1];
//             word2 = arr[word2];
//         }
//     }
//     if (!found)
//         cout << "-1" << endl;
//     return 0;
// }

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

struct NODE {
    char key;
    int next;
    bool flag;
}node[100010];

int main(int argc, char const *argv[]) {
    int s1, s2, n, a, b;
    scanf("%d%d%d", &s1, &s2, &n);
    char data;
    for (int i = 0; i < n; i++) {
        scanf("%d %c %d", &a, &data, &b);
        node[a] = {data, b, false};
    }
    for (int i = s1; i != -1;i = node[i].next) 
        node[i].flag = true;
    for (int i = s2; i != -1; i = node[i].next) {
        if (node[i].flag == true) {
            printf("%05d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}