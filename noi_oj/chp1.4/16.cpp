#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b > c) && (a - b < c))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}