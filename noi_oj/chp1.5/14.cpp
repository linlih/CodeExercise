#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    int x, n;
    cin >> x >> n;
    double res = (double)x;
    for (int i = 0; i < n; i++) {
        res = res * 1.001;
    }
    cout << setprecision(4) << fixed << res << endl;
    return 0;
}