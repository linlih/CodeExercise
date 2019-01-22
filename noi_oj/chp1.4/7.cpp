#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    if (a/10 > 0 || (b/20 > 0))
        cout << "1";
    else
        cout << "0";
    return 0;
}