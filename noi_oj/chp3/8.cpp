#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    double f;
    cin >> f;
    cout << setprecision(5) << fixed << (5*(f-32)/9) << endl;
    return 0;
}