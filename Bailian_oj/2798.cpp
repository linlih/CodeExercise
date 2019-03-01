/*
 * 这道题是个大数问题，无法用内置的数据类型来表示10000位的二进制数
 * 下面的做法是基于传统的思想，将二进制数转换成十进制，然后再转换成16进制
 */
// #include <iostream>
// #include <memory.h>

// using namespace std;

// unsigned long trans(string& num) {
//     unsigned long res = 0;
//     unsigned long base = 1;
//     for (int i = num.length() - 1; i >= 0; --i) {
//         res += (num[i] - '0')*base;
//         base *= 2;
//     }
//     return res;
// }

// #define SIZE 512

// int main(int argc, char const *argv[])
// {
//     int n;
//     cin >> n;
//     string str;
//     unsigned long res, tmp;
//     char hex[SIZE] = {0};
//     int k = 0;
//     for (int i = 0; i < n; ++i) {
//         cin >> str;
//         res = trans(str);
//         while (res!=0) {
//             tmp = res%16;
//             if (tmp < 10) {
//                 hex[k] = tmp + '0'; 
//             }
//             else if (tmp >= 10 && tmp <= 15) {
//                 hex[k] = tmp%10 + 'A';
//             }
//             k++;
//             res /= 16;
//         }
//         k = SIZE - 1;
//         while (hex[k] == 0) {
//             --k;
//             if (k == -1) {
//                 cout << "0";
//                 break;
//             }
//         }
//         for (int j = k; j >=0; --j)
//             cout << hex[j];
//         cout << endl;
//         memset(hex, 0, SIZE);
//     }
//     return 0;
// }

/*
 * 其实有个取巧的办法，我们知道二进制转换成16进制，可以按照4个二进制位为一组进行转换即可
 */
#include <iostream>
#include <string>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string str;
    int base[4] = {1, 2, 4, 8};
    int k = 0;
    int str_len = 0;
    int tmp = 0;
    string res;

    for (int i = 0; i < n; ++i) {
        cin >> str;
        for (int j = str.length() - 1; j >= 0; --j) {
            tmp += (str[j] - '0') * base[k];
            k++;
            if (k == 4 || j == 0) {
                if (tmp < 10)
                    res.insert(res.begin(), (char)(tmp + '0'));
                else if (tmp >= 10 && tmp <= 15)
                    res.insert(res.begin(), (char)(tmp%10 + 'A'));
                k = 0;
                tmp = 0;
            }
        }
        cout << res << endl;
        res.clear();
    }
    return 0;
}

