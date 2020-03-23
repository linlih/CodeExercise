// /*
//    问题描述：
//    解题思路： 
//    这个思路部分正确
//  */
// #include <bits/stdc++.h>

// using namespace std;
// int main(int argc, char const *argv[]) {    
//     string str;
//     cin >> str;
//     int n1 = 3, n2 = 3;

//     int mid_l = str.length() - 1;
//     int mid = ((mid_l  % 2) == 0) ? mid_l / 2 - 1 : mid_l/2;
//     //cout << mid << endl;
//     int third_partial = mid / 3;
//     for (int i = 0; i < mid - third_partial; i++) {
//         cout << str[i];
//         for (int j = 0; j < str.length()- 2 *(mid - third_partial) - 2; j++) {
//             cout << " ";
//         }
//         cout << str[str.length() - 1 - i];
//         cout << endl;
//     }
//     int mid_max = ((mid_l  % 2) == 0) ? mid + third_partial + 2: mid + third_partial + 1;

//     for (int i = mid - third_partial; i <= mid_max; i++) {
//         cout << str[i];
//     }
//     cout << endl;

//     return 0; 
// }


/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    char c[81], u[30][30];
    memset(u, ' ', sizeof(u));
    scanf("%s", c);
    int n = strlen(c) + 2;
    int n1 = n / 3, n2 = n/3+n%3, index = 0;
    for (int i = 0; i < n1; i++) u[i][0] = c[index++];
    for (int i = 1; i <= n2-2; i++) u[n1-1][i] = c[index++];
    for (int i = n1-1; i>=0; i--) u[i][n2-1] = c[index++];

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++)
            printf("%c", u[i][j]);
        printf("\n");
    }
    
    return 0;
}