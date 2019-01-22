#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    int temp;
    int t = 0;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> temp;
        t += temp;
    }
    cout << (n-2)*180 - t << endl;
    return 0;
}