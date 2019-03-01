#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    unsigned long base[32] = {0};
    base[0] = 2;
    for (int i = 1; i < 32; ++i) {
        base[i] = base[i-1]*2;
    } 
    string str;
    unsigned long res = 0;
    while(getline(cin, str) && str!="0") {
        if (str.length() > 32)
            break;
        for (int i = str.length() -1, j = 0; i >= 0; --i, ++j) {
            res += (str[i] - '0') * (base[j] - 1);
        }
        cout << res << endl;
        res = 0;
        str.clear();
    }
    return 0;
}