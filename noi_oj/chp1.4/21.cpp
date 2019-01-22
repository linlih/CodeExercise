#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n, x, y;
    cin >> n >> x >> y;
    int eat;
    eat = y/x;
    if (y%x != 0)
        eat += 1;
    if (eat > n)
        cout << "0" << endl;
    else
        cout << n - eat << endl;
    return 0; 
}