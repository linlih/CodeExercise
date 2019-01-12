#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int a, b, c;
    cin >> a >> b >> c;
    int big;
    if (a > b)
        big = a;
    else 
        big = b;
    if (big < c)
        big = c;
    cout << big << endl;
    return 0;
}