#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    double base[16] = {0};
    base[0] = 1.0/8;
    for (int i = 1; i < 16; ++i) {
        base[i] = base[i-1]/8.0;
    }

    double out = 0;
    for (int i = 2; i < str.length(); ++i) {
        out += (str[i] - '0') * base[i-2];
    }
    cout << str << " [8] = " ;//<< out << " [10]" << endl; // 不知道这里什么情况，这种输出方式提交是WA，改成printf的方式正常
    printf("%.50g [10]", out);
    return 0;
}