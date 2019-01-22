#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    long long a;
    long long b;
    cin >> a >> b;
    if (a > b)
        cout << ">" << endl;
    else if (a < b)
        cout << "<" << endl;
    else
        cout << "=" << endl;
    return 0;
}