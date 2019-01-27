#include <iostream>
#include <string>

using namespace std;
int main(int argc, char const *argv[])
{
    string a, b;
    cin >> a;
    cin >> b;
    //cout << a[0] <<" " << b << endl;    
    string res(200, ' ');
    int len = 0;
    int tmp = 0;
    string tmp_str;
    res[0] = '0';
    if (a.length() > b.length()) {
        len = b.length();
    }
    else {
        len = a.length();
    }
    for (int i = 0; i < len; ++i) {
        tmp =(res[i] + a[i] + b[i] - 3*'0');
        cout << tmp << endl;
        if (tmp > 10) {
            res[i] = tmp%10 + '0';
            res[i+1] = tmp/10 + '0';
        }
        else {
            res[i] = tmp + '0';
        }
    }
    cout << res << endl;

    return 0;
}