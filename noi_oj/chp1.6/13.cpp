/* 
 * 这个方法的整除7的没有实现 
*/


// #include <iostream>
// #include <string>

// using namespace std;

// /*
// （2）能被2整除的数的特征
// 若一个整数的末位是0、2、4、6或8，则这个数能被2整除。
// （3）能被3整除的数的特征
// 1，若一个整数的数字和能被3整除，则这个整数能被3整除。
// 2，由相同的数字组成的三位数、六位数、九位数……这些数字能被3整除。如111令3整除。 [2] 
// （4）能被4整除的数的特征
// 若一个整数的末尾两位数能被4整除，则这个数能被4整除。
// （5）能被5整除的数的特征
// 若一个整数的末位是0或5，则这个数能被5整除。
// （6）能被6整除的数的特征
// 若一个整数能被2和3整除，则这个数能被6整除。
// （7）能被7整除的数的特征 [2] 
// 1.若一个整数的个位数字截去，再从余下的数中，减去个位数的2倍，如果差是7的倍数，则原数能被7整除。如果差太大或心算不易看出是否7的倍数，就需要继续上述「截尾、倍大、相减、验差」的过程，直到能清楚判断为止。同能被17整除的数的特征。
// 2.末三位以前的数与末三位以后的差（或反过来）。同能被11,13整除的数的特征。
// （8）能被8整除的数的特征
// 若一个整数的末尾三位数能被8整除，则这个数能被8整除。
// （9）能被9整除的数的特征
// 若一个整数的数字和能被9整除，则这个整数能被9整除。
// */

// int* big_add(int *a, int *b, int *res) {
//     int tmp;

//     for (int i = 0; i < 210; ++i) {
//         tmp = res[i] + a[i] + b[i];
//         if (tmp >= 10) {
//             res[i] = tmp%10;
//             res[i+1] = tmp/10;
//         }
//         else {
//             res[i] = tmp;
//         }
//     }
//     return res;
// }

// // 实现一个大数减法
// int* big_minus(int *a, int *b, int *res) {
//     int tmp;
//     for (int i = 0; i < 210; ++i) {
//         if ((res[i] + a[i]) < b[i]) { // 接上res[i]是为了解决这种情况：987-87 结果为：9-19
//             res[i] = res[i] + a[i] + 10 - b[i];
//             res[i+1] = res[i+1] - 1;
//         }
//         else {
//             res[i] = res[i] + a[i] - b[i];
//         }
//     }
//     return res;
// }

// void str2arr(string &str, int *arr) {
//     for (int i = 0; i < str.length(); ++i) {
//         arr[str.length() - i - 1] = (str[i] - '0');
//     }
// }

// int main(int argc, char const *argv[])
// {
//     string str;
//     int a[30] = {0};
//     long sum = 0;
//     int num = 0;
//     int flag_2 = 0;
//     int flag_3 = 0;
//     int tmp = 0;
    
//     cin >> str;
//     str2arr(str, a);
//     int res[30] = {0};
//     // if (a[0]%2 == 0) {
//     //     cout << "2 ";
//     //     flag_2 = 1;
//     // }

//     // for (int i = 0; i < 30; ++i) {
//     //     sum+=a[i];
//     // }
//     // if (sum%3 == 0) {
//     //     cout << "3 ";
//     //     flag_3 = 1;
//     // }

//     // num = a[1]*10 + a[0];
//     // if (num%4 == 0)
//     //     cout << "4 "; 

//     // if (a[0]%5 == 0)
//     //     cout << "5 ";

//     // if (flag_2 == 1 && flag_3 == 1)
//     //     cout << "6 "; 

//     // int tmp[30] = {0};
//     // for (int i = 0; i < (str.length() - 2); ++i) {
//     //     int k = 1;
//     //     int m = 0;
//     //     for (int j = k;j < str.length(); ++j) {
//     //         tmp[m] = a[j];
//     //         m++;
//     //     }
//     //     m = 0;
//     //     int res[30] = {0};
//     //     big_minus(tmp, b, res);
//     // }


//     //for (int i = 0; i == 0; ++i) {
//     // for (int i = 0; i < (str.length() - 2); ++i) {
//     //     if (a[i+1] < (2*a[i])) {
//     //         if (a[i] < 5)
//     //         {
//     //             a[i+1] = a[i+1] + 10 - 2*a[i];
//     //             if (a[i+2] != 0)
//     //                 a[i+2] = a[i+2]-1;
//     //             else {
//     //                 tmp = i + 2;
//     //                 while(a[tmp] == 0) {
//     //                     a[tmp] = 9;
//     //                     tmp++;
//     //                 } 
//     //                 a[tmp] = a[tmp] - 1;
//     //             }
//     //         }
//     //         else {
//     //             a[i+1] = a[i+1] + 10 - 2*a[i]%10;
//     //             if (a[i+2] != 0)
//     //                 a[i+2] = a[i+2]-1;
//     //             else {
//     //                 tmp = i + 2;
//     //                 while(a[tmp] == 0) {
//     //                     a[tmp] = 9;
//     //                     tmp++;
//     //                 } 
//     //                 a[tmp] = a[tmp] - 1;
//     //             }
//     //             a[i+2] = a[i+2] + 10 - 2*a[i]/10;
//     //             if (a[i+3] != 0)
//     //                 a[i+3] = a[i+3]-1;
//     //             else {
//     //                 tmp = i + 3;
//     //                 while(a[tmp] == 0) {
//     //                     a[tmp] = 9;
//     //                     tmp++;
//     //                 } 
//     //                 a[tmp] = a[tmp] - 1;
//     //             }
//     //         }
//     //     }
//     //     else {
//     //         a[i+1] = a[i+1] - 2*a[0];
//     //     }
//     // }
//     // cout <<"test:" <<a[str.length() - 1] << " "<< a[str.length() - 2] << " " << a[str.length() - 3] << " " << a[str.length() - 4] << endl;

//     // num = a[2]*100 + a[1]*10 + a[0];
//     // if (num%8 == 0)
//     //     cout << "8 ";

//     // if (sum%9 == 0)
//     //     cout << "9";
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int a[40] = {};
int main()
{
    int i, j, c, d = 0;
    char al[40];
    gets(al);
    for (i = 2; i <= 9; i++)
    {
        for (j = 0; j < strlen(al); j++)
            a[strlen(al) - j] = al[j] - 48;
        if (strlen(al) == 1 && a[strlen(al)] == 0)
        {
            cout << "none";
            return 0;
        }
        for (j = strlen(al); j >= 1; j--)
        {
            if (j != 1)
            {
                a[j - 1] += (a[j] % i) * 10;
                a[j] = 0;
            }
            else
                c = a[j] % i;
        }
        if (c == 0)
        {
            cout << i << " ";
            d = 1;
        }
    }
    if (d == 0)
        cout << "none";
    return 0;
}