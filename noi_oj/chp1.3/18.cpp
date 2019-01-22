#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int a1, a2, n;
    cin >> a1 >> a2 >> n;
    int d = a2 - a1;
    cout << a1 + (n-1)*d << endl;
    return 0;
}