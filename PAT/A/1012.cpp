/*
 * 运行数据： ms  KB
 */
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

string to_radix(long num, int radix) {
    string res;
    long tmp = num;
    while(tmp != 0) {
        if (tmp%radix < 10) 
            res+=(char)(tmp%radix + '0');
        else if (tmp%radix > 10)
            res+=(char)(tmp%radix + 'A');
        tmp /= radix;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    long a, b;
    int radix;
    cin >> a >> b >> radix;
    string res = to_radix(a+b, radix);
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}