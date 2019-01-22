#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    int p = 1;
    int q = 2;
    int n;
    cin >> n;
    double sum = 0;
    int temp;
    for (int i = 0; i < n; ++i) {
        sum += (1.0*q)/p;
        temp = p;
        p = q;
        q = temp + q;
    }
    cout << setprecision(4) << fixed <<sum << endl;
    return 0;
}