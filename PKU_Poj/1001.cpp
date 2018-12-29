/********************************************************
* 特此说明, 代码参考自: https://blog.csdn.net/u012965373/article/details/21553483
*****************************************/

#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;

#define N 1000

// digits数组用于存放对应的数值信息, 每个int只保存一位
typedef struct {
    int digits[N];
    int len; // 长度
    int pos; // 小数点位置
}BigFloat;

// 打印大数, 数字的存储方式如下：
// 小数部分.整数部分, 数值排列反着排序
// eg: 数值123.456, 数组的存储为: 654.321
void printf_BigFloat(BigFloat f) {
    int i = 0, j = 0;
    // i变量用于确认小数点的位置
    while(f.digits[f.len - 1 - i] == 0 && f.len - f.pos > i)
        i++;
    while(f.digits[j] == 0 && j < f.pos)
        j++;
    for (; i < f.len - j; i++) {
        if (f.pos == f.len - i)
            putchar('.');
        cout << f.digits[f.len - 1 - i];
    }
}

// 两个大数的乘积
BigFloat BigFloat_multiply(BigFloat b, BigFloat c) {
    int i, j;
    BigFloat res;
    memset(res.digits, 0, sizeof(res.digits));
    res.pos = b.pos + c.pos;
    res.len = b.len + c.len;
    for (i = 0; i < b.len; i++)
        for (j = 0; j < c.len; j++)
            res.digits[i + j] += b.digits[i] * c.digits[j]; // 处理进位
    for (i = 0; i < res.len; i++)
        if (res.digits[i] > 9) {
            res.digits[i + 1] += res.digits[i] / 10;
            res.digits[i] %= 10;
            while (res.digits[res.len])
                res.len ++;
        }
    return res;
}

BigFloat BigFloat_pow(BigFloat s, int n) {
    BigFloat res;
    if (n == 1)
        return s;
    if (n == 2)
        return BigFloat_multiply(s, s);
    return BigFloat_multiply(s, BigFloat_pow(s, n - 1));
}

// 将数值字符串转化成BigFloat
BigFloat TranStr2BigFloat(const char str[]) {
    int len_str = 0;
    int len = 0;
    int i;
    BigFloat one;
    memset(one.digits, 0, sizeof(one.digits));
    one.len = 0;
    one.pos = 0;
    len_str = strlen(str);
    for (i = 0; i < len_str; i++) {
        if (str[len_str - 1 - i] == '.')
            one.pos = i;
        else {
            one.digits[len] = str[len_str - 1 - i] - '0';
            len ++;
        }
    }
    one.len = len;
    return one;
}

int main(int argc, char const *argv[])
{
    BigFloat bf;
    string str;
    int n;
    while(cin >> str >> n) {
        bf = TranStr2BigFloat(str.c_str());
        printf_BigFloat(BigFloat_pow(bf, n));
        cout << endl; 
    }
    return 0;
}