#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    double x;
    double a, b, c, d;
    cin >> x >> a >> b >> c >> d;
    cout << setprecision(7) << fixed << (a*x*x*x + b*x*x + c*x +d) << endl;
    return 0;
}