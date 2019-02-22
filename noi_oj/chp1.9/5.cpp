#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a;
    cin >> a;
    cin >> skipws;

    int max = a;
    int min = a;
    for (int i = 1; i < n; ++i) {
        cin >> a;
        cin >> skipws;
        if (max < a)
            max = a;
        if (min > a)
            min = a;
    }

    cout << max - min << endl;

    return 0;
}