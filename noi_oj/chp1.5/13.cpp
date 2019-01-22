#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    long a;
    int n;
    cin >> a >> n;
    long long res = 1;
    for (int i = 0; i < n; i++) {
        res *= a;
    }
    cout << res << endl;
    return 0;
}