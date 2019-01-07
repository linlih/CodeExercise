#include <iostream>
#include <iomanip>
using namespace std;
#define PI 3.14
int main(int argc, char const *argv[])
{
    double a;
    cin >> a;
    cout << setprecision(2) << fixed << ((double)4/3)*PI*a*a*a << endl;
    return 0;
}