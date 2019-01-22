#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int r, m, y;
    cin >> r >> m >> y;
    double sum = (double)m;
    for (int i = 0; i < y; i++) {
        sum = (100 + r) *sum;
        sum = sum/100;
    }

    cout << (int)sum << endl;
    return 0;
}