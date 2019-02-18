#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n, i, j;
    cin >> n >> i >> j;
    // 同行
    for (int k = 1; k <= n; ++k) {
        cout << "(" << i << "," << k << ")" << " ";
    }
    cout << endl;
    // 同列
    for (int k = 1; k <= n; ++k) {
        cout << "(" << k << "," << j << ")" << " ";
    }
    cout << endl;
    

    // 左上到右下
    int x = i; 
    int y = j;
    int flag_margin = 0;

    if (x == 1 || y == 1 ) {
        flag_margin = 1;
    }
    else if (x == n) {
        flag_margin = 2;
    }
    // else if (x == y) {
    //     flag_margin = 0;
    // }

    if (flag_margin != 1) {
        for (int k = 0; k < n; ++k) {
            if ( x > 1 && y > 1) {
                x -= 1;
                y -= 1;
            }
            if (x == 1 || y == 1)
                break;
        }
    }

    for (int k = 1; k <= n; ++k) {
        cout << "(" << x++ << "," << y++ << ")" << " ";
        if (x == (n+1)||y == (n+1))
            break;
    }
    cout << endl;

    // 左下到右上
    x = i;
    y = j;
    if (flag_margin != 2) {
        for (int k = 0; k < n; ++k) {
            if (y > 1) {
                x += 1;
                y -= 1;
            }
            if (x == n || y == 1)
                break;
        }
    }
    for (int k = 1; k <= n; ++k) {
        cout << "(" << x-- << "," << y++ << ")" << " ";
        if (x == 0||y == (n+1))
            break;
    }
    cout << endl;
    return 0;
}