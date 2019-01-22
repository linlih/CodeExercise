#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int x, y;
    cin >> x >> y;
    if (x >= -1 && x <= 1) {
        if (y >= -1 && y <= 1)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    else 
        cout << "no" << endl;
    return 0;
}