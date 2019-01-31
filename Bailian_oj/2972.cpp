#include <iostream>

using namespace std;

// 转化为10进制数
long trans(long num, long radix) {
    long ret = 0;
    long tmp = num;
    long tmp_r = 1;
    while(tmp!=0) {
        ret+=(tmp%10)*tmp_r;
        if (tmp%10 >= radix)
            return -1;
        tmp_r *= radix;
        tmp = tmp/10;
    }
    return ret;
}


int main(int argc, char const *argv[])
{
    long a, b, c;
    cin >> a >> b >> c;
    long t_a, t_b, t_c;
    int flag = 1;
    for (int i = 2; i <= 16; ++i) {
        t_a = trans(a, i);
        t_b = trans(b, i);
        t_c = trans(c, i);
        if (t_a == -1 || t_b == -1 || t_c == -1)
            continue;
        //cout << t_a << " " << t_b << " " << t_c << endl;
        if (t_a*t_b == t_c) {
            cout << i << endl;
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        cout << "0" << endl;

    return 0;
}