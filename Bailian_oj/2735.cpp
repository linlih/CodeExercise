#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    unsigned int a;
    cin >> a;
    unsigned int res = 0;
    unsigned int tmp = 1;
    while (a != 0) {
        res += (a%10)*tmp;
        tmp *= 8;
        a = a / 10;
    }
    cout << res << endl;
    return 0;
}