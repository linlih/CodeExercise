#include <iostream>

using namespace std;
int main(int argc, char const *argv[]) {
    int n, i;
    double a, b, c, d, x, y;
    cin >> n;
    cin >> a >> b;
    x = b / a;
    for (i = 1; i < n; i++) {
        cin >> c >> d;
        y = d / c;
        if (y - x > 0.05)
            cout << "better" << endl;
        else if (x - y > 0.05)
            cout << "worse" << endl;
        else
            cout << "same" << endl;
    }
    return 0;
}