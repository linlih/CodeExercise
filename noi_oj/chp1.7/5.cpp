#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    // 输入的字符串可能含有空格！这个实现方法不行！
    // string str;
    // cin >> str;

    string str;
    getline(cin, str);
    string out;
    for (int i = 0; i < (str.length() - 1); ++i) {
        out += (char)(str[i] + str[i + 1]);
    }
    out += (char)(str[0] + str[str.length() - 1]);
    cout << out << endl;

    return 0;
}