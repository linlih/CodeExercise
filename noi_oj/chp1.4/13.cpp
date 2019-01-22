#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    float n;
    float res = 0;
    cin >> n;
    if (n >= 0 && n < 5)
        res = -n + 2.5;
    else if (n >= 5 && n < 10)
        res = 2 - 1.5*(n - 3)*(n - 3);
    else if (n >= 10 && n < 20)
        res = n/2 - 1.5;
    cout << setprecision(3) << fixed << res << endl;
    return 0;
}