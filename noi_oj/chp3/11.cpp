#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    double a, b;
    cin >> a >> b;
    cout << (a - ((int)(a/b))*b) << endl;
    return 0;
}