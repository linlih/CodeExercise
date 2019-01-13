#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    int temp;
    int big = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cin >> skipws;
        if (big < temp)
            big = temp;
    }

    cout << big << endl;
    return 0;
}