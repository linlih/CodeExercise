#include <iostream>

using namespace std;

#define CHICKEN_FOOT 2
#define RABBIT_FOOT  4

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    if (n%2 != 0) {
        cout << "0 0" << endl;
        return 0;
    }
    if (n%RABBIT_FOOT == 0)
        cout << n/RABBIT_FOOT;
    else
        cout << n/RABBIT_FOOT + 1;
    cout << " " << n/CHICKEN_FOOT << endl;
    return 0;
}