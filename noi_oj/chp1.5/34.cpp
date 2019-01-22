#include <iostream>

using namespace std;

int fac[13] = {0};

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
    int n;
    cin >> n;
    long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += factorial(i);
    }
    cout << sum << endl;
    return 0;
}