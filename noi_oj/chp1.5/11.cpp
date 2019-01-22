#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    int c1 = 0, c2 = 0, c3 = 0;
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cin >> skipws;
        if (temp ==  1)
            c1 ++;
        else if (temp == 5)
            c2 ++;
        else if (temp == 10)
            c3 ++;
    }

    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;
    return 0;
}