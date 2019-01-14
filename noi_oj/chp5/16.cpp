#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    int i = 0;
    float sum = 200;
    for (i = 1; i <= 20; i++) {
        if ((i*n) > sum) {
            cout << i << endl;
            break;
        }
        sum = sum*(100+k);
        sum = sum / 100;
    }
    if (i == 21)
        cout << "Impossible" << endl;
    return 0;
}