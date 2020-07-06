// /*
//    问题描述：
//    解题思路：第三个测试用例过不了
//  */
// #include <bits/stdc++.h>

// using namespace std;
// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     int n;
//     cin >> n;
//     double temp;
//     double total = 0.0;
//     int cnt = 0;
//     char tmp_str[100] = {0};
//     for (int i = 0; i < n; ++i) {
//         scanf("%s", tmp_str);
//         //cout << tmp_str << endl;
//         int j = 0; 
//         bool is_num = true;
//         int dot_cnt = 0;
//         int dot_pos = 0;
//         int len = 0;
//         while(tmp_str[j] != 0) {
//             if (tmp_str[0] == '-') {
//                 j++;
//                 continue;
//             }
//             if (tmp_str[j] == '.') {
//                 dot_cnt++;
//                 if (dot_pos == 0) dot_pos = j;
//             }
//             else if (tmp_str[j] < '0' || tmp_str[j] > '9') {
//                 is_num = false;
//                 break;
//             } 
//             len++;
//             j++;
//         }
//         double trans_num = 0.0;
//         if (is_num) {
//             //cout << "dot_cnt: " << dot_cnt << " dot_pos: "<< dot_pos << " len: " << len << endl; 
//             if ((dot_cnt == 1 && len - 1 - dot_pos <= 2) || dot_cnt == 0) {
//                 trans_num = atof(tmp_str);
//                 if (trans_num >= -1000.0 && trans_num <= 1000.0) {
//                     total += trans_num;
//                     cnt++;
//                 }
//                 else {
//                     cout << "ERROR: " << tmp_str << " is not a legal number" << endl;
//                 }
//             }
//             else {
//                 cout << "ERROR: " << tmp_str << " is not a legal number" << endl;
//             }
//         }
//         else {
//             cout << "ERROR: " << tmp_str << " is not a legal number" << endl;
//         }
//         memset(tmp_str, 0, 100);
//     }
//     if (cnt == 1) {
//         printf("The average of %d number is %.2f\n", cnt, total/cnt);
//     }
//     else if (cnt > 1) {
//         printf("The average of %d numbers is %.2f\n", cnt, total/cnt);
//     }
//     else {
//         cout << "The average of 0 numbers is Undefined" << endl;
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
    freopen("input.txt","r",stdin);
    int n, cnt = 0;
    char a[50], b[50];
    double temp = 0.0, sum = 0.0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%s", a);
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2f", temp);
        int flag = 0;
        for (int j = 0; j < strlen(a); j++) 
            if (a[j] != b[j]) flag = 1;
        if (flag || temp < -1000 || temp > 1000) {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        }
        else {
            sum += temp;
            cnt++;
        }
    }
    if (cnt == 1) {
        printf("The average of 1 number is %.2f", sum);
    }
    else if (cnt > 1) {
        printf("The average of %d numbers is %.2f", cnt , sum/cnt);
    }
    else {
        printf("The average of 0 number is Undefined");
    }
    return 0;
}