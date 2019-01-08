#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    long res = 1;
    while(n!=0) {
        res*=2;
        n--;
    }
    cout << res << endl;
    return 0;
}