#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    if (m%2 == 0)
        m = m + 1;
    if (n%2 == 0)
        n = n - 1;
    int t = (n-m)/2 + 1;
    cout << m*t + t*(t-1) << endl;
    return 0;
}