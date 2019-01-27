#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int *a = new int[n];
    int *b = new int[n];
    long sum = 0;


    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cin >> skipws;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        cin >> skipws;
    }

    for (int i = 0; i < n; ++i) {
        sum += ((long)a[i]*b[i]);
    }

    cout << sum << endl;

    return 0;
}