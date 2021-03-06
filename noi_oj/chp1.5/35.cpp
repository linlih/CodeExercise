#include <iostream>
#include <iomanip>

using namespace std;

long fac[17] = {0};

long factorial(int n) {
    if (fac[n]) return fac[n];
    if (n == 1) {
        fac[1] = 1;
        return 1;
    }
    else {
        fac[n] = n*factorial(n-1);
        return fac[n];
    }
}

int main(int argc, char const *argv[])
{
    double sum = 1;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        sum += ((1.0*1)/factorial(i));
    }

    cout << setprecision(10) << fixed <<  sum << endl;
    return 0;
}