#include <iostream>
#include <string.h>

using namespace std;

long long trans_str_to_num(char n[],int length, int r) {
    long long num = 0;
    int i = length - 1;
    long long radix = 1;
    while(i >= 0) {
        if (n[i] >= 'A' && n[i] <= 'Z')
            num += radix * (n[i] - 'A' + 10);
        else if  (n[i] >= 'a' && n[i] <= 'z')
            num += radix * (n[i] - 'a' + 10);
        else 
            num += radix * (n[i] - '0');
        radix *= r;
        i--;
    }
    return num;
}

int main(int argc, char const *argv[])
{
    int size = 1000;
    int a, b;
    char n[size] = {0};
    cin >> a >> n >> b;

    long long r = trans_str_to_num(n, strlen(n), a);
    char res[size] = {0};
    memset(res, 0, size);

    int d[size] = {0};

    //cout << r << endl;
    if (strcmp(n, "0") == 0) {
        cout << "0" << endl;
        return 0;
    }

    int i = 0;

    ////////////////////// 方法一 ////////////////////////////
    while (r > 0)
    {
        d[i] = r % b;
        r /= b;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        if (d[j] >= 10)
        {
            cout << char(d[j] - 10 + 'A');
            continue;
        }
        else
            cout << d[j];
    }

    ////////////////////// 方法二 ////////////////////////////
    /* // 用字符串保存结果的形式提交结果为Wrong Answer，本地验证正常，原因没有找到
    while (r != 0) {
        if (r % b < 10)
            res[i] = (char)((r % b) + '0');
        else if (r % b >= 10)
            res[i] = (char)(r % b - 10 + 'A');
        r = r / b;
        ++i;
    }
    
    for (int j = i; j >= 0; --j)
        cout <<res[j];
    cout << endl;
    */
    return 0;
}